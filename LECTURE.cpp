#include<iostream>
#include<string>
using namespace std;

/// if a is lower order, return true; else, return false;
bool compareLexicograpicOrder(string a, string b){
    if (a.length() == 0)
        return false;
    else if (a[0] > b[0])
        return false ;
    else if (a[0] < b[0])
        return true;
    else
        return compareLexicograpicOrder(a.substr(1, a.length()), b.substr(1, b.length()));
}

string* tokenizingStringOfEvenLength(string s, int* size){
    int i = *size = s.length() / 2;
    string* ret = new string[i];

    while (i--){
        ret[i] = s.substr(i * 2, 2);       
    }
    return ret;
}

string mergeString(string a, string b){
    int ia = 0, ib = 0;
    string result = ""; 
    while (ia < a.length() && ib < b.length()){
        if (compareLexicograpicOrder(a.substr(ia, 2), b.substr(ib, 2))){
            result += a.substr(ia, 2);
            ia += 2;
        }
        else{
            result += b.substr(ib, 2);
            ib += 2;
        }
    }
    if (ia < a.length()){
        result += a.substr(ia, a.length());
    }
    else {
        result += b.substr(ib, b.length());
    }
    return result;
}

string mergeSort(string* input, int size){
    string a, b;
    if (size > 1){
        a = mergeSort(input, size/2);
        b = mergeSort(input + size/2, size - size/2); 
        //cout << "a : " << a << ", b : " << b << "\n";
        return mergeString(a, b);
    }
    else {
        return input[0];
    }
}

int main() {
    int cases, i = 0;
    int size = 0;
    string* sortedData; 
    string inputData;
    cin >> cases;

    sortedData = new string[cases];
     
    i = cases; 
    while (i--){
        cin >> inputData;
        string* token = tokenizingStringOfEvenLength(inputData, &size); 
        sortedData[i] = mergeSort(token, size);
    }

    while (cases--){
        cout << sortedData[cases] << "\n";
    }
    
    delete[] sortedData;
}

