#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	vector<int> v;
	v.reserve(8); 
	int N;
	int a[1001];
	scanf("%d",&N);
	for (int i = 0 ; i < N ; i++) scanf("%d",&a[i]);
	v.push_back(123);
	printf("%d",v.back());
}