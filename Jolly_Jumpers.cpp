#include<iostream>
#include<cstdlib>
#include<set>
#include<cstdio>

using namespace std;

int main(){
	int sequence_num = 0;
	int input;
	int front_num;
	bool is_failed = false;
	int diff;
	int count;

	while(scanf("%d", &sequence_num) != EOF){
		set<int> checked;
		
		is_failed = false;

		scanf("%d", &front_num);

		
		for(count = 0 ; count < sequence_num-1; count ++){
			scanf("%d", &input);
			diff = abs(front_num - input);
			

			if (diff <= sequence_num-1 && checked.find(diff) == checked.end())
			{
				checked.insert(diff);
			}
			else
			{
				is_failed = true;
				break;
			}
	
			front_num = input;
		}

	
		if ( is_failed || ( checked.size() < sequence_num -1) )
		{
			if(count < sequence_num-2)
			{
				scanf("%*[^\n]");
				//scanf("%d", &input);
				//count++;
			}
			cout << "Not jolly";
		}
		else
		{
			cout << "Jolly";
		}
		cout << "\n";
	}
	return 0;
}
