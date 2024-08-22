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
