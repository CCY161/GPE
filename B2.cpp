#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
	
	int number;
	int i = 1;

	while(cin >> number){
		vector<int>	seq1;
		set<int> sum;
		bool ans = true;

		for(int i = 0 ; i < number ; i++){
			int value;
			cin >> value;
			seq1.push_back(value);
		}
		for(vector<int>::iterator iter1 = seq1.begin() ; iter1 != seq1.end() ; iter1++ ){
			for(vector<int>::reverse_iterator iter2 = seq1.rbegin(); (iter2 != seq1.rend()) && (*iter1 <=  *iter2) ; iter2++){
				int result = *iter1 + *iter2;

				if(sum.find(result) != sum.end()){
					ans = false;
					break;
				}
				else	sum.insert(result);
			}
			if(!ans) break;
		}
		if(ans) cout << "Case #" << i <<": It is a B2-Sequence.\n";
		else    cout << "Case #" << i <<": It is not a B2-Sequence.\n";
		i++;
		cout << "\n";
	}
	return 0;
}
