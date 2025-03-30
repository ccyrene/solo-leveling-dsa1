#include<bits/stdc++.h>
using namespace std;


int compress(vector<char>& chars) {
    int n = chars.size();
    int write_index=0;
    int read_index=0;

    while(read_index < n) {
        char current_char = chars[read_index];
        int count=0;

        while(read_index < n && chars[read_index] == current_char) {
            read_index++;
            count++;
        }

        chars[write_index++]=current_char;

        if(count > 1) {
            string count_str = to_string(count);
            for(char c : count_str) {
                chars[write_index++] = c;
            }
        }
    }

    return write_index;
}

int main(){

    // vector<char> chars = {'a','a','b','b','c','c','c','\0'};
    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b','\0'};

    for (char c : chars) {
        cout << c;
    }
    cout << "\n";

    int count_update = compress(chars);

    for(int i=0; i<count_update; i++) {
        cout << chars[i];
    }
    cout << "\n";

    cout << "Count: " << count_update << "\n";
}