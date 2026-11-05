#include "ffta.h"

union LookupEntry08066718 {
    u32 index;
    const u8 *value;
};

struct LookupData08066718 {
    u8 unknown_000[0x424];
    union LookupEntry08066718 entries[1];
};

struct Lookup08066718 {
    struct LookupData08066718 *data;
    u8 unknown_04[4];
    u8 type;
};

extern const u16 data_08393ABC[];
extern const u16 data_08393AC4[];
extern const u16 data_0852A13E[];
extern const u16 data_0852A212[];
extern s32 func_080CA7A4(u16 entry, u8 selector);
extern u16 func_080CB53C(u16 value);

/* Complete [0x08066718, 0x080667E4): 204 bytes. */
u16 func_08066718(struct Lookup08066718 *lookup, u16 index)
{
    u16 result = 0;

    switch (lookup->type) {
    case 1:
        result = data_0852A13E[data_08393ABC[(s16)index]] + 1;
        break;
    case 2:
        result = data_0852A13E[data_08393AC4[(s16)index]] + 1;
        break;
    case 4:
        result = func_080CA7A4(*(const u16 *)lookup->data->entries[(s16)index].value, 1) + 1;
        break;
    case 5:
        result = func_080CB53C(lookup->data->entries[(s16)index].value[0]) + 1;
        break;
    case 6:
        result = data_0852A212[lookup->data->entries[(s16)index].index] + 1;
        break;
    }
    return result;
}
