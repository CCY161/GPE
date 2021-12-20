#include <stdio.h>

struct point {
    int x, y;
    int (*func) ();
};

int ff ();

typedef struct point Point;

int main ()
{
    struct point p_a;
    p_a.func = ff;


    p_a.func();     
    Point p_b;

    return 0;
}
