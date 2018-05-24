#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
char number[100];
int int_number[100];
int co;
int num_size;
int max_num;
int vigited[51] = {0};
bool result = false;
void print();
int f(int i){
	if(num_size <= i-1) {
		result = true;
		return 0;
	}
	if(result) return 0;
	if(number[i] == '\0') 
		{
			result = true;
			return 0;
		}
	
	if(!vigited[number[i] - '0'] && number[i] - '0' != 0){
		vigited[number[i] - '0'] = 1;
		int_number[co++] = number[i] - '0';
		f(i+1);
		if(result) return 0;
		co--;
		vigited[number[i] - '0'] = 0;
	}
	
	if(number[i+1] == '\0') {
		result = true;
		return 0;}
	if(number[i] < '5' && number[i] > '0' && (number[i] - '0') * 10 + (number[i+1] - '0') <= max_num){
		if(!vigited[(number[i] - '0') * 10 + (number[i+1] - '0')]){
			vigited[(number[i] - '0') * 10 + (number[i+1] - '0')] =1;
		int_number[co++] = (number[i] - '0') * 10 + (number[i+1] - '0');
		f(i+2);
		if(result) return 0;
		co--;
		vigited[(number[i] - '0') * 10 + (number[i+1] - '0')] = 0;
		}
	}
	if(number[i] == '5' && number[i+1] == '0' && (number[i] - '0') * 10 + (number[i+1] - '0') <= max_num){
		if(!vigited[50]){
		vigited[50] = 1;
		int_number[co++] = (number[i] - '0') * 10 + (number[i+1] - '0');
		f(i+2);
		if(result) return 0;
		co--;
		vigited[50] = 0;
		}
	}
	return 3;

}


void input(){
	scanf("%s",number);
	num_size = strlen(number);
	if(num_size < 10) max_num = num_size;
	else {
		max_num = 10 + (num_size-10)/2;
		}
}
void print(){
	for(int i = 0 ; i < co ; i++){
		printf("%d ",int_number[i]);
	}
}
int main(){
	input();
	f(0);
	print();
}