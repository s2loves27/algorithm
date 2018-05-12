#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int length,width,height;
	int N;
	int cube_length[20];
	int cube_number[20];
	int temp;
	int box_vol;
	int cube_vol;
	int cube_count = 0;
	int c= scanf("%d %d %d",&length,&width,&height);
	c=scanf("%d",&N);
	for(int i = 0 ; i < N ; i ++){
		c=scanf("%d %d",&cube_length[i],&cube_number[i]);
	}
	for(int i = 0 ; i < N ; i ++){
		for(int j = i+1 ; j < N ; j++){
			if(cube_length[i] > cube_length[j]){
				temp = cube_length[i];
				cube_length[i] = cube_length[j];
				cube_length[j] = temp;
				temp = cube_number[i];
				cube_number[i] = cube_number[j];
				cube_number[j] = temp;
			}
		}
	}
	box_vol = length * width * height;
	for(int i = N-1 ; i >= 0 ; i--){
		if( (pow(2,cube_length[i]) > length) ||  (pow(2,cube_length[i]) > width) || (pow(2,cube_length[i]) > height)){
			continue;
		}
		cube_vol = pow(2,cube_length[i]) * pow(2,cube_length[i]) *pow(2,cube_length[i]);
		for(int j = 0 ; j < cube_number[i] ; j++){
			if(box_vol >= cube_vol){
				box_vol -= cube_vol;
				cube_count++;
			}
			else{
				break;
			}
		}
	}
	if(box_vol == 0){
		printf("%d\n",cube_count);
	}
	else{
		printf("-1\n");
	}

	return 0;
}