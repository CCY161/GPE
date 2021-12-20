#include <iostream>
#include <string>
using namespace std;

int main(){
    string seq;
    while(cin >> seq && seq != "."){
        cout << seq.size() << "\n";
        if(seq.size()==1)
            cout << "1\n";
        else{
            for(long long int i = 1 ; i < seq.size() ; i++){
                bool finish = true;
                for(long long int j = 0 ; j < seq.size()-i ; j++){
                    if(seq[j] != seq[j+i]){
                        finish = false;
                        break;
                    }
                }
                if(finish){
                    long long int result = seq.size()/i;
                    cout << result << "\n";
                    break;
                }
                else if(i == seq.size()-1)
                    cout << "1\n";
            }
        }
    }   

    return 0;
}