#include "ffta.h"

typedef struct ScriptContext {
    u8 bank;
    u8 index;
    s16 position;
    const u8 *script;
} ScriptContext;

typedef struct __attribute__((packed)) ScriptEntry {
    u8 length[2];
    u8 callback[4];
} ScriptEntry;

typedef u32 (*ScriptHandler)(ScriptContext *, const u8 *);
extern const ScriptEntry g_table_0836D5A4[];

/* Complete [0x0800A154,0x0800A1A8): 84 bytes. */
u32 func_0800A154(ScriptContext *context)
{
    u32 entries = (u32)g_table_0836D5A4;
    for (;;) {
        const u8 *instruction = context->script + context->position;
        u8 opcode = *instruction;
        const ScriptEntry *entry;
        u8 low_byte;
        u32 low;
        u32 middle;
        u32 callback;
        u16 length;

        if (opcode == 0)
            return 1;
        entry = (const ScriptEntry *)(opcode * sizeof(ScriptEntry) + entries);
        low_byte = entry->callback[0];
        low = ((u32)entry->callback[1] << 8) | low_byte;
        middle = ((u32)entry->callback[2] << 16) | low;
        callback = ((u32)entry->callback[3] << 24) | middle;
        ((ScriptHandler)callback)(context, instruction);
        low_byte = entry->length[0];
        length = (entry->length[1] << 8) | low_byte;
        context->position = length + (u16)context->position;
    }
}
