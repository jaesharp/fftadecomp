#include "ffta.h"

typedef struct {
    u8 unknown_000[0x298];
    const void *image;
    u8 unknown_29C[0x5A];
    s8 selection;
} DrawStateA52C;

extern const u8 data_083A8298[];
extern const u8 data_083A82EC[];
extern const u8 data_083A8295[];
extern void func_08001F34(const void *, s32, s32, u8, u8, u8, u8,
                          u8, u32, u8, const void *);
extern void func_08001CF0(const void *, s32, s32, u8, u8, u8, u8,
                          u8, u32, u8, u32);
extern void func_0812ADDC(void *, s16, s16);

/* Complete 0x0812A52C..0x0812A5BC: 144 bytes. */
void func_0812A52C(DrawStateA52C *state)
{
    func_08001F34(data_083A8298, 80, 128, 0, 0, 0, 0, 0, 0, 0, 0);
    func_0812ADDC(state, 92, 136);
    func_08001CF0(state->image, 240, 154, 0, 0, 1, 0, 0, 0x240, 0, 0);
    func_08001F34(data_083A82EC, data_083A8295[state->selection], 8,
                  0, 0, 0, 0, 0, 0, 0, 0);
}
