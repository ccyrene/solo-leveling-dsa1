#include<bits/stdc++.h>
using namespace std;

int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){

    int sum=0;

    for(int i=sr; i<=er; i++) {
        for(int j=sc; j<=ec; j++) {
            sum += v[i][j];
        }
    }

    return sum;
}


int main(){

    int M=4, N=5;

    vector<vector<int>> mat = {{1, 2, 3, 4, 6},
                                {5, 3, 8, 1, 2},
                                {4, 6, 7, 5, 5},
                                {2, 4, 8, 9, 4}};

    int sr=2, sc=2, er=3, ec=4;

    int res = sum(mat, sr, sc, er, ec);

    cout << res << "\n";
}