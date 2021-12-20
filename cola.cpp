#include <iostream>

using namespace std;

int main(){

    int number;

    while(cin >> number){
        int total = number;
        int a=0, b=0;
        while(number > 2){
            a = number % 3;
            b = number / 3;
            total+=b;
            number = a + b;
        }
        if(number==2)
            total++;
        
        cout << total << "\n";
    }

    return 0;
}