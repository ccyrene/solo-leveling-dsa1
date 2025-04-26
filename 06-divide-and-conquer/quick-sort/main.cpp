#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &arr) {
    for(auto x: arr) cout << x << " ";
    cout << "\n";
}

int partition(vector<int> &arr, int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++) {
        if (arr[j] < pivot ){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);

    return i+1;

}

void quickSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;

    cout << "low: " << low << ", high: " << high << "\n";
    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int main(){

    vector<int> arr = {20, 2, 9, 7, 12, 15, 1, 6, 8};


    quickSort(arr, 0, arr.size() - 1);

    printVector(arr);

    return 0;
}