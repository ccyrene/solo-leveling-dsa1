#include<iostream>
using namespace std;

void spiralPrint(int arr[3][5], int m, int n) {
    int startRow=0, endRow=n-1;
    int startCol=0, endCol=m-1;

    // traverse the boundaries of the matrix
    while(startRow <= endRow && startCol <= endCol) {

        // print upper row
        for(int i=startCol; i<=endCol; i++) {
            cout << arr[startRow][i] << " ";
        }

        // print right col
        for(int i=startRow+1; i<=endRow; i++) {
            cout << arr[i][endCol] << " ";
        }

        // print bottom row
        for(int i=endCol-1; i>=startCol; i--) {
            if (startRow == endRow) break;

            cout << arr[endRow][i] << " ";
        }

        // print left col
        for(int i=endRow-1; i>=startRow+1; i--) {
            if (startCol == endCol) break;

            cout << arr[i][startCol] << " ";
        }

        

        //update traverse point
        startRow++;
        startCol++;
        endCol--;
        endRow--;

    }

    cout << "\n";
}

int main() {

    // int arr[][4] = {
    //     {1, 2, 3, 4},
    //     {12, 13, 14, 5},
    //     {11, 16, 15, 6},
    //     {10, 9, 8, 7}
    // };

    // int m = 4, n = 4;

    // int arr[][3] = {
    //     {1, 2, 3},
    //     {8, 9, 4},
    //     {7, 6, 5}
    // };

    // int m = 3, n = 3;

    int arr[3][5] = {
        {1,  2,  3,  4,  5},
        {12, 13, 14, 15, 6},
        {11, 10, 9, 8, 7}
    };

    int m = 5, n = 3;

    spiralPrint(arr, m, n);
    return 0;
    // Output: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
}