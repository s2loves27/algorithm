#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
char map[1001][1001];
int visited_1[1001][1001];
int visited_2[1001][1001];
struct node{
int x;
int y;
int num;
int blocking;
};
int main(){
	memset(map,'2',sizeof(char) * 1001 * 1001);
	memset(visited_1,0,sizeof(int) * 1001 * 1001);
	memset(visited_2,0,sizeof(int) * 1001 * 1001);
	int N , M;
	char load;
	node curr;
	queue<node> Q;
	scanf("%d%d",&N,&M);
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= M ; j++){
				scanf("%c",&load);
				if(load == '\n') j--;
				else map[i][j] = load;
		}
	}

	curr.x = 1;
	curr.y = 1;
	curr.num = 1;
	curr.blocking = 1;
	Q.push(curr);
	visited_1[1][1] = 1;
	while(!Q.empty()){
		curr = Q.front();
		Q.pop();
		int x = curr.x;
		int y = curr.y;
		int num = curr.num;
		int blocking = curr.blocking;
		if(x == N && y == M) {printf("%d\n",num); return 0;}
		if(map[x+1][y]== '0' && visited_1[x+1][y] == 0 && blocking == 1){
			visited_1[x+1][y] = 1;
			curr.x = x+1;
			curr.y = y;
			curr.num = num+1;
			curr.blocking = blocking;
			Q.push(curr);
		}
		if(map[x][y+1]== '0' && visited_1[x][y+1] == 0 && blocking == 1){
			visited_1[x][y+1] = 1;
			curr.x = x;
			curr.y = y+1;
			curr.num = num+1;
			curr.blocking = blocking;
			Q.push(curr);
		}
		if(map[x-1][y]== '0' && visited_1[x-1][y] == 0 && blocking == 1){
			visited_1[x-1][y] = 1;
			curr.x = x-1;
			curr.y = y;
			curr.num = num+1;
			curr.blocking = blocking;
			Q.push(curr);
		}
		if(map[x][y-1]== '0' && visited_1[x][y-1] == 0 && blocking == 1){
			visited_1[x][y-1] = 1;
			curr.x = x;
			curr.y = y-1;
			curr.num = num+1;
			curr.blocking = blocking;
			Q.push(curr);
		}
		if(map[x+1][y]== '0' && visited_2[x+1][y] == 0 && blocking == 0){
			visited_2[x+1][y] = 1;
			curr.x = x+1;
			curr.y = y;
			curr.num = num+1;
			curr.blocking = blocking;
			Q.push(curr);
		}
		if(map[x][y+1]== '0' && visited_2[x][y+1] == 0 && blocking == 0){
			visited_2[x][y+1] = 1;
			curr.x = x;
			curr.y = y+1;
			curr.num = num+1;
			curr.blocking = blocking;
			Q.push(curr);
		}
		if(map[x-1][y]== '0' && visited_2[x-1][y] == 0 && blocking == 0){
			visited_2[x-1][y] = 1;
			curr.x = x-1;
			curr.y = y;
			curr.num = num+1;
			curr.blocking = blocking;
			Q.push(curr);
		}
		if(map[x][y-1]== '0' && visited_2[x][y-1] == 0 && blocking == 0){
			visited_2[x][y-1] = 1;
			curr.x = x;
			curr.y = y-1;
			curr.num = num+1;
			curr.blocking = blocking;
			Q.push(curr);
		}
		if(map[x+1][y]== '1'  && blocking ==1){
			curr.x = x+1;
			curr.y = y;
			curr.num = num+1;
			curr.blocking = 0;
			Q.push(curr);
		}
		if(map[x-1][y]== '1'  && blocking ==1){
		
			curr.x = x-1;
			curr.y = y;
			curr.num = num+1;
			curr.blocking = 0;
			Q.push(curr);
		}
		if(map[x][y+1]== '1' && blocking ==1){
			
			curr.x = x;
			curr.y = y+1;
			curr.num = num+1;
			curr.blocking = 0;
			Q.push(curr);
		}
		if(map[x][y-1]== '1'  && blocking ==1){

			curr.x = x;
			curr.y = y-1;
			curr.num = num+1;
			curr.blocking = 0;
			Q.push(curr);
		}
	}

	printf("-1\n");
	return 0;
}