#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

class team{
	public: 
		string name;
		
//		team(){};
		
		team(string teamname): name(teamname)
		{
			   games = 0; wins = 0; ties = 0; losses = 0;
			   goal_score = 0; goal_against = 0;
		}
		
		void add_new_game ( int my_score, int other_score )
		{
			(this->games) ++;
			
			if ( my_score > other_score )
				(this->wins) ++;
			else if ( my_score == other_score )
				(this->ties) ++;
			else
				(this->losses) ++;
			
			(this->goal_score) += my_score;
			(this->goal_against) += other_score;
		}
		
		friend ostream& operator<<(ostream& os, const team& t)
		{
			// first -> goal_diff
			// second -> point
			pair<int, int> m_status = t.get_status();
			
			return os << t.name << " " 
						<< m_status.second << "p, " << t.games << "g (" << t.wins << "-" << t.ties << "-" << t.losses << "), " 
						<< m_status.first << "gd (" << t.goal_score << "-" << t.goal_against << ")"
						<< endl;			
		}
		
		bool operator< ( const team & cmp ) const
		{
			// first -> goal_diff
			// second -> point
			pair<int, int> m_status = this->get_status();
			pair<int, int> cmp_status = cmp.get_status();
			
			if(m_status.second != cmp_status.second)  return m_status.second > cmp_status.second;
			if(this->wins != cmp.wins) 			      return this->wins > cmp.wins;
			if(m_status.first != cmp_status.first)    return m_status.first > cmp_status.first;
			if(this->goal_score != cmp.goal_score)    return this->goal_score > cmp.goal_score;
			if(this->games != cmp.games) 			  return this->games > cmp.games;
			return name > cmp.name;
		}
			
	private: 
		int games, wins, ties, losses;
		int goal_score, goal_against;
		
		pair<int, int> get_status () const 
		{
			return pair<int, int> (this->goal_score - this->goal_against, this->wins * 3 + this->ties);			
		}
};

const team& get_second ( const pair<string, team>& src )
{
	return src.second;
}

int main(){
	
	int games;
	scanf("%d\n", &games);
	
	for(int i = 0 ; i < games ; i++){
		char tournament[101];
		
		scanf("%[^\n]\n", tournament);
		cout << tournament << endl;

		int team_num;
		scanf("%d\n", &team_num);
		
		map<string, team> teams;

		for(int j = 0 ; j < team_num ; ++j){
			
			char team_name_chr[32];
			scanf("%[^\n]\n", team_name_chr);
			
			string team_name(team_name_chr);
			teams.insert(pair<string, team> (team_name, team(team_name))); 
		}

		int game_num;
		scanf("%d\n", &game_num);

		for(int k = 0 ; k < game_num ; ++k){
			
			char front_team_chr[32], back_team_chr[32];
			int front_score, back_score;
			
			scanf("%[^#@]#%d@%d#%[^#@\n]\n", front_team_chr, &front_score, &back_score, back_team_chr);
			
			string front_team(front_team_chr), back_team(back_team_chr);
			
			teams.at(front_team).add_new_game ( front_score, back_score );
			teams.at(back_team).add_new_game ( back_score, front_score );		
		}
		
		//vector< team > sort_rank(teams.size());
		vector< team > sort_rank;
		back_insert_iterator< vector< team > > back_it ( sort_rank);
		
		transform(teams.begin(), teams.end(), back_it, get_second);
		sort(sort_rank.begin(), sort_rank.end());
		
		int number = 1;
		for(vector< team >::iterator iter = sort_rank.begin(); iter != sort_rank.end(); ++iter){
			cout << number << ") " << *iter;
			number++;
		}
		if(i != (games-1)) cout << "\n";
	}

	return 0;
}
