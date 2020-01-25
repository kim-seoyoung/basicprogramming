#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstdio>
using namespace std;

int N, M, space, max_space(0); 
int map[10][10];
bool wall_visit[10][10]={{false, }};
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
vector<pair<int, int>> virus;

int countvirus(int sp){
    int x,y, cnt(0);
    bool vi_visit[10][10]={{false,}};
    queue<pair<int, int>> new_virus;

    while(cnt < virus.size()){
        x = virus[cnt].first; y = virus[cnt].second;
        new_virus.push(make_pair(x,y));
        cnt++;
    }

    while(!new_virus.empty()){
        x = new_virus.front().first; y = new_virus.front().second; new_virus.pop();
        // cout << x << y << " " << sp << "\n";
        for(int i(0); i<4; i++){
            int tmpx = x+dx[i], tmpy = y+dy[i];
            if(0 <= tmpx && tmpx < N && 0<= tmpy && tmpy < M){
                if(map[tmpx][tmpy] == 0 && !vi_visit[tmpx][tmpy]){
                    new_virus.push(make_pair(tmpx, tmpy));
                    vi_visit[tmpx][tmpy] = true;
                    sp--;
                }
            }
        }
    }

    return sp;

}

void buildwall(int k){
    if(k == 3){
        max_space = max(countvirus(space), max_space);
        return;
    }
    for(int n(0); n < N; n++){
        for(int m(0); m < M; m++){
            if(map[n][m] == 0 && !wall_visit[n][m]){
                map[n][m] = 1;
                wall_visit[n][m] = true;
                space--;
                buildwall(k+1);
                map[n][m] = 0;
                wall_visit[n][m] = false;
                space++;
            }
        }
    }


}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    space = N*M; virus.reserve(space);
    for(int n(0); n <N; n++){
        for(int m(0); m< M; m++){
            cin >> map[n][m];
            if(map[n][m] == 2){
                virus.push_back(make_pair(n,m));
                space--;
            }
            else if(map[n][m] == 1) space--;
        }
    }

    buildwall(0);
    
    cout << max_space;

    fclose(stdin);

    return 0;
}