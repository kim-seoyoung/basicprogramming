#include <iostream>
using namespace std;

int N, schedule[32];
int _max=0;

void max_profit(int d, int lm){
    for(int i(d); i < N; i++){
        int dd=i+schedule[2*i];
        if(dd < N){
            max_profit(dd,lm+schedule[2*i+1]);
        }
        if(dd == N) _max = max(_max,lm+schedule[2*i+1]);
        else _max = max(_max,lm);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    for(int n(0); n < 2*N; n++){
        cin >> schedule[n];
    }

    max_profit(0,0);

    cout << _max;
    
    fclose(stdin);
    return 0;
}