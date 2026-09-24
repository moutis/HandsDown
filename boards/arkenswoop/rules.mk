# Build Options
#   change yes to no to disable

SRC += rgb.c

# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Compile for the Liatris
CONVERT_TO = promicro_rp2040
ENCODER_ENABLE = yes
CAPS_WORD_ENABLE = yes

CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
RGBLIGHT_ENABLE = yes       # Enable underlight
WS2812_DRIVER = vendor      # Use the RP2040's PIO interface

