#include <iostream>
#include <cstdio>
using namespace std;

int n;
int arr[1002]={0,1,3};

int dp(int N){
    if (arr[N]) return arr[N];
    return arr[N] = (dp(N-1)%10007 + 2*dp(N-2)%10007)%10007;

}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> n;
    cout << dp(n);
    fclose(stdin);
    return 0;
}