#include <iostream>
#include <queue>
using namespace std;
//right =1 / left =2 / south = 3 / north = 4
int N,M;
int map[102][102];
int vigit[102][102][5];
int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};
struct point{
	int x;
	int y;
	int dir;
};
queue<point> q;
point start;
point arr;
int ch(int a,int b){
	if(a == 1 && b == 2) return 2;
	else if(a == 2 && b == 1) return 2;
	else if(a == 3 && b == 4) return 2;
	else if(a == 4 && b == 3) return 2;
	else if(a == b) return 0;
	else return 1; 
}
int f(){
	point cc;
	while(!q.empty()){

		point cur = q.front();
		q.pop();

		int x = cur.x;
		int y = cur.y;
		int dir = cur.dir;
		if(x == arr.x && y == arr.y) return vigit[x][y][dir] + ch(arr.dir,dir);

		for(int i = 1 ; i < 5 ; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if((map[xx][yy] == 0) && (dir == i)){
				if(vigit[xx][yy][i] == 0){
					vigit[xx][yy][i] = vigit[x][y][dir] + 1;
					cc.x = xx;
					cc.y = yy;
					cc.dir = i;
					q.push(cc);
				}
				xx = xx + dx[i];
				yy = yy + dy[i];
				if(map[xx][yy] == 0){
					if(vigit[xx][yy][i] == 0){
						vigit[xx][yy][i] = vigit[x][y][dir] + 1;
						cc.x = xx;
						cc.y = yy;
						cc.dir = i;
						q.push(cc);
					}
					xx = xx + dx[i];
					yy = yy + dy[i];
					if(map[xx][yy] == 0){
						if(vigit[xx][yy][i] == 0){
						vigit[xx][yy][i] = vigit[x][y][dir] + 1;
						cc.x = xx;
						cc.y = yy;
						cc.dir = i;
						q.push(cc);
						}
					}else{continue;}
				}else {continue;}
			}
				
			else if((map[xx][yy] == 0) && (dir != i)){
				if(vigit[x][y][i] == 0){
					vigit[x][y][i] = vigit[x][y][dir] + ch(dir,i);
					cc.x = x;
					cc.y = y;
					cc.dir = i;
					q.push(cc);
				}
			}
		}
	}
	return -1;
}
int main(){
	scanf("%d %d", &M , &N);

	for(int i = 0 ; i <= M+1 ; i++){
		for(int j = 0 ; j <= N+1 ; j++){
			map[i][j] = -1;
		}
	}

	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d",&map[i+1][j+1]);
		}
	}
	scanf("%d %d %d",&start.x,&start.y,&start.dir);
	scanf("%d %d %d",&arr.x,&arr.y,&arr.dir);
	q.push(start);
	printf("%d\n",f());



}