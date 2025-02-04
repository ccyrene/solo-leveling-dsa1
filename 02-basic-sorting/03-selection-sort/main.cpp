#include<iostream>
using namespace std;

/*
Key Idea:
    Repeatedly select the minimum element from the unsorted part of the array and swap it with the first element of the unsorted part.
*/
void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        // Find the minimum element in the unsorted part of the array
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
}