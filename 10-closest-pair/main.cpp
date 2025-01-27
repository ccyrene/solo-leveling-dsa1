#include<bits/stdc++.h>
using namespace std;

//O(n^2) solution
pair<int, int> closestSum(vector<int> arr, int x){
    int n = arr.size();
    int closest = INT_MAX;
    pair<int, int> result = {INT_MAX, INT_MAX};
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            int distance = abs((arr[i] + arr[j]) - x);
            if (distance < closest) {
                closest = distance;
                result = {arr[i], arr[j]};
            }
        }
    }
    
    return result;

}

//O(n) solution **monotonically increasing array only
pair<int, int> closestSumOptimize(vector<int> arr, int x){
    int n = arr.size();
    int diff = INT_MAX;
    int l = 0, r = n-1;
    int closest_l, closest_r;

    while(l < r) {
        int distance = abs(arr[l] + arr[r] - x);
        if (distance < diff) {
            diff = distance;
            closest_l = arr[l];
            closest_r = arr[r];
        }

        if (arr[l] + arr[r] < x) {
            l++;
        }else{
            r--;
        }
    }
    return {closest_l, closest_r};
}

int main() {
    vector<int> testcase1 = {10, 22, 28, 29, 30, 40};
    int x = 54;
    pair<int, int> result = closestSum(testcase1, x);
    cout << "(" << result.first << "," << result.second << ")" << "\n"; // expected (22,30)

    result = closestSumOptimize(testcase1, x);
    cout << "(" << result.first << "," << result.second << ")" << "\n"; // expected (22,30)
    return 0;
}