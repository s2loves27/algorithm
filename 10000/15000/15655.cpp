#include <iostream>

using namespace std;
int N,M;
int num[9];
int ch[9];
int pr[9];
void f(int n, int m){
	if(m == M){
		for(int i = 0 ; i < M ; i++){
			printf("%d ", pr[i]);

		}
		printf("\n");
		return;
	}
	for(int i = n ; i < N ; i++){
		if(!ch[i]){
			ch[i] = 1;
			pr[m] = num[i];
			f(i,m+1);
			ch[i] = 0;
		}
	}
}
void swap(int *a , int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void q_sort(int start, int last){
	if(start+1 >= last) return;
	int small = start;
	for(int i = start+1; i < last ; i++){
		if(num[i] < num[start]){
			small++;
			swap(num[small], num[i]);
		}
	}
	swap(num[start], num[small]);
	q_sort(start,small);
	q_sort(small+1,last);
}
int main(){

	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; i ++){
		scanf("%d", &num[i]);
	}
	q_sort(0,N);
	f(0,0);

	return 0;
}