#include <stdio.h>
using namespace std;

int R, C, T, _sum=0;
int A[52][52];
int dr[]={1,0,-1,0}, dc[]={0,1,0,-1};

void spread(int B[][52]){
    int tr, tc, cnt, tmp;
    for(int r(0); r < R; r++){
        for(int c(0); c < C; c++){
            if(A[r][c] > 0){
                cnt = 0; tmp = A[r][c]/5;
                for(int i(0); i < 4; i++){
                    tr = r+dr[i]; tc = c+dc[i];
                    if(0<= tr && tr < R && 0<= tc && tc < C && A[tr][tc] != -1){
                        B[tr][tc] += tmp;
                        cnt++;
                    }
                }
                A[r][c] -= tmp*cnt;
            }
        }
    }
    for(int r(0); r < R; r++){
        for(int c(0); c < C; c++){
            A[r][c] += B[r][c];
        }
    }
}

void air_cleaner1(int ar){
    _sum -= A[ar-1][0];
    for(int i(ar-1); i > 0; i--){
        A[i][0] = A[i-1][0];
    }
    for(int i(0); i < C-1; i++){
        A[0][i] = A[0][i+1];
    }
    for(int i(0); i < ar; i++){
        A[i][C-1] = A[i+1][C-1];
    }
    for(int i(C-1); i > 1; i--){
        A[ar][i] = A[ar][i-1];
    }
    A[ar][1] = 0;
}
void air_cleaner2(int ar){
    _sum -= A[ar+1][0];
    for(int i(ar+1); i < R-1; i++){
        A[i][0] = A[i+1][0];
    }
    for(int i(0); i < C-1; i++){
        A[R-1][i] = A[R-1][i+1];
    }
    for(int i(R-1); i > ar; i--){
        A[i][C-1] = A[i-1][C-1];
    }
    for(int i(C-1); i > 1; i--){
        A[ar][i] = A[ar][i-1];
    }
    A[ar][1] = 0;
}

int main(){
    freopen("input.txt", "r", stdin);
    int air_con[3], cnt_air=0;
    scanf("%d %d %d", &R, &C, &T);
    for(int r(0); r < R; r++){
        for(int c(0); c < C; c++){
            scanf("%d", &A[r][c]);
            if(A[r][c] == -1){
                air_con[cnt_air++] = r;
            }
            else{
                _sum += A[r][c];
            }
        }
    }

    for(int t(0); t < T; t++){
        int B[52][52]={{0,}};
        spread(B);
        air_cleaner1(air_con[0]);
        air_cleaner2(air_con[1]);
    }

    printf("%d", _sum);
    fclose(stdin);
    return 0;
}