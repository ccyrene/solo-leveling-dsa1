#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVec(vector<string> &list) {
    for(auto x: list) cout << x << " ";
    cout << "\n";
}

// lexicographic sorted
bool comparator(string a, string b) {
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

void findSubsets(char *input, char *output, int i, int j, vector<string> &list) {

    // base case
    if(input[i] == '\0') {
        output[j] = '\0';
        string temp(output);
        list.push_back(temp);
        return;
    }

    // rec case
    output[j] = input[i];
    findSubsets(input, output, i+1, j+1, list);
    findSubsets(input, output, i+1, j, list);

}

int main(){

    char inputs[100] = "abc";
    char outputs[100];
    vector<string> vec;

    findSubsets(inputs, outputs, 0, 0, vec);

    printVec(vec);

    sort(vec.begin(), vec.end(), comparator);

    printVec(vec);

    return 0;
}