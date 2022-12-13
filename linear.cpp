#include <iostream>
using namespace std;

template <class T>
int search(T*a, T n){
    for(int i=0; i<sizeof(a); i++){
        if(a[i]==n){
            return i;
        }

    }
    return -1;
}

int main(){
    int n, num;
    cout<<"Enter the length of the array: ";
    cin>>n;
    int *arr=new int(10);
    for(int i=0; i<n; i++){
        cout<<"Enter the element: ";
        cin>>arr[i];
    }

    cout<<"Enter the element to be searched: ";
    cin>>num;
    int res=search<int>(arr,num);
    if(res==-1){
        cout<<"Element not found.";
    }else{
        cout<<"Element found at index "<<res;
    }
}