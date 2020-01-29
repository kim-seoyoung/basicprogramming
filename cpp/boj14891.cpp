#include <iostream>
#include <cstdio>
using namespace std;

int gear1[9], gear2[9], gear3[9], gear4[9];
int g1(0), g2(0), g3(0), g4(0);

void rotate(int num, int dir,int from){
    if(num == 1){
        g1 = (g1+8-dir) %8;
        if(gear1[(g1+2+dir)%8] != gear2[(g2+6)%8] && from == 0) {
            rotate(2, dir*-1,1);
        }
    }
    else if(num == 2){
        g2 = (g2+8-dir) %8;
        if(gear2[(g2+2+dir)%8] != gear3[(g3+6)%8] &&(from == 0 | from == 1)){
            rotate(3, dir*-1,2);
        }
        if(gear2[(g2+6+dir)%8] != gear1[(g1+2)%8] &&(from == 0 | from == 3)){
            rotate(1, dir*-1,2);
        } 
    }
    else if(num == 3){
        g3 = (g3+8-dir) %8;
        if(gear3[(g3+2+dir)%8] != gear4[(g4+6)%8] &&(from == 0 | from == 2)){
            rotate(4, dir*-1,3);
        }
        if(gear3[(g3+6+dir)%8] != gear2[(g2+2)%8] &&(from == 0 | from == 4)){
            rotate(2, dir*-1,3);
        } 
    }
    else if(num == 4){
        g4 = (g4+8-dir) %8;
        if(gear4[(g4+6+dir)%8] != gear3[(g3+2)%8] &&from == 0){
            rotate(3, dir*-1,4);
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int K,num,dir;
    char tmp;
    for(int i(0); i < 8; i++){
        cin >> tmp;
        gear1[g1+i] = tmp -'0';
    }
    for(int i(0); i < 8; i++){
        cin >> tmp;
        gear2[g2+i] = tmp -'0';
    }
    for(int i(0); i < 8; i++){
        cin >> tmp;
        gear3[g3+i] = tmp -'0';
    }
    for(int i(0); i < 8; i++){
        cin >> tmp;
        gear4[g4+i] = tmp -'0';
    }

    cin >> K;
    for(int k(0); k < K; k++){
        cin >> num >> dir;
        rotate(num, dir, 0);
    }

    cout << gear1[g1]+(gear2[g2]<<1)+(gear3[g3]<<2)+(gear4[g4]<<3);

    fclose(stdin);
    return 0;
}