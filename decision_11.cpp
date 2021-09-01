#include<iostream>
#include<string>

int main(){
	std::string input;

	while(std::cin >> input){
		int odd_num = 0;
		int even_num = 0;

		if(input == "0")
			break;
		else{
			for(int i = 0 ; i < input.length() ; i++){		
				if(i % 2 == 0)
					even_num += input[i] - '0';
				else
					odd_num += input[i] - '0';
			}
			if((even_num - odd_num) % 11 == 0)	
				std::cout << input << " is a multiple of 11.\n" ;
			else
				std::cout << input << " is not a multiple of 11.\n" ;
		}	
	}

	return 0;
}
