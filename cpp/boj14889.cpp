#include <iostream>
#include <cstdio>
using namespace std;

int N, capability[22][22]={{0,}};
int start_team[11], link_team[11], start(0), link(0);
int start_sum(0), link_sum(0),_min(100000);

void cal_capability(){
    start_sum = 0; link_sum = 0;
    for(int n(0); n < N/2; n++){
        for(int m=n+1; m < N/2; m++){
            start_sum += capability[start_team[n]][start_team[m]];
            link_sum += capability[link_team[n]][link_team[m]];
        }
    }
}

void splitteam(int p){
    if(p == N){
        cal_capability();
        _min = min(_min, abs(start_sum-link_sum));
        return;
    }
    if(start < N/2){
        start_team[start++] = p+1;
        splitteam(p+1);
        start--;
    }
    if(link < N/2){
        link_team[link++] = p+1;
        splitteam(p+1);
        link--;
    }

}

int main(){
    freopen("input.txt", "r", stdin);
    int tmp;
    cin >> N;
    for(int n(1); n <= N; n++){
        for(int m(1); m <= N; m++){
            cin >> tmp;
            if(n > m) capability[m][n] += tmp;
            else capability[n][m] += tmp;
        }
    }

    splitteam(0);

    cout << _min;

    fclose(stdin);
    return 0;
}