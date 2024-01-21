#include<iostream>
#include<algorithm>
using namespace std;
int *merge(int *arr,int *arr1,int n){
    
    int *result=new int[n*2];
    for(int i=0;i<n;i++){
        result[i] = min(arr[i], arr1[i]);
        result[i + n] = max(arr[i], arr1[i]);
             
        
    }
    sort(result,result+n*2);
    return result;
}
int main(){
int arr[]={2,3,4,1,6};
int arr1[]={1,7,5,9,8};
int n=sizeof(arr)/sizeof(arr[0]);
int* m=merge(arr,arr1,n);
 for(int i = 0; i < n*2; i++) {
        cout << *(m+i) << " ";
    }
delete[]m;

}