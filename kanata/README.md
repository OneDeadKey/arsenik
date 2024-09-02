Arsenik Kanata
================================================================================

Installation
--------------------------------------------------------------------------------

- To get Arsenik, check out this repository with Git or
[download it][Download Arsenik].
- Launch `kanata.kbd` with Kanata.
  - You can install Kanata by downloading a
  [pre-built executable][Download Kanata].
  - Follow the installation details of your operating system.

<details>
<summary>Windows</summary>

Windows users might prefer to download the `kanata_winIOv2.exe` version as it
fixes some weird bugs like <kbd>C</kbd> and <kbd>V</kbd> inversion.

*Note: this tip is tested for the version 1.6.1 of Kanata, in later version the
`winIOv2` version might be the default one.*

Put the `kanata_winIOv2.exe` in the Kanata Arsenik folder, run it and you’re
good to go!
</details>

<details>
<summary>Linux</summary>

### Run Kanata without <code>sudo</code>

kanata needs to intercept `uinput` signals, which it cannot do without the
proper authorisations.

If you don’t want to run `kanata` with `sudo`, you’ll need to allow Kanata to
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


### Making a user-side systemd service for Kanata

Note: This only works if `kanata` is able to run without `sudo` (and is using
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
- `systemctl --user enable kanata.service` so `kanata` may autostart whenever
the current user logs in
- `systemctl --user status kanata.service` to check if `kanata` is running
</details>

[Download Arsenik]: https://github.com/OneDeadKey/arsenik/releases
[Download Kanata]: https://github.com/jtroo/kanata/releases
