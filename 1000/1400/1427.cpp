#include <iostream>

using namespace std;
int num[10];

void swap(int *a , int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int split(int value){
	int cur = value;
	int x_num[10];
	int div_value;
	int div_res;

	int count = 0;
	while(cur != 0){
		div_res = cur % 10;
		x_num[count] = div_res;
		cur /= 10;
		count++;
	}
	for(int i = 0 ; i < count ; i++){
		num[i] = x_num[count - i -1];
	}
	return count;
}

void q_sort(int start, int last){
	if(start + 1  >= last) return;
	int small = start;
	for(int i = start+1 ; i < last ; i ++){
		if(num[i] > num[start]){
			small++;
			swap(num[i], num[small]);
		}
	}
	swap(num[small],num[start]);
	q_sort(start,small);
	q_sort(small+1,last);
	
	return;

}
int make_int(int size)
{
	int result = 0;
	int value = 0;
	int digit = 1;
	for(int i = 0 ; i < size ; i++){
		value = num[size - i -1] * digit;
		result += value;
		digit *= 10;
	}
	return result;
}
int main(){
	int N;
	scanf("%d",&N);
	int size = split(N);
	q_sort(0,size);
	printf("%d\n",make_int(size));
	return 0;
}