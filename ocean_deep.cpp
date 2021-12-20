#include <iostream>
#include <string>
using namespace std;

int main(){

    string number;
    while(cin >> number){

        while(number[number.size()-1]!='#'){
            string temp;
            cin >> temp;
            number += temp;
        }
        int remainder = 0;
        int value = 0;
        for(int i = 0 ; i < number.size() ; i++){
            value = remainder * 2;
            if(number[i]=='#'){
                if(remainder==0)
                    cout << "YES" << "\n";
                else
                    cout << "NO" << "\n";
            }
            else{
                value += (number[i] - '0');
                remainder = value % 131071; 
            }

        }

    }

    return 0;
}