#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double r;

    while(cin >> r){
        double a, b, c;
        double square = r * r;
        a = square * (1 - sqrt(3)/4 - M_PI/6);
        b = square - M_PI_4 * square - 2 * a;
        c = square - 4 * a - 4 * b;

        cout << fixed << setprecision(3) << c << " " << 4 * b << " " << 4 * a << "\n";

    }

    return 0;
}