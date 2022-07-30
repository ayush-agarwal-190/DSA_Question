#include<bits/stdc++.h>
using namespace std;
bool isFeasible(int mid,int arr[],int n,int k){
    int pos=arr[0],element=1;

    for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            element++;
            if(element==k){
                return true;
            }
        }
    }
    return false;
}
int largestMinDistance(int arr[],int n,int k){
sort(arr,arr+n);
int result=-1;
int left=1,right=arr[n-1];

while(left<right){
    int mid=(left+right)/2;
    if(isFeasible(mid,arr,n,k)){
        result=max(result,mid);
        left=mid+1;
    }
    else{
        right=mid;
    }
}
return result;

}


int main(){
int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int n=15,k=3;

cout<<" largest min distance "<<largestMinDistance(arr,n,k)<<endl;


return 0;
}