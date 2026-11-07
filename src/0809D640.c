#include "ffta.h"

typedef struct Owner0809D640 Owner0809D640;
typedef struct Record0809D640 Record0809D640;

typedef struct {
    Record0809D640 *record;
    u32 flag;
} Query0809D640;

typedef s32 (*RecordCallback0809D640)(Record0809D640 *, Query0809D640 *);

extern s32 func_0809C9E8(Record0809D640 *, Query0809D640 *);
extern void func_08099840(Owner0809D640 *, RecordCallback0809D640, Query0809D640 *);

/* Conditional ordinary callback transport follows the complete actual entries.
 * The immutable callback definition supports this record/context view; the
 * generic adapter's nominal function-pointer type is not asserted compatible.
 * Complete [0x0809D640, 0x0809D66C): 44 bytes including alignment and literal. */
u32 func_0809D640(Owner0809D640 *owner, Record0809D640 *record)
{
    Query0809D640 query;
    u32 result;

    if (record != 0) {
        query.record = record;
        query.flag = 0;
        func_08099840(owner, func_0809C9E8, &query);
        result = query.flag;
    } else {
        result = 0;
    }
    return result;
}
