#include <iostream>
#include<cmath>
using namespace std;

int prime[50000];
int pnum = 0;

int gcd(int n, int m){ 
    while(n%=m)
        swap(n, m);
    return m;
}

void primefilter(){
    prime[pnum++]=2;
    
    for(int i = 3 ; i < sqrt(50000) ; i+=2){

        for(int j = i * i ; j < 50000 ; j+=2*i){
            
        }
    }
}

int main (){
    int num;
    while(cin >> num && num!=0){
        int irreducible=0;
        for(int i = 1 ; i <= num ; i++){
            if(gcd(i, num)==1)
                irreducible++;
        }

        cout << irreducible << "\n";
    }

    return 0;
}