2010-12-11	Sanghoon Kim	wizest@gmail.com
--------------------------------------------

## Build Configuration

	# Compiler Flags
		-mcpu=cortex-m3
		-mthumb
		-march=armv7-m
			
	# Linker Flags
		-Wl,-Map,output.map -nostartfiles -T
	
		> arm-none-eabi-gcc -nostartfiles -T ../stm32f103rb.ld -o"WingWing.elf"  ./src/bas/kernel/sys/peripherals/misc.o ... 	
	
	
## Tool-chain Version

	Sourcery G++ Lite 2010.09-51
		GNU programming tools
		GNU Compiler Collection	4.5.1	
		GNU Binary Utilities	2.20.51	
		
		Debugging support and simulators
		GNU Debugger	7.2.50	
		
		Target libraries
		Newlib C Library	1.18.0	

		
## Development Environment

	1. Install CodeSourcery ARM Tool-chain
	2. Install Eclipse CDT
	3. Install Eclipse CDT Optional Package
		a. C/C++ GCC Cross Compiler Support
		b. C/C++ GDB Hardware Debugging
		c. C/C++ Code Analysis Framework (Codan)
	4. Install Eclipse SVN Plugin (subclipse)
