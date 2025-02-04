#include<iostream>
using namespace std;

/*
Key Idea:
    Take larger elements to the end by repeatedly swapping the adjacent elements.
*/

//O(n^2)
void bubbleSort(int arr[], int n) {
    for(int i=1; i<=n-1; i++) {
        for(int j=0; j<=n-i-1; j++) {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//best case O(n)
void optimizedBubbleSort(int arr[], int n) {
    bool swapped;
    for(int i=0; i<n-1; i++){
        swapped = false;
        for(int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        //printing the array after every pass
        for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
        }
        cout << "\n";

        if(!swapped) break;
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {8, 22, 7, 9, 31, 19, 5, 13};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);
    // bubbleSort(arr, n);
    optimizedBubbleSort(arr, n);
    printArray(arr, n);
}