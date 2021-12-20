// #include<iostream>
// #include <iomanip>
// #include <cmath>
// using namespace std;

// int main(){

//     int student;
//     while(cin >> student && student){
//         int money [1001];

//         for(int i = 0 ; i < 1001 ; i++){
//             money[i]=0;
//         }

//         double input, temp;
//         int sum = 0;
//         double avg = 0;
//         for(int i = 0 ; i < student ; i++){
//             cin >> input;
//             temp = input * 100.00;
//             money[i] = temp;
//             //cout << input * 100.00 << " , " << money[i] << "\n";
//             sum += money[i];
//         }

//         avg = (double)sum / (double)student;
//         cout << sum << ",  avg : " << avg << "\n";
//         double diff1 = 0, diff2 = 0;
//         double result = 0;

//         for(int i = 0 ; i < student ; i++){
//             if(money[i] > avg)
//                 diff1 += floor(money[i]-avg);
//             else
//                 diff2 += floor(avg - money[i]);
//         }
//         if(diff1 < diff2)
//             result = diff1/100;
//         else
//             result = diff2/100;
//         //cout << diff1 << " " << diff2 << " ";
//         cout << "$" << fixed << setprecision(2) << result << "\n";
//     }

//     return 0;
// }

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int cost[1010];
int main()
{
     int n, avg, rem, ans, t1, t2;
     while(scanf("%d", &n) && n != 0)
     {
         ans = avg = 0;
         for(int i = 0; i < n; ++i) {
             scanf("%d.%d", &t1, &t2);
             cost[i] = t1 * 100 + t2;
             avg += cost[i];
         }
         rem = avg % n;
         avg /= n;
         sort(cost, cost + n, cmp);
         for(int i = 0; i < rem; ++i)
             ans += abs(cost[i] - (avg + 1));
         for(int i = rem; i < n; ++i)
             ans += abs(cost[i] - avg);
         printf("$%.2lf\n", ans / 200.0);
     }
     return 0;
 }