#pragma once

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <malloc.h>
#include <stdio.h>


typedef struct tree_node node;

struct tree_node {
    int key;
    unsigned int height;

    node * left_node;
    node * right_node;
};

static node * new_node(
        int key);

unsigned int get_height(
        node * root);

static void count_height(
        node * root);

static int balance_factor(
        node * root);

static node * rotate_left(
        node * root);

static node * rotate_right(
        node * root);

static node * balance(
        node * root);

node * insert(
        node * root,
        int key);

void destroy(
        node * tree);

#endif
