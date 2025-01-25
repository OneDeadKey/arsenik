# Arsenik QMK

This is a generic implementation of the Arsenik layout for QMK keyboards.

**Disclaimer** : This is still relatively new. There might be bugs and your
keyboard might not be compatible *yet*.

## How it works

Arsenik-QMK will define a full qmk keymap in a dummy `ARSENIK_LAYOUT` layout
definition. At compile time, this dummy gets is replaced by the layout
definition your keyboard actually uses. This means that the keymap will
naturally remove unused keys (like the number row on a keyboard with 3 rows)
or add no-op to the keys unused by Arsenik on bigger keyboards.

Ideally, you install it and it just works, but not every keyboards are
currently supported. If the `ARSENIK_LAYOUT` isn’t defined for your keyboard,
it needs to be added at the end of the `arsenik.h` file. PRs are welcome, but
we will gladly help you if you open an issue ^^

Here is a list of all currently supported QMK layouts :

- `LAYOUT_split_3x5_2`
- `LAYOUT_split_3x5_3`
- `LAYOUT_split_3x6_3`
- `LAYOUT_ortho_4x10`
- `LAYOUT_ortho_4x12`
- `LAYOUT_ortho_5x10`
- `LAYOUT_ortho_5x12`
- `LAYOUT_planck_grid`
- `LAYOUT_keebio_iris_default`

## Install

You’ll need to setup your QMK environment beforhand, QMK’s cli tool does the
job well. You’ll need to know how is your keyboard is called inside of QMK’s
code, usually they are named `brand/model/revision` though that may vary from a
keyboard to another. You can always run `qmk list-keyboard | grep <your
keyboard>` to quickly find it, is case you don’t know.

Once you know how your keyboard is named, installing Arsenik-QMK is as easy as
cloning this repo locally and running the `./arsenik-qmk.sh <your keyboard>`.
The script expects to find the QMK repo at `~/qmk_firmware`, so if you already
have QMK setup somewhere else, you can set the `QMK_PATH` environment variable
before running the script.

The script will duplicate the default config for your keyboard, replace the
keymap by Arsenik’s keymap and install As-QMK’s library and default config.
Once this is done, the script will open the newly created `config.h` file with
your `$EDITOR` to let you emmidiatly toggle the different config options you
can choose from (see "Configuration" section).

Optionnal flags can be passed to `arsenik-qmk.sh` to enable or disable certain
features:

- `-n`: “no editor” (doesn’t open the `config.h` file)
- `-b`: “build” (immidiatlly build the keymap after installing it)
- `-f`: “flash” (immidiatlly build the keymap and flash your keyboard with it
    after installing it)

### example:

Let’s say I have a Keebio Iris Rev2, and I want to install Arsenik-QMK for it
(with my QMK folder located in `~/Code/qmk`) then flash the keymap. First, I
find my real keyboard name:

```sh
qmk list-keyboards | grep 'iris'
# >> ...
# >> keebio/iris/rev2
# >> ...
```

Then I run the script

```sh
QMK_PATH="$HOME/Code/qmk" ./arsenik-qmk.sh keebio/iris/rev2 -f
```
