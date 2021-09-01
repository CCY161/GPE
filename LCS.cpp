#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>

using namespace std;

int main(){


	//char str1_chr[1001];
	//char str2_chr[1001];
	string str1;
	string str2;
	
	//while(scanf("%[^\n]\n%[^\n]\n", str1_chr, str2_chr) != EOF){
	while(getline(cin, str1)){
		getline(cin, str2);
		//string str1(str1_chr);
		//string str2(str2_chr);
		int row_size = str2.length();
		int col_size = str1.length();	
		vector<int> row(row_size+1, 0);
		vector<vector<int> > table(col_size+1, row);
		
	//	cout << str1 << "\n";
	//	cout << str2 << "\n";
		int i = 0, j = 0;
		
		for(string::iterator iter1 = str1.begin() ; iter1 != str1.end() ; iter1++){
			i++;
			j = 0;
	//		cout << "\n";
			for(string::iterator iter2 = str2.begin() ; iter2 != str2.end() ; iter2++){
				j++;
				
				if(*iter1==*iter2)	table[i][j] = table[i-1][j-1] + 1;
				else table[i][j] = max(table[i-1][j], table[i][j-1]);
	//			cout << "[" <<  i << " "  << j << "]:" << table[i][j]<< " "  ;
								
			}
		}
		cout << table[i][j] << "\n";

	}
	return 0;
}
