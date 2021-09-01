#include<iostream>
#include<vector>

std::vector<int> fibonacci(const int num){
	std::vector<int> a(1000,0);
	std::vector<int> b(1000,0);
	std::vector<int> sum(1000,0);
	int tmp = 0;
	int carry = 0;
	a[0] = 1;
	b[0] = 1;
	
	if(num == 1 || num == 2)
		return a;
	else{
		for(int i = 2 ; i < num ; i++){
			for(int j = 0 ; j < 1000 ; j++){
				tmp = carry + a[j] + b[j];
				if(tmp != 0){
					carry = tmp / 10;
					sum[j] = tmp % 10;
				}
				
			}
			a = b;
			b = sum;
		}
		return sum;
	}
}


int main(){
	int input;

	while(std::cin >> input){
		bool out_flag = 0;
		std::vector<int> result(1000, 0);
		result = fibonacci(input);
		
		for(int i = 999 ; i >= 0 ; i--){
			if(result[i] != 0)
				out_flag = 1;	
			if(out_flag)
				std::cout << result[i];
		}
		std::cout<< "\n";
	}
	return 0;
}
