// Program to implement longest increasing subsequence.

#include <iostream>
using namespace std;

int max(int i,int j){
  return i>j?i:j;	
}

int main() {
	
	int a[100]={0},lis[100]={0},i,j,n;
	
	cin>>n;
	
	for(i=1;i<=n;i++)
	  cin>>a[i];
	  
	for(i=1;i<=n;i++){
	  for(j=1;j<=i;j++){
	  	if(a[i]>=a[i-j]){
	  		lis[i]=max(lis[i],lis[i-j]+1);
	  	
	  	}
	  		
	  }
	  cout<<lis[i]<<" ";
	}
	  cout<<"\n"<<lis[n];
	return 0;
}

/* input :
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
output : 
1 2 2 3 2 3 3 4 2 4 3 5 3 5 4 6 
6
*/
