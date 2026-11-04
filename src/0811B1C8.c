#include "ffta.h"

typedef struct { u16 phase; } Descriptor;
typedef struct {
    u8 unknown_00[8];
    void *child;
    void *record_task;
} Payload;
typedef struct {
    u8 unknown_000[0x13E];
    u16 value;
} State;
typedef struct {
    u8 left;
    u8 unknown_01;
    u8 top;
    u8 unknown_03;
    s16 right;
    s16 bottom;
    u8 unknown_08[4];
} Rectangle;
typedef struct RequestNode {
    u8 status;
    u8 kind;
    u8 unknown_02[2];
    u32 first;
    u32 second;
    u32 control;
    u8 unknown_10[8];
    struct RequestNode *next;
} RequestNode;
typedef struct { u8 unknown_00[28]; } Record080D3AF8;

extern const u8 data_0894C758[];
extern const u8 data_083A69E8[];
extern const u8 data_03003900[];
extern u8 data_06004FE0[];
extern State data_03003860;
extern const Rectangle data_083A69F0[];
extern void func_080D35D8(void);
extern void *func_080D4704(const void *, void *);
extern void *func_080DFD8C(const void *, u8, u16, u16, void *);
extern void *func_080D4774(void *);
extern u8 func_080D39F0(void);
extern void *func_080D3904(void);
extern Record080D3AF8 *func_080D3AF8(void);
extern void func_0814186C(const void *, void *, u32);
extern void func_08000B68(RequestNode *, u32, u32, u16);
extern void func_0801B73C(const Rectangle *, u8, u16);

/* Complete 0x0811B1C8..0x0811B2A0: 216 bytes. */
u32 func_0811B1C8(void *task, Descriptor *descriptor, Payload *payload)
{
    switch (descriptor->phase) {
    case 0:
        break;
    case 1:
        func_080D35D8();
        break;
    case 0x100:
        payload->child = func_080D4704(data_0894C758, task);
        payload->record_task = func_080DFD8C(data_083A69E8, 1, 4, 0, task);
        descriptor->phase++;
        break;
    case 0x101:
        payload->child = func_080D4774(payload->child);
        if (payload->child == 0) {
            u8 i;
            u16 fill;

            if (func_080D39F0()) {
                u8 *destination = (u8 *)func_080D3904() + 0x9E;
                func_0814186C(data_03003900, destination, 16);
            }
            func_08000B68((RequestNode *)func_080D3AF8(),
                          -1, (u32)data_06004FE0, 8);
            data_03003860.value = 0;
            fill = 0x927F;
            for (i = 0; i < 2; i++)
                func_0801B73C(&data_083A69F0[i], 1, fill);
            descriptor->phase = 2;
        }
        break;
    }
    return 0;
}
