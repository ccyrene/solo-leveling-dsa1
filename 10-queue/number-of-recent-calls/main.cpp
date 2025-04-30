#include<iostream>
#include<queue>
using namespace std;

class RecentCounter {
    private:
        queue<int> calls;
    public:
        RecentCounter() {}
        
        int ping(int t) {
            if(calls.empty()) {
                calls.push(t);
            }else{

                calls.push(t);
                while(t - 3000 > calls.front()) {
                    calls.pop();
                }
            }
            return calls.size();
        }
};
    
    /**
     * Your RecentCounter object will be instantiated and called as such:
     * RecentCounter* obj = new RecentCounter();
     * int param_1 = obj->ping(t);
     */

int main() {
    RecentCounter rc;

    // int param_1 = rc.ping(1);

    // cout << "param_1: " << param_1 << "\n";

    // int param_2 = rc.ping(100);

    // cout << "param_2: " << param_2 << "\n";

    // int param_3 = rc.ping(3001);

    // cout << "param_3: " << param_3 << "\n";

    // int param_4 = rc.ping(3002);

    // cout << "param_4: " << param_4 << "\n";

    int param_1 = rc.ping(642);

    cout << "param_1: " << param_1 << "\n";

    int param_2 = rc.ping(1849);

    cout << "param_2: " << param_2 << "\n";

    int param_3 = rc.ping(4921);

    cout << "param_3: " << param_3 << "\n";

    int param_4 = rc.ping(5936);

    cout << "param_4: " << param_4 << "\n";

    int param_5 = rc.ping(5957);

    cout << "param_5: " << param_5 << "\n";

}