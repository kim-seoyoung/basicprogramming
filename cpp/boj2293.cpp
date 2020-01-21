#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int n, k, tmp;
    int cases[10002]={1,};
    int coin[101];
    cin >> n >> k;
    for(int i(0); i < n; i++){
        cin >> coin[i];
    }

    for (int i(0); i < n; i++){
        for (int j=coin[i]; j < k+1; j++){
            cases[j] += cases[j-coin[i]];
        }
    }

    cout << cases[k];

    fclose(stdin);
    return 0;
}