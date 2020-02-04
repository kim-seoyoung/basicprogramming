#include <iostream>
using namespace std;

int N, num[12], asmd[4];
int _max(-1000000000),_min(1000000000),_sum;

void find(int n, int _sum){
    if(n==N){
        _max = max(_max,_sum);
        _min = min(_min, _sum);
        return;
    }
    for(int i(0);i < 4; i++){
        if(asmd[i]){
            asmd[i]--;
            if(i==0) find(n+1, _sum + num[n]); 
            else if(i==1) find(n+1,_sum - num[n]);
            else if(i==2) find(n+1,_sum * num[n]);
            else if(i==3) find(n+1,_sum /num[n]);
            asmd[i]++;
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    for(int n(0); n < N; n++){
        cin >> num[n];
    }
    for(int n(0); n < 4; n++){
        cin >> asmd[n];
    }
    find(1,num[0]);
    cout << _max << "\n" << _min;
    fclose(stdin);
    return 0;
}