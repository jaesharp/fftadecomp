# 081475A4 — palette channel adjustment

The recovered C is preserved unchanged. Its historical conditional match
requires an independently authenticated artifact bundle whose exact compiler,
preprocessor and binutils fingerprints differ from the freshly rebuilt local
toolchain. Native verification with
`--owner-runtime-profile conditional-palette-source-compilation-v1` refuses
with `frozen source, owner, ROM or fixed toolchain differs`.

The default profile also refuses the compiler-emitted runtime call with
`call target must be an undefined addressed function`. No source edits,
compiler-flag variations, new trust anchors or relaxed verification were used.
The complete historical report and embedded authenticated artifacts are kept
in `previous-match-report.md`; they are historical evidence, not a fresh local
MATCH. The ROM function owns `[0x081475A4, 0x0814774C)` (424 bytes).

Project rules require source without current admitted verification to remain
parked. A compatible authenticated toolchain or independently justified
verification support is needed before promotion. The mixed ROM build retains
the original bytes for this unmatched function.
