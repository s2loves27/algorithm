#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
int N;
int map[103][103];
int result[103][103];
int vigit[103][103];
int count=0;
int f(int curr,int col,int raw){
	vigit[col][raw] = 1;
	if(map[col+1][raw] > curr && vigit[col+1][raw] != 1 )
		f(curr,col+1,raw);
	if(map[col-1][raw] > curr && vigit[col-1][raw] != 1)
		f(curr,col-1,raw);
	if(map[col][raw+1] > curr && vigit[col][raw+1] != 1)
		f(curr,col,raw+1);
	if(map[col][raw-1] > curr && vigit[col][raw-1] != 1)
		f(curr,col,raw-1);
	return 1;
}
int main(){
	int real_max =1;
	scanf("%d",&N);
	for(int i = 0 ; i <= N+1 ; i ++){
		for(int j = 0 ;  j <= N+1 ; j++){
			map[i][j] = -1;
			vigit[i][j] = -1;
		}
	}
	for(int i = 1 ; i <= N ; i ++){
		for(int j = 1 ;  j <= N ; j++){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i = 1 ; i <= 100 ; i++){
		memset(vigit,-1,sizeof(int) * 103 * 103);
		int c_max = 0;
		for(int j = 1 ; j <= N ; j++){
			for(int z = 1 ; z <= N ; z++){
				if(vigit[j][z] != 1 && map[j][z] > i) c_max += f(i,j,z);
			}
		}
		if(real_max < c_max){
			real_max = c_max;
		}
	}
	printf("%d",real_max);

}