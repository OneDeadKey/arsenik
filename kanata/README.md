kanata
================================================================================

A modularized Arsenik that let you choose your features, e.g.
angle mods, Vim-like navigation layer, Mac/Azerty/Qwertz support, etc.

- load `kanata.kbd` with kanata (installation instructions below)
- enable each feature by un-commenting the related line
- live-reload the configuration with Space+Backspace (requires layer-taps)

Configuration options:

- key arrangement: Mac or PC, with or without angle mod?
- base layer: standard, layer-taps, homerow mods?
- symbols layer: AltGr, QWERTY, QWERTZ, AZERTY?
- navigation layer: ESDF or HJKL?

Note that kanata can also use the laptop’s trackpoint buttons (e.g. ThinkPad)
as two additional thumb keys. :-)


Installation
--------------------------------------------------------------------------------

You can install `kanata` by either downloading a [pre-built
executable](https://github.com/jtroo/kanata/releases), or by running the
following commands (if you have `rustc` installed):

```bash
rustup update stable
cargo install kanata
```

Windows users might prefer the `kanata_winIOv2.exe` version as it fixes some
weird bugs.

Linux users may want to run these extra steps:

<details>
<summary> Running kanata without <code>sudo</code> </summary>

kanata needs to intercept `uinput` signals, which it cannot do without the
proper authorisations.

If you don’t want to run `kanata` with `sudo`, you’ll need to allow `kanata` to
read from `uinput`. This requires the users to be part of both `input` and
`uinput` groups.

For that, you first need to create a `uinput` group if it is not the case yet:

```bash
sudo groupadd -U $USERNAME uinput
```

Where `$USERNAME` is the target user (or users in a comma separated list), and
add the target user (or users) to the group input:

```bash
sudo usermod -aG input $USERNAME
```

You can then check after relogin that both groups appear in the result of the
`groups` command launched as the target user.

Finally, you need to add a udev rule in `/etc/udev/rules.d/50-kanata.rules`:

```udev
KERNEL=="uinput", MODE="0660", GROUP="uinput", OPTIONS+="static_node=uinput"
```
</details>

<details>
<summary> Making a user-side systemd service for kanata </summary>

Note: This only works if `kanata` is able to run without <pre>sudo</pre> (and
is using `systemd`).

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
