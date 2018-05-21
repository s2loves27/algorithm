#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
struct node{
	int x;
	int y;
	
};
struct node_2{
	int x;
	int y;
	int num;
};
using namespace std;
char map[1002][1002];
int visited[1002][1002];
queue<node> Q_fire;
queue<node_2> Q;
int fire_count = 0;

node_2 start;
node temp;
node sa;

int T;
int h,w;
int temp_count = 0;
char save;

int result = 0;
int temp_count_1 = 0;
int num_1;
int num=0;
int x;
int y;

int main(){

	
	
	
	scanf("%d",&T);
	


	for(int z = 0 ; z < T ; z++){
		result = 0;
		num =0;
		memset(map,'0',sizeof(char) * 1002 * 1002);
		memset(visited,0,sizeof(int) * 1002 * 1002);
		while(!Q.empty()){
			Q.pop();
		}
		while(!Q_fire.empty()){
			Q_fire.pop();
		}
		
		fire_count = 0;
		scanf("%d%d",&w,&h);
	for(int i = 1 ; i <= h ; i++){
		for(int j = 1 ; j <= w ; j++){
			scanf("%c",&save);
			if(save == '\n') j--;
			else map[i][j] = save; 
			if(save == '@') {start.x = i ;start.y = j; start.num =1; visited[i][j] =1;}
			if(save == '*') {
				temp.x = i;
				temp.y = j;
				Q_fire.push(temp); } 
		}
	}

	// for(int i = 1 ; i <= h ; i++){
	// 	for(int j = 1 ; j <= w ; j++){
	// 		printf("%c",map[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	
	Q.push(start);

	while(!Q.empty()){

		start = Q.front();
		Q.pop();
		x = start.x;
		y = start.y;
		num_1 = start.num;
		temp_count = Q_fire.size();
		//printf("%d %d %d %d %d\n",z,x,y,temp_count,num);
		if(map[x][y] == '0') {result = 1; break; }
		if(num_1 != num){
		for(int i = 0 ; i < temp_count ; i ++) {
			temp = Q_fire.front();
			Q_fire.pop();
			if(map[temp.x+1][temp.y] != '*' && map[temp.x+1][temp.y] != '#' && map[temp.x+1][temp.y] != '0'){
				map[temp.x+1][temp.y] = '*';
				sa.x = temp.x+1;
				sa.y = temp.y;
				Q_fire.push(sa);
			}
			if(map[temp.x-1][temp.y] != '*' && map[temp.x-1][temp.y] != '#' && map[temp.x-1][temp.y] != '0'){
				map[temp.x-1][temp.y] ='*';
				sa.x = temp.x-1;
				sa.y = temp.y;  
				Q_fire.push(sa); 
				
			}
			if( map[temp.x][temp.y+1] != '*' &&map[temp.x][temp.y+1] != '#' && map[temp.x][temp.y+1] != '0'){
				map[temp.x][temp.y+1] ='*';
				sa.x = temp.x;
				sa.y = temp.y+1;  
				Q_fire.push(sa); 
			}
			if(map[temp.x][temp.y-1] != '*' && map[temp.x][temp.y-1] != '#'&& map[temp.x][temp.y-1] != '0'){
				map[temp.x][temp.y-1] ='*';
				sa.x = temp.x;
				sa.y = temp.y-1; 
				Q_fire.push(sa);  
				}
			}
			temp_count_1 = temp_count;
		}
		// if(num_1 != num){
		// 	for(int i = 1 ; i <= h ; i++){
		// 		for(int j = 1; j <= w ; j++){
		// 			if(map[i][j] == '*'){
		// 				if(map[i+1][j] == '.' || map[i+1][j] == '@'){
		// 					map[i+1][j] = '*';
		// 				}
		// 				if(map[i-1][j] == '.' || map[i-1][j] == '@'){
		// 					map[i-1][j] = '*';
		// 				}
		// 				if(map[i][j+1] == '.' || map[i][j+1] == '@'){
		// 					map[i][j+1] = '*';
		// 				}
		// 				if(map[i][j-1] == '.' || map[i][j-1] == '@'){
		// 					map[i][j-1] = '*';
		// 				}
		// 			}
		// 		}
		// 	}
		// }
		num = num_1;
		
		if(map[x+1][y] == '.'  && visited[x+1][y] == 0) {
			visited[x+1][y] = 1;
			start.x = x+1;
			start.y = y;
			start.num = num+1;
			Q.push(start);
		}
		if(map[x-1][y] == '.' && visited[x-1][y] == 0) {
			visited[x-1][y] = 1;
			start.x = x-1;
			start.y = y;
			start.num = num+1;
			Q.push(start);
		}
		if(map[x][y+1] == '.'  && visited[x][y +1] == 0) {
			visited[x][y+1] = 1;
			start.x = x;
			start.y = y+1;
			start.num = num+1;
			Q.push(start);
		}
		if(map[x][y-1] == '.'  && visited[x][y-1] == 0) {
			visited[x][y-1] = 1;
			start.x = x;
			start.y = y-1;
			start.num = num+1;
			Q.push(start);
		}
			if(map[x+1][y] == '0'  && visited[x+1][y] == 0) {
			num_1++;
			result = 1;
			break;
		}
		if(map[x-1][y] == '0'  && visited[x-1][y] == 0) {
			num_1++;
			result = 1;
			break;
		}
		if(map[x][y+1] == '0'  && visited[x][y +1 ] == 0) {
			num_1++;
			result = 1;
			break;
		}
		if(map[x][y-1] == '0'  && visited[x][y-1] == 0) {
			num_1++;
			result = 1;
			break;
		}

	}

	if(result == 1){
	printf("%d\n",num);
	}
	else {
		printf("IMPOSSIBLE\n");
	}	

	}
	
	return 0 ;
}