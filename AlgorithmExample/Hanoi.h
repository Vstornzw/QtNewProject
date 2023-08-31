#ifndef HANOI_H
#define HANOI_H
#include <stdio.h>

void printMove(char x, char y)
{
    printf("from %c-->%c\n", x, y);
}
void hanoi(int n, char A, char B, char C)
{
    /*递归出口*/
    if (n == 1) {
        printMove(A, C);
    } else {
        /*将n-1个盘子从A通过C移动到B*/
        hanoi(n - 1, A, C, B);

        /*将最大的盘子也就是n-（n-1）=1个盘子移动到C*/
        printMove(A, C);

        /*将n-1个盘子从B通过A移动到C*/
        hanoi(n - 1, B, A, C);
    }
}

#endif // HANOI_H
