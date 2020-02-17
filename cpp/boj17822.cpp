#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M, T, x, d, k;
int plate[51][51], dir[51]={0,};
int dp[]={1,0,-1, 0}, dr[]={0,1,0,-1};

void deletenumber(int np, int nr, bool *ch){
    queue<pair<int, int>> q;
    q.push(make_pair(np, nr));
    int tmpp, tmpr;
    bool isdelete=false, visit[51][51]={{false, }};
    while(!q.empty()){
        int p=q.front().first, r=q.front().second;
        q.pop();
        for(int i(0); i < 4; i++){
            tmpp=p+dp[i]; tmpr = (r+M+dr[i])%M;
            if(0<= tmpp && tmpp < N){
                if(!visit[tmpp][(dir[tmpp]+tmpr)%M] && plate[p][(dir[p]+r)%M] == plate[tmpp][(dir[tmpp]+tmpr)%M]){
                    q.push(make_pair(tmpp, tmpr));
                    isdelete=true;
                    *ch=true;
                    visit[tmpp][(dir[tmpp]+tmpr)%M] = true;
                }
            }
        }
        if(isdelete) plate[p][(dir[p]+r)%M] = 0;
    }
}

void rotate(){
    for(int n(0); n < N; n++){
        if((n+1)%x == 0){
            if(d == 0) dir[n] = (dir[n]+M-k)%M;
            else if(d == 1) dir[n] = (dir[n]+k)%M;
        }
    }

    bool ischange=false;
    for(int n(0); n <N; n++){
        for(int m(0); m < M; m++){
            if(plate[n][(dir[n]+m)%M]) deletenumber(n, m, &ischange);
        }
    }
    if(!ischange){
        float _avg(0); int _num(0);
        for(int n(0); n < N; n++){
            for(int i(0); i < M; i++){
                _avg += plate[n][i];
                if(plate[n][i]) _num++;
            } 
        }
        _avg /= _num;
        for(int n(0); n < N; n++){
            for(int i(0); i < M; i++){
                if(plate[n][i] && plate[n][i] < _avg) plate[n][i]++;
                else if(plate[n][i] && plate[n][i] > _avg) plate[n][i]--;
            }
        }

    }

}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M >> T;
    for(int n(0); n <N; n++){
        for(int i(0); i < M; i++){
            cin >> plate[n][i];
        }
    }
    for(int t(0); t < T; t++){
        cin >> x >> d >> k;
        rotate();
    }

    int _sum(0);
    for(int n(0); n <N; n++){
        for(int i(0); i < M; i++){
            _sum += plate[n][i];
        }
    }

    cout << _sum;

    
    fclose(stdin);
    return 0;
}