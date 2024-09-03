#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


/**
 * Trie : 문자열을 효율적으로 처리하기 위한 트리 자료구조
 * 트리에 같은 단어와 그 단어의 끝을 정하는 pointer와 비슷한 지점을 놓는 것으로 구현
 * 
 * 시간 복잡도
 * 삽입 삭제 탐색시 O(|S|)
 * 
 * 단, 그냥 배열에 저장하는 것 보다 최대 4 * 글자의 종류 만큼 공간을 더 사용한다.
 * 
 * 이론적으로 시간복잡도와는 별개로 트라이는 해시나 이진 검색 트리에 비해서 훨씬 느리지만
 * 트라이의 성질이 필수적인 상황이 존재함
 */


// 루트의 번호는 1로 고정이고 새로 정점이 추가될 때 마다 2, 3, 4, ... 순으로 번호를 부여합니다. 
// 이렇게 번호를 부여할 때 unused가 쓰이게 됩니다.

// chk는 이전에 초록색 테두리로 보여드렸던, 해당 정점이 문자열의 끝인지 여부를 저장하는 배열입니다. 
// 마지막으로 nxt는 각 정점에서 자식 정점의 번호를 의미합니다. 
// 지금은 가능한 문자의 종류가 알파벳 소문자로 26개여서 nxt 배열을 nxt[MX][26]으로 선언했는데 
// 만약 문자의 종류가 50개라면 nxt[MX][50]으로 선언을 해야 합니다. 
// 자식 정점의 번호를 이렇게 관리하기 때문에 매 순간마다 이동해야 하는 자식 정점의 번호를 O(1)에 알 수 있지만, 
// 단점으로는 각 정점마다 26칸을 할당하고 있어야 하기 때문에 메모리를 상당히 많이 사용합니다.

const int root = 1;
int unused = 2;
const int mx = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
bool chk[mx];
int nxt[mx][26];

int c2i(char c){
    return c - 'a';
}

void insert(string& s){
    int cur = root;
    for(auto c : s){
        if(nxt[cur][c2i(c)] == -1){
            nxt[cur][c2i(c)] = unused++;
            // 존재하지 않는 정점을 만나면 정점번호 늘리기
        }
        cur = nxt[cur][c2i(c)];
        // 현재 정점을 다음 정점으로 변경
    }
    chk[cur] = true;
    // 존재하는 부분에 chk
}

bool find(string& s){
    int cur = root;
    for(auto c : s){
        if(nxt[cur][c2i(c)] == -1){
            return false;
            // 존재하지 않는 정점이면 바로 false를 return
        }
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

void erase(string& s){
    int cur = root;
    for(auto c : s){
        if(nxt[cur][c2i(c)] == -1){
            return ;
            // 존재하지 않는 정점이면 함수를 종료
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = false;
    // 존재할리 없으므로 chk를 false로
}

// 배열 지정이 아닌 방식인 동적 배열로 푸는 방법이 메모리 제한에서 유리하지만
// 대부분은 넉넉하게 쥐어주므로 그냥 푸는게 낫다