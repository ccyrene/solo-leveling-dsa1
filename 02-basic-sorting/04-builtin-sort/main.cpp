#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int compare(int a, int b) {
    return a > b;
}

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);
    sort(arr, arr+n); //O(nlogn)
    sort(arr, arr+n, greater<int>()); //sort in descending order
    sort(arr, arr+n, compare); //sort in descending order
    sort(arr, arr+n, [](int a, int b){return a > b;}); //anonymouse function to sort in descending order
    printArray(arr, n);
}