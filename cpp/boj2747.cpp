#include <iostream>
using namespace std;

int n;
int arr[46]={0,1,};

int main(){
    cin >> n;

    for (int i(2); i < n+1; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[n];

    return 0;
}