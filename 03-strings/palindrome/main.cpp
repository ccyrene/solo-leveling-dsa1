#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    // int length=strlen(str);
    int length = str.length();
    for(int i=0; i<length/2; i++){
        if(str[i] != str[length-i-1]) {
            return false;
        }
    }

    return true;
}

int main()
{
    string str;
    cin >> str;

    if (isPalindrome(str))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}