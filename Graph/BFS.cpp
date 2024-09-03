#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

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
vector <int> adjDirected[10];
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
vector <int> adjDirected[10];
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
vector<int> adjUndirected[10];
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

// 그냥 2차원 배열에서의 BFS
// 이동할 방향을 지정하고 각 좌표별로 BFS 를 진행하며 조건을 확인한다.
int n;
int arr[100][100];
bool vis[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    
    // 시작 위치 방문 및 큐에 삽입
    vis[startX][startY] = true;
    q.push({startX, startY});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        cout << "(" << x << ", " << y << ") 방문" << endl; // 출력 및 외부를 향한 로직 체크

        // 네 방향으로 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 배열 범위 체크 및 미방문, 유효한 이동 조건 체크
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && arr[nx][ny] == 1) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}