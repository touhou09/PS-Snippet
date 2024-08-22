#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

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

vector<int> adjDirected[10];
bool vis[10];

// 재귀 dfs
bool vis[10];
void dfs(int cur){
    vis[cur] = true;
    cout << cur << ' '; // 여기서 출력, 계산 등의 로직
    for(auto nxt : adjDirected[cur]){
        if(vis[nxt]){
            continue;
        }
        dfs(nxt);
    }
}

vector<int> adjDirected[10];
bool vis[10];

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

