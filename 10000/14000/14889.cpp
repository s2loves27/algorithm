#include<iostream>

using namespace std;
int N;
int map[20][20];
bool ch[20];
int team[2][10];
int member_count;
bool m_ch[10];
int result = 1000000;
int value;
int diff(int a , int b){
	if(a>b) return a-b;
	else return b-a;

}
int min(int a, int b){
	if(a>b) return b;
	else return a;
}

int f2(){
	int sum[2];
	sum[0] = 0;
	sum[1] = 0;
	for(int i = 0 ; i < member_count; i++){
		for(int j  = i+1 ; j < member_count ; j++){
			sum[0]+=map[team[0][i]][team[0][j]];
			sum[0]+=map[team[0][j]][team[0][i]];
			sum[1]+=map[team[1][i]][team[1][j]];
			sum[1]+=map[team[1][j]][team[1][i]];
		}
	}

	return diff(sum[0],sum[1]);
} 
void f1(int k,int m){
	if(m == N/2){
		int count = 0;
		for(int i = 0 ; i < N ; i++){
			if(!ch[i]) team[1][count++] = i;
		}
		result = min(result, f2());
		return;
	}
	for(int i = k ; i < N ; i++){

		if(!ch[i]){
			ch[i] = true;
			team[0][m] = i;
			f1(i,m+1);
			ch[i] = false;
		}
	}
}
int main(){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i = 0 ; i < 20 ; i++){
		ch[i] = false;
	}
	member_count = N/2;
	f1(0,0);	
	printf("%d\n",result);
	return 0;
}