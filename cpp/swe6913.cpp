#include <iostream>
using namespace std;

int N, M;
int solve[20];

int main(){
    int T, people(0), _max(0), tmp;
    cin >> T;
    for (int t(0); t<T; t++){
        cin >> N >> M;
        for (int n(0);n<N;n++){
            solve[n] = 0;
            for (int m(0);m<M;m++){
                cin >> tmp;
                solve[n] += tmp;
            }
        }

        people = 0; _max = 0;

        for (int n(0);n<N;n++){
            if (_max < solve[n]){
                _max = solve[n];
                people = 1;
            }
            else if (_max == solve[n]){
                people += 1;
            }
        }

        cout << "#" << t+1 << " " << people << " " << _max << "\n";
    }
    return 0;
}