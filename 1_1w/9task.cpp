#include <iostream>
#include <array>
#include <string>
#include <iomanip>
using namespace std;

const int N_MAX = 1000;
int main(int c, char* l[]){
    int n = stoi(l[1]);
    if (c < 2 || n <= 0 || n > N_MAX) {
        return 1;
    }

    array<double, N_MAX> harmonic;

    for (int i = 0; i < n; ++i){
            harmonic[i] = 1.0/(i+1);
    }

    cout << scientific << setprecision(6);

    for (int i = 0; i < n; ++i){
            cout << i+1 << " " << harmonic[i] << endl;
    }
}
