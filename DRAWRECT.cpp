#include<iostream>
#include<string>
using namespace std;

int main() {
    int cases, i;
    int xCoord[2];
    int yCoord[2];
    int xSolIdx = -1;
    int ySolIdx = -1;
    
    int* xResult;
    int* yResult;
    
    cin >> cases; 
    
    xResult = new int[cases];
    yResult = new int[cases];
    
    i = cases; 
    while (i--)
    {
        int a, b;
        xCoord[0] = xCoord[1] = xSolIdx = -1;
        yCoord[0] = yCoord[1] = ySolIdx = -1;

        for (int h = 0; h < 3; ++h){
            cin >> a >> b;
            if (xCoord[0] < 0) {
                xCoord[0] = a;
            }
            else if (xCoord[0] == a){
                xSolIdx = 1; 
            }
            else if (xCoord[1] < 0){
                xCoord[1] = a; 
            }
            else if (xCoord[1] == a){
                xSolIdx = 0;
            }
            else {
                cout << "ERROR\n";
            }

            if (yCoord[0] < 0) {
                yCoord[0] = b;
            }
            else if (yCoord[0] == b){
                ySolIdx = 1; 
            }
            else if (yCoord[1] < 0){
                yCoord[1] = b; 
            }
            else if (yCoord[1] == b){
                ySolIdx = 0;
            }
            else {
                cout << "ERROR\n";
            }
        }
         
        xResult[i] = xCoord[xSolIdx]; 
        yResult[i] = yCoord[ySolIdx]; 
    }

    while (cases --){
        cout << xResult[cases] << " " <<  yResult[cases] << "\n";
    }
}

