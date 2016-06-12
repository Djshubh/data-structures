#include <iostream>

using namespace std;
 int t = 0;
int find_max(int mint,int maxt, int arr[]){
    int midt,x,y;
    midt = mint + (maxt-mint)/2;
    if(maxt-mint<=1){
        return (arr[maxt]>arr[mint])?arr[maxt]:arr[mint];

    }
    else{
    x= find_max(mint,midt,arr);
    y = find_max(midt,maxt,arr);
    t++;
    return (x>y)?x:y;
    }
}

int main(){

    int arr[100] = {53,26,48,3,5,24,6,77,47,78,51,80};
    int n=12,result;

    result = find_max(0,n-1,arr);

    cout<< result << " " << t;
    return 0;
}
