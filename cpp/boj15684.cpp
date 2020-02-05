#include <iostream>
using namespace std;

int N, M, H, cnt(100);
bool ladder[12][32];

bool play(){
    for(int n(1); n<=N; n++){
        int loc=n;
        for(int h(1); h <= H; h++){
            if(loc == 1&&ladder[loc][h]) loc++;
            else if(loc == N && ladder[loc-1][h]) loc--;
            else{
                if(ladder[loc][h]) loc++;
                else if(ladder[loc-1][h]) loc--;
            }
        }
        if(loc != n) return false;
    }

    return true;
}

void rigging(int c, int nn, int hh){
    if(play()){
        cnt = min(cnt,c);
        return;
    }
    if(c == 3) return;
    for(int n(nn); n<N; n++){
        int k; (n==nn) ? k=hh:k=1;
        for(int h(k); h <= H; h++){
            if(!ladder[n][h]){
                ladder[n][h] = true;
                rigging(c+1, n, h);
                ladder[n][h] = false;
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int a, b;
    cin >> N >> M >> H;
    for(int m(0); m < M; m++){
        cin >> a >> b;
        ladder[b][a] = true;
    }

    if(play()) cout << 0;
    else {
        rigging(0,1,1);
        if(cnt < 4) cout << cnt; 
        else cout << -1; 
    }
    fclose(stdin);
    return 0;
}