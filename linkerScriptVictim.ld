SECTIONS {
    . = 0x1000000000;  /* Specify the starting address for the code */
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

