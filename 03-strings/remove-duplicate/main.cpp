#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s){
    string result = "";

    sort(s.begin(), s.end());

    int length = s.length();
    if (length == 0){
        return result;
    }

    for (int i=0; i<length-1; i++){
        if (s[i] != s[i+1]){
            result += s[i];
        }
    }
    return result + s[length-1];
}

string removeDuplicate2(string s) {
    set<char> seen(s.begin(), s.end());
    string result;

    for (char c : seen) {
        result.push_back(c);
    }

    return result;
}

int main() {
    string s = "geeksforgeeks";
    cout << removeDuplicate(s) << endl;

    cout << removeDuplicate2(s) << endl;

    return 0;
}