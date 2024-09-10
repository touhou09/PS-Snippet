#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Prim 프림
 * 
 * 1. 임의의 정점을 선택해 최소 신장 트리에 추가, 해당 정점과 연결된 모든 간선을 우선 순위 큐에 추가
 * 
 * 2. 우선 순위 큐에서 비용이 가장 작은 간선을 선택
 * 
 * 3. 만약 해당 간선이 최소 신장 트리에 포함된 두 정점을 연결한다면 아무 것도 하지 않고 넘어감,
 *    해당 간선이 최소 신장 트리에 포함된 정점 u와 포함되지 않은 정점 v를 연결한다면 
 *    해당 간선과 정점 v를 최소 신장 트리에 추가 후 
 *    정점 v와 최소 신장 트리에 포함되지 않는 정점을 연결하는 모든 간선을 우선순위 큐에 추가
 * 
 * 4. 최소 신장 트리에 v-1개의 간선이 추가될 때 까지 2, 3번 과정을 반복
 */

int v, e;
vector<pair<int, int>> adj[10005];
bool chk[10005];
int cnt = 0;
int ans = 0;

priority_queue<tuple<int, int, int>,
                vector<tuple<int, int, int>>,
                greater<tuple<int,int,int>> > pq;

int prim(){
    cin >> v >> e;
    
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }

    chk[1] = 1;

    for(auto nxt : adj[1]){
        pq.push({nxt.first, 1, nxt.second});
    }
    while(cnt < v - 1){
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();

        if(chk[b]){
            continue;
        }

        ans += cost;
        chk[b] = 1;
        cnt++;

        for(auto nxt : adj[b]){
            if(!chk[nxt.second]){
                pq.push({nxt.first, b, nxt.second});
            }
        }
    }
    cout << ans;
}