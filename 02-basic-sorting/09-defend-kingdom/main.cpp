#include<bits/stdc++.h>
using namespace std;

int defkin(int W, int H, vector<pair<int, int>> position)
{
    sort(position.begin(), position.end(), [](pair<int, int> p1, pair<int, int> p2){
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    });

    int n = position.size();

    if (n == 0) return W * H;

    if (n == 1) {
        int x = position[0].first;
        int y = position[0].second;
        return (W-x) * (H-y);
    }

    int maxRegion = INT_MIN;
    for(int i=0; i<n-1; i++){
        int currX = position[i].first;
        int currY = position[i].second;
        int nextX = position[i+1].first;
        int nextY = position[i+1].second;

        int weak = abs(nextX - currX) * abs(nextY - currY);
        if (weak > maxRegion){
            maxRegion = weak;
        }
    }

    return maxRegion;
}

int main() {
    vector<pair<int, int>> position = {{3, 8}, {11, 2}, {8, 6}};
    int W = 15, H = 8;
    cout << defkin(W, H, position) << endl; //expected 12

    position = {{2,2}};
    W = 4, H = 3;
    cout << defkin(W, H, position) << endl; //expected 2

    position = {};
    W = 4, H = 3;
    cout << defkin(W, H, position) << endl; //expected 12

    return 0;
}