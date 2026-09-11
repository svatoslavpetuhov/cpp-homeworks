#include <iostream>
#include <fstream>
using namespace std;

int main(int c, char* l[]){
    if (c < 2) {
        return 1;
    }
    int n = stoi(l[1]);

    ofstream outFile("outnumbers.txt");
    if (n == 1){
        cout << "1 1" << endl;
    }
    if (n == 2){
        cout << "1 1" << endl;
        cout << "2 1" << endl;
    }
    else{
        outFile << "1 1" << endl;
        outFile << "2 1" << endl;
        int f0 = 1;
        int f1 = 1;
        int tmp = 0;
        for (int i = 3; i <= n; ++i){
            

            outFile << i << " " << f1 + f0 << endl;
            tmp = f1 + f0;
            f0 = f1;
            f1 = tmp;
    }
    }

    outFile.close();
}