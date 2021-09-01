#include<iostream>
#include<vector>
#include<cmath>

int mod_fibonacci(long int n, const int m){
	
	int fn_minus_1 = 1;
	int fn_minus_2 = 1;
	int sum = 0;
	
	int number;

	number = 3 * pow(2, (m-1));
	n = n % number;

	if(n == 1 || n == 2)
		return fn_minus_1;
	else{
		for(int i = 2; i < n ; i++){
			sum = fn_minus_1 + fn_minus_2;
			sum = sum & ((1 << m) - 1);
				
			fn_minus_1 = fn_minus_2;
			fn_minus_2 = sum;

		}
		return sum; 
	}

}

int main(){
	long int input_n;
	int input_m;

	while(std::cin >> input_n >> input_m ){
		std::cout << mod_fibonacci(input_n, input_m) << "\n";
	}

	return 0;

}
