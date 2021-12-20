#include <iostream>
#include <string>
using namespace std;

int main(){
    int number;
    string dir;
    while(cin >> number && number){
        int num[6]={1, 2, 3, 5, 4, 6};
        int temp[6];
        for(int i = 0 ; i < number ; i++){
            cin >> dir;
            if(dir =="north"){
                temp[0]= num[3];
                temp[1]= num[0];
                temp[2]= num[2];
                temp[3]= num[5];
                temp[4]= num[4];
                temp[5]= num[1];
            }
            else if(dir =="east"){
                temp[0]= num[2];
                temp[1]= num[1];
                temp[2]= num[5];
                temp[3]= num[3];
                temp[4]= num[0];
                temp[5]= num[4];
            }
            else if(dir =="west"){
                temp[0]= num[4];
                temp[1]= num[1];
                temp[2]= num[0];
                temp[3]= num[3];
                temp[4]= num[5];
                temp[5]= num[2];
            }
            else{
                temp[0]= num[1];
                temp[1]= num[5];
                temp[2]= num[2];
                temp[3]= num[0];
                temp[4]= num[4];
                temp[5]= num[3];
            }
            for(int j = 0 ; j < 6 ; j++){
                num[j] = temp[j];
            }
        }
        cout << num[0] << "\n";
    }


    return 0;
}