/**
 * Dijkstra
 * 
 * 음수 간선이 있는 경우 사용불가
 * 일단 연결된 간선으로 값을 지정하도록 한다.
 * 이후 다른 루트로 갈 수 있는 간선의 합과 저장값을 비교한다.
 * 최소값을 저장하고 이를 모든 노드에 대해서 반복한다.
 * 
 * Greedy의 일종
 * 
 * naive하게 구현하면 사용할 수 없으므로 아래 개량버전을 참고해야한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
bool fix[20005];
int d[20005];
int V = 10;

void dijkstra_naive(int st){
    fill(d, d+V+1, INF);
    d[st] = 0;

    while(true){
        int idx = -1;
        for(int i = 1; i <= V; i++){
            if(fix[i]){
                continue;
            }

            if(idx == -1){
                idx = i;
            } else if(d[i] < d[idx]){
                idx = i;
            }
        }
        if(idx == -1 || d[idx] == INF){
            break;
        }
        fix[idx] = 1;
        for(auto nxt : adj[idx]){
            d[nxt.second] = min(d[nxt.second], d[idx] + nxt.first);
        }
    }
}

/**
 * 우선순위 큐를 이용한 다익스트라
 * 1. 우선순위 큐에 (0, st) 추가
 * 2. 우선순위 큐에서 거리가 가장 작은 원소를 선택, 해당 거리가 최단 거리 테이블에 있는 값과 다르면 contiue
 * 3. 원소가 가리키는 정점 v와 이웃한 정점들에 대해 최단 거리 테이블 값보다 v를 거쳐가는 것이 더 작은 값을 가질 경우
 *    최단 거리 테이블의 값을 갱신하고 우선순위 큐에 (cur, v)를 추가
 * 4. 우선순위 큐가 빌 때까지 2, 3번 과정을 반복
 */

vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005];

void dijkstra(int st){
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    d[st] = 0;
    // 우선순위 큐에 (0, st) 추가
    pq.push({d[st], st});
    while(!pq.empty()){
        auto cur = pq.top(); // {비용, 정점 번호}
        pq.pop();

        if(d[cur.second] != cur.first){
            continue;
        }

        for(auto nxt : adj[cur.second]){
            if(d[nxt.second] <= d[cur.second] + cur.first){
                continue;
                
            }
            // cur를 거쳐가는 것이 더 작은 값을 가지는 경우
            // d[cur.secont]를 갱신 후 우선순위 큐에 (거리, nxt.second)를 추가
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }
}