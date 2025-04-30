#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

// // my solution
// class Solution {
//     public:
//         string removeDuplicates(string s) {
            
//             stack<char> unique;

//             for(char &c: s) {
//                 if (unique.empty()){
//                     unique.push(c);
//                 }else{
//                     if (unique.top() == c) {
//                         unique.pop();
//                     } else {
//                         unique.push(c);
//                     }
//                 }
//             }

//             string res = "";

//             while(!unique.empty()) {
//                 res += unique.top();
//                 unique.pop();
//             }

//             int n=res.size();
//             for(int i=0; i<n/2; i++) {
//                 swap(res[i], res[n-1-i]);
//             }

//             return res;

//         }
// };

// ans (mikelopster professor's solution)
// class Solution{
// public:
//     string removeDuplicates(string s) {
//         stack<char> stk;

//         for(char &c: s) {
//             if (!stk.empty() && stk.top() == c) {
//                 stk.pop();
//             }else{
//                 stk.push(c);
//             }
//         }

//         // construct the result string from the stack
//         string res = "";
//         while (!stk.empty()) {
//             res = stk.top() + res;
//             stk.pop();
//         }

//         return res;

//     }
// };

// beats 100% (vector's based)
class Solution{
public:
    string removeDuplicates(string s) {
        string unique="";
        
        for(char &c: s) {
            if (unique.empty() || unique.back() != c) {
                unique.push_back(c);
            }else{
                unique.pop_back();
            }
        }

        return unique;

    }
};

int main() {

    vector<string> testcases = {
        "abbaca",
        "azxxzy"
    };

    Solution s;

    for (string testcase: testcases) {
        cout << "removeDuplicates: from " << testcase << " to " <<  s.removeDuplicates(testcase) << "\n";
    }

    return 0;
}