#include <iostream>
#include <map>

using namespace std;

int main (){

    int words, jobs;
    cin >> words >> jobs;

    map<string, int> table;
    string sin;
    int din;
    
    for(int i = 0 ; i < words ; i++){
       cin >> sin >> din;
       table[sin] = din;
    }

    for(int i = 0 ; i < jobs ; i++){
        long  long sum = 0;
        while(cin >> sin && (sin != ".")){
            sum+=table[sin];
        }

        cout << sum << "\n";
    }


    return 0;
}