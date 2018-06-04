#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
long long N,A[1000000];
long long all_min(long long a[],long long N){
	long long min = 10000;
	for(long long i = 0 ; i < N ; i++){
		if(min > a[i] ){
			min = a[i];
		}
	}
	return min;
}
long long bar_max(long long v_min, long long v_max){
	if(v_min == v_max) return 0;
	if(v_min+1 == v_max) return A[v_min]*A[v_min];

	long long mid = (v_min + v_max) / 2;
	//int result = max(bar_max(v_min , mid) * all_min(&A[v_min],mid-v_min+1), bar_max(mid ,v_max) * all_min(&A[mid],v_max-mid+1));
	long long result = max(bar_max(v_min,mid)  , bar_max(mid,v_max) );
	long long left_v,right_v;
	long long l,r; long long w =A[mid];
	long long h = A[mid];
	long long val = h;
	l = mid ; r = mid;
	
	while(l >= v_min && r <= v_max){
		//printf("%lld %lld\n",mid , A[mid]);
		if(l >= v_min) left_v = min(h,A[l-1]);
		if(r <= v_max) right_v = min(h,A[r+1]);
		if(left_v >= right_v){
			h = left_v;
			w += A[l-1];
			
			l--;
		}
		else{
			h= right_v;
			w += A[r+1];
			r++;
		}
		result = max(result,w*h);
		//printf("%lld , %lld , %lld\n",v_min,v_max,result);
		//printf("%lld,%lld\n",left_v,right_v);
		//printf("%lld %lld %lld %lld %lld %lld\n",v_min,l , r,w, h ,result);
	}
	
	return result;
}


int main(){
	
	int z = scanf("%lld",&N);
	for(long long i = 0 ; i < N; i++){
		z = scanf("%lld",&A[i]);
	}
	printf("%lld",bar_max(0,N));
	
}