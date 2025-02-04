#include<bits/stdc++.h>
using namespace std;

/*
    Key Idea:
    1. Count the frequency of each element in the array.
    2. Modify the array based on the frequency of the elements.
*/
void countSort(int arr[], int n) {
    int largest = INT_MIN;
    int smallest = INT_MAX;
    for(int i=0; i<n; i++) {
        largest = max(largest, arr[i]);
        smallest = min(smallest, arr[i]);
    }

    int range = largest - smallest + 1;

    vector<int> freq(range, 0);

    for (int i=0; i<n; i++) freq[arr[i] - smallest]++;


    int j=0;
    /*
    Describe about the loop:
        Time complexity: O(n + K) where K is the range of the count array.
        *** If the inner loop always ran for every iteration of the outer loop, then it would indeed be O(n * K). 
        But the inner loop only runs for the number of times that the element appears in the array. 
        So, the total number of iterations of the inner loop is equal to the total number of elements in the array. 
        So, the time complexity is O(n + K). ****
    */
    for (int i=0; i<range; i++) {
        while(freq[i] > 0) {
            arr[j] = i+smallest;
            freq[i]--;
            j++; 
        }
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {2, 3, 4, 1, 5, 12, 6, 1, 3}; // postive integers only
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);
    countSort(arr, n); //O(n + m) which m is the range of the count array.
    printArray(arr, n);

    cout << "\n";
    
    int arr2[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    n = sizeof(arr2)/sizeof(int);

    printArray(arr2, n);
    countSort(arr2, n);
    printArray(arr2, n);
}