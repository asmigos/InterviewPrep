#include<iostream>
#include<vector>
using namespace std;

vector<int> negPosMove(vector<int> a){
    int j=0;
    for(int i=0;i<a.size(); i++){
        if(a[i]<0){
            if(i != j)
                swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main(){
    vector<int> a ;
    a.push_back(1);
    a.push_back(-1);
    a.push_back(2);
    a.push_back(9);
    a.push_back(-5);

    for(int i=0;i<a.size(); i++){
        cout<<a[i]<<" ";
    }

    

    cout<<endl;
    a = negPosMove(a);

    for(int i=0;i<a.size(); i++){
        cout<<a[i]<<" ";
    }

}
