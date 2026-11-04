# 08066048 stopped after one original native attempt

Accepted claim: 6619821046, lane sol-6048. One natural source form, one original native invocation, exit 1 in 1.0315860959235579 seconds. No retry, additional form, successful replay or compiler-only diagnostic.

Original native command:

```
python3 -B /home/user/Desktop/FFTA-handover-2026-10-30/repos/fftadecomp-kit/tools/match.py --root /home/user/Desktop/FFTA-handover-2026-10-30/state/resumed-matching-batch3-20261030/game-worktree --function-address-profile canonical-thunks-v1 0x08066048
```

Actual native error:

```
compile failed:
inert-spin complete body differs from ROM
```

The same-invocation observer attached to the executing __main__.Runner and retained the original object, linked ELF and complete 204-byte FUNC body without errors. Emitted and target extents are both 204 bytes. Exactly four positional bytes differ, at 080660AA, 080660AD, 080660B2 and 080660B4. The other 200 positional bytes agree; this is a raw equality metric, not a native alignment score or MATCH credit.

The difference is confined to the observed ten-bit byte-key computation: the ROM loads its high byte into R1, its mask into R2, and ORs into R1; this source emits the high byte in R2, the mask in R1, and ORs into R0 before the comparison. No semantic bug was established and no source steering or second form was attempted. Complete byte/instruction differences, ELF, original commands and logs are retained in state/matching-08066048-author/.

The unchanged parked source retains the actual void(u32) root ABI, genuine u32 D29D4(void*) return with the observed signed comparison, real helper prototypes and typed callback with three actual arguments through the canonical R3 thunk. No count bound, null guard, initialization, allocation/readability, callback effects, nonaliasing or termination guarantee was added. Historical declaration certainty is not claimed.

The source SHA256 is f5627a7d802f63e45f833b64e87fb7977eaa6901d950549a762afd02a8abcd76. Source and nine-header composite SHA256 is 5959a95e8bc7059b7bbd66feccd36a674313406d6980e0031fdade903e9efb8a, using the exact format recorded in source-before-native.json. No native report or plausibility verdict was generated after the complete-body rejection. Zero MATCH credit. Only the failed owned active source was moved here; no other source/report was changed.
