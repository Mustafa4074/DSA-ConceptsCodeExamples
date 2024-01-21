#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Heap{
	public:
		
	vector<int> array;
	int height;
	
	Heap(){
		this->height = 0;
	}
	Heap(vector<int> arr){
		this->array = arr;
		this->height = 0;
	}
	
	void swap(int a, int b){
		int temp = array[a];
		array[a] = array[b];
		array[b] = temp;
	}
	
	void insert(int item){
		array.push_back(item);
		if (array.size() == 1){
			return;
		}
		int index = array.size() - 1;
		while(index > 1){
			int parent = (index - 1)/2;
			if (array[index] > array[parent]){
				swap(index, parent);
				index = parent;
			}
			else{
				return;
			}
		}
	}
	
	void delete_item(){
		if (array.size() == 0){
			return;
		}
		int index = 0;
		
		array[0] = array[array.size()-1];
		
		array.pop_back();
		
		while (index<array.size()){
			int left = 2*index + 1;
			int right = 2*index + 2;
			if (left < array.size() && array[index] < array[left]){
				swap(index, left);
				index = left;
			}
			else if (right < array.size() && array[index] < array[right]){
				swap(index, right);
				index = right;
			}
			else{
				continue;
			}
		}
		
	}
	
	
	void printArray(){
		for (int i = 0; i<(array.size()); i++){
			cout<<array[i]<<endl;
		}
	}
	
};

void heapify(vector<int>& array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[largest] < array[left]) {
        largest = left;
    }
    if (right < n && array[largest] < array[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(array[largest], array[i]);
        heapify(array, n, largest);
    }
}


int main(){
	
	Heap heap;
	
	heap.insert(4);
	heap.insert(5);
	heap.insert(12);
	heap.insert(1);
	heap.insert(3);
	heap.printArray();
	cout<<"----------------------------------------"<<endl;
	heap.delete_item();
	heap.printArray();
	cout<<"-----------------------------------------"<<endl;
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(12);
	arr.push_back(7);
	arr.push_back(9);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(8);
	arr.push_back(16);
	int n = 8;
	for (int i = (n/2) + 1; i > 0; i--){
		heapify(arr, n, i);
	}
	for (int i = 0; i<8; i++){
		cout<<arr[i]<<endl;
	}
}
