#include <iostream>
using namespace std;
int N;
char arr[9][9];

bool check(int i, int j,int dir){
   if (dir == 1){
        for (int k(0); k < N/2; k++){
            if (arr[i][j+k] != arr[i][j+N-1-k]) return false;
        }
   }
    else if (dir == -1){
        for (int k(0); k < N/2; k++){
            if (arr[i+k][j] != arr[i+N-1-k][j]) return false;
        }
    }

    return true;
}

int main(){
    int cnt;
    for (int t(0); t < 10; t++){
        cin >> N;
        cnt = 0;
        for (int i(0); i < 8; i++){
            for (int j(0); j < 8; j++){
                cin >> arr[i][j];
            }
        }
        for (int i(0); i < 8;i++){
            for (int j(0); j < 8-N+1; j++){
                if (check(i,j,1)) cnt++;
            }
        }
        for (int i(0); i < 8-N+1;i++){
            for (int j(0); j < 8; j++){
                if (check(i,j,-1)) cnt++;
            }
        }

        cout << "#" << t+1 << " " << cnt << endl;
    }

    
    return 0;
}