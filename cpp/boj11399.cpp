// bubble sort
#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void bubble_sort(int peo[], int N){
    for(int i(0); i <N-1;i++){
        for(int j(N-1); j >i; j--){
            if(peo[j] < peo[j-1]) swap(peo[j], peo[j-1]);
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int N, peo[1001];
    cin >> N;
    for(int n=0; n < N; n++){
        cin >> peo[n];
    }
    bubble_sort(peo, N);
    for(int n=0; n < N; n++){
        cout << peo[n] << "\n";
    }
    int _time=0;
    for(int n=0; n < N; n++){
        for(int j=0; j<=n; j++){
            _time += peo[j];
        }
    }
    cout << _time;
    fclose(stdin);
    return 0;
}