#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num;
    while(cin >> num && num){        
        map< set<int> , int> table;
        
        int frosh;
        int max_value = 0;
        int kind = 1;

        for(int i = 0 ; i < num ; i++){
            set<int> students;
            for(int j = 0 ; j < 5 ; j++){
                
                cin >> frosh;
                students.insert(frosh);
            }
                table[students]++;

                if(max_value == table[students]) kind++;
                if(table[students] > max_value){
                    max_value = table[students];
                    kind=1;
                }
            
        }
        cout << max_value * kind << "\n";
    }
    return 0;
}