#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
struct node{
int x;
int y;
int num;
};
int visited[305][305];
int main(){
	int T,L;
	int start_x ,start_y;
	int destination_x , destination_y;
	node curr;
	
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i++){
		memset(visited,0,sizeof(int) * 305 * 305);
		queue<node> nite;
		scanf("%d",&L);
		scanf("%d%d",&start_x , &start_y);
		scanf("%d%d",&destination_x , &destination_y);
		curr.x = start_x;
		curr.y = start_y;
		curr.num = 0;
		nite.push(curr); 
		while(!nite.empty()){
			curr = nite.front();
			nite.pop();
			int x = curr.x;
			int y = curr.y;
			int num = curr.num;
			if(x == destination_x && y == destination_y){
				printf("%d\n",num);
				break;
			}
			if(x < L && y < L){
			if(visited[x+1][y+2] == 0){
			visited[x+1][y+2] = 1;
			curr.x = x + 1;
			curr.y = y + 2;
			curr.num = num+1;
			nite.push(curr);
			}
			if(x > 0){
			if(visited[x-1][y+2] == 0){
				visited[x-1][y+2] =1;
			curr.x = x - 1;
			curr.y = y + 2;
			curr.num = num+1;
			nite.push(curr);
			}
			}
			if(y > 1){
				if(visited[x+1][y-2] == 0){
			visited[x+1][y-2] =1;
			curr.x = x + 1;
			curr.y = y - 2;
			curr.num = num+1;
			nite.push(curr);
		}
			}
			if(x>0 && y> 2){
				if(visited[x-1][y-2]== 0){
					visited[x-1][y-2] =1;
			curr.x = x - 1;
			curr.y = y - 2;
			curr.num = num+1;
			nite.push(curr);
		}
			}
			if(visited[x+2][y+1]== 0){
				visited[x+2][y+1] =1;
			curr.x = x + 2;
			curr.y = y + 1;
			curr.num = num+1;
			nite.push(curr);
			}
			if(x > 1){if (visited[x-2][y+1]== 0){
				visited[x-2][y+1] = 1;
			curr.x = x - 2;
			curr.y = y + 1;
			curr.num = num+1;
			nite.push(curr);
			}
			}
			if(y > 0){if(visited[x+2][y-1]== 0){
				visited[x+2][y-1] =1;
			curr.x = x + 2;
			curr.y = y - 1;
			curr.num = num+1;
			nite.push(curr);
		}
			}
			if(x > 1 && y>0){ if(visited[x-2][y-1]== 0){
				visited[x-2][y-1] =1;
			curr.x = x - 2;
			curr.y = y - 1;
			curr.num = num+1;
			nite.push(curr);
		}
		}
			}


		}
	}


}