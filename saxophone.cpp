#include<iostream>
#include <cstdio>
#include<map>
using namespace std;

int main(){
    map<char, string> table;
    table['a']="0110000000";
    table['b']="0100000000";
    table['c']="0111001111";
    table['d']="0111001110";
    table['e']="0111001100";
    table['f']="0111001000";
    table['g']="0111000000";
    table['A']="1110000000";
    table['B']="1100000000";
    table['C']="0010000000";
    table['D']="1111001110";
    table['E']="1111001100";
    table['F']="1111001000";
    table['G']="1111000000";

    int number;
    cin >> number;
    getchar();
    for(int i = 0 ; i < number ; i++){
        string input;
        getline(cin,  input);

        if(input ==""){
            cout << "0 0 0 0 0 0 0 0 0 0\n";
        }
        else{
        string a, b;
        int result[10];
        for(int k = 0 ; k < 10 ; k++){
            result[k] = 0;  
        }

        a = table[input[0]];
        for(int k = 0 ; k < 10 ; k++){
            if(a[k]=='1') result[k]++;  
        }

        // for(int k = 0 ; k < 10 ; k++){
        //     cout << " " << result[k];  
        // }
        // cout << a << "\n";

        for(int j = 1 ; j < input.size() ; j++){
            b = table[input[j]];
            for(int k = 0 ; k < 10 ; k++){
                if(a[k]=='0' && b[k] =='1')
                    result[k]++;
            }
            a = b;
        }
        cout << result[0];
        for(int k = 1 ; k < 10 ; k++){
            cout << " " << result[k];  
        }
        cout << "\n";
        }
    }
    return 0;
}