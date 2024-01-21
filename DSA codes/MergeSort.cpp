#include <iostream>
using namespace std;

void merge(int *a,int mid,int low,int high){
    int i,j,k,b[high+1];
    i=low;
    j=mid+1;
    k=low;
    while(i<=low&&j<=high){
        if(*(a+i)<*(a+j)){
            *(b+k)=*(a+i);
            i++,k++;
        }
        else{
            *(b+k)=*(a+j);
            j++,k++;

        }
    }
    while(i<=mid){
        *(b+k)=*(a+i);
        i++,k++;
    }
    while(j<=high){
        *(b+k)=*(a+j);
        j++,k++;
    }
    for(int i=low;i<=high;i++){
       *(a+i)=*(b+i);
    }
}
void mergeSort(int *a,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,mid,low,high);
    }
}
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<" "<<*(a+i);
    }
    cout<<endl;
}
int main()
{
int a[]={3,2,4,19,13,5};
int n=sizeof(a)/sizeof(a[0]);
print(a,n);
mergeSort(a,0,n-1);
print(a,n);
return 0;
}