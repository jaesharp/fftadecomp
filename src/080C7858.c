#include "ffta.h"

typedef struct TreeNode080C7858 {
    s32 key;
    void *value;
    struct TreeNode080C7858 *parent;
    struct TreeNode080C7858 *left;
    struct TreeNode080C7858 *right;
    u32 flags;
} TreeNode080C7858;

typedef struct {
    void *owner;
    void *head;
    TreeNode080C7858 *root;
} TreeContext080C7858;

/* Complete [0x080C7858, 0x080C7906): 174 bytes, 87 instructions. */
void func_080C7858(TreeContext080C7858 *context, TreeNode080C7858 *node)
{
    TreeNode080C7858 *cur;
    TreeNode080C7858 *subtree;
    s32 key;

    if (node->parent == 0) {
        context->root = 0;
        if (node->left != 0) {
            context->root = node->left;
            node->left = 0;
        } else if (node->right != 0) {
            context->root = node->right;
            node->right = 0;
        }
        if (context->root != 0)
            context->root->parent = 0;
    } else {
        TreeNode080C7858 *parent = node->parent;

        if (parent->left == node)
            parent->left = 0;
        else if (parent->right == node)
            parent->right = 0;
        node->parent = 0;
    }

    if (node->left != 0) {
        cur = context->root;
        subtree = node->left;
        key = subtree->key;
        while (1) {
            if (key < cur->key) {
                if (cur->left != 0) {
                    cur = cur->left;
                    continue;
                }
                cur->left = subtree;
            } else {
                if (cur->right != 0) {
                    cur = cur->right;
                    continue;
                }
                cur->right = subtree;
            }
            break;
        }
        subtree->parent = cur;
        node->left = 0;
    }
    if (node->right != 0) {
        cur = context->root;
        subtree = node->right;
        key = subtree->key;
        while (1) {
            if (key < cur->key) {
                if (cur->left != 0) {
                    cur = cur->left;
                    continue;
                }
                cur->left = subtree;
            } else {
                if (cur->right != 0) {
                    cur = cur->right;
                    continue;
                }
                cur->right = subtree;
            }
            break;
        }
        subtree->parent = cur;
        node->right = 0;
    }
    node->parent = 0;
}
