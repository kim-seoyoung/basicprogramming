#include <iostream>
using namespace std;

int main(){
    int T, N, arr[8];
    cin >> T;
    for (int t(0); t < T; t++){
        for (int i(0); i < 8; i++){
            arr[i] = 0;
        }
        cin >> N;
        if (N >= 50000){
            arr[0] = N/50000;
            N = N - arr[0]*50000;
        }
        if (N >= 10000){
            arr[1] = N/10000;
            N = N - arr[1]*10000;
        }
        if (N >= 5000){
            arr[2] = N/5000;
            N = N - arr[2]*5000;
        }
        if (N >= 1000){
            arr[3] = N/1000;
            N = N - arr[3]*1000;
        }
        if (N >= 500){
            arr[4] = N/500;
            N = N - arr[4]*500;
        }
        if (N >= 100){
            arr[5] = N/100;
            N = N - arr[5]*100;
        }
        if (N >= 50){
            arr[6] = N/50;
            N = N - arr[6]*50;
        }
        if (N >= 10){
            arr[7] = N/10;
            N = N - arr[7]*10;
        }

        cout << "#" << t+1 << endl;
        for (int i(0); i < 8; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}