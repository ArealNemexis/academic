#include <bits/stdc++.h>

using namespace std;

int main(){
    int matrix[1000][1000];
    int n,m;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }

    cout << n << " " << m << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}