#include <iostream>
using namespace std;


bool BinarySearch(int arr[], int start, int end, int element){
	int size = end - start;
	if (size>=1){
		int middle = (end + start)/2;
		if(arr[middle] == element){
			return true;
		}
		else if(element < arr[middle]){
			return BinarySearch(arr, start, middle, element);
		}
		else{
			return BinarySearch(arr, middle+1, end, element);
		}
	}
	return false;
}

int main(){
	int array[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 25, 99, 172};
	int size = sizeof(array)/sizeof(int);
	if(BinarySearch(array, 0, size-1, 99)){
		cout<<"Found";
	}
	else{
		cout<<"Not Found";
	}
}
