_e_stack = ORIGIN(RAM) + LENGTH(RAM);

MEMORY{
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 64K
    RAM(rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(4);
        *(.isr_vector)
        *(.isr_vector*)
        . = ALIGN(4);
    } > FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
    } > FLASH

    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH
    
    _s_data_FLASH = LOADADDR(.data);

   .data :
   {
        . = ALIGN(4);
        _s_data = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _e_data = .;
    } > RAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);
        _s_bss = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _e_bss = .;
    } > RAM


}