# Listening for commands on this PC's tcp port 2331 
target remote 127.0.0.1:2331 

# Enable flash download and flash breakpoints. 
# Select flash device 
monitor flash device = STM32F103RB 

# Enable FlashDL and FlashBPs 
monitor flash download = 1 
monitor flash breakpoints = 1 

# Set gdb server to little endian 
monitor endian little 

# Set JTAG speed in khz 
monitor speed auto 

# Initializing PC and stack pointer
monitor reg r13 = (0x00000000)
monitor reg pc = (0x00000004)

# Load
load WingWing.elf
break main 
continue