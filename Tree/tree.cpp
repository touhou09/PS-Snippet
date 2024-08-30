/**
 * Tree
 * - 무방향이면서 사이클이 없는 연결 그래프
 * - V개의 정점을 가지고 V-1개의 간선을 가지는 사이클이 없는 그래프
 * 
 * 그래프에서 각 정점의 부모 배열을 저장할 p 배열을 추가하면 된다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[10];
int p[10];
int depth[10];

// 그래프와 동일한 형태로 입력