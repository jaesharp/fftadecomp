/* func_08145514 - 0x08145514, 14 bytes
 *
 * MATCHED byte-for-byte with: agbcc -mthumb-interwork -O2
 *   target  00b5 0349 0968 fcf7 95fe 01bc 0047
 *
 * Dispatches to the callback word kept in IWRAM at 0x02008EE8 and hands the
 * caller's argument straight through in r0.  The call is agbcc's indirect-call
 * thunk: `bl _call_via_r1`, the `bx r1` veneer at 0x08142248, so the callee
 * address never appears in the source.  func_08145528 is the same shape with
 * the next word, 0x02008EEC.
 */

#include "ffta.h"

void func_08145514(void *arg)
{
    ((void (*)(void *))*(u32 *)0x02008EE8)(arg);
}
