#include<iostream>
#include<vector>
using namespace std;


int rotateSearch(vector<int> arr, int key) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    while(s <= e) {
        int mid = (s+e) / 2;
        // cout << "mid: " << mid << "\n";
        if (arr[mid] == key) return mid;

        
        if (arr[s] <= arr[mid]){
            // key on left line

            // key on sorted line 
            if(arr[s] <= key and key <= arr[mid]) {
                e = mid - 1;
            }else{
                s = mid + 1;
            }

        }else{
            // key on right line

            // key on sorted line 
            if(arr[mid] <= key and key <= arr[e]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }

        }
    }

    return -1;

}


int main() {

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int key = 3;

    int index = rotateSearch(arr, key);

    cout << "res: " << index << "\n";

    return 0;
}