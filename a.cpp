#include <iostream>

struct point {
    public:
        int x, y;
        int method () {
            return x;
        };
};

class Point {
    private:
        int x, y;
        int method () {};
};

int main ()
{
    struct point p_a;
    Point p_b;
    p_a.method();
    return 0;
}

