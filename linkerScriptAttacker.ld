SECTIONS {
    . = 0x2000000000;  /* Specify the starting address for the code */
    .text : {
        *(.text)
    }
    .data : {
        *(.data)
    }
    .bss : {
        *(.bss)
    }
}

