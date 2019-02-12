#pragma once

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <malloc.h>
#include <stdio.h>

#define left 0
#define right 1


typedef struct tree_node node;

struct tree_node {
    int key;
    unsigned int height;

    node * child[2];
};

static node * new_node(
        int key);

unsigned int get_height(
        node * root);

static void count_height(
        node * root);

static int balance_factor(
        node * root);

static node * balance(
        node * root);

node * insert(
        node * root,
        int key);

void destroy(
        node * tree);

#endif
