#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// 방향이 정해지는 경우
// 여기서 v1은 vertex의 갯수
// e1은 edge의 갯수
vector <int> adjDirected[10];
int v1, e1;

void input_directed(){
    cin >> v1 >> e1;

    for(int i = 0; i < e1; i++){
        int u, v;
        // u, v는 각각의 vertex를 의미
        cin >> u >> v;

        adjDirected[u].push_back(v);
    }
}

// 방향이 정해지지 않는 경우
vector <int> adjUndirected[10];
int v2, e2;

void input_undirected(){
    cin >> v2 >> e2;

    for(int i = 0; i < e2; i++){
        int u, v;
        // u, v는 각각의 vertex를 의미
        cin >> u >> v;

        adjUndirected[u].push_back(v);
        adjUndirected[v].push_back(u);
    }
}

/**
 * BFS -> 너비 중점 탐색
 * 1. 시작 정점을 큐에 넣는다.
 * 2. 큐에서 정점을 꺼내고 방문 여부에 따라,
 * 방문 한 경우 -> 아무것도 하지 않음
 * 방문 안한 경우 -> 방문했다는 표시를 남기고, 연결된 모든 정점들을 큐에 삽입
 * 
 * 3. 큐가 빌때까지 2의 과정을 반복
 * 
 * 모든 정점이 큐에 최대 한번씩 들어간다.
 * -> O(V+E) or O(V^2)
 */
bool vis[10];

void bfs_directed(){
    queue <int> q;
    q.push(1); // 1번에서 시작한다고 가정
    vis[1] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << " "; // 여기서 출력, 계산 등의 로직

        for(auto nxt : adjDirected[cur]){
            if(vis[nxt]){
                continue; // 방문 한 경우 continue
            }
            // 방문하지 않은 경우로 nxt를 queue에 삽입하고 방문한 것으로 변경한다
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

// 1번 정점부터 각 정점간의 거리계산 응용
int dist[10]; // bool로 체크하는 것이 아닌 거리를 계산하도록 함

void bfs_directed_dist(){
    fill(dist, dist + 10, -1);
    queue <int> q;
    q.push(1); // 1번에서 시작
    dist[1] = 0; // 자기 자신과의 거리

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        // 계산 로직이 따로 없이 dist 배열로 거리를 계산함

        for(auto nxt : adjDirected[cur]){
            if(dist[nxt] != -1){
                continue; // 방문 한 경우 -1이 아니므로 조건을 걸고 continue
            }
            // 방문하지 않은 경우로 nxt를 queue에 삽입
            // dist[nxt]는 dist[cur]와 1만큼 차이나므로 이를 반영
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

// 연결이 안된 경우의 bfs
// 연결이 안되면 방문을 못하므로 방문을 안한 정점이 있는지 모든 정점을 돌면서 체크해야한다.
// ex) 1 -> 2 -> 3 -> 4 / 5 -> 6
// 1부터 시작하면 1, 2, 3, 4는 탐색
// 이후 for문을 통해 1, 2, 3, 4의 방문을 확인하고 5부터 다시 bfs
bool vis[10];
int v= 9; // vertex의 수

void bfs_undirected(){
    queue <int> q;
    
    for(int i = 1; i <= v; i++){
        if(vis[i]){
            continue;
        }

        q.push(i);
        vis[i] = true;
    
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            cout << cur << " "; // 여기서 출력, 계산 등의 로직

            for(auto nxt : adjUndirected[cur]){
                if(vis[nxt]){
                    continue; // 방문 한 경우 continue
                }
                // 방문하지 않은 경우로 nxt를 queue에 삽입하고 방문한 것으로 변경한다
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}

/**
 * DFS -> 깊이 중점 탐색
 * BFS에서 queue를 stack으로 바꾸는 경우와
 * 재귀(recursion)를 활용하는 경우가 있다
 * 
 * 재귀의 경우 스택 메모리 제한이 있다면 오류가 나므로 stack으로 구현하는 법도 알고 있어야 한다.
 * 
 * stack의 경우에는 순회 자체는 잘 수행하지만 개념적인 dfs와는 다르므로 주의
 * 
 * O(V+E)
 */

// 재귀 dfs
bool vis[10];
void dfs(int cur){
    vis[cur] = true;
    cout << cur << ' '; // 여기서 출력, 계산 등의 로직
    for(auto nxt : adjDirected[cur]){
        if(vis[nxt]){
            continue;
        }
        dfs[nxt];
    }
}

// 관념적으로 같은 방식으로 작동하는 stack dfs
bool vis[10];
void dfs_directed(){
    stack <int> s;
    s.push(1); // 1번에서 시작한다고 가정

    while(!s.empty()){
        int cur = s.top();
        s.pop();

        if(vis[cur]){
            continue;
        }
        vis[cur] = true;

        // 여기서 출력, 계산 등의 로직 (생략)

        for(auto nxt : adjDirected[cur]){
            if(vis[nxt]){
                continue; // 방문 한 경우 continue
            }
            // 방문하지 않은 경우로 nxt를 queue에 삽입하고 방문한 것으로 변경한다
            s.push(nxt);           
        }
    }
}

