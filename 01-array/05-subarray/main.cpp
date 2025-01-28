#include<iostream>
using namespace std;

void printSubarrays(int arr[], int n) {
    // O(N^3) - Time Complexity
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            for (int k=i; k<=j; k++){
                cout << arr[k] << ",";
            }
            cout << "\n";
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    
    printSubarrays(arr, n);

    return 0;
}