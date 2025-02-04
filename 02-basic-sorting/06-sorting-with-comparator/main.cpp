#include<bits/stdc++.h>
using namespace std;

vector<int> sortingWithComparator(vector<int> a, bool flag){
    // your code  goes here

    if (a.empty()) return a;

    int maxValue = *max_element(a.begin(), a.end());
    int minValue = *min_element(a.begin(), a.end());

    int range = maxValue - minValue + 1;

    vector<int> freq(range, 0);

    for(int x: a) freq[x - minValue]++;

    vector<int> sorted;
    if (flag) {
        for(int i=0; i<range; i++) {
            while(freq[i] > 0) {
                sorted.push_back(i + minValue);
                freq[i]--;
            }
        }
    } else {
        for(int i=range-1; i>=0; i--) {
            while(freq[i] > 0) {
                sorted.push_back(i + minValue);
                freq[i]--;
            }
        }
    }

    return sorted;
}

void printArray(vector<int> a) {
    for(auto x: a) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> a = {2, 3, 4, 1, 5, 12, 6, 1, 3}; // postive integers only
    vector<int> b = sortingWithComparator(a, true);
    printArray(b);
    
    vector<int> c = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    vector<int> d = sortingWithComparator(c, true);
    printArray(d);
}