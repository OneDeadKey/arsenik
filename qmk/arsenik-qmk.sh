#!/usr/bin/env bash

set -euo pipefail

if [ "$#" -lt 1 ]; then
    echo "Usage:"
    echo "$0 <keyboard_name> [-n] [-b,-f]"
    echo "    # Install Arsenik for your keyboard, opens your editor to edit the config"
    echo '    # -n: no editor: doesn’t open the config with your $EDITOR'
    echo "    # -c: compile the newly created keymap (after you edited the config)"
    echo "    # -f: compile the newly created keymap (after you edited the config) then flash"
    exit 0
fi

if [ -z "${QMK_PATH+x}" ]; then
    QMK_PATH="$HOME/qmk_firmware"
fi


if [ -z "${EDITOR+x}" ]; then
    if which nano >/dev/null 2>&1; then
        EDITOR="nano"
    else
        EDITOR="vi"
    fi
fi


function get_keymaps_folder() {
    keyboard_name="$1"
    while [ ! -d "$QMK_PATH/keyboards/$keyboard_name/keymaps" ]; do
        if [ "$keyboard_name" == "." ]; then
            echo "Couldn’t find keymap folder for your keyboard"
            exit 1
        fi
        keyboard_name=$(dirname "$keyboard_name")
    done

    echo "$QMK_PATH/keyboards/$keyboard_name/keymaps"
}

function handle_keymap_conflict() {
    local arsenik_folder="$1"
    local script_name=$(basename $0)

    echo -e "\x1b[1;31mError :\x1b[0m The Arsenik keymap already exists for this keyboard."
    echo -e "$script_name should \x1b[4mnot\x1b[0m be used to recompile your keymap, this is an \x1b[4minstall\x1b[0m script."
    echo "This is because some keyboards may need extra info to properly compile or flash the"
    echo "firmware (like if you need to specify the bootloader)"
    echo

    local old_arsenik_keymap_folder="${arsenik_folder::-1}"
    local old_arsenik_keymap_id=1

    while [ -d "$old_arsenik_keymap_folder"_"$old_arsenik_keymap_id" ]; do
        old_arsenik_keymap_id=$((old_arsenik_keymap_id + 1))
    done

    local keymap_backup_folder="$old_arsenik_keymap_folder"_"$old_arsenik_keymap_id"

    echo "If you want to reinstall the Arsenik keymap, your old keymap will be moved to this folder:"
    echo "    \`$keymap_backup_folder\`"
    echo

    echo "If you want to recompile and flash your keymap, you should do so with the commands provided by QMK"
    echo "    Using the QMK CLI:  \`qmk flash -kb $keyboard_name -km arsenik\`"
    echo "        (docs: https://docs.qmk.fm/cli_commands)"
    echo "    Using the \`make\` command:  \`make $keyboard_name:arsenik:flash\` run in $QMK_PATH"
    echo "        (docs: https://docs.qmk.fm/getting_started_make_guide)"
    echo
    echo "Note: Those commands may not work out of the box, some keyboards need extra cmdline arguments"
    echo "(for instance if you need to specify the bootloader explicitely)"
    echo "If you have an error, check the docs mentionned above."
    echo

    echo "What do you want to do?"
    COLUMNS=1  # Display options from select in a single column
    select cmd in \
        "Backup keymap and reinstall Arsenik" \
        "Recompile and flash keymap with the QMK CLI" \
        "Recompile and flash keymap with \`make\`" \
        "Abort"
    do
        case $cmd in
            "Backup keymap and reinstall Arsenik")
                mv "$arsenik_folder" "$keymap_backup_folder"
                return 0
                ;;
            "Recompile and flash keymap with the QMK CLI")
                cd "$QMK_PATH"
                make "$keyboard_name":arsenik:flash
                return 1
                ;;
            "Recompile and flash keymap with \`make\`")
                qmk flash -kb $keyboard_name -km arsenik
                return 1
                ;;
            "Abort")
                echo "Aborting."
                return 1
                ;;
            *)
                echo "Unknown command chosen. Aborting."
                return 1
                ;;
            esac
    done
}

function make_new_arsenik_keymap() {
    local keyboard_name="$1"
    local qmk_cmd="$2"
    local no_editor="$3"

    local keymap_folder=$(get_keymaps_folder "$keyboard_name")
    local arsenik_folder="$keymap_folder/arsenik/"
    local default_keymap_folder="$keymap_folder/default"

    [ -d "$arsenik_folder" ] && handle_keymap_conflict "$arsenik_folder"

    cp -r "$default_keymap_folder" "$arsenik_folder"

    local layout=""
    case $(ls "$default_keymap_folder"/keymap.* | sed 's/.*\(keymap.*\)/\1/') in
        "keymap.c")    layout=$(grep 'LAYOUT' "$default_keymap_folder"/keymap.c | sed 's/.*= \(.*\)(/\1/' | head -n 1);;
        "keymap.json") layout=$(grep 'LAYOUT' "$default_keymap_folder"/keymap.json | sed 's/ *"layout": "\(.*\)",/\1/');;
        *) echo "Unable to find layout name, unsupported keymap format";;
    esac

    if [ "$layout" == "LAYOUT" ]; then
        layout+="_$(echo "$keyboard_name" | sed 's,/,_,g' | sed 's/_rev[0-9]*$//')"
    fi

    layout="ARSENIK_$layout"

    rm "$arsenik_folder"/keymap.*
    cat ./arsenik_config.h >> "$arsenik_folder/config.h"
    cat ./rules.mk >> "$arsenik_folder/rules.mk"
    cp ./keymap.c ./arsenik.h ./keymap_ergol.h "$arsenik_folder"

    # echo "s/ARSENIK_PLACEHOLDER_LAYOUT/$layout/"
    sed -i "s/ARSENIK_PLACEHOLDER_LAYOUT/$layout/" "$arsenik_folder/config.h"

    if [ "$no_editor" = false ]; then
        eval "$EDITOR" "$arsenik_folder/config.h"
    fi

    case "$qmk_cmd" in
        "none") ;;
        "compile") cd "$QMK_PATH" && make "$keyboard_name:arsenik";;
        "flash") cd "$QMK_PATH" && make "$keyboard_name:arsenik:flash";;
    esac
}


no_editor=false
qmk_cmd="none"
for arg in "${@:2}"; do
    case "$arg" in
        "-n") no_editor=true;;
        "-c") qmk_cmd="compile";;
        "-f") qmk_cmd="flash";;
        *) echo "Unknown argument $arg."; exit 1;;
    esac
done

make_new_arsenik_keymap "$1" "$qmk_cmd" "$no_editor"
