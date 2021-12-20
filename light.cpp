#include <iostream>
#include <cmath>

using namespace std;

int main(){
    unsigned int test_num;
    while(cin >> test_num && test_num){
        int hit = 0;
        unsigned int sqrt_num = sqrt(test_num);
        //cout << "sqrt_num " << sqrt_num << "\n"; 
        /*for(int i = 1 ; i <= sqrt_num ; i++){
            //cout << "i " << i << "\n"; 
            if(test_num % i == 0) hit++;
        }
        hit = (hit << 1);*/
        if(sqrt_num * sqrt_num == test_num)
            cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

    return 0;
}