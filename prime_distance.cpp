#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>

using namespace std;

int pnum = 0;
int chkp[46341], prime[5000];

void pfilter1(){
    prime[pnum++]=2;
    int sqrtmax=sqrt(46341);

    for(int i = 3 ; i < sqrtmax ; i+=2){
        if(chkp[i-1]==0)
            prime[pnum++]=i;
        for(int j = i * i ; j < 46341 ; j+=2*i)
            chkp[j-1]=1;
    }

    for(int i = sqrtmax ; i < 46341 ; i+=2)
        if(chkp[i-1]==0)
            prime[pnum++]=i;
}

int pfilter2(int n){
    if(n < 46341)
        return chkp[n-1];
    for(int i = 0 ; i < pnum && i*i<=n ; i++){
        if(n%prime[i]==0)
            return 1;
    }
    return 0;
}

int main(){
    pfilter1();
    long long int l = 0, u = 0;
    while(cin >> l >> u){
        //cout << "111111111111111111111\n";
        long long int a1=0, a2=0, b1=0, b2=0; 
        long long int max=0, min = 46342;
        long long int temp[100000];
        long long int i = 0, j =0;
        //cout << "111111111111111111111\n";
        if(l<=2){
            temp[j++]=2;
            l=3;
        }
        else if(l%2==0)
            l++;

        for(i = l; i<=u ;i+=2){
            if(!pfilter2(i))
                temp[j++]=i;
        }

        //cout << " temp :  " << temp[0]  << " and " << temp[1] << "\n" ;

        for(i = 1 ; i < j ; i++){
            long long int interval = temp[i]-temp[i-1];
            
            if(interval < min){
                min = interval;
                a1 = temp[i-1];
                a2 = temp[i];
            }
            if(interval > max){
                max = interval;
                b1 = temp[i-1];
                b2 = temp[i];
            }
        }

        if(max==0)
            printf("There are no adjacent primes.\n");
        else
            cout << a1 << "," << a2 <<" are closest, "<< b1 << "," << b2 <<" are most distant.\n";
    }

    return 0;
}













// int prime_table[5000];
// bool checkprime[46341];

// int main(){
    
//     int max = 46341;
//     int pnum = 0;
//     prime_table[pnum++] = 2;

//     int gap = sqrt(max);
//     //cout << "prime table done\n";
//     for(int i = 3 ; i < sqrt(max) ; i+=2){
//         if(checkprime[i-1]==0)
//             prime_table[pnum++]=i;
//         for(int j = i * i ; j < max ; j += 2 * i){
//             //prime_table[j-1] = 1;
//             checkprime[j-1] = 1;
//         }
//     }    
//     //cout << "prime table done\n";
//     for(int i = gap ; i < 46341 ; i+=2){
//         if(checkprime[i-1]==0)
//             prime_table[pnum++]=i;
//     }
   
//     unsigned int n1 = 0, n2 = 0;
//     while(cin >> n1 >> n2){
//         //cout << n1 << " " << n2 << "\n";
//         long int min_interval = INT_MAX;
//         long int max_interval = 0;
//         long int min1=0, min2=0;
//         long int max1=0, max2=0;
//         vector <long int> primes;
//         if(n1 <=2){
//             primes.push_back(2);
//             n1 =3;
//         }
//         else if(n1%2==0) n1++;

//         //cout << n1 << "\n";

//         for(long int i = n1 ; i <= n2 ; i+=2){
//             if(i > 46340){
//                 bool is_prime = true;
//                 for(long int j = 0 ; j < pnum && j*j < i; j++){
//                     if(i % prime_table[j]){
//                         is_prime = false;
//                         break;
//                     }
//                 }
//                 if(is_prime)
//                     primes.push_back(i);
//             }
//             else{
//                 if(checkprime[i-1]==0){
//                     primes.push_back(i);
//                 }
//             }
            
//         }
//         //cout << "size : " << primes.size() << "\n";

//         if(primes.size() < 2)
//             cout << "There are no adjacent primes.\n";

//         else{ 
//             for(long int i = 1 ; i < primes.size() ; i++){
//                 int interval = primes[i]-primes[i-1];
//                 if(min_interval > interval){
//                     min1 = primes[i-1];
//                     min2 = primes[i];
//                     min_interval = interval;
//                 }
//                 if(max_interval <interval){
//                     max1 = primes[i-1];
//                     max2 = primes[i];
//                     max_interval = interval;
//                 }
//             }
//             cout << min1 << "," << min2 <<" are closest, "<< max1 << "," << max2 <<" are most distant.\n";
//         }

//     }

//     return 0;
// }