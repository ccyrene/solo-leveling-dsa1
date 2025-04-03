#include<iostream>
using namespace std;


pair<int, int> staircaseSearch(int arr[][4], int n, int m, int key) {

    if (key < arr[0][0] || key > arr[n-1][m-1]) return {-1, -1};

    int i=0, j=m-1;

    while(i<n && j>=0) {


        if(key == arr[i][j]) return {i, j};

        else if(key < arr[i][j]) j--;

        else i++;

    }

    return {-1, -1};

}


int main(){

    int arr[][4] = {
        {10, 20, 30, 40},
        {50, 51, 52, 53},
        {62, 64, 66, 68},
        {77, 78, 79, 80}
    };

    int n=4, m=4;

    pair<int, int> res = staircaseSearch(arr, n, m, 5);

    cout << res.first << " " << res.second << "\n";

}