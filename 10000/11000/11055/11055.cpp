#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int a[1002];
int coun = 0;

// int f(int N){
// 	if(N < 0) return 0;
// 	if(result[N] != 0) return result[N];
// 	return result[N] = max(f(N-1) + a[N],

// }
int main(){
	int N;
	int s;
	int ch = 0;
	vector<int> v[1002];
	scanf("%d",&N);
	for (int i = 0 ; i < N ; i++) scanf("%d",&a[i]);

	if(N == 1) {
		printf("%d\n",a[0]);
		return 0;
	}
	for (int i = 0 ; i < N-1 ; i++) {
		if(a[i] < a[i+1]){
			if(ch == 0){
				v[coun].push_back(a[i]);
				ch = 1;
			}
			v[coun].push_back(a[i+1]);
		}
		else{
			
			int temp = a[i+1];
			int c = 0;
			int small = 0;
			for(int j = 0 ; j <= i ; j++){
				
				if(a[j] < temp && small < a[j]){
					if(small > a[j]){
						small = a[j];
					}
					if(c == 0){
					small = a[j];
					c =1;
					v[++coun].push_back(a[j]);}
					else
					v[coun].push_back(a[j]);
				}
			}
		}
	}
	int result = 0;
	int temp = 0;
	int sum;
	for(int i = 0 ; i <= coun ; i++){
		sum = 0;
		for(int j = 0 ; j < v[i].size();j++){
			sum += v[i][j];
			printf("%d ",v[i][j]);
		}
		printf("\n");
		temp = max(sum,temp);
	}
	printf("%d",temp);
	//f(coun);
	return 0;
}