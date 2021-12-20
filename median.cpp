#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> dataset;

    int data;
    int number = 0;
    while(cin >> data){    
        number++;

        dataset.push_back(data);
        sort(dataset.begin(), dataset.end());

        if(number == 1) cout << dataset[0] << "\n";
        else if(number%2 == 0){
            int average = (dataset[number/2-1] + dataset[number/2])/2;
            cout << average << "\n";
        }
        else   cout << dataset[number/2] << "\n";

    }
    return 0;
}