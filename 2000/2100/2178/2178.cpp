#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>
#include<string.h>
using namespace std;
char map[102][102];
int N,M;
int min_num = 10000000;
struct node{
	int raw;
	int col;
	int num;
};
queue<node> Q;
int f(int raw, int col,int num){
	node a;
	a.raw = raw;
	a.col = col;
	a.num = num;
	Q.push(a);
	map[a.raw][a.col] = '0';
	while(!Q.empty()){
		node a = Q.front();
		Q.pop();

		int re_raw = a.raw;
		int re_col = a.col;
		int re_num = a.num;
		
		if(re_raw == N && re_col == M) {
			min_num = re_num;
			return 0;
		}
		if(map[re_raw+1][re_col] == '1'){
			a.raw = re_raw+1;
			a.col = re_col;
			a.num = re_num+1;
			Q.push(a);
			map[re_raw+1][re_col] = '0';
		}
		if(map[re_raw-1][re_col] == '1'){
			a.raw = re_raw-1;
			a.col = re_col;
			a.num = re_num+1;
			Q.push(a);
			map[re_raw-1][re_col] = '0';
		}
		
		if(map[re_raw][re_col+1] == '1'){
			a.raw = re_raw;
			a.col = re_col+1;
			a.num = re_num+1;
			Q.push(a);
			map[re_raw][re_col+1] = '0';
		}
		if(map[re_raw][re_col-1] == '1'){
			a.raw = re_raw;
			a.col = re_col -1;
			a.num = re_num +1;
			Q.push(a);
			map[re_raw][re_col-1] = '0';
		}

		
	}
}
int main(){
	char chch;
	scanf("%d%d",&N,&M);
	memset(map,'0',sizeof(char) * 102 * 102);
	for(int i = 1 ; i <= N ; i++ ){
		for(int j = 1 ; j <= M ; j++){
			scanf("%c",&chch);
			if(chch == '\n') j--;
			else map[i][j] = chch;
		}
	}
	f(1,1,1);
	printf("%d",min_num);
	return 0 ;
}
