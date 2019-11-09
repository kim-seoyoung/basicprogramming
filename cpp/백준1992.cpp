#include <iostream>
#include <string>

using namespace std;
int n;
const int MAX = 64;
int image[MAX][MAX];
void zip(int n, int r, int c)
{
    if(n == 1){
        if(image[r][c] == 1){
            cout << 1;
        }
        else{
            cout << 0;
        }
        return;
    }

    bool isZero = true, isOne = true;
    for (int k = r; k < r + n; k++){
        for (int l = c; l < c + n; l++){
            if(image[k][l] == 1){
                isZero = false;
            }
            else{
                isOne = false;
            }
        }
    }
    if(isZero){
        cout << 0;
    }
    else{
        if(isOne){
            cout << 1;
        }
        else{
            cout << '(';
            zip(n/2, r,c);
            zip(n/2, r, c + n/2);
            zip(n/2, r + n/2, c);
            zip(n/2, r+ n/2, c + n/2);
            cout << ')';
        }
    }

    return;
}

int main()
{
    cin >> n;
    string _str;
    for(int i = 0; i < n; i++){
       cin >> _str;
        for(int j = 0; j <n; j++){
            image[i][j] = _str[j] - '0';
        }
    }

    zip(n, 0,0);
    return 0;
}