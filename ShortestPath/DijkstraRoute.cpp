/**
 * 경로를 관리하는 pre 테이블을 별도로 설정, 갱신하는 방식
 * d를 갱신할 때 pre도 같이 갱신한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[1005];
int pre[1005];

void dijkstra_route(int st){
    priority_queue< pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>> > pq;
    
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
            // d를 갱신했으므로 pre도 갱신한다.
            pre[nxt.second] = cur.second;
        }
    }
}

int en; // 목표 지점

void routePrint(){
    int st;
    // 시작점은 위의 dijkstra에서 구해온다
    vector<int> path;
    int cur = en;

    while(cur != st){
        path.push_back(cur);
        cur = pre[cur];
    }

    path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n"; // 경로에 포함된 V 갯수
    for(auto x : path){
        cout << x << ' '; // 경로
    }
}

// 모든 정점까지의 거리 뿐만이 아니라 하나의 시작점에서 끝점까지의 거리나 경로를 구할때도 적용 가능하다