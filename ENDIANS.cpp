#include<iostream>
#include<string>
using namespace std;

unsigned int convertEdians(unsigned int input){
    unsigned int result = 0;
    result |= (input & 0xFF000000) >> 24;
    result |= (input & 0x00FF0000) >> 8;
    result |= (input & 0x0000FF00) << 8;
    result |= (input & 0x000000FF) << 24;
    return result;
}

int main() {
    int cases;
    int cases_;
    unsigned int targetNumbers[10000];
    unsigned int resultNumbers[10000];

    cin >> cases;
    cases_ = cases;
    
    while (cases--){
        cin >> targetNumbers[cases];    
        resultNumbers[cases] = convertEdians(targetNumbers[cases]);
    }
    
    while (cases_--){
        cout << resultNumbers[cases_] << "\n";
    }
}

