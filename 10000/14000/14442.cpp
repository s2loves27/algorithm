#include <iostream>
//#include <queue>
#define maxQueueSize 100000
using namespace std;
// N 1000 / M 1000 /K 10

int N,M,K;
char map[1002][1002];

int vigit[1002][1002][11];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int result = 100000000;
int co;
int min(int a, int b){
	if(a>b) return b;
	else return a;
}
class queue{
private:
	int arr[maxQueueSize];
	int front, rear;
public:
	bool isEmpty() {return front == rear?true:false;}
	bool isFull(){return (rear+1)%maxQueueSize == front ?true:false;}
	void init(){front = 0 ; rear =0;}
	void enq(int item) {if(!isFull()) arr[rear++%maxQueueSize] = item;}
	int deq(){if(!isEmpty()) return arr[front++%maxQueueSize];}
};

int f1(){
	queue q_x,q_y,q_block;
	q_x.init(); q_y.init(); q_block.init();
	q_x.enq(1);
	q_y.enq(1);
	q_block.enq(0);

	int cc = 0;
	while(!q_x.isEmpty()){
		
		int x = q_x.deq();
		int y = q_y.deq();
		int block = q_block.deq();


		if((x == N) && (y == M)) return vigit[x][y][block]+1;
		for(int i = 0 ; i < 4 ; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if((map[xx][yy] == '0') && (vigit[xx][yy][block] == 0)){
				
				vigit[xx][yy][block] = vigit[x][y][block] + 1;
				q_x.enq(xx);
				q_y.enq(yy);
				q_block.enq(block);
			}
			else if((map[xx][yy] == '1') && (block < K) && (vigit[xx][yy][block+1] == 0))
			{

				vigit[xx][yy][block+1] = vigit[x][y][block] + 1; 
				q_x.enq(xx);
				q_y.enq(yy);
				q_block.enq(block+1);
			}
		}
	}
	return -1;




}
// void f1(int x, int y,int count){
// 	if(x == N && y == M) {
// 		result = min(result , count);
// 	}

// 	for(int i = 0; i < 4 ; i++){
// 		if((map[x+dx[i]][y+dy[i]] == '1')&& K > 0  && (!ch[x+dx[i]][y+dy[i]])){
// 			ch[x+dx[i]][y+dy[i]] = true;
// 			K--;
// 			f1(x+dx[i],y+dy[i],count+1);
// 			K++;
// 			ch[x+dx[i]][y+dy[i]] = false;	

// 		}
// 		if((map[x+dx[i]][y+dy[i]] == '0') && (!ch[x+dx[i]][y+dy[i]])){
// 			ch[x+dx[i]][y+dy[i]] = true;
// 			f1(x+dx[i],y+dy[i],count+1);
// 			ch[x+dx[i]][y+dy[i]] = false;	
// 		}
// 	}
// }
// void f(int x, int y){
// 	if(co == K) {f1(1,1,1); return;}
// 	for(int i = x ; i < N ; i++ ){
// 		for(int j = y ; j < M ; j++){
// 			if(map[i+1][j+1] == '1'){
// 				map[i+1][j+1] = '0';
// 				co++;
// 				f(i,j);
// 				co--;
// 				map[i+1][j+1] = '1'; 
// 			}
// 		}
// 	}
// }
int main(){

	scanf("%d %d %d",&N,&M,&K);
	for(int i = 0 ; i <= N+1 ; i++){
		for(int j = 0 ; j <= M+1 ; j++){
			map[i][j] = '2';
		}
	}
	char temp;
	for(int i = 0 ; i < N ; i ++){
		for(int j = 0 ; j < M ; j++){
			scanf("%c",&temp);
			if(temp != '\n')
				map[i+1][j+1] = temp;
			else j--;
		}
	}
	//printf("%d\n",f1());
	printf("%d\n",f1());
	// if(result == 100000000 ) printf("-1\n");
	// else printf("%d\n",result);
	return 0;
}