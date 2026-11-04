# 0809B014

One natural source form was compiled once with the default native workflow,
using agbcc `-mthumb-interwork -O2`, under accepted claim 6619851160.

The original native invocation exited 1 after 0.220638904 seconds with:

```
compile failed:
division evidence requires runtime calls and a frameless caller
```

The current production guard in `tools/match.py:3605` rejects any
`udivsi3_context` caller whose verified instructions use a stack frame. This
root has a real 24-byte scalar frame in addition to its saved registers.
The earlier static qualification missed this exact route restriction.
No new profile, selector substitution or source rewrite was attempted.

The same original invocation's subprocess observer retained its relocatable
object, linked ELF and complete function before native cleanup. The sized
linked FUNC is 262 bytes, within a 264-byte `.text` section; the complete indexed
ROM target is 266 bytes. Therefore the preserved source also has a compiler
extent/byte difference. A separate positional comparison finds 159 equal bytes
at the same offsets over the 262-byte shared prefix; that is not MATCH credit.
Native verification stopped at the frame guard before a complete diff report
was written. The whole original linked function, target, exact positional diff,
ELF metadata, source fingerprint and original failure are retained under
`state/matching-0809B014-author/` in the handover workspace.

This is one form, one original native invocation, zero separate compiler
diagnostics, zero retries, zero successful replays and zero match credit.
The source here is byte-identical to that original compiled form. No claim
of arithmetic, helper effects, input-domain or termination equivalence follows.
