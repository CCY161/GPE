#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string string_1;

    while(cin >> string_1){
        string string_2;
        cin >> string_2;

        sort(string_1.begin(), string_1.end()); 
        sort(string_2.begin(), string_2.end());
        //int i = 0;
        
        for(string::iterator c1=string_1.begin(); c1!=string_1.end(); ++c1){
            int i = 0;
            bool hit = false;
            for(string::iterator c2=string_2.begin(); c2!=string_2.end(); ++c2){  
                i++;              
                if(*c1==*c2){
                    hit = true;
                    cout << *c1;
                    break;
                }
            }
            if(hit)
                string_2.erase(string_2.begin(), string_2.begin() + i);
            //cout << string_2 << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}