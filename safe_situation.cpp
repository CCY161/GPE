#include <iostream>

using namespace std;

int main(){
    int table[11]={0};
    table[0] = 1;
    table[1] = 1;

    for(int i = 2 ; i < 11 ; i++){
        int number = 0;
        for(int j = i-1 ; j >= 0 ; j--){
            number += table[j] * table[i-j-1];
        } 
        table[i] = number;
        //cout << "i : " << table[i] << "\n";
    }

    int test_num;
    cin >> test_num;
    cout << table[test_num]<< "\n";

    while(cin >> test_num){
        cout << "\n" ;
        cout << table[test_num]<< "\n";

    }
    return  0;
}