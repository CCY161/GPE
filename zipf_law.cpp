#include<iostream>
//#include<set>
#include<map>
#include<string>
#include<cctype>

using namespace std;

int main(){

    int number;
    string input_word;

    cin >> number;
    map<string, int> table;

        bool not_found = true;
        while(cin >> input_word && input_word!="EndOfText"){
            string word;
            for(unsigned int i = 0 ; i < input_word.size() ; i++){
                if(isalpha(input_word[i])) word.push_back(tolower(input_word[i]));
                else {
                    if(table.find(word) != table.end())
                        table[word]++;
                    else
                        table.insert(pair<string, int>(word, 1));
                    word ="";
                }
            }
            
            if(table.find(word) != table.end())
                table[word]++;
            else
                table.insert(pair<string, int>(word, 1)); 
        }

        for(map<string,int>::iterator it=table.begin(); it!=table.end(); ++it){
            if(it->second==number && it->first!=""){
                cout << (it->first)  << '\n';
                not_found = false;
            }
        }
        if(not_found)  cout << "There is no such word." << '\n';

    while(cin >> number){
         cout << "\n";
        map<string, int> table;

        bool not_found = true;
        while(cin >> input_word && input_word!="EndOfText"){
            string word;
            for(unsigned int i = 0 ; i < input_word.size() ; i++){
                if(isalpha(input_word[i])) word.push_back(tolower(input_word[i]));
                else {
                    if(table.find(word) != table.end())
                        table[word]++;
                    else
                        table.insert(pair<string, int>(word, 1));
                    word ="";
                }
            }

            if(table.find(word) != table.end())
                table[word]++;
            else
                table.insert(pair<string, int>(word, 1)); 
        }

        for(map<string,int>::iterator it=table.begin(); it!=table.end(); ++it){
            if(it->second==number && it->first!=""){
                cout << (it->first)  << '\n';
                not_found = false;
            }
        }
        if(not_found)  cout << "There is no such word." << '\n';
       
    }
    return 0;
}