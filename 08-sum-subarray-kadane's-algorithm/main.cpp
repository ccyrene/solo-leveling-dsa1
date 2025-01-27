#include<iostream>
using namespace std;

// Kadane's Algorithm, O(n)
int sumSubarray(int arr[], int n) {
    int currSum = 0;
    int maxSum = 0;

    for (int i=0; i<n; i++) {
        currSum += arr[i];
        if (currSum < 0) {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }

    return maxSum;

}

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr)/sizeof(int);
    
    int maxSum = sumSubarray(arr, n);

    cout << maxSum << "\n";

    return 0;
}