#include <iostream>
#include <vector>
using namespace std;

int N, M, num_chic(0),_min(50000);
int open[14], num_open(0), num_close(0), num_ck(0), num_h(0);
vector<int> chicken, house;

void choosechicken(){
    if(num_open + num_close == num_chic){
        int distance(0);
        for(int j(0); j < num_h; j++){
            int house_min(200);
            for(int i(0); i < M; i++){
                house_min = min(abs(house[2*j]-chicken[2*open[i]])+abs(house[2*j+1]-chicken[2*open[i]+1]), house_min);
            }
            distance += house_min;
        }
        _min = min(_min, distance);
        return;
    }
    if(num_open < M){
        open[num_open++] = num_ck++;
        choosechicken();
        num_open--; num_ck--;
    }
    if(num_close < num_chic-M){
        num_close++; num_ck++;
        choosechicken();
        num_close--; num_ck--;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int tmp;
    cin >> N >> M;
    chicken.reserve(26); house.reserve(2*N);
    for(int n(0); n < N; n++){
        for(int m(0); m < N; m++){
            cin >> tmp;
            if(tmp == 1) {
                house.push_back(n); 
                house.push_back(m);
                num_h++;
            }
            else if(tmp == 2) {
                chicken.push_back(n); 
                chicken.push_back(m);
                num_chic++;
            }
        }
    }

    choosechicken();

    cout << _min;
    
    fclose(stdin);
    return 0;
}