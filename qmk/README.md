Arsenik QMK
================================================================================

The QMK implementation of Arsenik is a bit different:

- it takes advantage of the 4 thumb keys
- the Navigation layer uses a mouse emulation on the left hand

![Arsenik on a 34-key keyboard](../img/qmk/all.svg)

TODO: update this image

In fact, this is what I ended up with for my beloved Ferris in the first place,
and Arsenik/Selenium is an attempt to fit most of this magic into my laptop
keyboard.

```bash
# from the `qmk_firmware` root:
make ferris/0_2/bling:1dk:flash
```
