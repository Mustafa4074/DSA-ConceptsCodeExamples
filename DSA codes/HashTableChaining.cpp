#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


class Student{
	public:
	
	int id;
	string name;
	
	Student(int id, string name) : id(id), name(name){}
};

class HashTable {
public:
    vector<list<Student> > table;


    int hash_function(int id) {
        return id % table.size();
    }
    
    void insertItem(int id, string name){
    	Student new_student(id, name);
    	
    	int index = hash_function(id);
    	table[index].push_back(new_student);
	}
	
	void deleteItem(int id) {
       int index = hash_function(id);
       list<Student>::iterator it; 

       for (it = table[index].begin(); it != table[index].end();) {
           if (it->id == id) {
               it = table[index].erase(it);
           } 
		   else {
               ++it;
           }
        }
    }
    
    void find(int id){
    	int index = hash_function(id);
    	list<Student>::iterator it;
    	
    	for (it = table[index].begin(); it != table[index].end(); it++){
    		if (it->id== id){
    			cout<<"Roll Number: "<<it->id<<endl;
    			cout<<"Name: "<<it->name<<endl;
    			break;
			}
		}
		cout<<"No record against this roll number exists!"<<endl;
		return;
	}
    
    
};

int main(){
	
	HashTable hashtable;
	
	hashtable.insertItem(4044, "Umar");
	hashtable.insertItem(4074, "Mustafa");
	hashtable.insertItem(8729, "Sajjad");
	hashtable.insertItem(4084, "Orakzai");
	hashtable.insertItem(4039, "Bhulla");
	
	hashtable.find(4084);
    

	
}
