#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include<string.h>
using namespace std;
int visited[1000000];
struct node{
	int x;
	int num;
};
int main(){
	memset(visited,0,sizeof(int)*1000000);
	int F,S,G,U,D;
	queue<node> stir;
	node curr;
	scanf("%d%d%d%d%d",&F,&S,&G,&U,&D);
	curr.x = S;
	curr.num = 0;
	stir.push(curr);
	while(!stir.empty()){
		curr = stir.front();
		stir.pop();
		int x = curr.x;
		int num = curr.num;
		if(x == G){printf("%d\n",num); return 0;}
		if(x > 0 && x <= F){
			if(x > D){
				if(visited[x-D] == 0){
				visited[x-D] =1;
				curr.x = x -D;
				curr.num = num+1;
				stir.push(curr);
			}
			}
			if(x <= F-U){if(visited[x+U] == 0){
				visited[x+U] =1;
				curr.x = x + U;
				curr.num = num+1;
				stir.push(curr);
			}
			}
		}

	}
	printf("use the stairs\n");
	return 0;
}