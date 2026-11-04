# 080A3848

One original natural C form, one DEFAULT native attempt under the accepted
sol-3848 lease6539857282. Zero matches. Source retained unchanged.

Native exit1: compiled symbol is shorter than the indexed span:412 <432.
The target complete span is080A3848..080A39F8,432 bytes,193 reached
instructions plus referenced pools/alignment; both inventory rows retain216.
The original ELF symbol is412 bytes. The first differing instruction is the
stack allocation at target+0xA: target reserves8 local bytes; emitted code
reserves12. The emitted code also merges two target selected-byte stores and
uses a different literal pool/register allocation. These are observations,
not an authorization for declaration, lifetime or register steering.

One concrete source-order discrepancy is preserved: target080A38F8..080A3904
loads both source data pointers before writing either data_0200F3F0 word. The
one authored source has two assignments, and its original emitted assembly
stores word0 before loading the entry data pointer for word1. No nonalias
premise was invented to erase this difference. It was reported to the parent;
no second form or correction was made.

All original compiler/link outputs and exact commands were copied by a
read-only same-invocation observer before unchanged native workspace cleanup.
This includes the linked ELF and complete412-byte symbol. No separate compiler
diagnostic, native retry, test, successful proof replay or shared-input edit
was performed. No generated match report was produced before the length guard.

Evidence: state/matching-080A3848-author/ contains the original C, native
stdout/stderr/exit, observer source/receipt, original-workspace/, complete body
comparison, target references and before/end source/tool/header/map/binary pins.
The parent owns reservation release and any separately authorized followup.
