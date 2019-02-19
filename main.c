/*---------------------------------------------*
*                                              *
*    Special thanks to Николай Ершов @nickme   *
*       https://habr.com/ru/post/150732/       *
*                                              *
*----------------------------------------------*/

#include "avltree.h"
/*
*t()
*
* root
* t(left)
* t(right)
*
* t(left)
* root
* t(right)
*
* t(left)
* t(right)
* root
*/



int main() {
    node * tree = NULL;

    int n,
        cur;

    scanf("%d", &n);

    if (n < 0) {
        puts("bad input");
        return 0;
    }

    while (n--) {
        scanf("%d", &cur);

        tree = insert(tree, cur);
    }
    printf("%d\n", get_height(tree));

    walk_the_tree(tree);

    destroy(tree);

    return 0;
}