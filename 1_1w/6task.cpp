#include <iostream>
#include <fstream>
using namespace std;

int main(int c, char* l[]){
    if (c < 2) {
        return 1;
    }
    int n = stoi(l[1]);

    ofstream outFile("outnumbers.txt");

    for (int i = 1; i <= n; ++i){
        outFile << i << " ";
    }

    outFile.close();
}