#include <iostream>
#include <queue>
using namespace std;

int N, plate[21][21][6]={{{0,}}};
int _max=0;
queue<int> q;

void get(int n, int m, int t){
    q.push(plate[n][m][t-1]);
}

void put(int n, int m, int dn, int dm, int time){
    if(q.empty()) return;
    int x1=q.front(), x2; q.pop();
    while(!q.empty()){
        x2=q.front(); q.pop();
        if(x1 == x2) {
            plate[n][m][time] = x1 *2;
            m += dm; n+= dn;
            x1 = 0;
        }
        else {
            if(x1){
                plate[n][m][time] = x1;
                m += dm; n+= dn;
            }
            x1 = x2;
        }
    }
    if(x1) plate[n][m][time] = x1;
}

void move(int d, int t){
    if(d==0){
        for(int i(0); i < N; i++){
            for(int j(0); j < N; j++){
                if(plate[i][j][t-1]) get(i,j,t);
                plate[i][j][t] = 0;
            }
            put(i,0,0,1,t);
        }
    }
    else if(d==1){
        for(int i(0); i < N; i++){
            for(int j(N-1); j >= 0; j--){
                if(plate[i][j][t-1]) get(i,j,t);
                plate[i][j][t] = 0;
            }
            put(i,N-1,0,-1,t);
        }
    }
    else if(d==2){
        for(int i(0); i < N; i++){
            for(int j(0); j < N; j++){
                if(plate[j][i][t-1]) get(j,i,t);
                plate[j][i][t] = 0;
            }
            put(0,i,1,0,t);
        }
    }
    else if(d==3){
        for(int i(0); i < N; i++){
            for(int j(N-1); j >= 0; j--){
                if(plate[j][i][t-1]) get(j,i,t);
                plate[j][i][t] = 0;
            }
            put(N-1,i,-1,0,t);
        }
    }
}

int find_max(){
    int local_max(0);
    for(int n(0); n < N; n++){
        for(int m(0); m < N; m++){
            local_max = max(plate[n][m][5], local_max);
        }
    }

    return local_max;
}

void movefivetimes(int nn){
    if(nn == 5){
        _max = max(find_max(), _max);
        return;
    }
    for(int i(0); i < 4; i++){
        move(i, nn+1);
        movefivetimes(nn+1);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    for(int n(0); n < N; n++){
        for(int m(0); m < N; m++){
            cin >> plate[n][m][0];
        }
    }
    movefivetimes(0);
    
    cout << _max;
    fclose(stdin);
    return 0;
}