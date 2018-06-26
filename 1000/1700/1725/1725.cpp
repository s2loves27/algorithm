//히스토 그램 난이도 (하) -- 분할 정복

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> histogram;

int big_size(int start , int end){
   if(start == end) return 0;
   if(start + 1 == end) return histogram[start];

   int mid = (start + end) / 2;

   int result = max(big_size(start,mid),big_size(mid,end));

   int left = mid;
   int right = mid;
   int high = histogram[mid];
   int w = 1;
   while(right - left + 1 < end - start){
      int p = left > start ? min(high , histogram[left-1]) : -1;
      int q = right < end-1 ? min(high, histogram[right+1]) : -1;

      if(p >= q){
         high = p;
         left --;
      } 
      else {
         high = q;
         right ++;
      }
      result = max(result , ++w*high);
   }
   return result;
}
int main(){
   scanf("%d",&N);
   int temp;
   for(int i = 0 ; i < N ; i++){
      scanf("%d",&temp);
      histogram.push_back(temp);
   }
   printf("%d", big_size(0,N));
}