#include <iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &arr) {
    for(auto x: arr) cout << x << " ";
    cout << "\n";
}

void merge(vector<int> &arr, int s, int e) {
    int mid = (s + e) / 2;
    int n1 = mid - s + 1;
    int n2 = e - mid;

    cout << "array input: ";
    printVector(arr);

    vector<int> L(n1), R(n2);

    for(int i=0; i<n1; i++)
        L[i] = arr[s + i];

    for(int j=0; j<n2; j++)
        R[j] = arr[mid + 1 + j];

    cout << "left: ";
    printVector(L);
    cout << "right: ";
    printVector(R);

    int i=0, j=0, k=s;
    while(i<n1 && j<n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    
    cout << "first sorted: ";
    printVector(arr);


    while(i<n1) arr[k++] = L[i++];
    cout << "fill from L: ";
    printVector(arr);
    while(j<n2) arr[k++] = R[j++];
    cout << "fill from R: ";
    printVector(arr);

    cout << "==============\n";

}

void mergeSort(vector<int> &arr, int s, int e) {

    if (s >= e) return;

    int mid = (s + e) / 2;

    mergeSort(arr, 0, mid);
    mergeSort(arr, mid+1, e);
    return merge(arr, s, e);
}

int main()
{
    vector<int> arr = {8, 3, 1, 7, 0, 10, 2};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printVector(arr);
    return 0;
}