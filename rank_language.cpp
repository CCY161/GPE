#include<iostream>
#include<map>
#include <cstdio>
using namespace std;

char world[21][21];
bool finish [22][22];

void dfs (int h, int w){
    finish[h][w]=1;
    if(world[h][w]==world[h-1][w] && !finish[h-1][w]) dfs(h-1, w);
    if(world[h][w]==world[h+1][w] && !finish[h+1][w]) dfs(h+1, w);
    if(world[h][w]==world[h][w-1] && !finish[h][w-1]) dfs(h, w-1);
    if(world[h][w]==world[h][w+1] && !finish[h][w+1]) dfs(h, w+1);
}

int main(){
    int test_num;
    cin >> test_num;

    for(int i = 1 ; i <= test_num ; i++){
        int height, width;
        cin >> height >> width;

        cout << "World #" << i << "\n";
        
        map<char, int> record;
        
        for(int j = 0 ; j < 22 ; j++){
            for(int k = 0 ; k < 22 ; k++){
                finish[j][k] = 0;
            }
        }

        for(int j = 1 ; j <= height ; j++){
            for(int k = 1 ; k <= width ; k++){
                char chr;
                cin >> chr;
                world[j][k] = chr;
                //cout << world[j][k];
            }
            //cout << "\n";
            getchar();
        }

        int max_res = 0;

        for(int j = 1 ; j <= height ; j++){
            for(int k = 1 ; k <= width ; k++){
               if(finish[j][k]==0) {
                    //cout << j << " " << k << " in\n"; 
                    dfs(j, k);
                    
                    if(record.find(world[j][k])==record.end())
                        record.insert(pair<char, int>(world[j][k], 1));
                    else
                        record[world[j][k]]++;
                    max_res = max(max_res, record[world[j][k]]);
               }
            }    
        }

        for(int j = max_res ; j >= 0 ; j--){
            for(map<char, int>::iterator it= record.begin() ;  it!=record.end() ; it++){
                if(it->second == j)
                    cout << it->first << ": " << it->second << "\n";
            }
        }
    }

    return 0;;
}