#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
int count =0;
int cut(int borad[20][20] ,int raw_start ,int raw_last, int col_start,int col_last,int imp,int cut_bo){
	printf("\n%d , %d , %d , %d , %d\n",raw_start,raw_last , col_start , col_last,imp);
	if(imp == 0 ){
		count++;
		return 0;
	}
	if(raw_start >= raw_last)
		return 0;
	if(col_start >= col_last)
		return 0;
	int ch_imp = 0;
	if (cut_bo == 0){
		for(int i = raw_start ; i < raw_last;i++){
			for(int j = col_start; j< col_last;j++){
				printf("%d ",borad[i][j]);
				if(borad[i][j] == 1){
					ch_imp =0;
					//printf("%d,%d\n",i,j);
					int z;
					for(z = raw_start; z < raw_last ; z++){
						if(borad[z][j] == 1){
							ch_imp++;
						}
						else if(borad[z][j] ==2){
							break;
						}
					}
					if(z == raw_last){
						cut(borad,raw_start,raw_last,col_start,j,imp-ch_imp,1);
						cut(borad,raw_start,raw_last,j+1,col_last,imp-ch_imp,1);
					}
					else{
						ch_imp = 0;
					}
				}
			}
			printf("\n");
		}
		
	}
	else if(cut_bo == 1){
		for(int i = raw_start ; i < raw_last;i++){
			for(int j = col_start; j < col_last;j++){
				printf("%d ",borad[i][j]);
				if(borad[i][j] == 1){
					ch_imp =0;
					int z;
					for(z = col_start; z < col_last ; z++){
						if(borad[i][z] == 1){
							ch_imp++;
						}
						else if(borad[i][z] ==2){
							break;
						}
					}
					if(z == col_last){
						if(ch_imp == 0){
							printf("end");
						}
						cut(borad,raw_start,i,col_start,col_last,imp-ch_imp,0);
						cut(borad,i+1,raw_last,col_start,col_last,imp-ch_imp,0);
					}
					else{
						ch_imp = 0;
					}
				}
			}
			printf("\n");
		}
		
	}
	return 0 ;


}

int main(){
	int s;
	int N;
	int imp=0;
	int borad[20][20];
	s = scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			s= scanf("%d",&borad[i][j]);
			if(borad[i][j] ==1){
				imp++;
			}
		}
	}
	//cut(borad,0 , 8 , 0 , 8,imp,0);
	cut(borad,0 , 8 , 0 , 8,imp,1);
	printf("%d",count);
	return 0;
}