#include <iostream>
using namespace std;
int N,M;
int map[10][10];
int v_map[10][10][10];
int result = 10000;
struct point{
	int x;
	int y;
	int number;
};
point camera[10];
int camera_count;

void up(int x , int y){
	for(int i = x ; i > 0 && map[i][y] != 6 ; i-- ){
		map[i][y] = -1;
	}
}
void down(int x , int y){
	for(int i = x ; i <= N && map[i][y] != 6 ; i++ ){
		map[i][y] = -1;
	}
}
void left(int x, int y){
	for(int i = y ; i > 0 && map[x][i] != 6 ; i-- ){
		map[x][i] = -1;
	}
}
void right(int x, int y){
	for(int i = y ; i <= M && map[x][i] != 6 ; i++ ){
		map[x][i] = -1;
	}
}


void copy(int v){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			v_map[v][i+1][j+1] = map[i+1][j+1];
		}
	}
}
void load(int v){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			map[i+1][j+1] = v_map[v][i+1][j+1]; 
		}
	}
}
int zero_count(){
	int temp = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(map[i+1][j+1] == 0) temp++;
		}
	}
	return temp;
}
int min(int a, int b){
	return a>b?b:a;

}
// 1: 4방향 // 2: 2방향 // 3: 4방향 // 4: 4방향 // 5: 1방향 
void f(int m){

	copy(m);
	if(m == camera_count){
		result = min(result , zero_count());
		return;
	}
	if(camera[m].number == 1){
		up(camera[m].x,camera[m].y);
		f(m+1);

		load(m);
		down(camera[m].x,camera[m].y);
		f(m+1);

		load(m);
		left(camera[m].x,camera[m].y);
		f(m+1);

		load(m);
		right(camera[m].x,camera[m].y);
		f(m+1);
	}
	if(camera[m].number == 2){
		up(camera[m].x,camera[m].y);
		down(camera[m].x,camera[m].y);
		f(m+1);


		load(m);
		left(camera[m].x,camera[m].y);
		right(camera[m].x,camera[m].y);
		f(m+1);
	}
	if(camera[m].number == 3){
		up(camera[m].x,camera[m].y);
		left(camera[m].x,camera[m].y);
		f(m+1);

		load(m);
		up(camera[m].x,camera[m].y);
		right(camera[m].x,camera[m].y);
		f(m+1);		
		
		load(m);
		down(camera[m].x,camera[m].y);
		right(camera[m].x,camera[m].y);
		f(m+1);

		load(m);
		down(camera[m].x,camera[m].y);
		left(camera[m].x,camera[m].y);
		f(m+1);
	}
	if(camera[m].number == 4){
		up(camera[m].x,camera[m].y);
		left(camera[m].x,camera[m].y);
		right(camera[m].x,camera[m].y);
		f(m+1);

		load(m);
		up(camera[m].x,camera[m].y);
		right(camera[m].x,camera[m].y);
		down(camera[m].x,camera[m].y);
		f(m+1);

		load(m);
		right(camera[m].x,camera[m].y);
		left(camera[m].x,camera[m].y);
		down(camera[m].x,camera[m].y);
		f(m+1);

		load(m);
		up(camera[m].x,camera[m].y);
		left(camera[m].x,camera[m].y);
		down(camera[m].x,camera[m].y);
		f(m+1);
	}
	if(camera[m].number == 5){
		up(camera[m].x,camera[m].y);
		left(camera[m].x,camera[m].y);
		right(camera[m].x,camera[m].y);
		down(camera[m].x,camera[m].y);
		f(m+1);
	}
}
int main(){

	scanf("%d %d",&N, &M);
	for(int i = 0 ; i <= N +1 ; i++){
		for(int j = 0 ; j <= M +1; j++){
			map[i][j] = -1;
		}
	}

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			scanf("%d",&map[i+1][j+1]);
			if(map[i+1][j+1] > 0 && map[i+1][j+1] < 6){
				camera[camera_count].x = i+1;
				camera[camera_count].y = j+1;
				camera[camera_count].number = map[i+1][j+1];	
				camera_count++;
			}
		}
	}
	f(0);
	printf("%d\n",result);
	return 0;
}