#include<iostream>
#include<sstream>
#include<set>
#include<string>
using namespace std;

struct data{
    double m;
    double b;
};

int main() {
    int test;
    cin >> test;

    for(int i = 0 ; i < test ; i++){
        int dot;
        cin >> dot;
        set<string> dataset;

        int x[1000], y[1000];

        for(int j = 0; j < dot ; j++){
            cin >> x[j] >> y[j];
            //cout << x[j] << " and " << y[j] << "\n";

            for(int k = 0 ; k < j ; k++){

                data line;
                double x_m = (x[j] - x[k]);
                double y_m = (y[j] - y[k]);
                //cout << x[j] << " " << y[j] << " " << x[k] << " " <<  y[k] << " temp\n";
                if(x_m==0){
                    line.m = 0;
                    line.b = x[j];
                }
                else{
                    if(y_m != 0)
                        line.m = y_m / x_m;
                    else
                        line.m = 0;
                    line.b = y[j] - line.m * x[j];
                }
                //cout << x_m << " and " << y_m << " and " << line.m << " and " <<  line.b << " temp\n";
                stringstream ss;
                string temp;
                ss.clear();
                if(x_m == 0)
                    ss << line.m << "_" << line.b << "_" << x[j];
                else
                    ss << line.m << "_" << line.b;

                temp = ss.str();
                //cout << temp << "\n";

                // 
                    // temp = to_string(line.m) + to_string(line.b) + to_string(x[j]);
                // else
                    // temp = to_string(line.m) + to_string(line.b);
                //cout << temp << " temp\n";
                dataset.insert(temp);
            }
        }

        cout << dataset.size() << "\n";

    }

    return 0;
}