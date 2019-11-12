#include <iostream>
using namespace std;

int main(){
    char num[4] = {'0','0','0','0'};
    cin >> num;
    int _sum = 0;

    for (int i(0); i < strlen(num); i++){
        _sum = _sum + int(num[i]) - int('0');
    }

    cout << _sum;
    return 0;
}