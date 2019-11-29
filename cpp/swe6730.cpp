#include <iostream>
using namespace std;

int T,N, arr[102];

int main(){
    cin >> T;
    for (int t(0); t < T; t++){
        int up(0), down(0);
        cin >> N;
        for (int n(0); n < N; n++){
            cin >> arr[n];
        }

        for (int n(0); n < N-1; n++){
            if (arr[n] <= arr[n+1]){
                if (up < arr[n+1]-arr[n]) up = arr[n+1]-arr[n];
            }
            else{
                if (down < arr[n]-arr[n+1]) down = arr[n]-arr[n+1];
            }
        }

        cout << "#" << t+1 << " " << up << " " << down << endl;
    }
    return 0;
}