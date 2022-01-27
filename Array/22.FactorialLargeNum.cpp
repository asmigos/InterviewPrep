#include <iostream>
#include <vector>

using namespace std;

int* factOfLargeNum(int num){
    int prod =1;
    int a, count = 0;
    int ans[500] = {0};
    while(num>0){
        prod *= num;
        a = prod;
        // while(a){
        //     a = a/10;
        //     count++;
        // }
        for(int i=1;prod>0;i++){
            int n = prod % 10;
            ans[500-i] = n;
            prod = prod/10;
        }
    }
}