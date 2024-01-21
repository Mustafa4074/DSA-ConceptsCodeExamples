#include <iostream>
using namespace std;
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<" "<<*(a+i);
    }
    cout<<endl;
}
void insertionSort(int *a,int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=*(a+i);
        j=i-1;
        while(j>=0&&(*(a+j))>key){
            *(a+(j+1))=*(a+j);
            j--;
        }
        *(a+(j+1))=key;
    }
}
int main()
{
int a[]={3,2,4,19,13,5};
int n=sizeof(a)/sizeof(a[0]);
print(a,n);
insertionSort(a,n);
print(a,n);
return 0;
}