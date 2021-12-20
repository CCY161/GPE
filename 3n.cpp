#include <iostream>

using namespace std;

int main(){
    int m, n;
    
    while(cin >> m >> n ){
        int max_cycle = 0;
        cout << m << " " << n << " ";
        if(m > n){
            int c = m;
            m = n;
            n = c;
        }
        for(int i = m ; i < n ; i++){
            int number = i;
            int cycle = 1;
            while(true){
                if (number == 1) break;
                else if(number % 2 == 0) number /= 2;
                else number = 3 * number +1;
                cycle++;
            }          
            max_cycle = max(cycle, max_cycle);
        }
        cout << max_cycle << "\n";
    } 
    return 0;
}