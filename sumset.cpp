#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct add_compose{
	public:	int add_result;
			int member1;
			int member2;
};

struct sub_compose{
	public:	int sub_result;
			int member1;
			int member2;
};

bool sort_add(const add_compose a, const add_compose b){
	return a.add_result < b.add_result;
}

bool sort_sub(const sub_compose a, const sub_compose b){
	return a.sub_result < b.sub_result;
}

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
		
		sort(element.begin(), element.end());
		
		vector<add_compose> add_member;
		vector<sub_compose> sub_member;		
		add_compose add_tmp;
		sub_compose sub_tmp;

		for(int i = 0 ; i < number-1 ; i++){
			for(int j = i + 1 ; j < number ; j++){
				int add_result = element.at(i) + element.at(j);
				add_tmp.add_result = add_result;
				add_tmp.member1 = element[i];
				add_tmp.member2 = element[j];
				add_member.push_back(add_tmp);

				int sub_result = element.at(j) - element.at(i);
				sub_tmp.sub_result = sub_result;
				sub_tmp.member1 = element[j];
				sub_tmp.member2 = element[i];
				sub_member.push_back(sub_tmp);
				
				sub_result = element.at(i) - element.at(j);
				sub_tmp.sub_result = sub_result;
				sub_tmp.member1 = element[i];
				sub_tmp.member2 = element[j];
				sub_member.push_back(sub_tmp);
			}
		}

		bool exit = false;
		bool distinct = false; 
		int max_element;
		
		sort(add_member.begin(), add_member.end(), sort_add);		
		sort(sub_member.begin(), sub_member.end(), sort_sub);		
	
		//cout << "add size: " << add_member.size() << "\n";
		//cout << "sub size: " << sub_member.size() << "\n";
	
		for(int i = add_member.size()-1 ; i >= 0 ; i--){
			for(int j = sub_member.size() -1 ; j >= 0 ; j--){
			//	cout << add_member[i].add_result << " " << add_member[i].member1 << " " << add_member[i].member2 << "\n";
			//	cout << sub_member[j].sub_result << " " << sub_member[j].member1 << " " << sub_member[j].member2 << "\n";
				//cout << "here";
				if(add_member[i].add_result < sub_member[j]. sub_result) 
					sub_member.pop_back();
				else if(add_member[i].add_result == sub_member[j].sub_result){	
					distinct = (add_member[i].member1 != sub_member[j].member1)
						    && (add_member[i].member1 != sub_member[j].member2)
					        && (add_member[i].member2 != sub_member[j].member1)
					        && (add_member[i].member2 != sub_member[j].member2);
					if(distinct){
						exit = true;
						vector<int> sort_element;
						sort_element.push_back(add_member[i].member1);		
						sort_element.push_back(add_member[i].member2);		
						sort_element.push_back(sub_member[j].member1);		
						sort_element.push_back(sub_member[j].member2);		
						sort(sort_element.begin(), sort_element.end());
						
						if(sort_element[3] < 0 ) max_element = sort_element[0];
						else max_element =sort_element[3];
					   // max_element = max(add_member[i].member2, sub_member[j].member2);
					    max_element = sub_member[j].member1;
						break;
					}
				}
			}
			if(exit) break;
		}
		
		if(exit) cout << max_element << "\n";
		else cout << "no solution\n";
	}
	return 0;
}
