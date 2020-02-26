#include <iostream>
using namespace std;

int N,M,x,y,K;
int map[21][21];
int u=1, r=3, f=5;
int dice[8]={0,};

void move(char &dir){
    if(dir == '1'){
        if(0<= y+1 && y+1 < M){
            y++;
            int tmp = u;
            u = 7-r;
            r = tmp;
            cout << dice[u] << "\n";
            if(map[x][y] == 0){
                map[x][y] = dice[7-u];
            }
            else{
                dice[7-u] = map[x][y];
                map[x][y] = 0;
            }
        }
    }
    else if(dir == '2'){
        if(0<= y-1 && y-1 < M){
            y--;
            int tmp = u;
            u = r;
            r = 7-tmp;
            cout << dice[u] << "\n";
            if(map[x][y] == 0){
                map[x][y] = dice[7-u];
            }
            else{
                dice[7-u] = map[x][y];
                map[x][y] = 0;
            }
        }
    }
    else if(dir == '3'){
        if(0<= x-1 && x-1 < N){
            x--;
            int tmp = u;
            u = f;
            f = 7-tmp;
            cout << dice[u] << "\n";
            if(map[x][y] == 0){
                map[x][y] = dice[7-u];
            }
            else{
                dice[7-u] = map[x][y];
                map[x][y] = 0;
            }
        }
    }
    else if(dir == '4'){
        if(0<= x+1 && x+1 < N){
            x++;
            int tmp = u;
            u = 7-f;
            f = tmp;
            cout << dice[u] << "\n";
            if(map[x][y] == 0){
                map[x][y] = dice[7-u];
            }
            else{
                dice[7-u] = map[x][y];
                map[x][y] = 0;
            }
        }
    }

}

int main(){
    freopen("input.txt", "r", stdin);
    char dir;
    cin >> N >> M >> x >> y >> K;
    for(int n(0); n < N; n++){
        for(int m(0); m < M; m++){
            cin >> map[n][m];
        }
    }
    for(int k(0); k < K; k++){
        cin >> dir;
        move(dir);
    }
    fclose(stdin);
    return 0;
}