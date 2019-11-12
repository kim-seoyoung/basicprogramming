#include <iostream>

using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    
    for(int j(l); j < r; ++j){
        if (arr[j] <= arr[r]){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}

void quicksort(int arr[], int l, int r){
    if (l < r){
        int p = partition(arr, l,r);

        quicksort(arr, 0, p-1);
        quicksort(arr, p+1, r);
    }
    return;
}

int main(){
    int N;
    cin >> N;
    int number[N+1];
    for (int n(0); n < N; ++n){
        cin >> number[n];
    }

    quicksort(number, 0, N-1);
    
    cout << number[N/2] << endl;

    return 0;
}