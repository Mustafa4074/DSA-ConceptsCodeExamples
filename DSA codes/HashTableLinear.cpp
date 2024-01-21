#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Student{
	public:
	
	int id;
	string name;
	Student(){
		this->id = 0;
		this->name = "";
	}
	Student(int id, string name){
		this->id = id;
		this->name = name;
	}
};


class HashTableLinear{
	public:
		Student* array;
		int size;
		
		HashTableLinear(int size){
			this->size = size;
			array = new Student[size];
			
			for (int i = 0; i<size; i++){
				array[i].id = -1;
			}
		}
		
		int hash_function(int id, int prob){
			int index = (id + prob)% size;
			if (prob > size){
				return -1;
			}
			if (array[index].id != -1){
				return hash_function(id, prob+1);
			}
			return index;
		}
		int hash_find(int id, int prob){
			int index = (id + prob)% size;
			if (prob > size){
				return -1;
			}
			if (array[index].id == id){
				return index;
			}
			return hash_find(id, prob+1);
		}
		
		void insert(int id, string name){
			int index = hash_function(id, 0);
			Student new_student(id, name); 
			if (array[index].id == -1){
				array[index] = new_student;
				return;
			}
			else{
				cout<<"No space remaining!"<<endl;
				return;
			}
			
		}
		
		void remove(int id){
			int index = hash_find(id, 0);
			
			if (index != -1){
				array[index].id = -1;
				array[index].name = "";
				
				cout<<"Deleted!"<<endl;
				return;
				
			}
			cout<<"Student Does Not Exists!"<<endl;
			return;
		}
		
		void find(int id){
			int index = hash_find(id, 0);
			if (index != -1){
				cout<<"Student id: "<<array[index].id<<endl;
				cout<<"Student name: "<<array[index].name<<endl;
				return;
			}
			cout<<"Student Not Found!"<<endl;
			return;
		}
};

int main(){
	HashTableLinear hashtable(10);
	
	hashtable.insert(4074, "Mustafa");
	hashtable.insert(4044, "Umar");
	hashtable.insert(8729, "Sajjad");
	hashtable.insert(4084, "Orakzai");
	hashtable.insert(4086, "Someone");
	hashtable.insert(4033, "NaMaloom");
	hashtable.insert(8727, "Hasan");
	
	hashtable.find(4086);
	hashtable.remove(4086);
	hashtable.find(4086);
}
	
	
