#
# J-LINK GDB SERVER initialization
#

# This connects to a GDB Server listening
# for commands on localhost at tcp port 2331
target remote 127.0.0.1:2331

monitor interface SWD
monitor speed 30

# Set GDBServer to little endian
monitor endian little

# Reset the chip to get to a known state.
monitor reset

# Set auto JTAG speed
monitor speed auto

# Enable Flash Download
monitor flash device = STM32F103RB
monitor flash download = 1

# Enable Flash Breakpoint
monitor flash breakpoints = 1

# Reset Stack Pointer and Entry Point
monitor reg r13 = (0x00000000)
monitor reg pc = (0x00000004)

# Load the program executable called "image.elf"
load out/wingwing.elf
