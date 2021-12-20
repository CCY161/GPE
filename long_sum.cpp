#include <iostream>

using namespace std;

int main(){
    int test_num;
    cin >> test_num;

    int digits;
    cin >> digits;
    int number[1000000] = {0};
    int first, second;

    for(int i = digits-1 ; i >= 0 ; i--){        
        cin >> first >> second;
        number[i] = first + second;
    }
    for(int j = 0 ; j < digits ; j++){
        if(number[j] >= 10){
            int carry = number[j]/10;
            number[j] %= 10; 
            number[j+1] += carry;
        }
    }
    for(int k = digits-1 ; k >= 0 ; k--){
        cout << number[k];
    }
    cout << "\n";
    test_num--;
    while(test_num--){
        cout << "\n";
        cin >> digits;

        for(int i = digits-1 ; i >= 0 ; i--){            
            cin >> first >> second;
            number[i] = first + second;
        }

        for(int j = 0 ; j < digits ; j++){
            if(number[j] >= 10){
                int carry = number[j]/10;
                number[j] %= 10;
                number[j+1] += carry;
            }
        }

        for(int k = digits-1 ; k >= 0 ; k--){
            cout << number[k];
        }
        cout << "\n";
    }

    return 0;
}