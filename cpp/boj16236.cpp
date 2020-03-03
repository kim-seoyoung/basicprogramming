#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct shark {
    int d, x, y;
    bool operator < (const shark &a) const{
        if(a.d == d){
            if(a.x == x) return a.y < y;
            else return a.x < x;
        }
        else return a.d < d;
    }
};
int N, space[21][21], _time=0;
int body=2, cnt=0;
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
priority_queue<shark> sk;

void eat(){
    bool visit[21][21] ={{false,}};
    while(!sk.empty()){
        int d=sk.top().d,x=sk.top().x,y=sk.top().y;
        sk.pop();
        if(0< space[x][y]&&space[x][y]<body){
            space[x][y] = 0;
            cnt++;
            if(cnt == body){
                body++;
                cnt=0;
            }
            _time += d;
            d = 0;
            memset(visit, false, sizeof(visit));
            while(!sk.empty()) sk.pop();
        }
        int tx, ty;
        for(int i(0); i <4; i++){
            tx = x + dx[i]; ty = y + dy[i];
            if(0<=tx&&tx<N&&0<=ty&&ty<N){
                if(0<=space[tx][ty] && space[tx][ty]<=body&&!visit[tx][ty]){
                    sk.push({d+1,tx,ty});
                    visit[tx][ty] = true;
                }
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i(0); i < N; i++){
        for(int j(0); j < N; j++){
            cin >> space[i][j];
            if(space[i][j] == 9){
                sk.push({0,i,j});
                space[i][j] = 0;
            }
        }
    }
    eat();
    cout << _time;
    fclose(stdin);
    return 0;
}