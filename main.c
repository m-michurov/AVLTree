/*---------------------------------------------*/
/*                                             */
/*   Special thanks to Николай Ершов @nickme   */
/*      https://habr.com/ru/post/150732/       */
/*                                             */
/*---------------------------------------------*/

#include "avltree.h"

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
    printf("%d", get_height(tree));

    destroy(tree);

    return 0;
}