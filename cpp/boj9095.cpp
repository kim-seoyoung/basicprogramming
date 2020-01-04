#include <iostream>
#include <cstdio>
using namespace std;
int n, cnt;

void dp(int N){
    if(N == n) {
        cnt++;
        return;
    }
    else if (N>n) return;

    for (int i(1); i<4;i++){
        N += i;
        dp(N);
        N -= i;
    }
}

int main(){
    freopen("input.txt","r", stdin);
    int T;
    cin >> T;
    for (int t(0); t < T; t++){
        cin >> n;
        cnt = 0;
        dp(0);
        cout << cnt << "\n";
    }
    fclose(stdin);

    return 0;
}