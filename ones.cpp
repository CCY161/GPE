#include<iostream>
#include<vector>

using namespace std;

int main(){
	int input;
	/*vector<int> table(10001, 0);

	for(int j = 1 ; j < 10001 ; j++){
		bool not_exist = true;
		long long int ones = 1;
		

		for(int i = 1 ; i < 64 ; i++){
			if((j % 2 == 0) || (j % 5 == 0)){
				break;
			
			}
			else if((j <= ones)){
				not_exist = false;
				table[j] = i;
				cout << j << " " << i << "\n";
				break;
			}
			ones = ones * 10 + 1;
			//cout << "ones :" << ones;
		}
		if(not_exist){
			table[j] = 0;
			//cout << 0 << "\n";
		}
		//cout << "n = " << j << " times " << table[j]<< "\n";
	}*/
	
	while(cin >> input){
		long long int ones = 1;
		int i = 1;
		int reminder;
		if(input % 2 == 0 || input % 5 == 0){
			i = 0;
		}
		else{
			while(((ones % input) != 0)){
				reminder = ones % input;
				ones = reminder * 10 + 1;
				i++;
			}
		}
		cout << i << "\n";


		//cout << table[input] << "\n";
	}

	return 0;
}
