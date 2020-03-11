// merge sort
#include <iostream>
using namespace std;

void merge(int log[], int ls, int le, int rs, int re){
    int lptr=ls, rptr=rs, aptr=0;
    int *a = new int[(le-ls)+(re-rs)+2];
    while(lptr <= le && rptr<=re){
        if(log[lptr] < log[rptr]) a[aptr++] = log[lptr++];
        else a[aptr++] = log[rptr++];
    }
    if(lptr <= le){
        for(int i(lptr); i<=le; i++) a[aptr++] = log[i];
    }
    if(rptr <= re){
        for(int i(rptr); i<=re; i++) a[aptr++] = log[i];
    }
    aptr = 0;
    for(int i(ls), j(0); i<=re; i++, j++) log[i] = a[j];

    delete[] a;
}

void merge_sort(int log[], int s, int e){
    if(s == e) return;
    int mid = (s+e)/2;
    merge_sort(log, s, mid);
    merge_sort(log, mid+1, e);
    merge(log, s, mid, mid+1, e);
}

int main(){
    freopen("input.txt", "r", stdin);
    int T, N, log[10001],nlog[10001];
    cin >> T;
    for(int t(0); t < T; t++){
        cin >> N;
        for(int n(0); n < N; n++){
            cin >> log[n];
        }
        merge_sort(log, 0, N-1);
        int i=0, j=N-1;
        for(int n(0); n < N; n++){
            if(n % 2 == 0) {
                nlog[i] = log[n];
                i++;
            }
            else{
                nlog[j] = log[n];
                j--;
            }
        }
        int _max=0,tmp;
        for(int n(0); n < N-1; n++){
            tmp = abs(nlog[n+1] - nlog[n]);
            if(tmp > _max) _max = tmp;
        }
        tmp = abs(nlog[N-1] - nlog[0]);
        if(tmp > _max) _max = tmp;
        cout << _max << "\n";
    }
    fclose(stdin);
    

    return 0;
}