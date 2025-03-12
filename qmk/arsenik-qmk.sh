#!/usr/bin/env bash

set -euo pipefail

if [ "$#" -lt 1 ]; then
    echo "Usage:"
    echo "$0 <keyboard_name> [-n] [-b,-f]"
    echo "    # Install Arsenik for your keyboard, opens your editor to edit the config"
    echo '    # -n: no editor: doesn’t open the config with your $EDITOR'
    echo "    # -b: build the newly created keymap (after you edited the config)"
    echo "    # -f: build the newly created keymap (after you edited the config) then flash"
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

function make_new_arsenik_keymap() {
    local keyboard_name="$1"
    local qmk_cmd="$2"
    local no_editor="$3"

    local keymap_folder=$(get_keymaps_folder "$keyboard_name")
    local arsenik_folder="$keymap_folder/arsenik/"
    local default_keymap_folder="$keymap_folder/default"

    cp -r "$default_keymap_folder" "$arsenik_folder"
    ls -l "$arsenik_folder"

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
        "build") cd "$QMK_PATH" && make "$keyboard_name:arsenik";;
        "flash") cd "$QMK_PATH" && make "$keyboard_name:arsenik:flash";;
    esac
}


no_editor=false
qmk_cmd="none"
for arg in "${@:2}"; do
    case "$arg" in
        "-n") no_editor=true;;
        "-b") qmk_cmd="build";;
        "-f") qmk_cmd="flash";;
        *) echo "Unknown argument $arg."; exit 1;;
    esac
done

make_new_arsenik_keymap "$1" "$qmk_cmd" "$no_editor"
