#include<bits/stdc++.h>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    sort(length.begin(), length.end());

    int count=0, i=0;

    while(i<length.size()-1){
        if(length[i+1]-length[i]<=D){
            count++;
            i+=2;
        }else{
            i++;
        }
    }

    return count;
}


int main() {
    vector<int> arr = {1, 3, 3, 9, 4};
    int x = 2;

    int n = sizeof(arr)/sizeof(int);

    int result = pairSticks(arr, x);

    cout << "Result: " << result << endl;
}