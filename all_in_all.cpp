#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1, str2;

    while(cin >> str1){
        cin >> str2;

        int k = 0;

        for(int i = 0 ; i < str2.size() ; i++){
            if(str1[k]==str2[i]) k++;
        }

        if(k==str1.size())
            cout << "Yes\n";
        else
            cout << "No\n";  
    }

    return 0;
}