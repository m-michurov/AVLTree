#include "avltree.h"

static node * new_node(
        int key)
{
    node * new_node = (node *)malloc(sizeof(node));

    new_node->key = key;
    new_node->height = 1;
    new_node->child[left] = new_node->child[right] = 0;

    return new_node;
}


inline unsigned int get_height(
        node * root)
{
    return root ? root->height : 0;
}


static inline void count_height(
        node * root)
{
    unsigned int left_height = get_height(root->child[left]);
    unsigned int right_height = get_height(root->child[right]);

    root->height = (left_height > right_height ? left_height : right_height) + 1;
}

static inline int balance_factor(
        node * root)
{
    return get_height(root->child[right]) - get_height(root->child[left]);
}


static node * rotate(
        node * root,
        int dir)
{
    node * new_root = root->child[1 - dir];

    root->child[1 - dir] = new_root->child[dir];
    new_root->child[dir] = root;

    count_height(root);
    count_height(new_root);

    return new_root;
}


static node * balance(
        node * root)
{
    count_height(root);

    if (balance_factor(root) == 2){
        if (balance_factor(root->child[right]) < 0)
            root->child[right] = rotate(root->child[right], right);

        return rotate(root, left);
    }

    if (balance_factor(root) == -2) {
        if (balance_factor(root->child[left]) > 0)
            root->child[left] = rotate(root->child[left], left);

        return rotate(root, right);
    }

    return root;
}


node * insert(
        node * root,
        int key)
{
    if (root == 0)
        return new_node(key);
    if (key < root->key)
        root->child[left] = insert(root->child[left], key);
    else
        root->child[right] = insert(root->child[right], key);

    return balance(root);
}


void destroy(
        node * tree)
{
    if (tree == NULL)
        return;

    destroy(tree->child[left]);
    destroy(tree->child[right]);

    free(tree);
}

