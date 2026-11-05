# match report - 0x080CCBFC

* source: `src/080CCBFC.c`
* verification: `elf-symbol-thumb-data-v1`
* source SHA-256: `eb0d289ce3103fe8a5734ca69cfb3f5b3e4e6cb66457e1eb682309e2a23bca5e`
* mapping SHA-256: `8de72aa3d18c5e7c7a7a7734133a8381605ff1dfd17fd0b057cb1d3f9f3e8a7b`
* control flow: closed leaf CFG
* data symbols SHA-256: `a16f9fdd0c0840bbf5c85b08b5a3af5fe28f0ee6af252d3e0f308264b1d50c3b`
* compiler: `$HOME/agbcc/gcc/agbcc -mthumb-interwork -O2`
* verified extent: complete ELF function symbol, including literal pools
* relocations: none
* ROM bytes: `00b50548054a81180878622801d80130087001bc0047000000000002681f0000` (32 bytes)
* compiled : `00b50548054a81180878622801d80130087001bc0047000000000002681f0000`
* source plausibility: plausible
* hand-asm allow list: not listed

**MATCH - byte identical** - 32/32 bytes

```
compiled                                rom
push {lr}                               push {lr}
ldr r0, [pc, #0x14]                     ldr r0, [pc, #0x14]
ldr r2, [pc, #0x14]                     ldr r2, [pc, #0x14]
adds r1, r0, r2                         adds r1, r0, r2
ldrb r0, [r1]                           ldrb r0, [r1]
cmp r0, #0x62                           cmp r0, #0x62
bhi #0x80ccc0e                          bhi #0x80ccc0e
adds r0, #1                             adds r0, #1
strb r0, [r1]                           strb r0, [r1]
pop {r0}                                pop {r0}
bx r0                                   bx r0
```
