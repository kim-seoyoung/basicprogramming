#include <iostream>

using namespace std;

int N, R, C;
int cnt(0);

void Find(int n, int r, int c){

    if (n == 2){
        if (r == R && c == C){
            cout << cnt;
            return;
        }
        cnt++;
        if (r == R  && c+1 == C){
            cout << cnt;
            return;
        }
        cnt++;
        if (r+1 == R && c == C){
            cout << cnt;
            return;
        }
        cnt++;
        if (r+1 == R && c+1 == C){
            cout << cnt;
            return;
        }
        cnt++;
    }

    else{
        Find(n/2, r,c);
        Find(n/2, r, c + n/2);
        Find(n/2, r + n/2, c);
        Find(n/2, r + n/2, c + n/2);
    }
    
}

int main(){
    cin >> N >> R >> C;
    Find(1<<N,0,0);
    return 0;
}