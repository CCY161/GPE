#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b, int &x, int &y){
    if(a % b == 0){
        x = 0;
        y = 1;
        return b;
    }
    else if( b % a == 0){
        x = 1;
        y = 0;
        return a;
    }
    else if(a >= b){
        int x1, y1;
        int value = gcd(a + b * (-a/b), b, x1, y1);
        x = x1;
        y = y1 - (a/b) * x1;
        return value;
    }   
    else{
        int x1, y1;
        int value = gcd(a, b - a * (b/a), x1, y1);
        x = x1 - (b/a) * y1;
        y = y1;
        return value;
    }
}

int main(){

    int a, b;

    while(scanf("%d%d", &a, &b)!= EOF){
        //cout << a << b;
        int x=0, y=0;
        int d;
        d= gcd(a, b, x, y);

        printf("%d %d %d\n", x, y, d);
        //cout << x << " " << y << " " << d << "\n";
    }

    return 0;
}