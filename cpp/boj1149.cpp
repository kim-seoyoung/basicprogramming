#include <iostream>
#include <cstdio>
using namespace std;

int N;
int price[1001][3];
int paint[1001][3];

void dp(){
    for (int i(0); i < 3; i++) paint[0][i] = price[0][i];
    for (int n(1); n < N; n++){
        for(int i(0); i < 3; i++){
            if(i == 0) paint[n][i] = min(paint[n-1][1], paint[n-1][2]) + price[n][i];
            else if(i == 1) paint[n][i] = min(paint[n-1][0], paint[n-1][2]) + price[n][i];
            else if(i == 2) paint[n][i] = min(paint[n-1][1], paint[n-1][0]) + price[n][i];
        }
    }

}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    for (int n(0); n < N; n++){
        for(int i(0); i < 3; i++){
            cin >> price[n][i];
        }
    }

    dp();

    cout << min(paint[N-1][0],min(paint[N-1][1], paint[N-1][2]));
    fclose(stdin);

    return 0;
}