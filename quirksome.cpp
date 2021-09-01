#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int number;

    while(cin >> number){
        
        if(number == 2){
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <= 9; j++){
                    int sum = i + j;
                    int result = sum * sum;
                    int expect = 10 * i + j;
                if(result == expect)
                    cout << i << j << "\n";
                }
            }
        }

        if(number == 4){
            for (int i = 0; i <= 99; i++){
                for (int j = 0; j <= 99; j++){
                    int sum = i + j;
                    int result = sum * sum;
                    int expect = 100 * i + j;

                    if(result == expect){
                        char i_chr[2];
                        char j_chr[2];
                      
                        i_chr[0] = i / 10 + '0';
                        i_chr[1] = i % 10 + '0';
                        j_chr[0] = j / 10 + '0';
                        j_chr[1] = j % 10 + '0';
                        cout << i_chr[0] << i_chr[1] << j_chr[0] << j_chr[1] << "\n";
                    }
                }
            }
        }

        if(number == 6){
            for (int i = 0; i <= 999; i++){
                for (int j = 0; j <= 999; j++){
                    int sum = i + j;
                    int result = sum * sum;
                    int expect = 1000 * i + j;

                    if(result == expect){
                        char i_chr[3];
                        char j_chr[3];
                      
                        i_chr[0] = i / 100 + '0';
                        i_chr[1] = (i % 100) / 10 + '0';
                        i_chr[2] = i % 10 + '0';
                        j_chr[0] = j / 100 + '0';
                        j_chr[1] = (j % 100) / 10 + '0';
                        j_chr[2] = j % 10 + '0';
                        cout << i_chr[0] << i_chr[1] << i_chr[2] << j_chr[0] << j_chr[1] << j_chr[2]<< "\n";
                    }
                }
            }
        }

        if(number == 8){
            for (int i = 0; i <= 9999; i++){
                for (int j = 0; j <= 9999; j++){
                    int sum = i + j;
                    int result = sum * sum;
                    int expect = 10000 * i + j;
                    if(result == expect){
                        char i_chr[4];
                        char j_chr[4];
                      
                        i_chr[0] = i / 1000 + '0';
                        i_chr[1] = (i % 1000) / 100 + '0';
                        i_chr[2] = (i % 100) / 10 + '0';
                        i_chr[3] = i % 10 + '0';

                        j_chr[0] = j / 1000 + '0';
                        j_chr[1] = (j % 1000) / 100 + '0';
                        j_chr[2] = (j % 100) / 10 + '0';
                        j_chr[3] = j % 10 + '0';
                        cout << i_chr[0] << i_chr[1] << i_chr[2] << i_chr[3] << j_chr[0] << j_chr[1] << j_chr[2] << j_chr[3]<< "\n";
                    }
                }
            }
        }

    }
    return 0;
}