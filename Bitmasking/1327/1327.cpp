#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N,K,f_result[8];
bool ch[90000000];
typedef struct va{
	int num[8];
	int count;
}va;
va a;
void input(){
	
	scanf("%d%d",&N,&K);
	for(int i = N; i > 0 ; i --){
		scanf("%d",&a.num[N - i]);
		
	}
	a.count =0;
	for(int i = 0; i < N ; i++){
		f_result[i] = i+1;
	}
}
int make_int(int num[]){
	int result = 0;
	for(int i = 0 ; i < N ; i++){
		int mul = 1;
		for(int j = N-i-1 ; j > 0 ; j--){
		mul *= 10;	
		}
		result += num[i]*mul;
	}
	return result;
}
void reverseArrayInt(int* array, int size) {
  int temp;

  for (int i = 0; i < size / 2; i++) {
    temp = array[i];
    array[i] = array[(size - 1) - i];
    array[(size - 1) - i] = temp;
  }
}
bool compare(int* array1 , int* array2,int size)
{	
	int i;
	for(i = 0 ; i < size ; i++) {
		if(array1[i] != array2[i]) break; 
	}
	if(i == size) return true;
	else return false;
}
int f(){
	int cur = 0;
	queue<va> Q;
	Q.push(a);
	while(!Q.empty()){
		va temp = Q.front();
		int count = temp.count;
		Q.pop();
		if(compare(temp.num,f_result,N)) return temp.count;
		for(int i = 0 ; i<N-K +1; i++){
			reverseArrayInt(&temp.num[i],K);
			int value = make_int(temp.num);
			if(!ch[value]){
				ch[value] = true;
				count ++;
				temp.count = count;
				Q.push(temp);
				count --;
			}
			reverseArrayInt(&temp.num[i],K);
		}

	}
	return -1;

}

int main(){
	memset(ch,false,0);
	input();
	printf("%d\n",f());
	return 0;
}