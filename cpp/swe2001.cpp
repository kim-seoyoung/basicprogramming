#include <iostream>
using namespace std;

int main(){
    int T, N, M, arr[16][16];
    cin >> T;
    for (int t(0); t < T; t++){
        int _max = 0;
        cin >> N >> M;
        for(int i(0); i < N; i++){
            for(int j(0); j < N; j++){
                cin >> arr[i][j];
            }
        }

        for (int k(0); k < N-M+1; k++){
            for (int l(0); l < N-M+1; l++){
                int sum = 0;
                for (int n(0);n < M; n++){
                    for(int m(0); m < M; m++){
                        sum = sum + arr[k+n][l+m];
                    }
                }
                if (_max < sum) _max = sum;
            }
        }

        cout << "#" << t+1 << " " << _max << endl; 
    }

    return 0;
}