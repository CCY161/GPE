#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int number;

    while(cin >> number && number){
        vector<int> lists;
        int input;
        for(int i = 0 ; i < number ; i++){
            cin >> input;
            lists.push_back(input);
        }

        sort(lists.begin(), lists.end());

        long long int costs = 0, result = 0;

        while(lists.size()!=1){
            costs = lists[0] + lists[1];
            result += costs;
            lists.erase(lists.begin(), lists.begin()+2);
            lists.push_back(costs);
            sort(lists.begin(), lists.end());
            //cout << costs << " " << lists.size() << " " << result << "\n";
        }

        cout << result << "\n";
    }

    return 0;
}