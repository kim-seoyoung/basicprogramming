#include <iostream>
#include <string.h>
using namespace std;

int dp(const int N, const int K){
    int _sum[K+1][N+2];

    for (int k(1); k < K+1; k++){
        for (int n(0); n < N+1; n++){
            _sum[k][n] = 0;
        }
    }

    for (int k(1); k < K+1; k++){
        for (int n(0); n < N+1; n++){
            if(k == 1 | n == 0) _sum[k][n] = 1;
            else {
                _sum[k][n] = (_sum[k-1][n]+_sum[k][n-1])%1000000000;
            }
        }
    }

    return _sum[K][N];
}

int main(){
    int N, K;
    cin >> N >> K;
    cout << dp(N, K);
}