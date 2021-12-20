#include<iostream>
#include<queue>

using namespace std;

int main(){
    int region;
    while(cin >> region && region){
        //cout << region << "\n";
        if(region==13)
            cout << 1 << "\n";
        else{
            for(int i = 2 ; ;i++){
                queue<int> area;
                int cnt = 1;
                for(int j = 1 ; j <= region ; j++){
                    area.push(j);
                    //cout << j << "\n";
                } 
    
                while(area.size()!=1){
                    int first = area.front();
                    //if(i==5)
                    //    cout << i << " : " << first << "\n";
                    area.pop();
    
                    if(cnt % i != 1)
                        area.push(first);
                    cnt++;
                }
    
                if(area.front()==13){
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
        

    return 0;
}