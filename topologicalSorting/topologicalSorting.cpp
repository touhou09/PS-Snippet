#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 위상정렬 (Topological Sorting)
 * 
 * 방향 그래프에서 선후 관계를 지키도록 나열하는 정렬
 * -> 사이클이 있으면 성립되지 않는다.
 * 
 * 따라서 DAG(Directed Acycle Graph) 에서만 정상적으로 작동함
 */

vector<int> adj[10];
int deg[10];
int n;

void topo(){
    queue<int> q;
    vector<int> res;

    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        res.push_back(cur);

        for(auto nxt : adj[cur]){
            deg[nxt]--;

            if(deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
}

/**
 * 위상정렬 시 여러가지 경우의 수를 가진 정렬이 나오고 모두 맞는다.
 * 
 * 특정 조건이 들어가는 정렬의 경우 그에 맞게 응용을 해줄 필요가 있다.
 */

// 오름차순 정렬이 된(사전 순으로 가장 앞선) 정렬을 구하는 경우
// 우선순위 큐를 사용해서 정렬하면서 진행한다.
vector<int> adj[10];
int deg[10];

int n, m;
// n은 수열크기 m은 비교횟수

void PriorityTopo() {
    priority_queue<int> q;
    vector<int> res;

    for(int i = 1; i <= m; i++){
        if(deg[i] == 0){
            q.push(-i);
            // c++의 경우 우선순위 큐가 큰 값을 뽑기 때문에
            // 최소값을 뽑기 위해 -i를 입력
        }

        while(!q.empty()) {
            int cur = -q.top();
            q.pop();

            res.push_back(cur);

            for(auto nxt : adj[cur]) {
                deg[nxt]--;
                if(deg[nxt] == 0){
                    q.push(-nxt);
                }
            }
        }
    }
}