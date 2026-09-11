#include <iostream>
#include <array>
#include <string>
using namespace std;

const int N_MAX = 90;
int main(int c, char* l[]){
    int n = stoi(l[1]);
    if (c < 2 || n <= 0 || n > N_MAX) {
        return 1;
    }
    
    array<long long, N_MAX> fib;

    if (n >= 1){
        fib[0] = 1;
    }
    if (n >= 2){
        fib[1] = 1;
    }
    for (int i = 2; i < n; ++i){
            fib[i] = fib[i-1] + fib[i-2];
    }
    for (int i = 0; i < n; ++i){
            cout << i+1 << " " << fib[i] << endl;
    }
}
