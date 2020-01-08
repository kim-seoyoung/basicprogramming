#include <iostream>
#include <queue>
using namespace std;

struct map
{
    int x, y, w;
};


int N,M;
int zido[1001][1001];
int dist[2][1001][1001];
int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1};

int bfs(){
    map now;
    int xtmp, ytmp;
    queue<map> q;
    q.push({0,0,0});
    dist[0][0][0] = 1;

    while (!q.empty()){
        now = q.front(); q.pop();
        if (now.x == N-1 && now.y == M-1) return dist[now.w][now.x][now.y];
        for (int i(0); i < 4; i++){
            xtmp = now.x + dx[i];
            ytmp = now.y + dy[i];
            if (xtmp >= 0 && xtmp < N && ytmp >=0 && ytmp < M){
                if (!zido[xtmp][ytmp] && !dist[now.w][xtmp][ytmp]){
                    dist[now.w][xtmp][ytmp] = dist[now.w][now.x][now.y] + 1;
                    q.push({xtmp, ytmp, now.w});
                }
                else if(zido[xtmp][ytmp] && !now.w && !dist[now.w][xtmp][ytmp]){
                    dist[1][xtmp][ytmp] = dist[now.w][now.x][now.y] + 1;
                    q.push({xtmp, ytmp, 1});
                }
            }
        }
    }
    return -1;
}

int main(){
    char tmp;
    cin >> N >> M;

    for(int n(0); n < N; n++){
        for(int m(0); m < M; m++){
            cin >> tmp;
            zido[n][m] = tmp - '0';
            dist[0][n][m] = 0;
            dist[1][n][m] = 0;
        }
    }

    cout << bfs();
    return 0;
}