#include<iostream>
#include<algorithm>
using namespace std;

int maxElement(int a[], int size){
    int max = a[0];
    for(int i=1;i<size;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

int minElement(int a[], int size){
    int min = a[0];
    for(int i=1;i<size;i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    return min;
}

int kMaxElement(int a[], int size, int k){
    sort(a, a+size, greater<int>());
    return a[k-1];
}

int main(){
    int a[]  = {6,2,4,1,3};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<"Max = "<<maxElement(a, size)<<" Min = "<<minElement(a, size);
    cout<<endl<<kMaxElement(a, size, 2);
}