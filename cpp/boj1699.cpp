#include <iostream>
using namespace std;

int main(){
    int N, number[100001]={0,};
    cin >> N;

    for(int n(1); n <= N; n++){ 
        number[n] = 1000000000;
    }

    for(int n(1); n <= N; n++){
        for(int i(1); i*i <= n; i++){
            number[n] = min(number[n-i*i] + 1, number[n]);
        }
    }

    cout << number[N];

    return 0;
}