#include<iostream>

using namespace std;

int main(){
	int input;

	while(cin >> input && input != 0){
		cout << "f91(" << input << ") = ";

		if(input <= 100)
			cout << 91;	
		else
			cout << (input -10);
		cout << "\n";	
	
	}
	return 0;

}
