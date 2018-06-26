#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdlib.h>

int N,r,c;
int count = 0;
int r_count = 0;
int raw_ca[4] = {0,0,1,1};
int col_ca[4] = {0,1,0,1};
bool ch = false;
void f(int raw,int col,int size){
	if(size == 0){
		//if(raw == r && col == c) {printf("%d\n",count);}
		printf("%d",count);
		return;
		
	}
	if(r >=raw +  pow(2,size-1) && c < col +pow(2,size-1)){
		count = count + pow(4,size-1) * 2;
		f(raw+pow(2,size-1),col,size-1);
	}
	else if(r < raw + pow(2,size-1) && c >= col +pow(2,size-1)){
		count = count + pow(4,size-1);
		f(raw,col+pow(2,size-1),size-1);
		
	}
	else if(r < raw + pow(2,size-1) && c < col + pow(2,size-1)){
		f(raw,col,size-1);
	}
	else {
		count = count + pow(4,size-1) *3;
		f(raw+pow(2,size-1),col+pow(2,size-1),size-1);
	}



}

int main(){
	scanf("%d %d %d",&N,&r,&c);
	f(0,0,N);
	//printf("%d\n", r_count);
}