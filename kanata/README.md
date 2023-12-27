kanata
================================================================================


Pick Your Poison!
--------------------------------------------------------------------------------

| type  | without homerow-mods        | with homerow-mods          | suitable layouts                  |
| ----- | --------------------------- | -------------------------- | --------------------------------- |
| ANSI  | [arsenik_easy_ansi.kbd][1]  | [arsenik_hrm_ansi.kbd][3]  | QWERTY, Dvorak, Colemak, Workman… |
| AltGr | [arsenik_easy_altgr.kbd][2] | [arsenik_hrm_altgr.kbd][4] | [Lafayette42][10], [Ergo-L][11]…  |

[1]: arsenik_easy_ansi.kbd
[2]: arsenik_easy_altgr.kbd
[3]: arsenik_hrm_ansi.kbd
[4]: arsenik_hrm_altgr.kbd

- “Easy” variants don’t use any homerow-mods and leave the left thumb key
modifier unchanged — but they still use a <kbd>Prog</kbd> layer and put the
<kbd>Backspace</kbd> and <kbd>Return</kbd> keys under the thumbs. A good
starting point if you’re new to dual keys.
- ANSI variants assume all symbols in your keyboard layout are in their
QWERTY-ANSI positions: works fine with most US layouts but Dvorak users will get
a slightly different <kbd>Prog</kbd> layer.
- AltGr variants use your layout’s AltGr layer instead of the <kbd>Prog</kbd>
layer: perfect for layouts that already have an optimized AltGr layer, such as
[QWERTY-Lafayette][10] and [Ergo-L][11].

[10]: https://qwerty-lafayette.org/42
[11]: https://ergol.org

Note that kanata can also use the laptop’s trackpoint buttons (e.g. ThinkPad)
as two additional thumb keys. :-)


Installation
--------------------------------------------------------------------------------

You can install `kanata` by either downloading a [pre-built
executable](https://github.com/jtroo/kanata/releases), or by running the
following commands (if you have `rustc` installed):

```bash
rustup update stable
cargo insall kanata
```

Linux users may want to run these extra steps:

<details>
<summary> Running kanata without `sudo` </summary>

kanata needs to intercept `uinput` signals, which it cannot do without the
proper authorisations. If you don’t want to run `kanata` with `sudo`, you’ll
need to allow `kanata` to read from `uinput` with a udev rule at
`/etc/udev/rules.d/50-kanata.rules`:

```udev
KERNEL=="uinput", MODE="0660", GROUP="uinput", OPTIONS+="static_node=uinput"
```
</details>

<details>
<summary> Making a user-side systemd service for kanata </summary>

Note: This only works if `kanata` is able to run without `sudo` (and are using
`systemd`).

Using a `systemd service` allows running `kanata` as a daemon, possibly right
after logging in. Here is a template for a service file:

```
[Unit]
Description=Kanata keyboard remapper
Documentation=https://github.com/jtroo/kanata

[Service]
Environment=PATH=/usr/local/bin:/usr/local/sbin:/usr/bin:/bin
Environment=DISPLAY=:0
Environment=HOME=/path/to/home/folder
Type=simple
ExecStart=/usr/local/bin/kanata --cfg /path/to/kanata/config/file
Restart=no

[Install]
WantedBy=default.target
```

Copy-paste it into `~/.config/systemd/user/kanata.service`, fill in the
placeholders, then run one of the following commands:

- `systemctl --user start kanata.service` to manually start `kanata`
- `systemctl --user enable kanata.service` so `kanata` may autostart whenever the current user logs in
- `systemctl --user status kanata.service` to check if `kanata` is running

</details>
