#include<bits/stdc++.h>
using namespace std;

// O(2n) -> O(n) solution
vector<int> kRotate(vector<int> a, int k){
    int n = a.size();
    k = k % n;
    int count = 0;
    vector<int> result;
    for (int i=n-1; i>=0; i--){
        if (count < k) {
            result.insert(result.begin(), a[i]);
        }
        count++;
    }

    for (int i=0; i<n-k; i++){
        result.push_back(a[i]);
    }

    return result;
}

// O(n) solution
vector<int> kRotate2(vector<int> a, int k){
    int n = a.size();
    k = k % n;

    vector<int> v;
    for (int i=0; i<n; i++) {
        if (i < k) {
            v.push_back(a[n-k+i]);
        } else {
            v.push_back(a[i-k]);
        }
    }

    return v;
}

void printVector(vector<int> a){
    for (int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> testcase1 = {1, 3, 5, 7, 9};
    int x = 2;
    printVector(kRotate(testcase1, x)); // expected {7, 9, 1, 3, 5}

    printVector(kRotate2(testcase1, x)); // expected {7, 9, 1, 3, 5}
    return 0;
}