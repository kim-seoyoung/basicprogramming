#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, is3(0);
    string n;
    cin >> N;
    
    for (int i(1); i <= N; i++){
        n = to_string(i);
        is3 = 0;
        for (int j(0); j < n.size(); j++){
            if ((int(n[j]) - int('0')) % 3 == 0 && n[j] != '0') is3++;
        }
        if (is3) {
            for (int _(0); _ < is3; _++){
                cout << "-";
            }
        }
        else cout << n;

        cout << " ";
    }
    return 0;
}