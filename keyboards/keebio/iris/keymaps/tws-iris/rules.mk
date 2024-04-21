# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = qmk-dfu

# Build Options
#   change yes to no to disable
#
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
SPLIT_KEYBOARD = yes
NKRO_ENABLE = yes            # Enable N-Key Rollover
LEADER_ENABLE = yes 		# Enable leader keys

ENCODER_ENABLE = no
EXTRAKEY_ENABLE = no       # Audio control and System control
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
CONSOLE_ENABLE = no        # Console or debug
COMMAND_ENABLE = no         # Command for debug and configuration
AUDIO_ENABLE = no           # Audio output