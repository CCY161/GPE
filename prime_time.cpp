#include <iostream>
#include <iomanip>
using namespace std;

int prime(int n){
    if(n==2)
        return 1;
    else if(n%2==0){
        return 0;
    }
    else{
        for(int i = 3 ; i * i <=n ; i+=2){
            if(n%i==0)
                return 0;
        }
        return 1;
    }

}

int main(){
    int l, u;
    while(cin >>l >> u){
        int pnum = 0;
        for(int i = l ; i <= u ; i++){
            int func = i * i + i + 41;
            if(prime(func))
                pnum++;
        }
        //cout << pnum << " and " << u-l+1 << "\n";
        double result = (double)pnum*100 / (double)(u-l+1)  + 0.000001;

        cout << fixed << setprecision(2) << result << "\n";

    }

    return 0;
}