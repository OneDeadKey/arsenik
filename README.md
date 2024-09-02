Arsenik
================================================================================

Configure your keyboard (even if it is not programmable) with a
beginner-friendly, simplified [Miryoku][1]-like approach to minimize finger
movements!

![base, navigation and sym layers on a 33-key keyboard](img/all.svg)

*Note: The keyboard layout presented here in the illustration is Qwerty but it
works with other layouts as well — e.g. Azerty, Qwertz, Ergo‑L, Bépo…*

**Bring the keys to your fingers, rather than moving your fingers to the keys!**

- A long press on the <kbd>Return</kbd> key brings up the <kbd>Symbol</kbd>
layer in blue, where all programming symbols are arranged for comfort and
efficiency.
- A long press on the <kbd>Space</kbd> bar brings up the <kbd>Navigation</kbd>
layer in orange, with a numpad, cursor navigation (<kbd>ESDF</kbd>) and one-hand
shortcuts.

This is how modern ergonomic keyboards work — e.g. [Planck][2], [Atreus][3],
[Corne][4], [Ferris][5]… The goal here is to propose an approach that works
with any keyboard, including your laptop’s.

*Note: You might benefit the most of Arsenik if you are [touch typing][6].*


Modular Approach
--------------------------------------------------------------------------------

Enable Arsenik features from the following options:
- [angle mod][7] (the only enabled option by default)
- 3 home row mods (HRM) per hand for <kbd>Ctrl</kbd>, <kbd>Alt</kbd>,
<kbd>Super</kbd>
- 3 layer-tap keys under the thumbs: <kbd>Alt</kbd> (or <kbd>Shift</kbd> in
HRM)/<kbd>Backspace</kbd>, <kbd>Navigation</kbd>/<kbd>Space</kbd>,
<kbd>Symbol</kbd>/<kbd>Return</kbd>
- symbol layer: have all programmation characters at, at most, one key away from
your fingers
- num row or num pad
- navigation layer like in arrow cluster or Vim-like

Use it with Qwerty, Qwertz, Azerty, Ergo‑L, Bépo, and many other keyboard layouts!


Main Benefits
--------------------------------------------------------------------------------

- <kbd>Shift</kbd>, <kbd>Backspace</kbd>, <kbd>Return</kbd> under the thumbs!
- all numbers and programming symbols in the comfortable 3×10 zone (close to the
home row)
- symmetrical modifiers on the home row
- easier left-hand shortcuts
- works with any keyboard

Unlike Miryoku which requires 6 thumb keys, Arsenik has been designed to work
with standard ANSI/ISO/laptop keyboards, leveraging the spacebar and the two
Alt/Cmd keys.


Installation
--------------------------------------------------------------------------------

Starts right now with the keyboard you already have, and install
[Kanata with Arsenik configuration](kanata).

If you have a programmable keyboard you might want to take a look at the
[QMK](qmk) version of Arsenik (work in progress).

Other desktop implementations (kmonad, keyd…) would be nice to see as well.


Related Projects
--------------------------------------------------------------------------------

### Inspiration

- [Miryoku][1] for the main idea of using modifiers on the home row and layer
shifters under the thumbs;
- [Lafayette][8] and [Ergo-L][9] for the <kbd>Symbol</kbd> layer, which has been
blatantly taken *as is*;
- [Extend][10], [Neo][11], [Shaka34][12] for the <kbd>Navigation</kbd> layer.

### Alternative Symbol Layers

- [Neo][11]
- [Seniply][13]
- [Pascal Getreuer’s][14]

### Non-Goals

- being the most efficient 3×5 layout — [Miryoku][1] is probably the most
advanced approach for that, at least on custom 36-key keyboards;
- fitting any OS layout — Arsenik works best if your OS layout has either no
AltGr layer at all (e.g. QWERTY, Colemak, Workman…), or an optimized AltGr layer
([Lafayette][8], [Ergo-L][9]…).

### Similar Projects

- [Miryoku][1]: 36 keys, 6 layers
- [Seniply][13]: 34 keys, 6 layers, no layer-taps (“Callum-style”)

### Join the community

French-speaking users may join the [Ergo-L Discord server][15] which hosts a
channel to talk about Arsenik.

Feel free to open an issue and/or a pull request if you encounter a bug or want
to enhance the Arsenik experience!

TODO
--------------------------------------------------------------------------------

- KMonad / Karabiner support
- sample QMK / ZMK implementations for common keyboards
<!-- https://jasoncarloscox.com/writing/combo-mods/ -->


[1]: https://github.com/manna-harbour/miryoku
[2]: https://olkb.com/collections/planck
[3]: https://atreus.technomancy.us
[4]: https://github.com/foostan/crkbd
[5]: https://github.com/pierrechevalier83/ferris
[6]: https://en.wikipedia.org/wiki/Touch_typing
[7]: https://colemakmods.github.io/ergonomic-mods/angle.html
[8]: https://qwerty-lafayette.org/42
[9]: https://ergol.org
[10]: https://dreymar.colemak.org/layers-extend.html
[11]: https://neo-layout.org
[12]: https://github.com/lobre/shaka34
[13]: https://stevep99.github.io/seniply/
[14]: https://getreuer.info/posts/keyboards/symbol-layer/#my-symbol-layer
[15]: https://discord.gg/5xR5K3nAFX
