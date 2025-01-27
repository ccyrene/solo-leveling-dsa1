#include<iostream>
using namespace std;

// Brute Force approach, Time Complexity: O(n^3)
int sumSubarray(int arr[], int n) {
    int largestSum = 0;

    for (int i = 0; i<n; i++){
        for (int j = i; j<n; j++){
            int sum = 0;
            for (int k=i; k<=j; k++){
                sum += arr[k];
            }
            largestSum = max(largestSum, sum);
        }
    }

    return largestSum;

}

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr)/sizeof(int);
    
    int maxSum = sumSubarray(arr, n);

    cout << maxSum << "\n";

    return 0;
}