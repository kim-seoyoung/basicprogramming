#include <iostream>
using namespace std;

int main(){
    int N,T,_sum;
    cin >> T;

    for (int i(0); i < T; i++){
        cin >> N;
        _sum = 0;
        for (int j(1); j <= N; j++){
            if (j % 2 == 0) _sum = _sum - j;
            else _sum = _sum + j;
        }

        cout << "#" << i+1 << " " << _sum << endl;
    }

    return 0;
}