#include <iostream>

using namespace std;
int N,M;
int map[10][10];
bool ch_map[10][10];
int count = 3;
int result;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
struct birus{
	int x;
	int y;
};
struct birus bi[10];
int bi_count = 0;
int ch_blank;
int blank;
bool ch(int a){
	if(a == 0) return true;
	else return false;
}
int f3(int x,int y){
	
	if(ch_blank <= 0) return 0;
	for(int i = 0 ; i < 4 ; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(ch(map[xx][yy]) && !ch_map[xx][yy]){
			ch_map[xx][yy] = true;
			ch_blank--;
			f3(xx,yy);
		}
	}

}
void reset(){
	for(int i = 0; i < 10;i++){
		for(int j = 0 ; j < 10 ; j++){
			ch_map[i][j] = false;
		}
	}
}
int f2(){
	ch_blank = blank;
	for(int i = 0 ; i < bi_count; i++){
		f3(bi[i].x,bi[i].y);
	}
	//printf("%d\n",ch_blank);
	//printf("%d\n",ch_blank);
	reset();
	return ch_blank;
}
int max(int a , int b){
	if(a>b) return a;
	else return b;
}
void f1(){
	
	if(count == 0) {
		result = max(result,f2());
		return;
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(map[i+1][j+1] == 0){
				count--;
				map[i+1][j+1] = 1;
				f1();
				map[i+1][j+1] = 0;
				count++;
			}
		}	

	}


}

int main(){
	scanf("%d %d",&N,&M);
	reset();
	for(int i = 0 ; i < 10 ; i ++){
		for(int j = 0 ; j < 10 ; j++){
			map[i][j] = -1;
		}
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			scanf("%d",&map[i+1][j+1]);
			if(map[i+1][j+1] == 2){
				bi[bi_count].x = i+1;
				bi[bi_count].y = j+1;
				bi_count++;
			}
			else if(map[i+1][j+1] == 0){
				blank++;
			}
		}
	}
	blank -=3;
	f1();

	printf("%d\n",result);
	return 0;
}