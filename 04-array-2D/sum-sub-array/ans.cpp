#include<bits/stdc++.h>
using namespace std;
 
/*
Explaination:

To efficiently handle multiple submatrix sum queries on a matrix, we can use a prefix sum array prefix where each prefix[i][j] accumulates sums from the top-left corner to (i, j) in the matrix. 
This array is initialized such that prefix[i][j]  includes the sum of matrix elements up to (i, j). 
By computing row-wise and column-wise cumulative sums, each query (tli, tlj, rbi, rbj) can be resolved in constant time by utilizing the prefix sum array to subtract appropriate sums. 
This preprocessing step allows each query to be resolved efficiently, making the overall complexity O(1) per query after O(M*N) preprocessing time.
*/

void printVector(vector<vector<int>> arr, int m, int n){
   cout << "\n";
   for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
         cout << arr[i][j] << " ";
      }
      cout << "\n";
   }
}

int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){
   int m=v.size();
   int n=v[0].size();
   // // int aux[m][n];
   int M=m;
   int N=n;
   vector<vector<int>> aux = v;
   vector<vector<int>> mat = v;
   int tli=sr, tlj=sc, rbi=er, rbj=ec;
   for (int i=0; i<N; i++)
   aux[0][i] = mat[0][i];

   printVector(aux, M, N);
  
   // Do column wise sum
   for (int i=1; i<M; i++)
      for (int j=0; j<N; j++)
         aux[i][j] = mat[i][j] + aux[i-1][j];

   printVector(aux, M, N);
  
   // Do row wise sum
   for (int i=0; i<M; i++)
      for (int j=1; j<N; j++)
         aux[i][j] += aux[i][j-1];
 
   printVector(aux, M, N);

   int res = aux[rbi][rbj];

   cout << "\n";
   cout << res << "\n";

   // Remove elements between (0, 0) and (tli-1, rbj)
   cout << res << " - " << aux[tli-1][rbj] << "\n";

   if (tli > 0)
      res = res - aux[tli-1][rbj];

   cout << res << " - " << aux[rbi][tlj-1] << "\n";

   // Remove elements between (0, 0) and (rbi, tlj-1)
   if (tlj > 0)
      res = res - aux[rbi][tlj-1];

   cout << res << " + " << aux[tli-1][tlj-1] << "\n";
   // Add aux[tli-1][tlj-1] as elements between (0, 0)
   // and (tli-1, tlj-1) are subtracted twice
   if (tli > 0 && tlj > 0)
      res = res + aux[tli-1][tlj-1];

   cout << res << "\n";

   return res;
}

int main(){

   int M=4, N=5;

   vector<vector<int>> mat = {{1, 2, 3, 4, 6},
                               {5, 3, 8, 1, 2},
                               {4, 6, 7, 5, 5},
                               {2, 4, 8, 9, 4}};

   int sr=2, sc=2, er=3, ec=4;

   int res = sum(mat, sr, sc, er, ec);

   cout << res << "\n";
}