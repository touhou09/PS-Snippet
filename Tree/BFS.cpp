/**
 * 부모 배열을 저장한 p를 이용해서 순회 방향을 정한다.
 * 
 * 이진 트리에서는 레벨 순회에서 사용된다
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[10];
int p[10];

void bfs(int root){
    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << ' '; // 로직 및 입출력 관리

        for (int nxt : adj[cur]){
            q.push(nxt);
            p[nxt] = cur;
        }
    }
}

int depth[10];

void bfsDepth(int root){
    queue<int> q;
    q.push(root);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << ' '; // 출력 및 로직

        for(int nxt : adj[cur]){
            if(p[cur] == nxt){
                continue;
            }
            q.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}

// 이진트리 저장 방식
int lc[9];
int rc[9];

void levelOrder(){
    queue<int> q;
    q.push(1); // root 값을 넣어줘야 한다.

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << ' ';
        
        if(lc[cur]){
            q.push(lc[cur]);
        }

        if(rc[cur]){
            q.push(rc[cur]);
        }
    }
}
