#include<bits/stdc++.h>
using namespace std;

pair<bool,int> binarySearch(vector<int> A, int key) {
    int s = 0;
    int e = A.size()-1;
    int finalIndex = -1;
    while(s<=e) {
        int mid = (s+e)/2;
        if (A[mid] == key) return {true, mid};
        
        if (A[mid] > key) {
            e = mid - 1;
        }else{
            s = mid + 1;
        }

        finalIndex = mid;
    }
    
    return {false, finalIndex};
}


int lowerBound(vector<int> A, int Val) {

    // check smallest element of Array A.
    if (Val < A[0]) return -1;
    
    pair<bool, int> result = binarySearch(A, Val);
    
    // cout << "(" << result.first << "," << result.second << ")" << "\n";
    
    if (result.first) {
        return Val;
    } else {
        return A[result.second - 1];
    }
    
}

int main() {
    vector<int> testcase1 = {-1, -1, 2, 3, 5};
    int Val = 4;
    int result = lowerBound(testcase1, Val);
    cout << result << "\n"; // expected 3

    vector<int> testcase2 = {1, 2, 3, 4, 6};
    result = lowerBound(testcase2, Val);
    cout << result << "\n"; // expected 4
    
    return 0;
}