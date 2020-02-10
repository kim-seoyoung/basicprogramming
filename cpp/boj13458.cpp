#include <iostream>
using namespace std;

long long count_peo(int *A, const int N, const int B, const int C){
    int p, sub; 
    long long d=N;
    for(int n=0;n < N; n++){
        p=A[n]-B;
        if(p > 0){
            sub = p / C;
            if(p % C == 0) d+= sub;
            else d += sub+1;
        }
    }

    return d;

}

int main(){
    freopen("input.txt", "r", stdin);
    int N,B,C;
    cin >> N;
    int *A= new int[N];
    for(int n=0; n < N; n++){
        cin >> A[n];
    }
    cin >> B >> C;
    
    cout << count_peo(A, N, B, C);

    delete[] A;
    fclose(stdin);
    return 0;
}