#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    cin.get();

    char sentence[1000];
    char largest[1000];

    int largest_len=0;
    while(n--){
        cin.getline(sentence, 1000);

        int length=strlen(sentence);
        if(length > largest_len){
            largest_len=length;
            strcpy(largest, sentence);
        }
    }

    cout << "Largest string is: " << largest << "\n";

    return 0;
}