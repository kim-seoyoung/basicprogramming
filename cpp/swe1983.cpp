#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int T, N, K;
int mt, fi, as;
float _sum;
pair<float, int> student;
priority_queue< pair<float, int> > pq;
int main(){
    cin >> T;
    for (int t(0); t < T; t++){
        cin >> N >> K;
        for (int n(0); n < N; n++){
            cin >> mt >> fi >> as;
            _sum = 0.35 * mt + 0.45 * fi + 0.2 * as;
            pq.push(make_pair(_sum, n+1));
        }
        for (int i(0); i < 10; i++){
            for (int j(0); j < N/10; j++){
                student = pq.top();
                pq.pop();
                if (student.second == K){
                    if (i == 0) cout << "#" << t+1 << " " << "A+" << endl;
                    else if (i == 1) cout << "#" << t+1 << " " << "A0" << endl;
                    else if (i == 2) cout << "#" << t+1 << " " << "A-" << endl;
                    else if (i == 3) cout << "#" << t+1 << " " << "B+" << endl;
                    else if (i == 4) cout << "#" << t+1 << " " << "B0" << endl;
                    else if (i == 5) cout << "#" << t+1 << " " << "B-" << endl;
                    else if (i == 6) cout << "#" << t+1 << " " << "C+" << endl;
                    else if (i == 7) cout << "#" << t+1 << " " << "C0" << endl;
                    else if (i == 8) cout << "#" << t+1 << " " << "C-" << endl;
                    else if (i == 9) cout << "#" << t+1 << " " << "D0" << endl;
                    break;
                }
            }
        }

    }
    return 0;
}