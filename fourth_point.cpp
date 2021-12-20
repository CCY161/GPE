#include <iostream>
#include <iomanip>
#include <set>

using namespace std; 

typedef struct{
    double x;
    double y;
}point;

bool comp(point p1, point p2){
    return p1.x > p2.x;
}

int main(){
    int i=3;
    while(i--){
        point input_point, res_point, total_data;
        total_data.x=0.0;
        total_data.y=0.0;
        bool(*comp_pt)(point,point) = comp;
        set<point, bool(*)(point,point)> point_set;

        for(int i = 0 ; i < 4 ; i++){
            cin >> input_point.x >> input_point.y;
            total_data.x+= input_point.x;
            total_data.y+= input_point.y;
            cout << i << " " << fixed << setprecision(3) << input_point.x << " " << input_point.y << "\n";

            if(point_set.find(input_point)==point_set.end()){
                //cout << input_point.x << " " << input_point.y << "\n";
                point_set.emplace(input_point);
            }
            else{
                res_point.x = input_point.x;
                res_point.y = input_point.y;
            }
        }
        total_data.x -= (3*res_point.x);
        total_data.y -= (3*res_point.y);
        cout << fixed << setprecision(3) << total_data.x << " " << total_data.y << "\n";
    }

    return 0;
}