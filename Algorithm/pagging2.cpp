#include<iostream>
#include<stdlib.h>
#define pagetable_size 4096

using namespace std;

int main(){

 int input_address =19986;

 int page_number = input_address / pagetable_size;

 int offset_value = input_address%pagetable_size;

cout<<"The page table address "<<input_address<<endl;
cout<<"Page number value as = "<<page_number<<endl;
cout<<" And offset value as = "<<offset_value;

}
