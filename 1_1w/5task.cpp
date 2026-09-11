#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n;
    cin >> n;
    ofstream outFile("outnumbers.txt");

    for (int i = 1; i <= n; ++i){
        outFile << i << " ";
    }

    outFile.close();
}