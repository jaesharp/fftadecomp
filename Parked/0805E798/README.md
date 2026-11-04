# 0x0805E798 nonmatching state update

One evidence-grounded natural C form was submitted once under accepted lease
6620186904 (sol-E798), using the DEFAULT native workflow and standard
`-mthumb-interwork -O2` compiler flags. The source is unchanged from that run.

The complete target is `[0x0805E798,0x0805E864)`: 204 bytes and 79 reached
instructions, including eight referenced literal words. The original native
run produced one complete 204-byte ELF function and a plausible source verdict,
but reported `NOT MATCHING - bytes differ`: 189/204 bytes and 64/79 instructions
identical. The first differing byte is at function offset zero. The candidate
saves r4-r7/LR while the target saves r4-r6/LR; register allocation and copies
also differ. Both allocate eight outgoing scalar stack bytes.

The actual seven helper interfaces, genuine mapped data identities and observed
read/store/call order are retained. The D0590 result remains a full u32 before
its low byte is stored. No source bug or impossibility is established by this
bounded comparison. No declaration, register, lifetime, spelling or loop
variants were tried to influence those differences.

The same original native invocation captured its object, linked ELF, complete
function bytes, all 12 subprocess commands and report before native cleanup.
There were zero observer errors, separate compiler diagnostics, retries,
success replays or additional source forms. The native exit was 1 after
0.3026874701026827 seconds. Ordinary helper ABI summaries are conditional;
no callback-body, allocation, capacity, lifetime, nonalias, readability,
initialization, physical-memory, numerical or termination theorem is claimed.

Immutable original evidence and final pins are in
`state/matching-0805E798-author/`. The original report is preserved there as
`original-native-report.md`; it is failure evidence, not an active MATCH report.
