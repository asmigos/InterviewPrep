#include<iostream>
#include<vector>

using namespace std;

//Not completed
// Rearrange array in alternating positive & negative items with O(1) extra space in-place
void rotateRight(int array[], int size, int start, int end){
    if(start < end){
        int temp = array[end];
        for(int j=end;j>start;j--){
            array[j] = array[j-1];
        }
        array[start] = temp;
    }
}
//O(n)
int* alternatePosNeg(int array[], int size){
    
    int j=0, markPos =-1, markNeg = -1;
    for(int i=0;i<size;i++){
        if(markPos ==-1 && markNeg == -1){
            if(i%2==0){ //negative number index
            if(array[i]>=0){
                    markNeg = i;
            }
            }else if(i%2 == 1){ //positive number index
                if(array[i]<0){
                        markPos = i;
                }
            }
        }

        if(array[i] < 0 && markNeg > -1){
            rotateRight(array, size, markNeg, i);
            markPos  = i+ 2;
            markNeg =-1;
        }
        if(array[i] >= 0 && markPos > -1){
            rotateRight(array, size, markPos, i);
            markNeg = i+2;
            markPos = -1;
        }
    }
    return array;
}

int main(){
    int arr[] = {1, 2, 3, -4, -1, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int* ans;
    ans = alternatePosNeg(arr, size);

    for(int i=0;i<size;i++){
        cout<<ans[i]<<" ";
    }

}