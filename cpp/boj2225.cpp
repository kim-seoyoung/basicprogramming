#include <iostream>
#include <string.h>
using namespace std;

long long dp(const int N, const int K){
    long long _sum[K+1][N+2];

    for (int k(1); k < K+1; k++){
        for (int n(0); n < N+1; n++){
            _sum[k][n] = 0;
        }
    }

    for (int k(1); k < K+1; k++){
        for (int n(0); n < N+1; n++){
            if(k == 1 | n == 0) _sum[k][n] = 1;
            else {
                for (int j(0); j < n+1; j++){
                    _sum[k][n] += (_sum[1][j] * _sum[k-1][n-j]) % 1000000000;
                }
            }
        }
    }

    return _sum[K][N] % 1000000000;
}

int main(){
    int N, K;
    cin >> N >> K;
    cout << dp(N, K);
}