#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string first;
    while(getline(cin, first, ' ')){
        vector<pair<int, int> > line;
        vector<int> sort_number;
        int number = 0;
        int overlap_value = 0;
        if(first != "."){
            string second;
            number++;
            getline(cin, second);
            int x1 = atoi(first.c_str());
            int x2 = atoi(second.c_str());
            //sort_number.push_back(x1);
            //sort_number.push_back(x2);
            line.push_back(pair<int, int>(x1, x2));
        }
        else{
            sort(sort_number.begin(), sort_number.end());

            for(int i = 0 ; i < number ; i++){
                if((line[i].first < sort_number[number/2]) && (line[i].second < sort_number[number/2]))
                    overlap_value += (sort_number[number/2]);

            }
        } 
    }
    return 0;
}