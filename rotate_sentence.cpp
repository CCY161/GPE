#include <iostream>
#include <cstring>
//#include <cstdio>
using namespace std;

int main(){
    char word[100][101];
    int len[100];
    int line = 0, max = 0;

    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 101 ; j++)
            word[i][j] = 0;
        len[i] = 0;
    }

    while(cin.getline(word[line], 101)){
        len[line] = strlen(word[line]);
        if(len[line] > max)
            max = len[line];
        for(int i = len[line] ; i < max ; i++){
            word[line][i]=' ';
            len[line]++;
        }
        line++;
    }

    for(int i = 0 ; i < max ; i++){
        for(int j = line-1 ; j >= 0 ; j--){
            if(j < len[i])
                cout << word[j][i];
        }
        cout << "\n";
    }

    return 0;
}