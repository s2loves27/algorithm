#include <cstdio>
#include <cmath>
#include <algorithm>
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

int main(){
	memset(map,'0',sizeof(char) * 1002 * 1002);
	memset(visited,0,sizeof(int) * 1002 * 1002);
	int T;
	int h,w;
	int num=0;
	int temp_count = 0;
	char save;
	node temp;
	int fire_count = 0;
	node_2 start;
	vector<node> Q_fire;
	scanf("%d",&T);
	queue<node_2> Q;
	for(int z = 0 ; z < T ; z++){
		while(!Q.empty()){
			Q.pop();
		}
		memset(visited,0,sizeof(int) * 1002 * 1002);
		Q_fire.clear();
		fire_count = 0;
	scanf("%d%d",&w,&h);
	for(int i = 1 ; i <= h ; i++){
		for(int j = 1 ; j <= w ; j++){
			scanf("%c",&save);
			if(save == '\n') j--;
			else map[i][j] = save; 
			if(save == '@') {start.x = i ;start.y = j; start.num =1;}
			if(save == '*') {
				temp.x = i;
				temp.y = j;
				Q_fire.push_back(temp); } 
		}
	}
	// for(int i = 1 ; i <= h ; i++){
	// 	for(int j = 1 ; j <= w ; j++){
	// 		printf("%c",map[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	
	Q.push(start);
	// printf("%d %d\n",w ,h );
	// printf("-----------\n");
	// printf("%d\n" , fire_count);
	//for(int i = 0 ; i < fire_count ; i++) printf("%d %d\n", fire[i].x , fire[i].y);
	//for(int i = 1 ; i < fire_count ; i++) Q_fire.push_back(fire[i]);
	//for(int i = 0 ; i < Q_fire.size() ; i++) printf("%d %d\n",Q_fire.at(i).x,Q_fire.at(i).y);

	int result = 0;
	int temp_count_1 = 0;
	int temp_count;
	int num_1;
	while(!Q.empty()){

		start = Q.front();
		Q.pop();
		node sa;
		int new_count = 0;
		int x = start.x;
		int y = start.y;
		num_1 = start.num;
		//printf("%d %d %d %d\n",z,x,y,Q_fire.size());
		if(map[x][y] == '0') {result = 1; break; }
		if(num_1 != num){

		temp_count = Q_fire.size();
		for(int i = 0 ; i < temp_count ; i ++) {
			temp = Q_fire.at(i);
			if(map[temp.x+1][temp.y] != '*' && map[temp.x+1][temp.y] != '#' && map[temp.x+1][temp.y] != '0'){
				map[temp.x+1][temp.y] = '*';
				sa.x = temp.x+1;
				sa.y = temp.y;
				Q_fire.push_back(sa);
			}
			if(map[temp.x-1][temp.y] != '*' && map[temp.x-1][temp.y] != '#' && map[temp.x-1][temp.y] != '0'){
				map[temp.x-1][temp.y] ='*';
				sa.x = temp.x-1;
				sa.y = temp.y;  
				Q_fire.push_back(sa); 
				
			}
			if( map[temp.x][temp.y+1] != '*' &&map[temp.x][temp.y+1] != '#' && map[temp.x][temp.y+1] != '0'){
				map[temp.x][temp.y+1] ='*';
				sa.x = temp.x;
				sa.y = temp.y+1;  
				Q_fire.push_back(sa); 
			}
			if(map[temp.x][temp.y-1] != '*' && map[temp.x][temp.y-1] != '#'&& map[temp.x][temp.y-1] != '0'){
				map[temp.x][temp.y-1] ='*';
				sa.x = temp.x;
				sa.y = temp.y-1; 
				Q_fire.push_back(sa);  
				}
			}
			Q_fire.erase(i);
			temp_count_1 = temp_count;
		}
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
		if(map[x][y+1] == '.'  && visited[x][y +1 ] == 0) {
			visited[x-1][y] = 1;
			start.x = x;
			start.y = y+1;
			start.num = num+1;
			Q.push(start);
		}
		if(map[x][y-1] == '.'  && visited[x][y-1] == 0) {
			visited[x-1][y] = 1;
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
	printf("%d\n",num_1);
	}
	else {
		printf("-1\n");
	}	

	}
	
	return 0 ;
}