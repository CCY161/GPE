#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;

int main(){
    int num1;
    int rounds = 0;
    while(cin >> num1 && num1){
        getchar();
        //cout << "1111111111111111111111\n";
        string str1, str2, temp;
        rounds++;
        for(int i = 0 ; i < num1 ; i++){
            if(i > 0)
                str1 += "\n";
            getline(cin, temp);
            str1 += temp;
            //cout << temp << " from temp " << "\n";
        }
        int num2;
        cin >> num2;
        getchar();
        for(int i = 0 ; i < num2 ; i++){
            if(i > 0)
                str2 += "\n";
            getline(cin, temp);
            str2 += temp;
        }

        bool ac = false;

        //cout << str1 << "\n";
        //cout << str2 << "\n";

        if(str1 == str2) 
            ac =true;
        
        if(ac)
            cout << "Run #" << rounds << ": Accepted\n";
        else{
            string str3, str4;
            for(int i = 0 ; i < str1.size() ; i++){
                if(isdigit(str1[i]))
                    str3 += str1[i];
            }
            for(int i = 0 ; i < str2.size() ; i++){
                if(isdigit(str2[i]))
                    str4 += str2[i];
            }

            if(str3 == str4)
                cout << "Run #" << rounds << ": Presentation Error\n";
            else
                cout << "Run #" << rounds << ": Wrong Answer\n";
        }
        //cout << "1111111111111111111111\n";   
    }
    return 0;
}