#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    int books;
    int i = 0;
    while(cin >> books){
        vector<int> price;
        for(int i = 0 ; i < books ; i++){
            int money;
            cin >> money;
            price.push_back(money);
        }
        int total_money;
        cin >> total_money;

        int b1 = 0, b2 = 0, diff = 100000000, cur_diff = 0;
        for(int i = 0 ; i < books ; i++){
            for(int j = i+1 ; j < books ; j++){
                cur_diff = abs(price[i] - price[j]);
                if(price[i] + price[j]==total_money && cur_diff < diff){
                    if(price[i] >= price[j]){
                        b1 = price[j];
                        b2 = price[i];                        
                    }
                    else{
                        b1 = price[i];
                        b2 = price[j];
                    }
                    diff = cur_diff;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << b1 << " and " << b2 << ".\n\n";

    }

    return 0;
} 