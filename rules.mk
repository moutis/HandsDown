# hardware features (set in each keyboard rules.mk)

# QMK software features

LEADER_ENABLE = no       # Enable the Leader Key feature
MOUSEKEY_ENABLE = no     # Mouse keys
UNICODE_ENABLE = no      # will need this for HD Polyglot
NKRO_ENABLE = no         # USB Nkey Rollover
KEY_OVERRIDE_ENABLE = no
CONSOLE_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
TAP_DANCE_ENABLE = no

AUTO_SHIFT_ENABLE = no  # requires 1936 bytes!

EXTRAKEY_ENABLE = yes   # Audio control and System control
COMBO_ENABLE = yes      # chording
LTO_ENABLE = yes		# optimize at link time
EXTRAFLAGS += -flto

SRC += moutis.c

CFLAGS += -fcommon


