#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

class team{
	public:
			string name;
			int point, rank, games, wins, ties, losses;
			int goal_diff, goal_score, goal_against;
	
			team(string teamname){
				   name = teamname;
				   point = 0; rank = 0; games = 0; wins = 0; ties = 0; losses = 0;
				   goal_diff = 0; goal_score = 0; goal_against = 0;};
			int cal_diff();
			team(){};
};

int team::cal_diff(){
	return goal_score - goal_against;
}

bool compare(const pair<string, team> a, const pair<string, team> b){
	team first = a.second, next = b.second; 
	if(first.point != next.point) 			return first.point > next.point;
	if(first.wins != next.wins) 			return first.wins > next.wins;
	if(first.goal_diff != next.goal_diff) 	return first.goal_diff > next.goal_diff;
	if(first.goal_score != next.goal_score) return first.goal_score > next.goal_score;
	if(first.games != next.games) 			return first.games > next.games;
	return first.name > next.name;
}


int main(){
	int games;
	cin >> games;
	getchar();
	
	for(int i = 0 ; i < games ; i++){
		string tournament;
		getline(cin, tournament);
		cout << tournament << endl;

		int team_num;
		cin >> team_num;
		getchar();
		
		map<string, team> teams;

		for(int j = 0 ; j < team_num ; ++j){
			string team_name;
			getline(cin, team_name);
			//teams[team_name] = team(team_name);
			//teams.emplace(team_name, team(team_name));
			teams.insert(pair<string, team> (team_name, team(team_name))); 
		}


		int game_num;
		cin >> game_num;
		getchar();

		for(int k = 0 ; k < game_num ; ++k){
			string game;
			string front_team, back_team;
			string f_score, b_score;

			getline(cin, front_team, '#');
			getline(cin, f_score, '@');
			getline(cin, b_score, '#');
			getline(cin, back_team);
			
			int front_score = atoi(f_score.c_str());
			int back_score = atoi(b_score.c_str());

			teams[front_team].games += 1;
			teams[back_team].games += 1;
			
			if((front_score - back_score) > 0){
				teams[front_team].wins += 1;
				teams[back_team].losses+= 1;
			}
			else if(front_score == back_score){
				teams[front_team].ties += 1;
				teams[back_team].ties += 1;
			}
			else{
				teams[front_team].losses += 1;
				teams[back_team].wins += 1;
			}
			teams[front_team].goal_score += front_score;
			teams[front_team].goal_against += back_score;
			teams[back_team].goal_against += front_score;
			teams[back_team].goal_score += back_score;

			teams[front_team].goal_diff = teams[front_team].cal_diff();
			teams[back_team].goal_diff = teams[back_team].cal_diff();
			teams[front_team].point = teams[front_team].wins * 3 + teams[front_team].ties;
			teams[back_team].point = teams[back_team].wins * 3 + teams[back_team].ties;
		
		}
		
		vector<pair<string, team> > sort_rank;
		copy(teams.begin(), teams.end(), back_inserter(sort_rank));
		
		sort(sort_rank.begin(), sort_rank.end(), compare);

		int number = 1;
		for(vector<pair<string, team> >::iterator iter = sort_rank.begin();iter != sort_rank.end();++iter){
			cout << number << ") " << iter->second.name << " " << iter->second.point << "p, " << iter->second.games << "g (" << iter->second.wins << "-" << iter->second.ties << "-" << iter->second.losses << "), " << iter->second.goal_diff << "gd (" << iter->second.goal_score << "-" << iter->second.goal_against << ")"<< endl;
			number++;
		}
		teams.clear();
		if(i != (games-1)) cout << "\n";
	}

	return 0;
}
