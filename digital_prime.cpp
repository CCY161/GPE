#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int number;
    cin >> number;

    for(int i = 0 ; i < number ; i ++){
        int first, second;
        cin >> first >> second;

        int prime_number = 0;
        for(int j = first ;  j <= second ; j++){
            if(j == 2 || j == 5) prime_number++;
            
            if(j == 1 || j % 2 == 0 || j % 5 == 0)
                continue;

            int rms = sqrt(j);
            bool is_prime = true;

            for(int k = rms ; k > 1 ; k--){
                if(j % k == 0){ 
                    is_prime = false;
                    break;            
                }
            }
            
            if(is_prime){
                int tmp1 =  j / 100000;
                int tmp2 = (j % 100000) / 10000;
                int tmp3 = (j % 10000) / 1000;
                int tmp4 = (j % 1000) / 100;
                int tmp5 = (j % 100) / 10;
                int tmp6 = (j % 10);
                int sum = tmp1 + tmp2 + tmp3 + tmp4 + tmp5 + tmp6;
                
                if(sum == 2 || sum == 5){
                    prime_number++;
                }
                if(sum == 1 || sum % 2 == 0 || sum % 5 == 0)
                    continue;

                int rms_sum = sqrt(sum);
                for(int k = rms_sum ; k > 1 ; k--){
                    if(sum % k == 0){ 
                        is_prime = false;
                        break;                
                    }
                }
            }
            
            if(is_prime){
                prime_number++;
                //cout << "rms : " << rms << " j " << j << "\n"; 
            }
        }
        cout << prime_number << "\n";
    }

    return 0;
}