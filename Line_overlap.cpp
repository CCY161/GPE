#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct line{
    int n1;
    int n2;
};

long long int fac(int n){
    long long int sum = 0;
    for(int i=1 ; i < n ; i++){
        sum+=i;
    }
    return sum; 
}

int main(){
    string str;
    long long int result = 0;
    line num;    
    stringstream ss;
    long int table [100000];
    for(int i = 0 ; i < 100000 ; i++){
        table[i] = 0;
    }

    while(getline(cin, str) && str != "."){
        ss << str;
        ss >> num.n1 >> num.n2;
        ss.clear();
        for(int i = num.n1 ; i < num.n2 ; i++){
            table[i]++;
        }
    }

    for(int i = 0 ; i < 100000 ; i++){
        if(table[i] > 1){
            //cout << table[i] << " " << i << "\n";
            result +=fac(table[i]);
        }
    }

    cout << result << "\n";

    return 0;
}