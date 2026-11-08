#include "ffta.h"

typedef struct ListNode08005BDC {
    u8 unknown_00[8];
    struct ListNode08005BDC *next;
} ListNode08005BDC;

typedef struct {
    u8 unknown_00[0x10];
    ListNode08005BDC *head;
} List08005BDC;

/* 0x08005BDC..0x08005BF8: 28 bytes, 14 instructions. */
ListNode08005BDC *func_08005BDC(List08005BDC *list, s32 index)
{
    ListNode08005BDC *node = list->head;

    if (node && index > 0) {
        do {
            node = node->next;
            --index;
        } while (index > 0 && node);
    }
    return node;
}
