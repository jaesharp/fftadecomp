# 0808A0B4

Complete indexed target [0x0808A0B4, 0x0808A158), 164 bytes.

The function is a self-recursive quicksort over 8-byte `{s32 key; s32 value;}`
records. It takes a middle pivot, swaps records with `stm r7!, {r0,r1}` and
`str`, and recurses on both halves.

## Bytes: identical

`0808A0B4.c` was compiled with the fixed `agbcc -mthumb-interwork -O2` and
assembled, and its `.text` was extracted. All 164 bytes equal the ROM except
the two `bl` immediates, which are unresolved self-call relocations that
resolve to 0x0808A0B4 in the ROM.

The pivot must be written `(right + left) / 2`. Writing `(left + right)`
swaps the `adds` operands.

`plausible.py` reports no findings.

## Why it is not in src/

* Default `match.py`: "call target must be an undefined addressed function".
  Self-calls are not admitted.
* `--owner-runtime-profile entry-recursive-ordinary-call-v1`, the profile
  used by the matched recursive `src/080C7DC8.c`: "entry saved-only owner
  excludes memory stores and register-list transfers". The record swap needs
  both of those.

Verifying this needs a recursive-call profile that admits memory stores and
`stm`. No tooling was changed.

Tracked upstream: https://github.com/shubshub/fftadecomp-kit/issues/77
