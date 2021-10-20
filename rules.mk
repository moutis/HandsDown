# QMK software features

LEADER_ENABLE = no       # Enable the Leader Key feature
MOUSEKEY_ENABLE = no     # Mouse keys
EXTRAKEY_ENABLE = yes    # Audio control and System control
UNICODE_ENABLE = no      # will need this for HD Polyglot
NKRO_ENABLE = no         # USB Nkey Rollover
COMBO_ENABLE = yes       # chording
KEY_OVERRIDE_ENABLE = no
CONSOLE_ENABLE = no
BACKLIGHT_ENABLE = no
RGB_ENABLE = no

SRC += moutis.c

CFLAGS += -fcommon

EXTRAFLAGS += -flto

