Selenium33
================================================================================

A basic [Miryoku](https://github.com/manna-harbour/miryoku)-like approach to
minimize finger movements:

- 3 home-row mods per hand for <kbd>Ctrl</kbd>, <kbd>Alt</kbd>, <kbd>Super</kbd>
- 3 layer-tap keys under the thumbs: <kbd>Shift</kbd>/<kbd>Backspace</kbd>,
<kbd>Navigation</kbd>/<kbd>Space</kbd>, <kbd>Prog</kbd>/<kbd>Return</kbd>

![base, navigation and prog layers on a 33-key keyboard](img/all.svg)

**Bring the keys to your fingers, rather than moving your fingers to the keys!**

- A long press on the <kbd>Return</kbd> key brings up the <kbd>Prog</kbd> layer,
where all programming symbols are arranged for comfort and efficiency,
Dvorak-like.
- A long press on the <kbd>Space</kbd> bar brings up the <kbd>Navigation</kbd>
layer, with easy one-hand shortcuts (<kbd>Ctrl</kbd>-<kbd>WASZXCV</kbd>),
Vim-like navigation (<kbd>HJKL</kbd>) and more…

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
- all programming symbols in the comfortable 3×10 zone
- symmetrical modifiers on the home row
- Vim-like navigation in all apps
- easier left-hand shortcuts
- works with any keyboard


Using Selenium33
--------------------------------------------------------------------------------

### Standard/Laptop Keyboard

Unlike Miryoku which requires 6 thumb keys, Selenium has been designed to work
with standard ANSI/ISO/laptop keyboards from the very beginning, leveraging the
spacebar and the two Alt/Cmd keys.

Non-programmable keyboards are supported through [kanata](https://github.com/jtroo/kanata):

- install kanata
- grab the [Selenium33 configuration file](kanata.kbd)
- enjoy!

| type  | with homerow-mods       | without homerow-mods         | suitable layouts                  |
| ----- | ----------------------- | ---------------------------- | --------------------------------- |
| ANSI  | [selenium_ansi.kbd][1]  | [selenium_easy_ansi.kbd][3]  | QWERTY, Dvorak, Colemak, Workman… |
| AltGr | [selenium_altgr.kbd][2] | [selenium_easy_altgr.kbd][4] | [Lafayette42][10], [Ergo-L][11]…  |

[1]: selenium_ansi.kbd
[2]: selenium_altgr.kbd
[3]: selenium_easy_ansi.kbd
[4]: selenium_easy_altgr.kbd

- ANSI variants assume all symbols in your keyboard layout are in their
QWERTY-ANSI positions: works fine with most US layouts but Dvorak users will get
a slightly different <kbd>Prog</kbd> layer.
- AltGr variants use your layout’s AltGr layer instead of the <kbd>Prog</kbd>
layer: perfect for layouts that already have an optimized AltGr layer, such as
[QWERTY-Lafayette][10] and [Ergo-L][11].
- “Easy” variants don’t use any homerow-mods and leave the left thumb key
modifier unchanged — but they still use a <kbd>Prog</kbd> layer and put the
<kbd>Backspace</kbd> and <kbd>Return</kbd> keys under the thumbs. A good
starting point if you’re new to dual keys.

[10]: https://qwerty-lafayette.org/42
[11]: https://ergol.org

Note that kanata can also use the laptop’s trackpoint buttons (e.g. ThinkPad)
as two additional thumb keys. :-)

### Custom Programmable Keyboard

TODO: sample configurations for QMK, ZMK, Kaleidoscope, etc.


No numbers? No problem.
--------------------------------------------------------------------------------

If your keyboard has no number row, we got you covered! From <kbd>Prog</kbd>
mode, pressing the <kbd>Num</kbd> key brings up the NumRow layer:

![NumRow layer on a 33-key keyboard](img/numrow.svg)

- all digits are on the home row, in the order you already know
- the upper row helps with <kbd>Shift</kbd>-digit shortcuts
- the lower row has dash, comma, dot and slash signs to help with number / date
inputs

Even on keyboards that *do* have a number row, this <kbd>Num</kbd> layer can be
interesting to use in order to minimize finger movements a bit more.


TODO
--------------------------------------------------------------------------------

The main idea is settled (3 home-row mods + 3 layer-taps), but Selenium is still
a work in progress in an early stage. Expect refinements.

- NumPad layer
- angle mods!
- macOS support (KMonad / Karabiner)
- sample QMK / ZMK implementations for common keyboards
- variants for specific keyboard layouts


Why the name?
--------------------------------------------------------------------------------

I believe 34-key keyboards like the [Ferris][34] are the end game of ergonomic
keyboards, and 34 is selenium’s atomic number. All other keyboards I’ve tried
feel like unstable isotopes of the Ferris experience.

[Other cultural biases](https://en.wikipedia.org/wiki/Evolution_(2001_film))
might have been involved as well, though this remains to be proven. :-)
