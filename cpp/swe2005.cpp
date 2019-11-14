#include <iostream>
using namespace std;

int main(){
    int T, N, arr[11][11];
    cin >> T;
    for (int i(0); i < T; i++){
        cin >> N;
        for(int j(0); j < N; j++){
            if (j == 0) arr[j][0] = 1;
            else {
                for (int k(0); k <= j; k++){
                    if (k == 0 | k == j) arr[j][k] = 1;
                    else arr[j][k] = arr[j-1][k-1] + arr[j-1][k];
                }
            }
        }
        cout << "#" << i+1 << endl;
        for (int j(0); j < N; j++){
            for (int k(0); k <= j; k++){
                cout << arr[j][k] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}