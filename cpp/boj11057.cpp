#include <iostream>
using namespace std;

int dp(const int n){
    int cnt[n][10];

    for (int i(0);i <n; i++){
        for (int j(9); j >=0; j--){
            if (i == 0) cnt[i][j] = 1;
            else if (j == 9) cnt[i][j] = 1;
            else cnt[i][j] = (cnt[i][j+1] + cnt[i-1][j]) % 10007;

        }
    }

    int _sum(0);
    for (int j(0); j < 10; j++){
        _sum += cnt[n-1][j];
    }

    return _sum % 10007;
}

int main(){
    int N;
    cin >> N;

    cout << dp(N);
    return 0;
}