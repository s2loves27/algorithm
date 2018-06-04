#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
long long result_fu;
long long C;
long long mul(long long a , long long b){
	if(b == 0) return 1;
	result_fu = mul(a,b/2);
	if (b % 2 == 1) return (a * result_fu % C * result_fu) % C ;
	else return (result_fu * result_fu) % C;
}
int main(){
	long long A,B;
	long long result;
	scanf("%lld %lld %lld",&A,&B,&C);
	result = mul(A,B);
	printf("%lld\n",result);
	return 0;
}