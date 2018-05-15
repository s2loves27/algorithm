#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int IMPOSSIBLE = 1000000000;
int coin[101];
int result[10001] = {-1};

int f(int money,int met){
	if(money == 0) return 0;
	if(money < 0) return IMPOSSIBLE;
	if(result[money] != -1) return result[money];
	int mid_result = f(money - coin[0],met)+1;
	for(int i = 1 ; i < met ; i++)
		mid_result = min(mid_result,f(money-coin[i],met)+1);
	return result[money] = mid_result;
}

int main(){
	
	int n , k;
	fill(result , result + 10001,-1);
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&coin[i]);
	}

	f(k,n);
	if(result[k] >= IMPOSSIBLE){
		printf("-1\n");
	}
	else printf("%d\n",result[k]);

	return 0;
}