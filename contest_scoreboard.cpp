#include<iostream>
#include<sstream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct team{
    bool involve;
    int num;
    int problem;
    int score;
    int state[10];
};

bool comp(team a, team b){
    if(a.problem != b.problem) return a.problem > b.problem;
    if(a.score   != b.score)   return a.score   < b.score;
    if(a.num != b.num)         return a.num < b.num;
    return false;
}

int main(){
    int test;
    cin >> test;
    getchar();
    getchar();
    for(int i = 0 ; i < test ; i++){
        if(i) cout << "\n";
        team man[101];
        string line;

        for(int j = 0 ; j < 101 ; j++){
            man[j].num= j;
            man[j].involve = false;
            man[j].problem = 0;
            man[j].score  = 0;
            for(int k=0;k<10;k++){
                man[j].state[k]=0;
            }
        }    

        while(getline(cin ,line) && line != ""){

            stringstream ss;
            int number, problem, score;
            char alpa;
            ss << line;
            ss >> number >> problem >> score >> alpa;
            ss.clear();
            
            //cout << number <<" "<< problem <<" "<< score <<" "<< alpa  << "\n";
            
            man[number].involve = true;
            if(man[number].state[problem]==-1) continue;

            if(alpa=='C'){
                man[number].problem++;
                man[number].score += (score + man[number].state[problem]*20);
                man[number].state[problem]= -1;
            }

            else if(alpa=='I'){
                man[number].state[problem]++;
            }
            //cout << man[number].problem <<" "<< man[number].score <<" "<< number << " " << man[number].state[problem] << "12345\n";
        }

        sort( man, man+101 , comp );

        for(int j = 0 ; j < 101 ; j++){
            if(man[j].involve)
                cout << man[j].num << " " << man[j].problem << " " << man[j].score << "\n";
        }
        

    }

    return 0;
}