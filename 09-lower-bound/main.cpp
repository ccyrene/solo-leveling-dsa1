#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> A, int Val) {

    int s=0, e=A.size()-1, answer=-1;

    while (s <= e) {
        int mid = (s + e) / 2;
        if (A[mid] > Val) {
            e = mid-1;
        } else {
            answer = A[mid];
            s = mid+1;
        }
    }

    return answer;
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