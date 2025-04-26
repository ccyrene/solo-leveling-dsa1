#include<iostream>
#include<vector>
using namespace std;

void findSubsets(char *input, char *output, int i, int j) {
    

    // base case
    if(input[i] == '\0') {
        output[j] = '\0';
        if (output[0] == '\0') cout << "NULL";

        cout << output << "\n";
        return;
    }

    // recursive case
    output[j] = input[i];
    // Include the ith letter
    findSubsets(input, output, i+1, j+1);
    // Exclude the ith letter
    findSubsets(input, output, i+1, j);

}


int main() {

    char inputs[100] = "abc";
    char outputs[100];

    findSubsets(inputs, outputs, 0, 0);

    return 0;
}