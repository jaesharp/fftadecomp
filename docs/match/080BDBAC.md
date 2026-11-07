# match report - 0x080BDBAC

* source: `src/080BDBAC.c`
* verification: `elf-symbol-thumb-data-v1`
* source SHA-256: `931dcc9b2cef49623d933da4a7a67ef6df5ab27019ec872cdd35f08b935678a2`
* mapping SHA-256: `038fd325c3b3a1ec19dafc32362280bd74da7b9a6b55723a6a306068e540b345`
* control flow: direct Thumb BL with ordinary ARM ABI call summaries
* data symbols SHA-256: `52a3fe1807f7e712797f258fe9c72d4e95dbf06647cf1b95885ea9e8a64e4fb0`
* compiler: `$HOME/agbcc/gcc/agbcc -mthumb-interwork -O2`
* verified extent: complete ELF function symbol, including literal pools
* relocations: none
* ROM bytes: `00b5034a0349126884f04afb01bc0047b8d4360804450000` (24 bytes)
* compiled : `00b5034a0349126884f04afb01bc0047b8d4360804450000`
* source plausibility: plausible
* hand-asm allow list: not listed

**MATCH - byte identical** - 24/24 bytes

```
compiled                                rom
push {lr}                               push {lr}
ldr r2, [pc, #0xc]                      ldr r2, [pc, #0xc]
ldr r1, [pc, #0xc]                      ldr r1, [pc, #0xc]
ldr r2, [r2]                            ldr r2, [r2]
bl #0x814224c                           bl #0x814224c
pop {r0}                                pop {r0}
bx r0                                   bx r0
```
