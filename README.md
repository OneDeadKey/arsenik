Selenium33
================================================================================

A basic [Miryoku](https://github.com/manna-harbour/miryoku)-like approach to
minimize finger movements on any keyboard:

- 3 home-row mods per hand for <kbd>Ctrl</kbd>, <kbd>Alt</kbd>, <kbd>Super</kbd>
- 3 layer-tap keys under the thumbs: <kbd>Shift</kbd>/<kbd>Backspace</kbd>, <kbd>Navigation</kbd>/<kbd>Space</kbd>, <kbd>Prog</kbd>/<kbd>Return</kbd>

![base, navigation and prog layers on a 33-key keyboard](img/all.svg)

A long press on the <kbd>Return</kbd> key brings up the Prog layer, where all
programming symbols are arranged for comfort.

A long press on the <kbd>Space</kbd> bar brings up the Navigation layer, with
easy one-hand shortcuts (<kbd>Ctrl</kbd>-<kbd>WASZXCV</kbd>), Vim-like
navigation (<kbd>HJKL</kbd>) and more…

The idea behind these layers is to **bring the characters to the fingers, rather
than moving the fingers to the keys**. This approach is what makes those 34-key
keyboards so comfortable, and the goal here is to get a comparable experience
with any other keyboard — including your laptop’s.


Main Benefits
--------------------------------------------------------------------------------

- <kbd>Shift</kbd>, <kbd>Backspace</kbd>, <kbd>Return</kbd> under the thumbs!
- all programming symbols are moved to the comfortable 3×10 zone
- symmetrical modifiers on the home row
- Vim-like navigation in all apps
- easier left-hand shortcuts
- works with any keyboard


Suitable for *all* keyboards
--------------------------------------------------------------------------------

… well, all keyboards that have at least 3×10 finger keys and 3 thumb keys. So
yes, pretty much every computer keyboard out there.

Miryoku requires 6 thumb keys, which tends to limit its use to ergonomic
keyboards. Selenium works with 3, which means it’s usable with any standard ANSI
or ISO keyboard (spacebar + Alt/Cmd keys), even non-programmable ones thanks to
[kanata](https://github.com/jtroo/kanata); and it also works with minimalist
keyboards like the [Ferris](https://github.com/pierrechevalier83/ferris) (only 4
thumb keys).

Of course, Selenium can be implemented in programmable keyboards with QMK, ZMK,
Kaleidoscope, etc.


No numbers? No problem.
--------------------------------------------------------------------------------

If your keyboard has no number row, we got you covered! From <kbd>Prog</kbd>
mode, pressing the <kbd>Num</kbd> key brings up the NumRow layer:

![NumRow layer on a 33-key keyboard](img/numrow.svg)

- all digits are on the home row, in the order you already know
- the upper row helps with <kbd>Shift</kbd>-digit shortcuts
- the lower row has dash, comma, dot and slash signs to help with number / date
inputs


TODO
--------------------------------------------------------------------------------

The main idea is settled (3 home-row mods + 3 layer-taps), but Selenium is still
a work in progress in an early stage. Expect refinements.

- NumPad layer
- macOS support (KMonad / Karabiner)
- sample QMK / ZMK implementations for common keyboards
- variants for specific keyboard layouts


Why the name?
--------------------------------------------------------------------------------

I believe 34-key keyboards like the [Ferris](https://github.com/pierrechevalier83/ferris)
are the end game of ergonomic keyboards, and 34 is selenium’s atomic number. All
other keyboards I’ve tried feel like unstable isotopes of the Ferris experience.

[Other cultural biases](https://en.wikipedia.org/wiki/Evolution_(2001_film))
might have been involved as well, though this remains to be proven. :-)
