#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int number;

    while(cin >> number){
        vector<int> element;
        vector<int> sort_element;
        vector<vector<int> > table(number + 1, vector<int>(number + 1, 0));

        for(int i = 0 ; i < number ; i++){
            int input;
            cin >> input;
            element.push_back(input);
        }

        sort_element = element;
        sort(sort_element.begin(), sort_element.end());

        /*for(int i = 0 ; i < number ; i++){
            cout << element[i] << " " << sort_element[i]  << "\n";
        }*/

        for(int i = 1 ; i < number+1 ; i++){
            for(int j = 1 ; j < number+1 ; j++){
                if((element[i-1] == sort_element[j-1]) && (table[i-1][j] == table[i][j-1]))  table[i][j] = table[i-1][j-1] + 1;
                else table[i][j] = max(table[i-1][j], table[i][j-1]);
               //cout << table[i][j] << " ";
            }
            //cout << "\n";
        }
        cout << table[number][number] << "\n";
    }
    return 0;
}