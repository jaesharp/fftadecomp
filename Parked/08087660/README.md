# 08087660

The single natural source form is retained unchanged. Original native matching
exited 1 after 0.279018 seconds under `addressed-signed-runtime-v1`; the error
was `inert spins require an exact unique nonoverlapping Thumb span` at
`tools/inert_spin_profile.py:86`. No match report was produced.

The complete target is 148 bytes with 72 reached instructions. The original
native invocation emitted a 150-byte function with 73 decoded instructions.
The linked `.text` section is 152 bytes, including the separate terminal
`c046` alignment NOP. The function extent itself differs by two bytes.
Within the common 148 bytes there are 91 differing positions, beginning at
offset 6. Register allocation, counter handling and channel-extraction code
differ. No unsupported-profile or source-impossibility conclusion follows.

The observed four-slot interface uses two halfword pointers and two low-byte
scalars. The source retains the genuine `s16 func_08007A60(u8)` helper and
`s32 func_081426B8(s32, s32)` addressed runtime interface, the explicit byte and
halfword narrowings, and the source read before destination write. No alias,
readability, allocation, numerical-result or helper-effect premises were added.

The shared subprocess observer retained the original object, linked ELF, full
linked section, assembly, preprocessed input and exact compiler/link commands
from this same invocation. These are original native artifacts, not a separate
compiler diagnostic. There was one source form, one original native attempt,
zero compiler diagnostics, zero native retries and zero MATCH credit.

Raw source SHA256:
`b8f68532182dbcd31a320e9127e2dd019b1b59590c22de36b6d9faaafb0ef52d`.
The immutable source, original logs, complete body comparison and receipts are
under `state/matching-08087660-author/` in the handover workspace.

Original command:
```sh
python3 -B /home/user/Desktop/FFTA-handover-2026-10-30/repos/fftadecomp-kit/tools/match.py --root /home/user/Desktop/FFTA-handover-2026-10-30/state/resumed-matching-batch3-20261030/game-worktree --addressed-signed-runtime-profile addressed-signed-runtime-v1 0x08087660
```
