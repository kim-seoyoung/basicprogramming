#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N;

void hanoi(int m, int a, int b){
    if (m == 1){
        cout << a << " " << b << "\n";
        return;      
    }
    int c = 6-a-b;
    hanoi(m-1, a,c);
    cout << a << " " << b << "\n";
    hanoi(m-1, c, b);
}

int main(){

    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    cout << (1<<N)-1 << endl;

    hanoi(N,1,3);


    return 0;
}