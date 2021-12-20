#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string seq;
    int length;
    while(cin >> seq >> length){
    //cout << seq << " " << length << "\n";
        stack<int> num;
        stack<char> op;

        bool is_neg = false;
        int round =0;
        for(int i = 0 ; i < seq.size() ; i++){
            if(seq[i]=='+' || seq[i]=='*'){
                op.push(seq[i]);
                is_neg = false;
            }
            else if(seq[i]=='-'){
                is_neg = true;
            }
            else if(seq[i]!='[' && seq[i] !=']'){
                round++;
                char c = seq[i];
                int value = c -'0';
                if(is_neg){
                    value = -1 * value;
                }
                //cout << "value : " << value << "\n";
                num.push(value);
                is_neg = false;
            }
        }        

        long long int v[51], s[51];
        int data = num.top();
        num.pop();

        for(int i = 0 ; i < length ;i++){
            v[i]=data;
            s[i]=data;
            //cout << v[i] << " ";
        }
        //cout <<"\n";

        for(int i = round-1 ; i > 0 ;i--){
            int oper = op.top();
            data = num.top();
            op.pop();
            num.pop();

            for(int j = 0 ; j < length ;j++){
                if(oper=='+'){
                    if(j==0)
                        v[j]=data;
                    else
                        v[j]= v[j-1]+s[j-1];
                }
                else{
                    if(j==0)
                        v[j]=data*s[0];
                    else{
                        v[j]=v[j-1]*s[j];
                    }
                }
                //cout << v[j] << " ";
            }
            //cout <<"\n";
            for(int j = 0 ; j < length ; j++)
                s[j]=v[j];            
        }

        cout << v[0];
        for(int i = 1 ; i < length ;i++){
            cout << " " << v[i];
        }

        cout << "\n";
    }

    return 0;
}