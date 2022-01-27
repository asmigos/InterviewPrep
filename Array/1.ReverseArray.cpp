#include<iostream>
using namespace std;

void reverseArray(int a[], int size){
    int temp = 0;
    for(int i=0;i<size/2;i++){
        temp = a[i];
        a[i] = a[size-1-i];
        a[size-1-i] = temp;
    }
}

int main(){
    int a[] = {1,3,2,4,5};
    int size = sizeof(a)/sizeof(a[0]);
    reverseArray(a, size);
    for(int i=0; i< size;i++){
        cout<<a[i];
    }
}