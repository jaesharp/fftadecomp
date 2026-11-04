#include "ffta.h"

/* 080C7DEC..080C7E36, 74 bytes.
 * Target: 30b5011c002401235b420d1c01e00b1c8968002915d00a69002a07d09a4205d0c86898420bd00b1c111cf2e7c868984205d00134002802d00b1c011ce9e7a942e5d1201c30bc02bc0847
 * External alignment 080C7E36..080C7E38: 0000, outside FUNC.
 */
struct Node {
    u8 unknown_00[8];
    struct Node *parent;
    struct Node *left;
    struct Node *right;
};

int func_080C7DEC(struct Node *current)
{
    struct Node *root;
    struct Node *previous;
    int count;

    count = 0;
    previous = (struct Node *)-1;
    root = current;

    while (current != 0) {
        struct Node *right = current->right;

        if (right != 0 && right != previous) {
            if (current->left != previous) {
                previous = current;
                current = right;
                continue;
            }
        } else {
            struct Node *left = current->left;

            if (left != previous) {
                count++;
                if (left != 0) {
                    previous = current;
                    current = left;
                    continue;
                }
            }
        }

        if (current == root)
            break;
        previous = current;
        current = current->parent;
    }

    return count;
}
