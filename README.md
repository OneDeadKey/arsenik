Selenium
================================================================================

A [Miryoku](https://github.com/manna-harbour/miryoku)-like approach to minimize
finger movements without changing the keyboard layout:

- 3 home-row mods per hand for <kbd>Ctrl</kbd>, <kbd>Alt</kbd>, <kbd>Super</kbd>
- 3 layer-tap keys under the thumbs
    - left: <kbd>Shift</kbd> / <kbd>Backspace</kbd>
    - center: <kbd>Navigation</kbd> / <kbd>Space</kbd>
    - right: <kbd>Symbols</kbd> / <kbd>Return</kbd>

The idea behind these layers is to **bring the characters under the fingers,
rather than moving the fingers over the keys**. This approach is what makes
those 36-key keyboards so comfortable, and the goal here is to get a comparable
experience with any other keyboard — including your laptop’s.


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


Navigation Layer
--------------------------------------------------------------------------------

A long press on the <kbd>Space</kbd> bar brings up the Navigation layer:

![navigation layer on a 33-key keyboard](img/navigation.svg)

- right: Vim-like arrows on HJKL, home/end page up/down, mouse scroll
- left: one-hand shortcuts (Ctrl-WASZXCV), Tab/Shift-Tab, prev/next


Symbols Layer
--------------------------------------------------------------------------------

A long press on the <kbd>Return</kbd> key brings up the Symbols layer:

![symbols layer on a 33-key keyboard](img/symbols.svg)

- all symbols are on the same layer, arranged for comfort
- the <kbd>Shift</kbd> key becomes a <kbd>Num</kbd> layer key


Why the name?
--------------------------------------------------------------------------------

I believe 34-key keyboards like the [Ferris](https://github.com/pierrechevalier83/ferris)
are the end game of ergonomic keyboards, and 34 is selenium’s atomic number. All
other keyboards I’ve tried feel like unstable isotopes of the Ferris experience.

[Other cultural biases](https://en.wikipedia.org/wiki/Evolution_(2001_film))
might have been involved as well, though this remains to be proven. :-)
