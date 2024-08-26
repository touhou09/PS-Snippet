/**
 * Floid
 * - 대부분의 그래프에서 사용 가능
 * - 간선이 음수여도 동작하나 음수 사이클이 있으면 오류가 나온다
 * 
 * 
 * 기본적인 원리
 * - 현재 테이블에서 일단 x번을 거쳐가는 최단 거리만을 갱신하는 방법
 * 1. 1번 정점을 거쳐가는 것이 효율적일 때에만 D[s][t]를 D[s][1] + D[1][t]로 갱신
 * 2. D[s][t]보다 D[s][2] + D[2][t]가 작을 경우 D[s][t]를 D[s][2] + D[2][t]로 갱신
 * 3. 이를 계속 반복하여 1, 2, 3을 거치는 경우, 1, 2, 3, 4를 거치는 경우 ... 반복
 * 
 * V번째 단계마다 총 V^2개의 모든 D[s][t]값을 D[s][k]+D[k][t]값과 비교
 * 시간복잡도 : O(V^3)
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 0x3f3f3f3f; 
// floid 계산중 INF + INF가 일어날 수 있다
// int overflow가 나지 않도록 죽의하면서 진행해야함

int adj[102][102];
int n, m;

int main(){
    for(int i = 1; i <= n; i++){
        fill(adj[i], adj[i] + n + 1, INF);
    }

    while(m--){
        int a, b, cost;

        cin >> a >> b >> cost;

        adj[a][b] = min(adj[a][b], cost);
    }

    for(int i = 1; i <= n; i++){
        adj[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
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


}