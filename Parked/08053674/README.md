# 08053674

One natural source form was attempted under accepted claim 6619816472 (sol-3674).
The original native workflow used addressed-signed-runtime-v1 and stopped with
exit 1 after 0.217835792 seconds at the combined exact indexed-span/ownership
guard: `inert spins require an exact unique nonoverlapping Thumb span`.

The same original invocation produced a complete 168-byte FUNC in both its
relocatable and linked ELF, against the retained 160-byte ROM target. Both
.text sections are also 168 bytes. The linked function has 77 reached
instructions; the target has 73. The compiled source saves/restores R9 in
addition to R8 and emits additional register copies. These are measured
compiler-output differences, not authority to change declarations, register
lifetimes, operand spelling or source layout. No definite semantic source
correction was identified or attempted.

The unchanged source is retained here. Its raw SHA256 is
9b6b1ebdf1ae70d526e298bf3cfa1e89e7db0fd96ec4f71d8c948396b0f9ed5c.
The canonical source/header SHA256 before moving it here was
c998d1e5abc0711a6a8f53fc2d525f64c2d0f25782380e816b820a9b21edb3c5.
Original linked FUNC SHA256:
5ad162c5a1f111ebb005bc54b80ef97ce085c9f6416c41e407592fabfdce06ff.

Original stdout/stderr, every subprocess command, object and linked ELF,
assembly, full function bytes, disassembly and body measurements are retained
under `state/matching-08053674-author/` at the handover root. The subprocess
observer captured these during the original workflow, before native cleanup.
There were zero observer errors, zero separate compiler diagnostics, no second
form, no native retry, no successful proof replay and no MATCH credit.

This extent mismatch does not establish unsupported model behavior or source
impossibility. Helper/runtime contracts remain conditional returning ARM ABI;
no numeric, allocation, readability, nonalias, memory safety or termination
theorem is claimed.
