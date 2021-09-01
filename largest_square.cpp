#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    int test_num;
    cin >> test_num;

    for(int i = 0 ; i < test_num ; i++){
        int M, N, Q;
        cin >> M >> N >> Q;
        cout << M << " " << N << " "<< Q << "\n";
        vector<vector<char> > grid (M, vector<char> (N, '0'));
        getchar();

        for(int j = 0 ; j < M ; j++){
            for(int k = 0 ; k < N ; k++){
                char c;
                c = getchar();
                if(k ==N-1) getchar();
                //cout << grid[k][j] << " ";
                grid[j][k] = c;
                //cout << j << " " << k << " "<< grid[j][k] << " ";
            }
            //cout <<"\n";
        }

        vector<pair<int, int> > center;

        for(int i = 0 ; i < Q ; i++){
            int y, x;
            cin >> y >> x;
            //cout << y << " " << x << "\n";
            int times;
            int boundary_ru = 0, boundary_ld = 0;
            boundary_ru = min(x, y);
            boundary_ld = min(M - y - 1, N - x - 1);
            times = min(boundary_ru, boundary_ld);
            bool is_rect = true;
            char center_c = grid[y][x];

            //cout << "center : " << center_c << "\n";

            for(int j = times ; j > 0 ; j--){
                is_rect = true;
                for(int k = y - j ; k <= y + j ; k++){
                    for(int l = x - j  ; l <= x + j ; l++){
                        //cout << k << " " << l << " "<< grid[k][l] << " ";
                        //cout << grid[k][l] << " ";
                        if(center_c != grid[k][l]){
                            is_rect = false;
                        }
                    }
                    //cout << "\n";
                }
                if(is_rect){
                    cout << 2 * j + 1 << "\n";
                    break;
                } 
            }
            if(!is_rect || times == 0) cout << 1 << "\n";
        }
    }
    return 0;
}