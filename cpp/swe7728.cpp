#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int t(0); t<T; t++){
        int X, x, diversity(0);
        bool numbers[]={false, false, false,false,false,false,false,false,false,false,false};
        cin >> X;
        while(X > 0){
            x = X % 10;
            X = X / 10;

            if (!numbers[x]){
                numbers[x] = true;
                diversity += 1;
            }
        }

        cout << "#" << t+1 << " " << diversity << "\n";
    }
    return 0;
}