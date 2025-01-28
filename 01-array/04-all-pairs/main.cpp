#include<iostream>
using namespace std;

void printAllPairs(int arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++){
            cout << "(" << arr[i] << ", " << arr[j] << ")\n";
        }
    }
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    printAllPairs(arr, n);

    return 0;
}