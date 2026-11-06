#include "ffta.h"

typedef struct {
    u8 unknown_00[0x0A];
    u8 level;
    u8 unknown_0B[0xCB];
    u16 value_D6;
} Entity;

typedef struct {
    u8 unknown_00[0x40];
    u8 values[256];
} ProgressRecord;

typedef struct {
    u32 unknown_00;
    u16 identifier;
} TransferEntry;

typedef struct {
    u8 unknown_00[3];
    u8 kind;
} Action;

typedef struct {
    Entity *source;
    Entity *other;
    Entity *target;
    u8 unknown_0C[0x0C];
    u16 result;
    u8 unknown_1A[6];
    s16 amounts[3];
    u16 flags;
    u8 index;
    u8 unknown_29[7];
    const Action *action;
} Transfer;

extern const u16 data_083A8C14[];
extern void *func_08022840(u32 size);
extern void func_08022854(u8 *object);
extern s32 func_080C7EA4(const void *object, u32 selector);
extern void func_080CA2E8(void *object);
extern u8 func_080CD1FC(void *object, u8 index);
extern void func_080CD364(void *object, u8 index);
extern void func_080CD544(void *object, u8 index);
extern void func_080CD620(void *object, u8 index);
extern void func_0813255C(Transfer *transfer);
extern u8 func_08132CB8(Transfer *transfer, u16 identifier);
extern void func_08132D84(const TransferEntry **entries, s32 count, s32 rounds);
extern u16 func_08132DDC(const Entity *entity, const TransferEntry *entry);
extern u16 func_08132E2C(Entity *entity, const TransferEntry *const *entries,
                         s32 count, s32 *selected_index);
extern u16 func_08133CC8(const TransferEntry **entries, const Entity *entity);

void func_08132EE8(Transfer *transfer)
{
    if (transfer->flags & 0x10)
        return;

    switch (transfer->action->kind) {
    case 8: {
        s32 selected_index;
        const TransferEntry **entries = func_08022840(0x400);
        u16 count = func_08133CC8(entries, transfer->target);
        u16 source_slot;
        u16 target_slot;

        func_08132D84(entries, count, 4);
        source_slot = func_08132E2C(transfer->source, entries, count, &selected_index);
        ((ProgressRecord *)transfer->source)->values[source_slot] = 0xE4;
        func_080CD620(transfer->source, source_slot);
        func_080CD364(transfer->source, source_slot);
        target_slot = func_08132DDC(transfer->target, entries[selected_index]);
        ((ProgressRecord *)transfer->target)->values[target_slot] = 0;
        if (func_080CD1FC(transfer->target, target_slot))
            func_080CD544(transfer->target, target_slot);
        func_080CD620(transfer->target, target_slot);
        transfer->result = entries[selected_index]->identifier;
        func_08022854((u8 *)entries);
        break;
    }
    case 7:
        if (!func_08132CB8(transfer, 29))
            func_08132CB8(transfer, 28);
        func_080CA2E8(transfer->target);
        break;
    case 15:
        if (!func_08132CB8(transfer, 24) && !func_08132CB8(transfer, 25))
            func_08132CB8(transfer, 26);
        func_080CA2E8(transfer->target);
        break;
    case 16:
        if (!func_08132CB8(transfer, 21) && !func_08132CB8(transfer, 22))
            func_08132CB8(transfer, 23);
        func_080CA2E8(transfer->target);
        break;
    case 27:
        func_08132CB8(transfer, 20);
        func_080CA2E8(transfer->target);
        break;
    case 37: {
        u32 i;

        for (i = 0; i < 19; i++) {
            if (func_08132CB8(transfer, data_083A8C14[i]))
                break;
        }
        func_080CA2E8(transfer->target);
        break;
    }
    case 6: {
        u16 *count = &transfer->source->value_D6;
        s32 value = *count + transfer->amounts[transfer->index];

        if (value > 9)
            value = 10;
        *count = value;
        break;
    }
    case 17: {
        s32 level = func_080C7EA4(transfer->source, 7)
                    + transfer->amounts[transfer->index];
        s32 amount;

        if (level > 99)
            level = 100;
        if ((u32)func_080C7EA4(transfer->source, 6) > 49 && level > 99)
            level = 99;
        transfer->source->level = level;
        level = func_080C7EA4(transfer->other, 7)
                - transfer->amounts[transfer->index];
        if (level < 0)
            level = 0;
        transfer->other->level = level;
        amount = transfer->amounts[transfer->index];
        if (amount < 0)
            amount = -amount;
        transfer->result = amount + 1;
        break;
    }
    case 9: {
        s32 amount;

        func_0813255C(transfer);
        amount = transfer->amounts[transfer->index];
        if (amount < 0)
            amount = -amount;
        transfer->result = amount + 1;
        break;
    }
    }
}
