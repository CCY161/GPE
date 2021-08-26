#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int test_num;
    cin >> test_num;

    for(int i = 0 ; i < test_num ; i++){
        int M, N, Q;
        cin >> M >> N >> Q;
        cout << M << N << Q;
        vector<vector<char> > grid (M, vector<char> (N, '0'));
        
        for(int j = 0 ; j < M ; j++){
            for(int k = 0 ; k < N ; k++){
                char c;
                c = getchar();
                grid[j][k] = c;
            }
        }

        vector<pair<int, int> > center;
        for(int i = 0 ; i < Q ; i++){
            int x, y;
            cin >> x >> y;
            int times;
            times = min(x, y);
            for(int j = 1 ; j < times < j++){
                char center_c = grid[x][y]; 
                if(center_c == grid[x-j][y-j] && center_c == grid[x][y-j]   && center_c == grid[x+j][y-j] && center_c == grid[x-j][y]
                && center_c == grid[x+j][y]   && center_c == grid[x-j][y+j] && center_c == grid[x][y+j]   && center_c == grid[x+j][y+j])
                
                
            }
        }


    }

    return 0;
}