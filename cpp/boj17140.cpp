#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int r,c,k, arr[101][101]={{0,}};
int row(3), col(3);

int calculate_arr(){
    int time(0);
    while(arr[r-1][c-1]!=k){
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        if(row >= col){
            for(int i(0);i < row; i++){
                int num[101]={0,};
                for(int j(0); j < col; j++){
                    if(arr[i][j]) num[arr[i][j]]++;
                }
                for(int j(1);j < 101; j++){
                    if(num[j]){
                        pq.push(make_pair(num[j],j));
                    }
                }
                int pos(0);
                while(!pq.empty()){
                    int x=pq.top().first,y=pq.top().second;
                    pq.pop();
                    arr[i][2*pos] = y;
                    arr[i][2*pos+1] = x;
                    pos++;
                    if(pos>=50) break;
                }
                while(!pq.empty()){
                    pq.pop();
                }
                if(2*pos < col){
                    for(int j(2*pos); j < col; j++){
                        arr[i][j] = 0;
                    }
                }
                col = max(2*pos, col);
            }
        }
        else{
            int num[101][101]={{0,}}, pos[101]={0,};
            for(int i(0);i < row; i++){
                for(int j(0); j < col; j++){
                    if(arr[i][j]) num[j][arr[i][j]]++;
                }
            }
            for(int i(0);i < col; i++){
                for(int j(1);j < 101; j++){
                    if(num[i][j]){
                        pq.push(make_pair(num[i][j],j));
                    }
                }
                while(!pq.empty()){
                    int x=pq.top().first,y=pq.top().second;
                    pq.pop();
                    arr[2*pos[i]][i] = y;
                    arr[2*pos[i]+1][i] = x;
                    pos[i]++;
                    if(pos[i]>=50) break;
                }
                while(!pq.empty()){
                    pq.pop();
                }
                if(2*pos[i] < row){
                    for(int j(2*pos[i]); j < row; j++){
                        arr[j][i] = 0;
                    }
                }
                row = max(2*pos[i], row);
            }
        }
        time++;
        if(time == 101) break;
    }

    return (time < 101) ? time:-1;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> r >> c >> k;
    for(int i(0); i < 3; i++){
        for(int j(0);j < 3;j++){
            cin >> arr[i][j];
        }
    }

    cout << calculate_arr() << "\n";

    
    fclose(stdin);
    return 0;
}