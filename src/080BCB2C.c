#include "ffta.h"

typedef struct Node080BCB2C Node080BCB2C;
struct Node080BCB2C {
    s32 unknown_00;
    s32 unknown_04;
    s32 unknown_08;
    s32 unknown_0C;
    s8 unknown_10;
    u8 unknown_11;
    u8 unknown_12[2];
    Node080BCB2C *unknown_14;
    Node080BCB2C *unknown_18;
};

typedef struct {
    Node080BCB2C unknown_00[16];
    Node080BCB2C *unknown_1C0;
    u16 unknown_1C4;
    s16 unknown_1C6;
} State080BCB2C;

extern Node080BCB2C *func_080BCA74(State080BCB2C *state);
extern u32 func_08002804(void);
extern s32 func_08142950(s32 numerator, s32 denominator);

static inline Node080BCB2C *findInactive(Node080BCB2C *node)
{
    while (node != 0) {
        if (node->unknown_11 == 0)
            return node;
        node = node->unknown_18;
    }
    return 0;
}

static inline Node080BCB2C *insertNode(Node080BCB2C *head, Node080BCB2C *node)
{
    Node080BCB2C *current;

    if (head == 0)
        return node;
    if (head->unknown_10 < node->unknown_10) {
        head->unknown_14 = node;
        node->unknown_18 = head;
        return node;
    }
    current = head;
    while (current->unknown_18 != 0) {
        if (current->unknown_10 < node->unknown_10) {
            node->unknown_18 = current;
            node->unknown_14 = current->unknown_14;
            current->unknown_14 = node;
            return head;
        }
        current = current->unknown_18;
    }
    current->unknown_18 = node;
    node->unknown_14 = current;
    return head;
}

/* Complete [080BCB2C, 080BCC70): 324 bytes. */
void func_080BCB2C(State080BCB2C *state, u8 enabled)
{
    Node080BCB2C *current = state->unknown_1C0;

    while (current != 0) {
        if (current->unknown_11 != 0) {
            s16 first, second;

            current->unknown_00 += current->unknown_08;
            current->unknown_04 += current->unknown_0C;
            current->unknown_08 -= 12;
            current->unknown_0C += 23;
            first = current->unknown_00 >> 8;
            second = current->unknown_04 >> 8;
            if (first < 0 || second > 160)
                current->unknown_11 = 0;
        }
        current = current->unknown_18;
    }
    if (enabled) {
        if (state->unknown_1C6 > 0) {
            state->unknown_1C6--;
        } else {
            Node080BCB2C *node;

            state->unknown_1C6 = 3;
            node = func_080BCA74(state);
            if (node == 0) {
                node = findInactive(state->unknown_1C0);
                if (node == 0)
                    return;
            } else {
                Node080BCB2C *head = state->unknown_1C0;
                Node080BCB2C **slot = &state->unknown_1C0;
                *slot = insertNode(head, node);
            }
            node->unknown_00 = (s16)func_08142950((s16)func_08002804(), 0x10F) << 8;
            node->unknown_04 = 0;
            node->unknown_08 = -((s16)func_08142950((s16)func_08002804(), 0x41) + 128);
            node->unknown_0C = (s16)func_08142950((s16)func_08002804(), 0x81) + 384;
            node->unknown_11 = 1;
        }
    }
}
