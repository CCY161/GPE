#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    long long int dollar [3001];
    int value[11] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

    for(int i = 0 ; i < 3001 ; i++)
        dollar[i] = 1;

    for(int j = 1 ; j < 11 ; j++){
        for(int k = value[j] ; k < 3001 ; k++){
            dollar[k] += dollar[k-value[j]];            
        }
    }

    double money;
    while(cin >> money){
        if(money == 0) break;
        cout << fixed << setprecision(2) << setw(6) << money;
        cout << setw(17) << dollar[(int)(money*10.0)] << "\n";
    }
    return 0;
}