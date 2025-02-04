#include<iostream>
using namespace std;
/*
Key Idea:
    - Insertion sort is similar to how we sort playing cards in our hands.
    - Insert the card in the correct position in the sorted part.
*/
void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int current = arr[i];
        int j = i-1;
        //loop to find the right index where the element current should be inserted
        while(j>=0 && arr[j] > current) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
        //printing the array after every pass
        for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    // int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int arr[] = {31,41,59,26,41,58};
    int n = sizeof(arr)/sizeof(int);

    // printArray(arr, n);
    insertionSort(arr, n);
    // printArray(arr, n);
}