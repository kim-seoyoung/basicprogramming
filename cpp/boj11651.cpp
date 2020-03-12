// quick sort
#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int split(int *x, int *y, int s, int e){
    int p=s, l = s+1, r = e;
    while(l <= r){
        while((y[l] < y[p] || (y[l] == y[p]&&x[l]<=x[p])) && l <= r) l++;
        while((y[r] > y[p] || (y[r] == y[p]&&x[r]>=x[p])) && l <= r) r--;
        if(l <= r) {
            swap(&y[r], &y[l]); swap(&x[r], &x[l]);
        }
    }
    swap(&y[r], &y[p]); swap(&x[r], &x[p]);
    return r;
}

void quick_sort(int *x, int *y, int s, int e){
    if(s >= e) return;
    int m = split(x, y, s, e);
    quick_sort(x, y, s, m-1);
    quick_sort(x, y, m+1, e);
}

int main(){
    freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    int *x = new int[N];
    int *y = new int[N];
    for(int n(0); n < N; n++){
        cin >> x[n] >> y[n];
    }

    quick_sort(x, y,0, N-1);

    for(int n(0); n < N; n++){
        cout << x[n] << " " << y[n] << "\n";
    }
    delete[] x; delete[] y;
    fclose(stdin);
    return 0;
}