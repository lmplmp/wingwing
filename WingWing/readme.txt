2010-12-11
Sanghoon Kim
wizest@gmail.com

## Build Configuration

# Compiler Flags
	-mcpu=cortex-m3
	-mthumb
	-march=armv7-m
		
# Linker Flags
	-Wl,-Map,output.map -nostartfiles -T

	> arm-none-eabi-gcc -nostartfiles -T ../stm32f103rb.ld -o"WingWing.elf"  ./src/bas/kernel/sys/peripherals/misc.o ... 	
	
