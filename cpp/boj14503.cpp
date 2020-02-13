#include <iostream>
#include <cstdio>
using namespace std;

int N, M, cnt(1), space[51][51];
bool clean[51][51]={{false,}};
int dc[]={-1,0,1,0}, dr[]={0,-1,0,1};

void working(int r,int c, int d){
    int tmp_r, tmp_c;
    bool is_work=false;
    for(int i(0); i < 4; i++){
        tmp_r=r+dr[(d+4-i)%4]; tmp_c=c+dc[(d+4-i)%4];
        if(0 <= tmp_r && tmp_r < N && 0 <= tmp_c && tmp_c < M){
            if(!space[tmp_r][tmp_c] && !clean[tmp_r][tmp_c]){
                clean[tmp_r][tmp_c] = true;
                cnt ++;
                working(tmp_r, tmp_c, (d+3-i)%4);
                is_work = true;
                break;
            }
        }
    }
    if(!is_work){
        tmp_r=r+dr[(d+3)%4]; tmp_c=c+dc[(d+3)%4];
        if(0 <= tmp_r && tmp_r < N && 0 <= tmp_c && tmp_c < M){
            if(!space[tmp_r][tmp_c]) working(tmp_r, tmp_c, d);
        }
    }

}

int main(){
    freopen("input.txt", "r", stdin);
    int r,c,d;
    cin >> N >> M >> r >> c >> d;
    for(int n(0); n < N; n++){
        for(int m(0); m < M; m++){
            cin >> space[n][m];
        }
    }

    clean[r][c] = true;
    working(r,c,d);

    cout << cnt;
    fclose(stdin);
    return 0;
}