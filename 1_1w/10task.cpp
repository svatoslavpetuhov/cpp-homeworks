#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


int main(int c, char* l[]){
    int n = stoi(l[1]);
    if (c < 2 || n <= 0) {
        return 1;
    }

    vector<double> harmonic(n);

    for (int i = 0; i < n; ++i){
            harmonic[i] = 1.0/(i+1);
    }

    cout << scientific << setprecision(6);

    for (int i = 0; i < n; ++i){
            cout << i+1 << " " << harmonic[i] << endl;
    }
}