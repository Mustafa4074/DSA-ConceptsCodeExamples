#include <iostream>
using namespace std;

void QuickSort(int* arr, int size){
	if(size <= 1) return;
	int pivot = arr[size/2];
	int* left = new int[size-1] , * right = new int[size-1];
	int ls=0, rs=0;
	for (int i = 0; i<size; i++){
		if (size/2==i)continue;
		if (pivot > arr[i]){
			left[ls++] = arr[i];
		}
		else{
			right[rs++] = arr[i];
		}
	}
	
	QuickSort(left, ls);
	QuickSort(right, rs);
	
	for (int i = 0; i<ls; i++){
		arr[i] = left[i];
	}
	arr[ls] = pivot;
	for (int i = 0; i<rs; i++){
		arr[ls+i+1] = right[i]; 
	}
	
}


int main(){
	int arr[] = {54, 8, 23, 66, 99, 1, 6, 3};
	QuickSort(arr, 8);
	for (int i = 0; i<8; i++){
		cout<<arr[i]<<endl;
	}
}
