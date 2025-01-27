#include<iostream>
using namespace std;

// Prefix approach, Time Complexity: O(n^2)
int sumSubarray(int arr[], int n) {

    //Cumulative sum to prefix array
    int prefix[n] = {0};
    prefix[0] = arr[0];
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    int largestSum = 0;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            int sum = i>0 ? prefix[j] - prefix[i-1] : prefix[j];
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