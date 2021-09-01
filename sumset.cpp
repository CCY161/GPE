#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

struct compose{
	int result;
	int member1;
	int member2;

	bool operator< (const struct compose src )
	{
		return this->result < src.result;
	}
};

typedef struct compose Compose;

int main(){
	int number;
	while(cin >>number){
		if(number == 0) break;
		vector<int> element;
		
		for(int i = 0 ; i < number ; i++){
			int value;
			cin >> value;
			element.push_back(value);			
		}

		vector<Compose> add_meme;
		
		vector<compose> add_member;
		vector<compose> sub_member;		
		
		for(int i = 0 ; i < number ; i++){
			for(int j = i + 1 ; j < number ; j++){
				compose add_tmp;
				compose sub_tmp;

				int add_result = element.at(i) + element.at(j);
				add_tmp.result = add_result;
				add_tmp.member1 = element[i];
				add_tmp.member2 = element[j];
				add_member.push_back(add_tmp);

				int sub_result = element.at(j) - element.at(i);
				sub_tmp.result = sub_result;
				sub_tmp.member1 = element[j];
				sub_tmp.member2 = element[i];
				sub_member.push_back(sub_tmp);
				
				sub_result = element.at(i) - element.at(j);
				sub_tmp.result = sub_result;
				sub_tmp.member1 = element[i];
				sub_tmp.member2 = element[j];
				sub_member.push_back(sub_tmp);
			}
		}

		bool exit = false;
		bool distinct = false; 
		int max_element = INT_MIN, current_max = 0;
		
		sort(add_member.begin(), add_member.end());		
		sort(sub_member.begin(), sub_member.end());		
	
		//cout << "add size: " << add_member.size() << "\n";
		//cout << "sub size: " << sub_member.size() << "\n";
	
		for(int i = add_member.size()-1 ; i >= 0 ; i--){
			for(int j = sub_member.size()-1 ; j >= 0 ; j--){
			
				if(add_member[i].result < sub_member[j].result) {
					sub_member.pop_back();
				}
				else if(add_member[i].result == sub_member[j].result) {	
					distinct = (add_member[i].member1 != sub_member[j].member1)
						    && (add_member[i].member1 != sub_member[j].member2)
					        && (add_member[i].member2 != sub_member[j].member1)
					        && (add_member[i].member2 != sub_member[j].member2);
					if(distinct){
						
						current_max = sub_member[j].member1;
						exit = true;
						
						if(current_max > max_element) 
							max_element = current_max;
					}
				}
				else {
					break;
				}
			}
		}
		
		if(exit) cout << max_element << "\n";
		else cout << "no solution\n";
	}
	return 0;
}
