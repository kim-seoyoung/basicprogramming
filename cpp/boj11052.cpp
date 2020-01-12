#include <iostream>
#include <cstdio>
using namespace std;

int N, price[1001];
unsigned int _sum[1002];

void dp(int n){
    unsigned int _max(0);
    if(n == 1) {
        _sum[1] = price[0];
        dp(n+1);
        return;
    }
    else if(n == N+1) return;
    for (int i(1); i < n; i++){
        unsigned int tmp = _sum[n-i]+_sum[i];
        if(tmp > _max) _max = tmp;
    }
    if (_max < price[n-1]) _max = price[n-1];
    _sum[n] = _max;
    dp(n+1);
}

int main(){
    freopen("input.txt","r", stdin);
    cin >> N;
    for (int i(0); i < N; i++){
        cin >> price[i];
    }
    dp(1);
    cout << _sum[N];
    fclose(stdin);
    return 0;
}