#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string i, string j){
    return (i + j) > (j + i);
}

int main(){

    int numbers;

    while(cin >> numbers && numbers){
        vector<string> list;
        string input;

        for(int i = 0 ; i < numbers ; i++){
            cin >> input;
            list.push_back(input);
        }
        sort(list.begin(), list.end(), comp);

        
        for(int i = 0 ; i < numbers ; i++){
            cout << list[i];
        }
        cout << "\n";
    }

    return 0;
}