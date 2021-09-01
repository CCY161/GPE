#include<iostream>
#include<vector>
#include<string>

int main(){
	int case_number = 0;
	int inst_num = 0;
	int position = 0;
	int location = 0;
	std::string current_inst;
	std::vector<bool> inst; 

	std::cin >> case_number;
	
	for(int i = 0 ; i < case_number ; i++){
		std::cin >> inst_num;
		position = 0;	
		inst.clear();

		for(int j = 0 ; j < inst_num ; j++){
			std::cin >> current_inst;

			if(current_inst=="RIGHT"){
				position++;
				inst.push_back(1);
			}
			else if(current_inst == "LEFT"){
				position--;
				inst.push_back(0);
			}
			else{
				std::cin >> current_inst >> location;
				if(inst[location-1]){
					position++;
					inst.push_back(1);
				}
				else{
					position--;
					inst.push_back(0);
				}

			}
		
		}
		std::cout << position << "\n";
	}
	return 0;
}
