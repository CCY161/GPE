#include<iostream>
#include<vector>

using namespace std;

int main(){
	int input;
	vector<int> table(1001, 0);
		
	vector<int> factorial_num(3000, 0);
	factorial_num[0] = 1;
	int n = 0;
	
	table[0]=1;

	for(int i = 1; i <= 1000 ; i++){
		n = 0;
		for(int j = 0 ; j < 3000 ; j++){
			factorial_num[j] *= i;
		}
		for(int k = 0 ; k < 3000 ; k++){
			if(factorial_num[k] > 9){
				factorial_num[k+1] += factorial_num[k]/10;
				factorial_num[k] %= 10;
			}
			n += factorial_num[k];
		}
		table[i]= n;
	}

	while(cin >> input){
		cout << table[input] << "\n";
	}
	return 0;
}
