#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int key) {
    // O(log n)
    // *** Works only on sorted arrays (monothonic)
    int s = 0;
    int e = n-1;
    while(s <= e) {
        int mid = (s+e)/2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            e = mid - 1;
        }else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {11, 12, 13, 15, 19, 25, 28, 30, 35, 40, 45, 50, 55, 60};
    int n = sizeof(arr)/sizeof(int);
    int key = 30;

    int index = binary_search(arr, n, key);
    if (index != -1){
            cout << key << " is present at index " << index << "\n";
    } else {
        cout << key << "is NOT Found!\n";
    }

    return 0;
}