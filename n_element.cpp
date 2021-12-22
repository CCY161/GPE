#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int test;
    cin >> test;

    for(int i = 0 ; i < test ; i++){
        long long int p, q, r;
        long long int x, y, z;
        long long int n, n_q = 0;
        long long int s1 = 0, s2 = 0;
        long long int n1 = 0, n2 = 0;

        cin >> p >> q >> r;
        cin >> x >> y >> z;
        cin >> n;
        long long int a = 0, b = 0;

        while(n>=1){
            n_q = n;            
            if(n%2!=0)
                n_q++;   
            
            n_q/=2;
            n/=2;

            n1 = s1 + n_q -1;
            n2 = s2 + n_q -1;

            a = p * n1 * n1 + q * n1 + r;
            b = x * n2 * n2 + y * n2 + z;

            if(a < b){
                s1 = n1+1;
            }
            else{
                s2 = n2+1;
            }
        }       
        if(n1) n1= s1-1;
        if(n2) n2= s2-1;

        a = p * n1 * n1 + q * n1 + r;
        b = x * n2 * n2 + y * n2 + z;
        long long int result = a > b ? a : b;
        printf("%lld\n", result);
        //cout << (a > b ? a : b) << "\n";
    }

    return 0;
}