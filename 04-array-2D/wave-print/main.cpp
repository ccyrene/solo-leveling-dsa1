#include<bits/stdc++.h>
using namespace std;
 
vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    
    int startRow=0, endRow=m-1;
    int startCol=0, endCol=m-1;

    vector<int> res;

    while(endCol > 0) {

        // store up to down
        for(int i=startRow; i<=endRow; i++) {
            res.push_back(arr[i][endCol]);
        }

        // update traverse point
        endCol--;

        // store down to up
        for(int i=endRow; i>=startRow; i--) {
            res.push_back(arr[i][endCol]);
        }

        // update traverse point
        endCol--;

    }

    return res;

}


int main() {

    vector<vector<int>> arr = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
    };

    int m=4,n=4;

    vector<int> res = WavePrint(m, n, arr);

    // print vector
    for(int a: res) {
        cout << a << " ";
    }

    cout << "\n";

    return 0;
}