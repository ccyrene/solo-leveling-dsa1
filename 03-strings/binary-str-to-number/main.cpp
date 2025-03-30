#include <iostream>
#include <string>
#include<cmath>
using namespace std;
 
int binaryToDecimal(string s){
    int decimal = 0;
    int length = s.length();
    for(int i=0; i<length; i++) {
        if (s[i] == '1'){
            decimal += pow(2, length-i-1);
        }else if (s[i] == '0'){
            decimal += 0;
        }else{
            return -1; // Invalid character
        }
    }
    return decimal;
}

int main(){
    string s = "1101";
    cout << binaryToDecimal(s) << endl;
}