kanata
================================================================================

Non-programmable keyboards are supported through [kanata](https://github.com/jtroo/kanata).


Pick Your Poison
--------------------------------------------------------------------------------

| type  | with homerow-mods      | without homerow-mods        | suitable layouts                  |
| ----- | ---------------------- | --------------------------- | --------------------------------- |
| ANSI  | [arsenik_ansi.kbd][1]  | [arsenik_easy_ansi.kbd][3]  | QWERTY, Dvorak, Colemak, Workman… |
| AltGr | [arsenik_altgr.kbd][2] | [arsenik_easy_altgr.kbd][4] | [Lafayette42][10], [Ergo-L][11]…  |

[1]: arsenik_ansi.kbd
[2]: arsenik_altgr.kbd
[3]: arsenik_easy_ansi.kbd
[4]: arsenik_easy_altgr.kbd

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


Installation
--------------------------------------------------------------------------------

TBD
