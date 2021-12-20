#include<iostream>
#include<list>
#include<climits>

using namespace std;

#define VILLAGE_NUM 6

int main(){
	int village_no_1;
	int village_no_2;
	int input_distance;
	int distance;
	int max = 0;
	list<list<int> > table(VILLAGE_NUM, list<int>(VILLAGE_NUM, 0));
		

	while(cin >> village_no_1 >> village_no_2 >> input_distance){
		table[village_no_1-1][village_no_2-1]= input_distance;
		table[village_no_2-1][village_no_1-1]= input_distance;
	}

	for(int i = 0 ; i < VILLAGE_NUM ; i++){
		for(int j = 0 ; j < VILLAGE_NUM ; j++){
			if(i != j)	
				table[i][j] = INT_MAX;
			else
				table[i][j] = 0;
		}
	}

	for(int i = 0 ; i < VILLAGE_NUM ; i++){
		for(int j = 0 ; j < VILLAGE_NUM ; j++){
			for(int k = 0 ; k < VILLAGE_NUM ; k++){

				if(i != j && i != k && j != k && table[j][i] != INT_MAX && table[i][k] != INT_MAX){
					distance = table[j][i] + table[i][k];
					if(distance < table[j][k]){
						table[j][k] = distance;
						cout << "[" << j << "]" << "[" << k << "]: " << distance << "\n"; 
					}
					if(table[j][k] > max){
						max = table[j][k];
					}

				}
			}
		}
	
	}
	cout << max << "\n";

	return 0;

}
