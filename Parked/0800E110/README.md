# 0800E110

Complete indexed target [0x0800E110, 0x0800E1A0), 144 bytes.

This is a sibling of the matched `src/0800E1A0.c`, with the same State/Range
structs, the packed `FrameHeader {u16 width; s16 frame_count}` and the same
F480/F308 branch. Here the fill loop is `func_08010058(object, 0, 160, 245,
250)`, and there is no frame-advance tail.

`0800E110.c` compiles to 140 bytes, and every emitted instruction is
identical to the target. `match.py` reports "compiled symbol is shorter than
the indexed span: 140 < 144".

## Missing 4 bytes

At 0800E134 and 0800E136 the target has two dead loads,
`ldrb r0,[r1,#2]; ldrb r0,[r1,#3]`. They read `header->frame_count` before
the width bytes, in the order agbcc uses in the sibling. Their shift/OR is
gone and r0 is overwritten immediately. This suggests `frame_count` had a use
when flow analysis ran, and a later combine pass folded that use to a
constant, which left the loads orphaned.

## Ruled out

* `frame_count` assigned but unused (s16/s32/u16/u32): flow deletes both
  loads.
* A struct copy of the packed header: produces `memcpy` and a stack slot.
* Byte-struct copies (`u8 b[4]` or four named u8s): `ldr` plus a stack slot.
* Reading the packed header as a u32, then masking or narrowing to u16:
  either all four bytes are loaded or only two.
* Packed `u32 :16` bitfields: only two bytes are loaded.
* A range check like `c >= 0x8000` on an int copy: combine does not fold it.

Every use that combine would fold that we found was a contrived steering
expression, so this was stopped there. No new data symbols are needed.
