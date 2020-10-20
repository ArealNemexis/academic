#include <bits/stdc++.h>
#include <math.h>
#define lli long long int
using namespace std;

int main(){
    lli n, manhattan=0;
    long double euclidian = 0;
    cin >> n;
    vector<lli> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        manhattan += abs(vec[i]);
        euclidian += vec[i]*vec[i];
    }
    

    cout << manhattan << endl;
    // printf("%Lf\n", euclidian);
    cout << setprecision(15) << sqrt(euclidian) << endl;
    cout << *max_element(vec.begin(), vec.end()) << endl;
    return 0;
}