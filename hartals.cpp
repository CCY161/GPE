#include <iostream>

using namespace std;

int main(){

    int test_num;
    cin >> test_num;

    while(test_num--){
        int days, parties;
        cin >> days >> parties;

        int hartals[101], other_hartals[101];
        for(int i = 0 ; i < parties ; i++){
            cin >> hartals[i];
            other_hartals[i] = hartals[i];
        }

        int  work_day = 0;
        for(int i = 1 ; i <= days ; i++){
            bool is_work = false;
            for(int j = 0 ; j < parties ; j++){
                if(hartals[j] == i){
                    hartals[j] += other_hartals[j];
                    if((i % 7 != 6) && (i % 7 != 0)){
                        //cout << "day  : " << i << "\n";
                        is_work = true;
                    }
                }
            }
            if(is_work) work_day++;
        }
        cout << work_day << "\n";
    }
    return 0;
}