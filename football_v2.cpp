#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<regex>
#include<algorithm>

using namespace std;

int main(){
	int games;
	cin >> games;
	getchar();
	
	for(int i = 0 ; i < games ; ++i){
		string tournament;
		getline(cin, tournament);
		cout << tournament << endl;

		int team_num;
		cin >> team_num;
		getchar();
		map<string, vector<int> > teams;
		vector<int> init(7, 0);
		for(int j = 0 ; j < team_num ; ++j){
			string team;
			getline(cin, team); 
			teams.insert(pair<string, vector<int> >(team, init));
		}

		int game_num;
		cin >> game_num;
		getchar();

		for(int k = 0 ; k < game_num ; ++k){
			string game;
			getline(cin, game);

			regex reg("@");
			smatch sm;
			
			regex_search(game, sm , reg);
			
			regex reg1("#");
			smatch sm1;
			smatch sm2;
			//cout << sm.prefix() << " and " << sm.suffix() << "\n";
			string front = sm.prefix(); 
			regex_search(front, sm1, reg1);
			string back = sm.suffix();
			regex_search(back, sm2, reg1);
			
			//cout << sm1.prefix() << " get " << sm1.suffix() << "\n";
			//cout << sm2.suffix() << " get " << sm2.prefix() << "\n";

			string front_team = sm1.prefix();
			string back_team  = sm2.suffix();
			string front_score = sm1.suffix();
			string back_score  = sm2.prefix();

			teams[front_team][1] += 1;
			teams[back_team][1] += 1;
			
			//cout << "first_team:" << teams[front_team] << "\n";
			//cout << "second_team:" << teams[back_team]  << "\n";
			if((stoi(front_score) - stoi(back_score)) > 0){
				teams[front_team][0] += 3;
				teams[front_team][2] += 1;
				teams[back_team][4] += 1;
			}
			else if(stoi(front_score) == stoi(back_score)){
				teams[front_team][0] += 1;
				teams[back_team][0] += 1;
				teams[front_team][3] += 1;
				teams[back_team][3] += 1;
			}
			else{
				teams[back_team][0]+=3;
				teams[front_team][4] += 1;
				teams[back_team][2] += 1;
			}
			teams[front_team][5] += stoi(front_score);
			teams[front_team][6] += stoi(back_score);
			teams[back_team][6] += stoi(front_score);
			teams[back_team][5] += stoi(back_score);
		}
	
		sort(teams->second.begin(), teams->second.end(), [](vector<int> a, vector<int> b){return a[0] > b[0];});
		
		for(map<string, vector<int> >::iterator iter = teams.begin();iter != teams.end();++iter){
			cout << iter->first << " " << iter->second[0] << "p, " << iter->second[1] << "g (" << iter->second[2] << "-" << iter->second[3] << "-" << iter->second[4] << "), " << iter->second[5]-iter->second[6] << "gd (" << iter->second[5] << "-" << iter->second[6] << ")" << endl;
		}
		teams.clear();
	}

	return 0;
}
