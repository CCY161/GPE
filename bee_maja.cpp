#include<iostream>

using namespace std;

int main(){
    int number;

    while(cin >> number){
        int x = 0, y = 0;
        int circle = 0;
        int comp_num = 1;
        bool finish = false;

        //cout << number << " " << ((number - 1) / 3) + ((number - 1) % 3) << "\n";

        for(int i = 0 ; i < 200 ; ++i){
            if(3*(i*i + i) == (number - 1)){ 
                circle = i;
                break;
            }
            else if((i*i + i) > ((number - 1) / 3)){ 
                circle = i;
                //cout << "break : " << i << " " << circle << " " << (i*i + i)  << " " << ((number - 1) / 3) << "\n";
                break;
            }
        }

        for(int i = 0 ; i < circle ; i++){
            x++;
            comp_num += 6 * (i+1);
            //cout << x << " " << y << "\n";
            if(comp_num == number) finish = true;
        }

        //cout << "circle: " << circle << " " << comp_num << "\n";

        for(int i = 0 ; i < circle ; i++){
            if(comp_num == number) finish = true;
            if(!finish) y--;
            else break;
            comp_num--;
            //cout << x << " " << y << " " << comp_num << "\n";
        }

        for(int i = 0 ; i < circle ; i++){
            if(comp_num == number) finish = true;
            if(!finish) x--;
            else break;
            comp_num--;
            //cout << x << " " << y << " " << comp_num << "\n";
        }

        for(int i = 0 ; i < circle ; i++){
            if(comp_num == number) finish = true;
            if(!finish){
                x--;
                y++;
            }
            else break;
            comp_num--;
            //cout << x << " " << y << " " << comp_num << "\n";
        }

        for(int i = 0 ; i < circle ; i++){
            if(comp_num == number) finish = true;
            if(!finish) y++;
            else break;
            comp_num--;
            //cout << x << " " << y << " " << comp_num << "\n";
        }

        for(int i = 0 ; i < circle ; i++){
            
            if(comp_num == number) finish = true;
            if(!finish) x++;
            else break;
            comp_num--;
            //cout << x << " " << y << " " << comp_num << "\n";
        }

        for(int i = 0 ; i < circle ; i++){  
            if(comp_num == number) finish = true;
            if(!finish){
                x++;
                y--;
            }
            else break;
            comp_num--;
            //cout << x << " " << y << " " << comp_num << "\n";
        }

        cout << x << " " << y << "\n";
    
    }
    return 0;
}