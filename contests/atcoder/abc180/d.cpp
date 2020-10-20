#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int str_x, y , a, b, maximum_possible_exp = 0;
    int c=0;
    int d=20;
    cin >> str_x >> y >> a >> b;

    while(d--){
        cout << c << endl;
        if(str_x == y){
            cout << maximum_possible_exp << endl;
            break;
        }
        if (str_x < y)
        {
            if(str_x*a < str_x+b && str_x*a < y){
                str_x = str_x*a;
                maximum_possible_exp +=1;
                cout << "a" << endl;
            }else if(str_x+b < str_x*a && str_x+b < y){
                cout << "b" << str_x+b << str_x*a << endl;
                str_x = str_x+b;
                maximum_possible_exp +=1;
            }else if(str_x+b == str_x*a && str_x+b < y)
            {
                str_x = str_x+b;
                maximum_possible_exp +=1;
                cout << "c" << endl;
            }else
            {
                cout << maximum_possible_exp << endl;
                break;
                cout << "d" << endl;
                
            }
        }
        c++;
    }
    return 0;
}