//필요하지 않는 부분은 미리 만들어 놓는다. !!


#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

char star[6561][6561];
int N;

void print(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			printf("%c",star[i][j]);
		}
		printf("\n");
	}
}

int f(int rs , int rf, int cs, int cf){

	if(rf - rs == 1) {
		star[rs][cs] = '*';
		return 0;
	}

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			//printf("%d\n",rs + ((rf-rs) * i) /3 );
			if(i != 1 || j != 1) f(rs + ((rf-rs) * i)/3 , rs + ((rf-rs) *(i+1)/3) , cs + ((cf-cs) * j) /3  , cs + ((cf-cs) * (j+1)/3) );
		}
	}

	
	return 1;
}


int main(){
	memset(star, ' ' , sizeof(star));
	scanf("%d",&N);
	f(0,N,0,N);
	print();
}