@echo off
echo Processing Post-Build...
echo Convert Elf to Hex.
arm-none-eabi-objcopy -O ihex wingwing.elf wingwing.hex
