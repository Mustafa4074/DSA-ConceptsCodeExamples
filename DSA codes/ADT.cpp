#include <iostream>
using namespace std;
class DynamicList{
    private:
    int* arr;
    int capacity;
    int length;
    public:
    DynamicList(){
        capacity=2;
        arr=new int[capacity];
        length=0;
    }
~DynamicList(){
    delete[]arr;
}
void insert(int value){
    if(length==capacity){
        capacity*=2;
        int* temp=new int[capacity];
        for(int i=0;i<length;i++){
            temp[i]=arr[i];
        }
        delete[]arr;
        arr=temp;
    }
    arr[length++]=value;

}
void remove(int value){
    int i;
    for(i=0;i<length;i++){
        if(arr[i]==value){
            break;
        }
    }
    
    if(i<length){
        for(int j=i;j<length-1;j++){
            arr[j]=arr[j+1];
        }
        length--;

    }
}
void print(){
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};
int main(){
    DynamicList list;
    list.insert(5);
    list.insert(3);
    list.insert(1);
    list.insert(2);
    list.insert(6);
    list.print();
    list.remove(2);
    list.print();
}