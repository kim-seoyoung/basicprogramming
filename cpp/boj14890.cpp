#include <iostream>
#include <cstdio>
using namespace std;

int N, L, map[101][101];

int findpassway(){
    int cnt(0), l(1); bool canpass=true, down=false;
    // 가로방향 이동
    for(int n(0); n < N; n++){
        l=1; down=false; canpass=true;
        for(int m(1); m < N; m++){
            if (abs(map[n][m] - map[n][m-1]) > 1){
                canpass = false;
                break;
            }
            if(map[n][m] > map[n][m-1]){
                if(l < L) {
                    canpass = false;
                    break;
                }
                if(down){
                    if(l < 2*L) {
                        canpass = false;
                        break;
                    }
                    else down=false;
                }
                l = 1;
            }
            else if(map[n][m] < map[n][m-1]){
                if(down){
                    if(l < L){
                        canpass=false;
                        break;
                    }
                }
                if(m > N-L){
                    canpass = false;
                    break;
                }
                l = 1; down=true;
            }
            else if(map[n][m] == map[n][m-1]) l++;
        }
        if(canpass) cnt++;
    }

    // 세로방향 이동
    for(int n(0); n < N; n++){
        l=1; down=false; canpass=true;
        for(int m(1); m < N; m++){
            if (abs(map[m][n] - map[m-1][n]) > 1){
                canpass = false;
                break;
            }
            if(map[m][n] > map[m-1][n]){
                if(l < L) {
                    canpass = false;
                    break;
                }
                if(down){
                    if(l < 2*L) {
                        canpass = false;
                        break;
                    }
                    else down=false;
                }
                l = 1;
            }
            else if(map[m][n] < map[m-1][n]){
                if(down){
                    if(l < L){
                        canpass=false;
                        break;
                    }
                }
                if(m > N-L){
                    canpass = false;
                    break;
                }
                l = 1; down=true;
            }
            else if(map[m][n] == map[m-1][n]) l++;
        }
        if(canpass) cnt++;
    }

    return cnt;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> L;
    for(int n(0); n < N; n++){
        for(int m(0); m < N; m++){
            cin >> map[n][m];
        }
    }

    cout << findpassway();

    fclose(stdin);

    return 0;
}