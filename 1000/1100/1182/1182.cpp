#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;
int S,N;
int set[20];
int result_sum = 0;
int cnt;
void input(){
	scanf("%d%d",&N,&S);
	for(int i = 0 ; i < N ; i++) scanf("%d",&set[i]);
}
int dfs(int i){
	if(i == N) return 0;

	if(S == result_sum + set[i]) cnt++;

	dfs(i+1);
	result_sum += set[i];
	dfs(i+1);
	result_sum -= set[i];
}
int main(){
 	input();
 	dfs(0);
 	printf("%d\n",cnt);
	return 0;
}