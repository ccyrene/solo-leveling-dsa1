#include<iostream>
#include<stack>
#include<string>
using namespace std;

// // my solution
// class Solution {
//     public:
//         bool isValid(string s) {
//             stack<char> checker;
//             for (char c: s) {
//                 if (c == '(') checker.push('(');
//                 if (c == '{') checker.push('{');
//                 if (c == '[') checker.push('[');

//                 if (c == ')') {
//                     char top = checker.top();
//                     if (top == '(') {
//                         checker.pop();
//                     }else{
//                         return false;
//                     }
//                 }

//                 if (c == '}') {
//                     char top = checker.top();
//                     if (top == '{') {
//                         checker.pop();
//                     }else{
//                         return false;
//                     }
//                 }

//                 if (c == ']') {
//                     char top = checker.top();
//                     if (top == '[') {
//                         checker.pop();
//                     }else{
//                         return false;
//                     }
//                 }

//             }

//             if (checker.empty()) return true;

//             return false;

//         }
// };

// ans from mikelopster's professor
class Solution {
public:
    bool isValid(string s) {

        stack<char> parentheses;

        for(char &c: s) {
            switch(c) {
                case '(':
                case '{':
                case '[':
                    parentheses.push(c);
                    break;
                case ')':
                    if (parentheses.empty() || parentheses.top() != '(') return false;
                    parentheses.pop();
                    break;
                case '}':
                    if (parentheses.empty() || parentheses.top() != '{') return false;
                    parentheses.pop();
                    break;
                case ']':
                    if (parentheses.empty() || parentheses.top() != '[') return false;
                        parentheses.pop();
                        break;
                default:
                    break;
            }
        }

        return parentheses.empty();

    }
};

int main() {
    Solution s;

    string testcase1 = "()";
    string testcase2 = "()[]{}";
    string testcase3 = "(]";
    string testcase4 = "([])";

    cout << "testcase1: " << s.isValid(testcase1) << "\n"; //true
    cout << "testcase2: " << s.isValid(testcase2) << "\n"; // true
    cout << "testcase3: " << s.isValid(testcase3) << "\n"; // false
    cout << "testcase4: " << s.isValid(testcase4) << "\n"; // true

}