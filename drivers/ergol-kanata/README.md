# Ergo-L Kanata driver

An Ergo-L "portable" driver, emulated with Kanata over your regular keymap.

## Prerequisites

Kanata v1.7.0+ is required.

## Caveats

- Only Windows is supported at this point; this *doesn’t work* on GNU/Linux
  (yet?) and is untested on macOS.
- Only Azerty-FR is supported as the base keymap at this point.
- Mac keyboards are not supported at this point.
- Not all the dead keys on the AltGr-Shift layer are implemented yet.
- Some other exotic characters may be missing, please report bugs.
- Layer taps are not supported at this point.
- Home row mods are not supported at this point.

## Installation

The easiest way to run this driver is to:

1.  Clone this Git repository (or download a zip snapshot).
1.  Download `kanata_winIOv2.exe` (*not* `kanata.exe`!) from
    <https://github.com/jtroo/kanata/releases>.
1.  Place the downloaded exe in this directory.
1.  Run the exe.

## Angle mod

This driver supports the angle mod for ISO keyboards; you may enable it by
editing `kanata.kbd`.
