Arsenik
================================================================================

A basic [Miryoku][1]-like approach to minimize finger movements:

- 3 home-row mods per hand for <kbd>Ctrl</kbd>, <kbd>Alt</kbd>, <kbd>Super</kbd>
- 3 layer-tap keys under the thumbs: <kbd>Shift</kbd>/<kbd>Backspace</kbd>,
<kbd>Navigation</kbd>/<kbd>Space</kbd>, <kbd>Symbol</kbd>/<kbd>Return</kbd>

![base, navigation and sym layers on a 33-key keyboard](img/all.svg)

**Bring the keys to your fingers, rather than moving your fingers to the keys!**

- A long press on the <kbd>Return</kbd> key brings up the <kbd>Symbol</kbd>
layer, where all programming symbols are arranged for comfort and efficiency,
Dvorak-like.
- A long press on the <kbd>Space</kbd> bar brings up the <kbd>Navigation</kbd>
layer, with a numpad, cursor navigation (<kbd>ESDF</kbd>) and one-hand shortcuts.

This is how modern ergonomic keyboards work — e.g. [Planck][47], [Atreus][44],
[Corne][42], [Ferris][34]… The goal here is to propose an approach that works
with any keyboard, including your laptop’s.

[47]: https://olkb.com/collections/planck
[44]: https://atreus.technomancy.us
[42]: https://github.com/foostan/crkbd
[34]: https://github.com/pierrechevalier83/ferris


Main Benefits
--------------------------------------------------------------------------------

- <kbd>Shift</kbd>, <kbd>Backspace</kbd>, <kbd>Return</kbd> under the thumbs!
- all numbers and programming symbols in the comfortable 3×10 zone
- symmetrical modifiers on the home row
- easier left-hand shortcuts
- works with any keyboard

Unlike Miryoku which requires 6 thumb keys, Arsenik has been designed to work
with standard ANSI/ISO/laptop keyboards, leveraging the spacebar and the two
Alt/Cmd keys.


Pick Your Poison!
--------------------------------------------------------------------------------

Adjusting to compact keyboard layouts isn’t easy, but Arsenik is designed for
a step-by-step approach.

### 1. Supercharge Your Thumbs

If you’re new to mod-taps, we suggest to start with the “easy” variants where
only the thumbs are affected:

- the left thumb key remains a <kbd>Cmd</kbd> or <kbd>Alt</kbd> key when hold,
but emits a <kbd>Backspace</kbd> when tapped;
- the right thumb key brings the <kbd>Symbols</kbd> layer when hold (similar to
an <kbd>AltGr</kbd> key), and emits <kbd>Return</kbd> when tapped;
- the spacebar brings the <kbd>Navigation</kbd> layer when when hold.

Having <kbd>Backspace</kbd> and <kbd>Enter</kbd> under the thumbs is enough to
reduce the pinky fatigue very significantly. And using the <kbd>Symbol</kbd>
and <kbd>Navigation</kbd> layer further reduces hand and finger movements.

### 2. Enable the Home-Row Mods

When you are familiar with mod-taps, it’s time to enable them on the homerow
with the “hrm” variants:

- <kbd>FDS</kbd> and <kbd>JKL</kbd> become <kbd>Ctrl</kbd>, <kbd>Alt</kbd>,
<kbd>Super</kbd> when hold long enough;
- the left thumb key can now emit a <kbd>Shift</kbd> rather than <kbd>Alt</kbd>
wen hold.

This is a very basic variant of the [Miryoku][1] principle: one layer on each
thumb key, and symmetrical modifiers on the homerow.

### 3. Spice It Up

- the 300 ms delay before a key becomes a modifier has been chosen to be easy for
beginners. Once used to mod-taps, you may want to reduce it so keyboard
shortcuts can be done more quickly;
- adding new layers should be easy, even without additional thumb keys — check the
mods to get some ideas;
- the right thumb key could do something more useful than <kbd>Enter</kbd> —
like a one-time-shift, for instance.


Downloads
--------------------------------------------------------------------------------

[Non-programmable keyboards are supported through kanata.](kanata)
Other implementations (kmonad, keyd…) would be nice to see as well.

Programmable keyboards should be trivial to configure with QMK, ZMK,
Kaleidoscope, etc.


Related Projects
--------------------------------------------------------------------------------

### Inspiration

- [Miryoku][1] for the main idea of using modifiers on the homerow and layer
shifters under the thumbs;
- [Lafayette][2] and [Ergo-L][3] for the <kbd>Symbol</kbd> layer, which has been
blatantly taken *as is*;
- [Extend][4], [Neo][5], [Shaka34][6] for the <kbd>Navigation</kbd> layers.

### Alternative Symbol Layers

- [Neo][5]
- [Pascal Getreuer’s][6]

### Non-Goals

- being the most efficient 3×5 layout — [Miryoku][1] is probably the most
advanced approach for that, at least on custom 36-key keyboards;
- fitting any OS layout — Arsenik works best if your OS layout has either no
AltGr layer at all (e.g. QWERTY, Colemak, Workman…), or an optimized AltGr layer
([Lafayette][2], [Ergo-L][3]…).

[1]: https://github.com/manna-harbour/miryoku
[2]: https://qwerty-lafayette.org/42
[3]: https://ergol.org
[4]: https://dreymar.colemak.org/layers-extend.html
[5]: https://www.neo-layout.org/
[6]: https://github.com/lobre/shaka34
[7]: https://getreuer.info/posts/keyboards/symbol-layer/


TODO
--------------------------------------------------------------------------------

- angle mods!
- KMonad / Karabiner support
- sample QMK / ZMK implementations for common keyboards
- variants for specific OS layouts
