#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;

vector<int> dragon;
queue<pair<int,int>> curve_cor;
int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
bool cordinate[102][102]={{false,}};

int check_square(){
    int cnt(0);
    bool visit[102][102]={{false,}};
    while(!curve_cor.empty()){
        int x=curve_cor.front().first, y=curve_cor.front().second;
        curve_cor.pop();
        if(y>= 100 | x >= 100) continue;
        if(!visit[y][x] && cordinate[y+1][x] && cordinate[y][x+1] && cordinate[y+1][x+1]) cnt++;
        visit[y][x] = true;
    }

    return cnt;
}

void dragoncurve(int x, int y, int d, int g){
    vector<int> direction;
    vector<pair<int,int>> cor;
    direction.reserve((1<<g));
    cor.reserve((1<<g)+1);
    direction.push_back(d);
    cor.push_back(make_pair(x,y));
    curve_cor.push(make_pair(x,y));
    cordinate[y][x] = true;

    for(int gg(0); gg < g; gg++){
        for(int i((1<<gg)-1); i >= 0; i--){
            direction.push_back((direction[i]+1)%4);
        }
    }

    for(int i(0); i < (1<<g); i++){
        cor.push_back(make_pair(cor[i].first+dx[direction[i]], cor[i].second+dy[direction[i]]));
        curve_cor.push(make_pair(cor[i].first+dx[direction[i]], cor[i].second+dy[direction[i]]));
        cordinate[cor[i].second+dy[direction[i]]][cor[i].first+dx[direction[i]]] = true;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int N, tmp;
    cin >> N;
    dragon.reserve(4*N+1);
    for(int n(0); n < N; n++){
        for(int i(0); i < 4; i++){
            cin >> tmp;
            dragon.push_back(tmp);
        }
    }

    for(int n(0); n < N; n++){
        dragoncurve(dragon[4*n],dragon[4*n+1],dragon[4*n+2],dragon[4*n+3]);
    }

    cout << check_square();

    fclose(stdin);
    return 0;
}