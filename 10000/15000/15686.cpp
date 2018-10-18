#include <iostream>
#define Queuesize 10000
using namespace std;
int N,M;
int map[52][52];
int d[99][15];
int vigit[15];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int result = 10000;
struct point{
	int x;
	int y;
};
point house[99];
int house_count ;
point chiken[15];
int chiken_count;
//queue q_x,q_y,q_count;
// class queue{
// private:
// 	int front,rear;
// 	int arr[Queuesize];
// public:
// 	void init(){front = 0 ; rear = 0;}
// 	bool isEmpty(){return front == rear ? true : false;}
// 	bool isFull(){return (rear+1)%Queuesize ? true : false;}
// 	void push(int value){arr[rear++%Queuesize] = value;}
// 	int pop(){return arr[front++%Queuesize];}
// };
int min(int a, int b){
	return a < b?a:b;
}

int f(int k,int m){

	if(m == M){
		int temp = 1000;
		int temp_sum = 0;
		for(int i = 0 ; i < house_count;i++){
			temp = 10000;
			for(int j = 0 ; j < m ; j++){
				temp = min(temp, d[i][vigit[j]]);
			}
			temp_sum += temp;
		}
		result = min(result , temp_sum);
		return 0;

	}

	for(int i = k ; i < chiken_count;i++){
		if(vigit[i] == 0){
			vigit[m] = i; 
			f(i,m+1);
			vigit[m] = 0;

		}
	}

}
int abs(int a,int b){
	if(a > b) return a-b;
	else return b-a;

}
int main(){
	//x.init();y.init();q_count.init();

	scanf("%d %d",&N,&M);
	for(int i = 0 ; i <= N+1 ; i++){
		for(int j = 0 ; j <= N+1 ;j++){
			map[i][j] = -1;
		}
	}
	int temp;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d",&temp);
			map[i+1][j+1]=temp;
			if(temp == 1) {
				house[house_count].x = i+1;
				house[house_count].y = j+1;
				house_count++;
			}
			else if(temp == 2){
				chiken[chiken_count].x = i+1;
				chiken[chiken_count].y = j+1;
				chiken_count++;
			}
		}
	}
	for(int i = 0 ; i < house_count ; i++){
		for(int j = 0 ; j < chiken_count ; j++){
			d[i][j] = abs(house[i].x,chiken[j].x) + abs(house[i].y,chiken[j].y); 		
		}
	}
	f(0,0);
	printf("%d\n",result);

	return 0;
}