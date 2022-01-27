#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    
    bool winner[n] = {true};
    for(int i=0;i<n;i++){
        cin>>winner[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(array[i]<array[j]){
                winner[i] = false;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(winner[i]==true ){
            cout<<array[i]<<" ";
        }
    }
    return 0;
    
}
