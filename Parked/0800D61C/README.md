# 0800D61C

Indexed target [0x0800D61C, 0x0800D660), 68 bytes. The true extent is 72
bytes, because the second literal pool word (`0x04000052`, BLDALPHA) sits at
0x0800D660, just past the indexed end.

The function takes two u8 arguments. It creates an object with
`func_0800C3CC(func_0800DEC0, 0x140, 2, (void *)0x04000052)` and gets a
buffer from `func_0800C614()`. It then writes the two values into 160
byte-pairs (a per-scanline BLDALPHA table) and returns the object.

`0800D61C.c` is the plausible non-volatile reconstruction.

## Blockers

1. **Index.** `match.py` stops with "function address is unknown, ambiguous,
   misaligned, or not Thumb ROM code" before comparing anything:
   * `func_0800DEC0`, the callback literal `0x0800DEC1`, has no index entry.
     The nearest entry is 0800DECC.
   * The 68-byte extent misses the trailing pool word.

   Both need index corrections in `config/`. These were not made.
2. **Dead `ldrb` before each `strb`.** This only appears for a store to a
   member of a `volatile` struct (u8 members, `u16 :8` bitfields or a
   one-member struct). `plausible.py` allows `volatile` only for direct I/O,
   and this is a RAM buffer. The original probably reused the BLDALPHA
   register type for the RAM mirror.
3. **Loop shape.** Even with `volatile`, the target keeps two pointers
   (`buf` and `buf + 1`, each stepping by 2). Every tested form compiles to
   one pointer with `[r1]` / `[r1,#1]`.

Ruled out:
* plain `u8` stores
* `vu8 *` stores: indexed, pointer-increment and two-pointer
* non-volatile bitfield structs (`u8`, `u16` and `u32` 8-bit fields, and
  mixes)
* narrower bitfields, which load and then mask and OR

The prologue, the u8 narrowing, the call setup, `0x140` as `#0xa0 << 1`, the
159/`bge` counter and the returned object all match in hand compiles.

Same family as `Parked/08009728` and `Parked/08135D38`.
