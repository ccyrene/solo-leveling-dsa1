#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> v, int key, int s, int e) {

    if(e >= s) {
        int mid = s + (e - s) / 2;
        
        if(v[mid] == key) return mid;

        if(v[mid] > key) return helper(v, key, s, mid-1);

        return helper(v, key, mid+1, e);
    }

    return -1;

}

int binarySearch(vector<int> v, int x)
{
    int n = v.size();

    return helper(v, x, 0, n-1);
}

int main() {

    // vector<int> arr = { 0, 1, 2, 3, 4};
    // int key = 4;
    vector<int> arr = { 1, 3, 5, 7, 9 };
    int key = 3;

    int index = binarySearch(arr, key);

    cout << "res: " << index << "\n";

    return 0;
}