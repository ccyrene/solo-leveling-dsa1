#include <bits/stdc++.h>
using namespace std;

bool arePermutation(string A, string B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return A == B;
}

int main() {
    string A, B;
    cin >> A >> B;
    if (arePermutation(A, B)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}