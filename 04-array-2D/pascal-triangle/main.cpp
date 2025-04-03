#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    int fact=1;
    
    if (n < 0) return 0;

    if (n == 1 || n == 0) return 1;

    for(int i=2; i<=n; i++) fact*=i;

    return fact;

}

vector<vector<int>> printPascal(int n)
{
    vector<vector<int>> res;

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            // if (((i==0 && j==0) || (i==n-1 && j==n-1))) temp.push_back(1);
            int frac = factorial(j) * factorial(i-j);
            if (frac != 0  ) {
                int binomial = factorial(i)/frac;
                if (binomial > 0 ) temp.push_back(binomial);
            }
        }
        res.push_back(temp);
    }

    return res;
    
}


int main() {


    vector<vector<int>> res = printPascal(10);


    for(vector<int> row: res) {
        for(int a: row) {
            cout << a << " ";
        }
        cout << "\n";
    }
}
 



