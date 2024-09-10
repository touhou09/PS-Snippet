#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Kruscal 크루스칼
 * 
 * 1. 간선을 크기의 오름차순으로 정렬하고 제일 낮은 비용의 간선을 선택
 * 2. 현재 선택한 간선이 정정 u, v를 연결할 때, 만약 u, v가 같은 그룹이라면 continue
 *    그렇지 않다면 같은 그룹으로 만들고 현재 선택한 간선을 MST에 추가
 * 3. MST에 V - 1개의 간선을 추가시켰다면(최대 간선) 과정을 종료, 그렇지 않다면
 *    그 다음으로 비용이 작은 간선을 선택한 후 2번 과정을 반복
 */

vector<int> p(10005, -1);

int find(int x){
    if(p[x] < 0){
        return x;
    }

    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v){
        return 0;
    }
    if(p[u] == p[v]){
        p[u]--;
    }
    if(p[u] < p[v]){
        p[v] = u;
    }
    else {
        p[u] = v;
    }

    return 1;
}

int v, e;
tuple<int, int, int> edge[100005];

int kruscal(){
    cin >> v >> e;
    
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    sort(edge, edge + e);

    int cnt = 0;
    int ans = 0;

    for(int i = 0; i < e; i++){
        int a, b, cost;

        tie(cost, a, b) = edge[i];

        if(!is_diff_group(a, b)){
            continue;
        }
        ans += cost;
        cnt++;
        if(cnt == v-1){
            break;
        }
    }
    cout << ans;
}