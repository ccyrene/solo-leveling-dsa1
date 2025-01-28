#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void reverseArray(int arr[], int n) {
    // N/2 => O(N)
    int s = 0;
    int e = n-1;
    while(s < e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);
    reverseArray(arr, n);
    printArray(arr, n);

    return 0;
}