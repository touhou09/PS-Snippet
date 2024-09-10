#include <iostream>
#include <vector>

using namespace std;

// 부모를 저장하는 배열과 랭크(트리의 높이)를 저장하는 배열
vector<int> parent;
vector<int> Rank;

// 초기화 함수: 처음엔 모든 원소가 자기 자신을 부모로 설정
void initialize(int n) {
    parent.resize(n);
    Rank.resize(n, 0); // 모든 트리의 랭크는 처음에 0
    for (int i = 0; i < n; i++) {
        parent[i] = i; // 자기 자신을 부모로
    }
}

// Find 연산 (경로 압축 적용)
int find(int u) {
    if (u == parent[u]) {
        return u; // 자기 자신이 부모이면 반환
    }
    return parent[u] = find(parent[u]); // 부모를 루트로 갱신하며 반환 (경로 압축)
}

// Union 연산 (랭크 사용)
void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    
    if (u != v) {
        // 랭크가 더 높은 쪽이 부모가 된다.
        if (Rank[u] > Rank[v]) {
            parent[v] = u;
        } else if (Rank[u] < Rank[v]) {
            parent[u] = v;
        } else {
            parent[v] = u;
            Rank[u]++; // 랭크가 같으면 하나의 트리 랭크를 증가
        }
    }
}