
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

const int INF = 0x3f3f3f3f;

int adj[102][102];
// 경로를 저장하는 nxt 2중배열이 필요하다
int nxt[102][102];

int main(){

    for(int i = 1; i <= n; i++){
        fill(adj[i], adj[i] + n + 1, INF);
    }

    while(m--){
        int a, b, cost;

        cin >> a >> b >> cost;

        adj[a][b] = min(adj[a][b], cost);
        // 기존 연결되는 경로를 입력
        nxt[a][b] = b;
    }

    for(int i = 1; i <= n; i++){
        adj[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[k][j] + adj[i][k];
                    // 갱신될 때 마다 nxt[i][j]를 nxt[i][k]로 같이 갱신해야함
                    nxt[i][j] = nxt[i][k];
                }

            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(adj[i][j] == INF){
                cout << 0 << " ";
            } else {
                cout << adj[i][j] << " ";
            }
        }
        cout << "\n";
    }

// 경로복원의 출력

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(adj[i][j] == 0 || adj[i][j] == INF){
        cout << "0\n";
        continue;
      }
      // 출력할 경로 저장
      vector<int> path;
      // 각 경로별 시작지점 i 입력
      int st = i;
      // st에서 연결되는 nxt[st][j]를 입력
      while(st != j){
        path.push_back(st);
        // 이후 st를 j로 변경
        st = nxt[st][j];
      }
      // 최종 위치를 path에 추가
      path.push_back(j);
      cout << path.size() << ' ';
      for(auto x : path) cout << x << ' ';
      cout << '\n';
    }
  }
}