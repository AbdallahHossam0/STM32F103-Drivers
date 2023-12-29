ToolChain = arm-none-eabi-
CPU = -mcpu=cortex-m3 -mthumb
LF = linker_file.ld
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

ALL: funky.bin funky.hex
	@echo "_^^Build is Done^^_"
%.o : %.c
	$(ToolChain)gcc -c $(CPU) $< -o $@

funky.elf : $(OBJ)
	$(ToolChain)ld -Map funky.map -T $(LF) $^ -o $@

funky.hex : funky.elf
	$(ToolChain)objcopy -O ihex $< $@
	
funky.bin : funky.elf
	$(ToolChain)objcopy -O binary $< $@

clean:
	rm *.asm *.elf *.o *.hex *.map *.bin
