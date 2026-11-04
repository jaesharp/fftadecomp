# 0813F19C bounded attempt

Result: Parked, zero MATCH credit. One natural C form, one original native attempt, no compiler diagnostic, no replay, no source correction.

The accepted sol-F19C claim is 6539580792. The actual native command, times, output and exit 1 are preserved in state/matching-0813F19C-author/native-result.json. Native stopped at `inert_spin_profile.validate_span` with `inert-spin complete body differs from ROM`; no native report was generated.

Target and original linked function are both 60 bytes and 29 instructions. The first mismatch at 0x0813F1B0 is target `bhs 0x0813F1CE` versus compiled `blo 0x0813F1B8`. The compiler places the terminal second-result block before the helper path; ROM places it after. Complete target/compiled hex, all byte differences, retained original relocatable and linked ELF symbol extents, and disassemblies are in state/matching-0813F19C-author/saved-body-comparison.json. This is a direct byte mismatch; no definite source semantic defect or unsupported model is established.

The unchanged source preserves the actual s32(s16,s16,u16,u16) caller view, actual s32(s32,s32) helper declaration, and observed signed-halfword result narrowing. Raw source SHA256 e4374c6b4fffbc42fe3ca2779ed4e8c04a70d63b73eb931aa3ed998826d5446c; original complete source/header composite 623660d080b0b24af311f712eefaae0b128bf22f072aa3f94a80468f6fbe0ef5. No arithmetic domain, termination, helper effect or C-equivalence theorem is claimed.

All original compiler artifacts were copied read-only from this invocation's source-bound native workspace before normal native cleanup. No second compilation, diagnostic, proof API, source form, new ROM read or successful replay was needed. Parent owns release and integration.
