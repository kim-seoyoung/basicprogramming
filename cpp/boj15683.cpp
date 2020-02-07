#include <iostream>
#include <utility>
using namespace std;

int N,M, office[9][9];
int _min=81, cc=0;
pair<int, int> cctv[9];
int dn[]={1,0,-1,0},dm[]={0,1,0,-1};
int cnt(0);

int watch(int n, int m, int i, int o[][9], int dead){
    if(o[n][m]==1){  //0,1,2,3
        n+=dn[i]; m+=dm[i];
        if(n<0 | n>= N | m <0 | m>=M) return dead;
        while(o[n][m]!=6){
            if(o[n][m]==0){
                o[n][m] = 7; dead--;
            }
            n+=dn[i]; m+=dm[i];
            if(n<0 | n>= N | m <0 | m>=M) break;
        }
    }
    else if(o[n][m]==2){ //0,1
        int nn=n, mm=m;
        nn+=dn[i]; mm+=dm[i];
        if(nn>=0 && nn< N && mm >=0 && mm<M){
            while(o[nn][mm]!=6){
                if(o[nn][mm]==0){
                    o[nn][mm] = 7; dead--;
                }
                nn+=dn[i]; mm+=dm[i];
                if(nn<0 | nn>= N | mm <0 | mm>=M) break;
            }
        }
        nn=n; mm=m;
        nn+=dn[i+2]; mm+=dm[i+2];
        if(nn>=0 && nn< N && mm >=0 && mm<M){
            while(o[nn][mm]!=6){
                if(o[nn][mm]==0){
                    o[nn][mm] = 7; dead--;
                }
                nn+=dn[i+2]; mm+=dm[i+2];
                if(nn<0 | nn>= N | mm <0 | mm>=M) break;
            }
        }
    }
    else if(o[n][m]==3){ //0,1,2,3
        int nn=n, mm=m;
        nn+=dn[i]; mm+=dm[i];
        if(nn>=0 && nn< N && mm >=0 && mm<M){
            while(o[nn][mm]!=6){
                if(o[nn][mm]==0){
                    o[nn][mm] = 7; dead--;
                }
                nn+=dn[i]; mm+=dm[i];
                if(nn<0 | nn>= N | mm <0 | mm>=M) break;
            }
        }
        nn=n; mm=m;
        nn+=dn[(i+1)%4]; mm+=dm[(i+1)%4];
        if(nn>=0 && nn< N && mm >=0 && mm<M){
            while(o[nn][mm]!=6){
                if(o[nn][mm]==0){
                    o[nn][mm] = 7; dead--;
                }
                nn+=dn[(i+1)%4]; mm+=dm[(i+1)%4];
                if(nn<0 | nn>= N | mm <0 | mm>=M) break;
            }
        }
    }
    else if(o[n][m]==4){ //0,1,2,3
        for(int j(0);j<4;j++){
            if(j==i) continue;
            int nn=n, mm=m;
            nn+=dn[j]; mm+=dm[j];
            if(nn<0 | nn>= N | mm <0 | mm>=M) continue;
            while(o[nn][mm]!=6){
                if(o[nn][mm]==0){
                    o[nn][mm] = 7; dead--;
                }
                nn+=dn[j]; mm+=dm[j];
                if(nn<0 | nn>= N | mm <0 | mm>=M) break;
            }
        }
    }
    else if(o[n][m]==5){
        for(int j(0);j<4;j++){
            int nn=n, mm=m;
            nn+=dn[j]; mm+=dm[j];
            if(nn<0 | nn>= N | mm <0 | mm>=M) continue;
            while(o[nn][mm]!=6){
                if(o[nn][mm]==0){
                    o[nn][mm] = 7; dead--;
                }
                nn+=dn[j]; mm+=dm[j];
                if(nn<0 | nn>= N | mm <0 | mm>=M) break;
            }
        }
    }

    return dead;
    
}

void find_min(int c, int off[][9], int d){
    if(c == cc){
        _min = min(_min,d);
        return;
    }
    if(office[cctv[c].first][cctv[c].second]==2){
        for(int i(0); i < 2; i++){
            int tmp[9][9];
            for(int n(0); n < N; n++){
                for(int m(0); m<M;m++){
                    tmp[n][m] = off[n][m];
                }
            }
            int nd=watch(cctv[c].first,cctv[c].second, i, tmp,d);
            find_min(c+1, tmp,nd);
        }
    }
    else if(office[cctv[c].first][cctv[c].second]==5){
        int tmp[9][9];
        for(int n(0); n < N; n++){
            for(int m(0); m<M;m++){
                tmp[n][m] = off[n][m];
            }
        }
        int nd=watch(cctv[c].first,cctv[c].second, 0, tmp,d);
        find_min(c+1, tmp,nd);
    }
    else{
        for(int i(0); i < 4; i++){
            int tmp[9][9];
            for(int n(0); n < N; n++){
                for(int m(0); m<M;m++){
                    tmp[n][m] = off[n][m];
                }
            }
            int nd=watch(cctv[c].first,cctv[c].second, i, tmp,d);
            find_min(c+1, tmp,nd);
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    int dd=N*M;
    for(int n(0); n < N; n++){
        for(int m(0); m<M;m++){
            cin >> office[n][m];
            if(office[n][m]) dd--;
            if(office[n][m]>=1 && office[n][m] < 6) cctv[cc++]={n,m};
        }
    }

    find_min(0,office,dd);

    cout << _min;
    fclose(stdin);
    return 0;
}