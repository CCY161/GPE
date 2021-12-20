#include <iostream>
using namespace std;

int main(){
    
    int test_num;
    cin >> test_num;

    while(test_num--){
        int number;
        cin >> number;
        int ans[32] = {0};
        int len = 0;
        
        if(number == 0){
            cout << 10;
        }

        else if(number == 1){
            cout << 1;
        }

        else{
            for(int i=9 ; i >=2 ; i--){
                while(number % i == 0){
                    number /= i;
                    ans[len]=i;
                    len++;
                }
            }
            if(number == 1){
                for(int j = len-1 ; j >= 0 ; j--){
                    cout << ans[j];
                }
            }
            else cout << -1;
        }
        cout << "\n";
    }
    return 0;
}