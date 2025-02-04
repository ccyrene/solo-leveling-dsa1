#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v) {
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)  
            return a.second < b.second; // Sort by y if x is the same
        return a.first < b.first; // Otherwise, sort by x
    });
    return v;
}

vector<pair<int, int>> bubbleSortCartesian(vector<pair<int, int>> v) {

    int n = v.size();

    bool swapped;
    for(int i=0; i<n-1; i++) {
        swapped = false;
        for(int j=0; j<n-i-1; j++) {
            pair<int, int> a = v[j];
            pair<int, int> b = v[j+1];

            if (a.first > b.first || (a.first == b.first && a.second > b.second)) {
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }

    return v;

}

// Driver code to test
int main() {
    vector<pair<int, int>> points = {{3, 2}, {1, 5}, {3, 1}, {1, 2}, {2, 4}};
    
    vector<pair<int, int>> sortedPoints = sortCartesian(points);

    cout << "Sorted Points:\n";
    for (auto p : sortedPoints) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "\n";

    vector<pair<int, int>> sortedPoints2 = bubbleSortCartesian(points);

    cout << "Sorted Points:\n";
    for (auto p : sortedPoints2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "\n";

    return 0;
}