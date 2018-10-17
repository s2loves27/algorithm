#include <iostream>

using namespace std;
int N,M;
int count;
int num[8];
int pr[8];
int ch[9];
int value[9];
int cnt[9];
void f1(int m){
	if(m == M){
		for(int i = 0 ; i < M ; i++){
			printf("%d ",pr[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 0 ; i <= count ; i++){
			pr[m] = value[i]; 
			f1(m+1);
	}
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void q_sort(int start, int last){
	if(start + 1 >= last) return;
	int cur = start;
	for(int i = start + 1 ; i < last; i++){
		if(num[start] > num[i]){
			cur++;
			swap(num[cur],num[i]);
		}
	}
	swap(num[start],num[cur]);
	q_sort(start,cur);
	q_sort(cur+1,last);
}
int main(){

	scanf("%d %d",&N,&M);
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&num[i]);
	}
	
	q_sort(0,N);

	count = 0;
	value[0] = num[0];
	cnt[0]++;

	for(int i = 1 ; i < N ; i++){
		if(num[i] != num[i-1]) value[++count] = num[i];
		cnt[count]++;
	}

	f1(0);

	return 0;
}