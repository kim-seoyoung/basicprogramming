#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int check(int c, int num[], int s, int e){
    if(s > e){
        return 0;
    }
    int mid = (s+e)/2;
    if(num[mid] == c) return 1;
    else if(num[mid] > c) return check(c, num, s, mid-1);
    else return check(c, num, mid+1,e);
}

int main(){
    freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N;
    int card[500002], _int[500002], ans[500002]={0,};
    for(int n(0); n < N; n++){
        cin >> card[n];
    }
    cin >> M;
    for(int m(0); m <M; m++){
        cin >> _int[m];
    }

    sort(card, card+N);

    for(int m(0); m < M; m++){
        cout << check(_int[m], card, 0 ,N-1) << " ";
    }

    fclose(stdin);
    return 0;
}