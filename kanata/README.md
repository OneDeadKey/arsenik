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

*Note: This tip has been tested for version 1.6.1 of Kanata. In later versions the
`winIOv2` version might be the default.*

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

For that, you first need to create a `uinput` group if it doesn’t exist yet:

```bash
sudo groupadd -U $USERNAME uinput
```

where `$USERNAME` is the target user (or users in a comma-separated list). Then
add the target user (or users) to the group input:

```bash
sudo usermod -aG input $USERNAME
```

You can check after re-logging that both groups appear in the result of the
`groups` command launched as the target user.

Finally, you need to add a udev rule in `/etc/udev/rules.d/50-kanata.rules`:

```udev
KERNEL=="uinput", MODE="0660", GROUP="uinput", OPTIONS+="static_node=uinput"
```

### Making a user-side <code>systemd</code> service for Kanata

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

<details>
<summary> macOS</summary>

### Karabiner DriverKit installation

Install the [Karabiner-DriverKit-VirtualHIDDevice](https://github.com/pqrs-org/Karabiner-DriverKit-VirtualHIDDevice/releases/tag/v4.3.0). Latest version (v5.0.0) is not working with Kanata.

To activate it:

```
/Applications/.Karabiner-VirtualHIDDevice-Manager.app/Contents/MacOS/Karabiner-VirtualHIDDevice-Manager activate
```

You may have to allow Kanata execution in the Privacy & Security panel from macOS settings.

As root, add the following content in `/Library/LaunchDaemons/org.pqrs.service.daemon.Karabiner-VirtualHIDDevice-Daemon.plist` file:

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
  <dict>
    <key>Label</key>
    <string>org.pqrs.service.daemon.Karabiner-VirtualHIDDevice-Daemon</string>
    <key>KeepAlive</key>
    <true/>
    <key>ProcessType</key>
    <string>Interactive</string>
    <key>ProgramArguments</key>
    <array>
      <string>/Library/Application Support/org.pqrs/Karabiner-DriverKit-VirtualHIDDevice/Applications/Karabiner-VirtualHIDDevice-Daemon.app/Contents/MacOS/Karabiner-VirtualHIDDevice-Daemon</string>
    </array>
  </dict>
</plist>
```

A new item *Fumihiko Takayama* will be added in System Settings > Login Items.

Two Karabiner processes should be started:

```
sh-3.2# ps aux | grep -i karabiner | grep -v grep
_driverkit       26050   0.0  0.0 410598064   2256   ??  Ss    8:02PM   0:00.04 /Library/SystemExtensions/.../org.pqrs.Karabiner-DriverKit-VirtualHIDDevice.dext/org.pqrs.Karabiner-DriverKit-VirtualHIDDevice org.pqrs.Karabiner-DriverKit-VirtualHIDDevice 0x10002b929 org.pqrs.Karabiner-DriverKit-VirtualHIDDevice
root             25744   0.0  0.1 410756464   9872   ??  Ss    8:01PM   0:00.16 /Library/Application Support/org.pqrs/Karabiner-DriverKit-VirtualHIDDevice/Applications/Karabiner-VirtualHIDDevice-Daemon.app/Contents/MacOS/Karabiner-VirtualHIDDevice-Daemon
```

### Kanata installation

Download Kanata [here](https://github.com/jtroo/kanata/releases/tag/v1.7.0) and save it in a persistent directory.

Add a sudo rule in `/private/etc/sudoers.d/kanata` where `$USERNAME` is your username:

```
$USERNAME ALL=(ALL) NOPASSWD: /path/to/kanata/binary/kanata
```

To start Kanata at the beginning of the session, add a property list file in `~/Library/LaunchAgents/com.jtroo.kanata.plist` with the following content:

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>com.jtroo.kanata</string>

    <key>ProgramArguments</key>
    <array>
        <string>sudo</string>
        <string>/path/to/kanata/binary/kanata</string>
        <string>--cfg</string>
        <string>/path/to/kanata/config/file</string>
        <string>-n</string>
    </array>

    <key>RunAtLoad</key>
    <true/>

    <key>KeepAlive</key>
    <true/>
</dict>
</plist>
```

In system settings, search Login Items menu and select `sudo` service in *Allow in the Background* list.
You can restart Kanata with new configuration by disabling and enabling this service.

</details>

[Download Arsenik]: https://github.com/OneDeadKey/arsenik/releases
[Download Kanata]: https://github.com/jtroo/kanata/releases
