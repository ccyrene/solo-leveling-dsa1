#include<bits/stdc++.h>
using namespace std;

void print2DArray(vector<vector<int>> vec, int m, int n) {

    for (auto x: vec){
        for (auto y: x)
            cout << y << " ";

        cout << "\n";
    }

    cout << "===========\n";

}


void mergeRow(vector<vector<int>> &mat, int i, int cs, int cm, int ce) {
    vector<int> sorted;
    int x = cs;
    int y = cm+1;

    while(x<=cm && y<=ce) {
        if (mat[i][x] <= mat[i][y]) {
            sorted.push_back(mat[i][x]);
            x++;
        } else {
            sorted.push_back(mat[i][y]);
            y++;
        }
    }


    while(x <= cm) {
        sorted.push_back(mat[i][x]);
        x++;
    }

    while(y <= ce) {
        sorted.push_back(mat[i][y]);
        y++;
    }

    int k=0;
    for(int j=cs; j<=ce; j++) {
        mat[i][j] = sorted[k];
        k++;
    }

    return;

}

void mergeCol(vector<vector<int>> &mat, int j, int rs, int rm, int re) {
    vector<int> sorted;
    int x=rs;
    int y=rm+1;

    while(x<=rm && y<=re) {
        if (mat[x][j] <= mat[y][j]) {
            sorted.push_back(mat[x][j]);
            x++;
        }else{
            sorted.push_back(mat[y][j]);
            y++;
        }
    }

    while(x <= rm) {
        sorted.push_back(mat[x][j]);
        x++;
    }

    while(y <= re) {
        sorted.push_back(mat[y][j]);
        y++;
    }

    int k=0;
    for(int i=rs; i<=re; i++) {
        mat[i][j] = sorted[k];
        k++;
    }

    return;

}


// merge core
void merge(int m, int n, vector<vector<int>> &mat, int rs, int rm, int re, int cs, int cm, int ce) {


    // for sorting rows
    for(int i=rs; i<=re; i++)
        mergeRow(mat, i, cs, cm, ce);

    // for sorting columns
    for(int j=cs; j<=ce; j++)
        mergeCol(mat, j, rs, rm, re);

    return;

}


// split to sub-array
void mergeUtils(int m, int n, vector<vector<int>> &mat, int rs, int re, int cs, int ce) {

    if(rs >= re && cs >= ce) return;

    int rm = (rs + re) / 2;
    int cm = (cs + ce) / 2;


    mergeUtils(m, n, mat, rs, rm, cs, cm); // above left
    mergeUtils(m, n, mat, rm + 1, re, cs, cm); // buttom left
    mergeUtils(m, n, mat, rs, rm, cm + 1, ce); // above right
    mergeUtils(m, n, mat, rm + 1, re, cm + 1, ce); // buttom right

    merge(m, n, mat, rs, rm, re, cs, cm, ce);

}

vector<vector<int>> mergeSort(int m, int n, vector<vector<int>> v){
    
    mergeUtils(m, n, v, 0, m-1, 0, n-1);

    return v;

}


int main() {


    vector<vector<int>> vec = {
        {18, 4, 16, 8},
        {23, 13, 20, 11},
        {28, 24, 26, 25},
        {1, 30, 15, 19}
    };

    int m = vec.size();
    int n = vec[0].size();

    print2DArray(vec, m, n);

    vector<vector<int>> sorted = mergeSort(m, n, vec);

    print2DArray(sorted, m, n);

    return 0;

}