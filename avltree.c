#include "avltree.h"

static node * new_node(
        int key)
{
    node * new_node = (node *)malloc(sizeof(node));

    new_node->key = key;
    new_node->height = 1;
    new_node->left_node = new_node->right_node = 0;

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
    unsigned int left_height = get_height(root->left_node);
    unsigned int right_height = get_height(root->right_node);

    root->height = (left_height > right_height ? left_height : right_height) + 1;
}

static inline int balance_factor(
        node * root)
{
    return get_height(root->right_node) - get_height(root->left_node);
}


static node * rotate_left(
        node * root)
{
    node * new_root = root->right_node;

    root->right_node = new_root->left_node;
    new_root->left_node = root;

    count_height(root);
    count_height(new_root);

    return new_root;
}


static node * rotate_right(
        node * root)
{
    node * new_root = root->left_node;

    root->left_node = new_root->right_node;
    new_root->right_node = root;

    count_height(root);
    count_height(new_root);

    return new_root;
}


static node * balance(
        node * root)
{
    count_height(root);

    if (balance_factor(root) == 2){
        if (balance_factor(root->right_node) < 0)
            root->right_node = rotate_right(root->right_node);

        return rotate_left(root);
    }

    if (balance_factor(root) == -2) {
        if (balance_factor(root->left_node) > 0)
            root->left_node = rotate_left(root->left_node);

        return rotate_right(root);
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
        root->left_node = insert(root->left_node, key);
    else
        root->right_node = insert(root->right_node, key);

    return balance(root);
}


void destroy(
        node * tree)
{
    if (tree == NULL)
        return;

    destroy(tree->left_node);
    destroy(tree->right_node);

    free(tree);
}

