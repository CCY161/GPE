#include <iostream>

using namespace std;

char maze [12][12];
bool finish [12][12];
//bool is_find;
bool bfs(int n, int m){

    finish[n][m]=true;
    bool  a=false, b=false, c=false, d=false;

    if(maze[n][m]=='G'){
        maze[n][m]='+';
        return true;
    }

    // if(finish[n+1][m] && finish[n-1][m] && finish[n][m+1] && finish[n][m-1])
    //     return false;

    if(!finish[n+1][m]) a=bfs(n+1, m);
    if(!finish[n-1][m]) b=bfs(n-1, m);
    if(!finish[n][m+1]) c=bfs(n, m+1);
    if(!finish[n][m-1]) d=bfs(n, m-1);

    if(a||b||c||d){
        maze[n][m]='+';
        return true;
    }
    else 
        return false;
}


int main(){

    int x = 0, y = 0;
    //is_find = false;
        
    for(int j = 0 ; j < 12 ; j++){
        finish[0][j]=true;
        finish[11][j]=true;
    }       

    for(int j = 0 ; j < 12 ; j++){
        finish[j][0]=true;
        finish[j][11]=true;
    }  

    for(int i = 1 ; i < 11 ; i++){
        for(int j = 1 ; j < 11 ; j++){
            cin >> maze[i][j];
            //finish[i][j]=false;
            if(maze[i][j]=='S'){
                x = i;
                y = j;
            }
            if(maze[i][j]=='#')
                finish[i][j]=true;
            else
                finish[i][j]=false;
        }       
    }
    
    bool is_find = bfs(x, y);

    // for(int i = 1 ; i < 11 ; i++){
    //     for(int j = 1 ; j < 11 ; j++){
    //         cout << finish[i][j];
    //     }
    //     cout << "\n";       
    // }

    if(is_find){
        for(int i = 1 ; i < 11 ; i++){
            for(int j = 1 ; j < 11 ; j++){
                cout << maze[i][j];
            }
            cout << "\n";       
        }
    }
    else cout << "No solution\n";
    return 0;
}