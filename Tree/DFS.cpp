/**
 * 재귀, 비재귀 2가지 방식으로 구현 가능
 * 
 * 이진 트리에서는 전위, 중위, 후위 순회로 응용한다
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> adj[10];
int p[10];
int depth[10];

// 비재귀 형태의 DFS 깊이 채우기
void dfsDepthNonRecur(int root){
    stack<int> s;
    s.push(root);
    
    while(!s.empty()){
        int cur = s.top();
        s.pop();

        cout << cur << ' '; // 출력 및 로직

        for(int nxt : adj[cur]){
            if(p[cur] == nxt){
                continue;
            }
            s.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}

// 재귀 형태의 DFS 깊이 채우기
vector<int> adj[10];
int p[10];
int depth[10];
void dfsDepthRecur(int cur){
    cout << cur << ' '; // 로직 처리
    for(int nxt : adj[cur]){
        if(p[cur] == nxt){
            continue;
        }
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        dfsDepthRecur(nxt);
    }
}

// 재귀 형태의 단순 순회 DFS
vector<int> adj[10];
int p[10];

void dfs(int cur){
    cout << cur << ' ';
    for(int nxt : adj[cur]){
        if(p[cur] == nxt){
            continue;
        }
        dfs(nxt);
    }
}

// 전위 순회
int lc[9];
int rc[9];

void preorder(int cur){
    cout << cur << ' '; // 로직 및 출력
    if(lc[cur] != 0){
        preorder(lc[cur]);
    }
    if(rc[cur] != 0){
        preorder(rc[cur]);
    }
}

// 중위 순회
void inorder(int cur){
    if(lc[cur] != 0){
        inorder(lc[cur]);
    }
    cout << cur << ' '; // 출력 및 로직 관리
    if(rc[cur] != 0){
        inorder(rc[cur]);
    }
}

// 후위 순회
void postOrder(int cur){
    if(lc[cur] != 0){
        inorder(lc[cur]);
    }
    if(rc[cur] != 0){
        inorder(rc[cur]);
    }
    cout << cur << ' '; // 출력 및 로직 관리
}