# Ortho 60

A Blue Pill STM32F103C8T6-based 12x5 ortholinear keyboard.

Keyboard Maintainer: [Andrew Kannan](https://github.com/awkannan1)  
Hardware Supported: Blue Pill STM32F103C8T6  

Make example for this keyboard (after setting up your build environment):

    make cannonkeys/ortho60:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

make cannonkeys/ortho60:ppattern

dfu-util -d 1eaf:0003 -a 2 -D "/Users/ppattern/dev/qmk/qmk_firmware/cannonkeys_ortho60_ppattern.bin"

# Ortho48

make cannonkeys/ortho48:ppattern

dfu-util -d 1eaf:0003 -a 2 -D "/Users/ppattern/dev/qmk/qmk_firmware/cannonkeys_ortho48_ppattern.bin"
