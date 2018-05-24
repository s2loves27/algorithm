#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int array_max = 100001;
int stic[2][100001];
int result[2][100001];
int f(int v_min , int v_max,int location){
	if(v_max == 0 && location == 0) return result[location][0] = stic[location][0];
	if(v_max == 0 && location == 1) return result[location][0] = stic[location][0];
	if(v_max == -1 && location == 0) return 0;
	if(v_max == -1 && location == 1) return 0;
	if(result[location][v_max] != -1) return result[location][v_max];
	if (location == 0) return result[location][v_max] = max(f(v_min,v_max-1,1) , f(v_min,v_max-2,1)) + stic[location][v_max];
	else return result[location][v_max] = max(f(v_min,v_max-1,0) , f(v_min,v_max-2,0)) + stic[location][v_max];

}

int main(){
	int T;
	int n;
	int max_v;
	int max_1;
	int max_2;
	scanf("%d",&T);
	for (int i = 0 ; i < T ; i++){

		scanf("%d",&n);
		for(int z = 0 ; z < 2 ; z++){
			for(int j = 0 ; j < n ; j++){
				result[z][j] = -1;
				scanf("%d ",&stic[z][j]);
			}
		}
		max_1 = f(0,n-1,0);
		max_2 = f(0,n-1,1);
		if(max_1 > max_2) printf("%d\n",max_1);
		else printf("%d\n",max_2);
	}
	return 0;
}