#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k,y,x;
    cin >> n >> k >> x >> y;

    if(n > k){
        cout << ((n-(n-k))*x) + ((n-k)*y) << endl;
    }
    else{
        cout << n*x << endl;
    }
    
    return 0;
}