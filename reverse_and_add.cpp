#include <iostream>

using namespace std;

int main(){

    int test_num;
    cin >> test_num;

    while(test_num--){
        int number;
        int number_arr [11] = {0};
        int total_sum [11] = {0};
        int i = 0;
        int iter = 0;
        int result = 0;

        cin >> number;        
        while(number != 0){
            number_arr[i] = number % 10;
            number /=10;
            i++;    
        }

        while(1){
            bool is_palindrome = true;
            int sum, carry = 0;
            for(int j = 0 ; j < (i/2) ; j++){
                if(number_arr[j]!=number_arr[i-j-1])
                    is_palindrome = false;
            }

            if(is_palindrome) break;
            else{
                for(int j = 0 ; j < i ; j++){
                    sum = carry + number_arr[j] + number_arr[i-j-1];
                    //cout << sum << "\n";
                    total_sum[j] = sum % 10;
                    carry = sum / 10;
                }
                if(carry !=0){
                        total_sum[i] = carry;
                        i++;
                }
                for(int j = 0 ; j < i ; j++){
                    number_arr[j] = total_sum[j];
                    //cout << number_arr[j] << "!!!! \n";
                }
            }
            
            iter++;
            //cout << i << " " << result << "\n"; 
        }

        for(int j = i-1 ; j > 0 ; j--){
                result += number_arr[j];
                result *=10;
                //cout << result << "???? \n";
            }
        result += number_arr[0];

        cout << iter << " " << result << "\n"; 
    }

    return 0;
}