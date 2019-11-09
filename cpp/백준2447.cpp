#include <iostream>

using namespace std;

char image[2187][2187];
int N;

void star(int n, int rstep, int cstep){
    
    if(n == 1){
        image[rstep][cstep] = '*';
        return;
    }

    for(int k = 0; k < 3; k++){
        for (int l = 0; l < 3; l++){
            if(k == 1 & l == 1) continue;
            else star(n/3, rstep +k*n/3, cstep + l*n/3);
        }
    }
    
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            image[i][j] = ' ';
        }
    }

    star(N, 0,0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << image[i][j];
        }
        cout << '\n';
    }

    return 0;

}