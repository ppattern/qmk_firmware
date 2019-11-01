# Ortho 48

A Blue Pill STM32F103C8T6-based 12x4 ortholinear keyboard.

Keyboard Maintainer: [Andrew Kannan](https://github.com/awkannan1)  
Hardware Supported: Blue Pill STM32F103C8T6  

Make example for this keyboard (after setting up your build environment):

    make cannonkeys/ortho48:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

    make cannonkeys/ortho48:ppattern
    dfu-util -d 1eaf:0003 -a 2 -D "/Users/ppattern/dev/qmk/qmk_firmware/cannonkeys_ortho48_ppattern.bin"

Mac OS
  Requirements
    To reflash your bootloader on Mac OS, you first need st-flash and possibly openocd to unlock your blue pill, in addition to your ST-Link. st-flash (via stlink) and openocd can be installed from Homebrew.

      brew install openocd stlink

Flashing the bootloader
  The first thing you'll need to do is hook your ST Link into your Blue-pill. For some reason, on Mac OS, you may need to swap the SWDIO and SWCLK pins. Additionally, you may need to update your ST-Link's firmware with STSW-LINK007. You'll also need the bootloader binary

  1.Ensure that your Blue-pill is recognized by running st-info --probe
    - if the chipid is 0x0000, swap the SWDIO and SWCLK pins
    - if the chipid is 0x0410, you're connected correctly
  2.Attempt to flash the bootloader using

    st-flash --reset --format binary write /Users/ppattern/dev/qmk/generic_boot20_pc13.bin 0x8000000

    if you get a Unknown memory region error message, you'll need to unlock the chip with the following command then unplug your ST Link to reboot the Blue-pill:

    openocd -f interface/stlink-v2.cfg \
    -f target/stm32f1x.cfg \
    -c "init; reset halt; stm32f1x unlock 0; reset halt; exit"

    If you see the following (or something similar), your Blue-pill was successfully flashed

    st-flash 1.5.1
    2019-04-28T19:58:23 INFO common.c: Loading device parameters....
    2019-04-28T19:58:23 INFO common.c: Device connected is: F1 Medium-density device, id 0x20036410
    2019-04-28T19:58:23 INFO common.c: SRAM size: 0x5000 bytes (20 KiB), Flash: 0x10000 bytes (64 KiB) in pages of 1024 bytes
    2019-04-28T19:58:23 INFO common.c: Attempting to write 7160 (0x1bf8) bytes to stm32 address: 134217728 (0x8000000)
    Flash page at addr: 0x08001800 erased
    2019-04-28T19:58:23 INFO common.c: Finished erasing 7 pages of 1024 (0x400) bytes
    2019-04-28T19:58:23 INFO common.c: Starting Flash write for VL/F0/F3/F1_XL core id
    2019-04-28T19:58:23 INFO flash_loader.c: Successfully loaded flash loader in sram
    7/7 pages written

    Now you should have a reflash bootloader ready to be flashed with the QMK firmware of your choosing!
