#include "ffta.h"

typedef struct Node08099F58 Node08099F58;
typedef struct List08099F58 List08099F58;

typedef struct {
    u8 unknown_00[0x10];
    List08099F58 *objects;
} Lookup08099F58;

typedef struct {
    u8 unknown_00[0x80];
    Lookup08099F58 *lookup;
} Object08099F58;

typedef struct {
    u8 unknown_00[4];
    s8 x;
    s8 z;
    u8 unknown_06[2];
    Object08099F58 *match;
} Search08099F58;

typedef s32 (*SearchCallback08099F58)(const Node08099F58 *, Search08099F58 *);

/* The root consumes the full return word. Every complete 08097504 return
 * defines that word with MOV 0/1; incoming coordinates consume low signed
 * bytes and the range consumes its low unsigned byte.
 */
extern s32 func_08097504(Object08099F58 *, s8, s8, u8);
extern s32 func_0809ABB0(const Node08099F58 *, Search08099F58 *);
extern void func_080C7CC0(List08099F58 *, SearchCallback08099F58,
                         Search08099F58 *);

/* Complete [0x08099F58,0x08099FAE): 86 bytes.
 * The actual callback reads signed bytes4/5 and can store the pointer at8.
 * Other local fields remain unspecified. These are conditional transport
 * views, not initialization, effect, bounds or termination guarantees.
 */
s32 func_08099F58(Object08099F58 *object, s8 x, s8 z, u8 range)
{
    Search08099F58 search;
    Lookup08099F58 *lookup;
    s32 column = x;
    s32 row = z;

    if (!func_08097504(object, column, row, range))
        return 0;
    lookup = object->lookup;
    search.match = 0;
    search.x = column;
    search.z = row;
    func_080C7CC0(lookup->objects, func_0809ABB0, &search);
    if (search.match != 0 && search.match != object)
        return 0;
    return 1;
}
