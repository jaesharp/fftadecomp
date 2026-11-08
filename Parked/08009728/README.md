# 08009728

Complete indexed target [0x08009728, 0x0800975C), 52 bytes, leaf function.

It clears bit 0x2000 of the u16 at `g_control_flags_03000940`, then zeroes
the bytes at +0x3B, +0x3F, +0x3A and +0x3E. Each `strb` is preceded by an
`ldrb` of the same byte, and the result of that load is discarded.

`08009728.c` is the natural non-volatile form, a `ControlState` struct over
`g_control_flags_03000940`. It compiles to 40 bytes. The only difference is
the four missing dead `ldrb` (12 bytes): the read-modify-write, the store
order, the `adds #4` / `subs #5` address walk and the register allocation all
match.

## What reproduces the target

Declaring the six bytes at +0x3A..+0x3F as `volatile u8` reproduces the
target instruction for instruction, registers included. This was tested in
scratch only. gcc 2.9 reads a volatile lvalue back before a plain store to
it. `plausible.py` allows `volatile` only for genuine MMIO, and 0x03000940 is
IWRAM, so this form is not admissible.

## Ruled out (each loses the dead `ldrb`)

* 4-bit and 1+7-bit bitfield pairs
* full-width `:8` bitfields in `u8`, `u16` and `u32` containers
* `x &= 0` and `x *= 0`
* volatile bitfield clears, which give a masked read-modify-write instead

## Precedent

`Parked/08135D38` reaches the same conclusion for the same object
(0x03000940+0x4C/0x4D: dead `ldrb`, then `strb`). If the project ever
accepts `volatile` for this interrupt-shared IWRAM block, both functions
become matchable. No new data symbol is needed.
