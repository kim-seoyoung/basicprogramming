#include <iostream>
using namespace std;

int N,L,R, A[51][51];
int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
int num_mem, _sum;

void findassociation(int a[][51], int x, int y, int num, bool *is){
    int tmpx, tmpy;
    for(int i(0); i< 4; i++){
        tmpx = x+dx[i]; tmpy=y+dy[i];
        if(0<=tmpx && tmpx < N && 0<=tmpy && tmpy < N){
            if(L <= abs(A[x][y]-A[tmpx][tmpy])&&abs(A[x][y]-A[tmpx][tmpy]) <=R){
                if(!a[tmpx][tmpy]){
                    a[tmpx][tmpy] = num;
                    _sum += A[tmpx][tmpy]; num_mem++;
                    *is = true;
                    findassociation(a, tmpx, tmpy, num, is);
                }
            }
        }
    }
}

bool populationchange(){
    int asso[51][51]={{0,}}, num_asso=1, _avg[50*50];
    bool is_change=false;
    for(int n(0); n < N; n++){
        for(int m(0); m < N; m++){
            if(!asso[n][m]){
                bool is_asso=false;
                num_mem=1; _sum=A[n][m];
                asso[n][m] = num_asso;
                findassociation(asso,n,m,num_asso, &is_asso);
                if(is_asso) {
                    _avg[num_asso++] = _sum/num_mem;
                    is_change=true;
                }
                else asso[n][m] = 0;
            }
        }
    }
    for(int n(0); n < N; n++){
        for(int m(0); m < N; m++){
            if(asso[n][m]){
                A[n][m] = _avg[asso[n][m]];
            }
        }
    }

    return is_change;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> L >> R;
    for(int n(0); n < N; n++){
        for(int m(0); m < N; m++){
            cin >> A[n][m];
        }
    }
    
    int day(0); bool change=true;
    while(change){
        change = populationchange();
        if(change) day++;
    }

    cout << day;
    fclose(stdin);
    return 0;
}