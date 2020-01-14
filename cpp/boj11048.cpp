#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
int maze[1001][1001];
int candy[1001][1001];

void dp(){
    for(int i(0);i < N; i++){
        for(int j(0); j < M ;j++){
            if(i == 0 && j >0){
                candy[i][j] = candy[i][j-1] + maze[i][j];
            }
            else if(i > 0) {
                candy[i][j] = max(candy[i][j-1]+maze[i][j], candy[i-1][j] + maze[i][j]);
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int n(0); n < N; n++){
        for (int m(0); m < M; m++){
            cin >> maze[n][m];
        }
    }
    candy[0][0] = maze[0][0];
    dp();
    cout << candy[N-1][M-1];
    fclose(stdin);

    return 0;
}