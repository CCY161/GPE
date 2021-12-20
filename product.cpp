#include <iostream>
#include <string>

using namespace std;

int main(){
    string x, y;
    while(cin >> x){
        cin >> y;
        int temp [501];

        for(int k = 0 ; k < 501 ; k++){
            temp[k] = 0;
        }

        int i = 0,  j= 0;
        for (std::string::reverse_iterator xit=x.rbegin(); xit!=x.rend(); ++xit){
            j= 0;
            for (std::string::reverse_iterator yit=y.rbegin(); yit!=y.rend(); ++yit){
                char x1 = *xit;
                char y1 = *yit;
                int x2 = x1 - '0';
                int y2 = y1 - '0';        

                temp[i+j] += x2 * y2;
                j++;
            }
            i++;
        }

        int carry = 0;
        for(int k = 0 ; k < i+j ; k++){
            temp[k]+=carry;
            if(temp[k] > 9){
                carry = temp[k] / 10;
                temp[k] = temp[k] % 10;
            }
            else carry = 0;
        }
       
        bool first = false;
        for(int k = i+j-1 ; k >= 0 ; k--){
            if(temp[k] != 0)
                first = true;
            if(first)
                cout << temp[k];
        }
        cout << "\n";
    }

    return 0;
}