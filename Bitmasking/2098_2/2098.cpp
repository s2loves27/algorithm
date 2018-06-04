#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;
 
int N, W[16][16], dp[16][1<<16];
 
int co=0;
int TSP(int current, int visited){
    
    if(dp[current][visited] != -1) return dp[current][visited];
    // base case: 모든 마을을 방문함
    if(visited == (1<<N)-1){
        if(W[current][0] != 0) return W[current][0];
        return IMPOSSIBLE; // 시작점으로 갈 수 없음
    }
    //if(dp[current][visited] != -1) return dp[current][visited];
    int ret = IMPOSSIBLE;
    for(int i=0; i<N; i++){
        // i번 마을을 이미 방문했거나 i번 마을로 갈 수 없음
        if(visited & (1<<i) || W[current][i] == 0) continue;
        // 그 외
        ret = min(ret, TSP(i, visited | (1<<i)) + W[current][i]);
    }
    return ret;
}
 
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &W[i][j]);
 
    memset(dp, -1, sizeof(dp));
    printf("%d\n", TSP(0, 1));
    //printf("%d\n",co);
}
