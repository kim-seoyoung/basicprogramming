#include <iostream>
using namespace std;

int cases[100002][3]={{0,0,0},{1,1,1}};
int N;

void dp(const int n){
    if (n == N+2) return;

    cases[n][0] = (cases[n - 1][0] + cases[n - 1][1] + cases[n - 1][2]) %9901;
    cases[n][1] = (cases[n - 1][0] + cases[n - 1][2])%9901;
    cases[n][2] = (cases[n - 1][0] + cases[n - 1][1])%9901;
    dp(n+1);
    
}

int main(){
    cin >> N;

    if(N < 2) cout << cases[N][0]+cases[N][1]+cases[N][2];
    else {
        dp(2);
        cout << cases[N+1][0];
    }

    return 0;
}