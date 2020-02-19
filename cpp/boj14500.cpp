#include <iostream>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int N,M, paper[501][501];
    int nn,nm, _max=0, _sum;
    int dn[]={0,0,0,1,2,3, 1,1,0, 0,1,2,0,-1,-2,0,1,2,0,-1,-2,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1, 1,1,2,1,1,2,0,1,1,0,-1,-1, -1,-1,-1,1,1,1,-1,0,1,-1,0,1};
    int dm[]={1,2,3,0,0,0, 0,1,1, 1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,0,1,2,0,-1,-2,0,1,2,0,-1,-2, 0,1,1,0,-1,-1,1,1,2,1,1,2, -1,0,1,-1,0,1,-1,-1,-1,1,1,1};

    cin >> N >> M;
    for(int n=0;n < N; n++){
        for(int m=0;m<M;m++){
            cin >> paper[n][m];
        }
    }

    for(int n=0;n < N; n++){
        for(int m=0;m<M;m++){
            for(int i(0); i < 19; i++){
                _sum=paper[n][m];
                bool complete=true;
                for(int j(0); j<3;j++){
                    nn=n+dn[3*i+j]; nm=m+dm[3*i+j];
                    if(0<=nn && nn < N && 0<=nm && nm < M){
                        _sum += paper[nn][nm];
                    }
                    else {
                        complete=false;
                        break;
                    }
                }
                if(complete) _max=max(_max, _sum);
                
            }
        }
    }

    cout << _max;

    fclose(stdin);
    return 0;
}