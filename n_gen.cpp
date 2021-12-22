#include <iostream>

using namespace std;

int main(){
    int a, b;
    
    for(int i = 0 ; i < 10 ; i++){
        a = 1 *i *i + 1 *i + 1;
        cout << a << " ";
    }
    cout << "\n";

    for(int i = 0 ; i < 10 ; i++){
        a = 2 *i *i + 2 *i + 2;
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}