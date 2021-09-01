#include<iostream>
#include<string>
#include<vector>
//#include<map>

using namespace std;

int main(){
    string first;
    while(getline(cin, first, ' ')){
        vector<pair<int, int> > line;
        vector<int> sort_number;
        if(first != "."){
            string second;
            getline(cin, second);
            int x1 = stoi(first);
            int x2 = stoi(second);
            sort_number.push_back(x1);
            
            line.push_back(pair<int, int>(x1, x2));
        }
        else{
            




        } 
    }
    return 0;
}