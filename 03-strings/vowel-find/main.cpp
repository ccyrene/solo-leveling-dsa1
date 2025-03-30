#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string vowel(string S){
    // your code goes here
    string result;
    for(char c: S) {
        if (isVowel(c)) {
            result += c;
        }
    }
    return result;
}

int main() {
    string S = "aeoibsddaeioudb";
    cout << vowel(S) << endl;
    return 0;
}