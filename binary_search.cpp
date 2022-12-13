#include <iostream>
using namespace std;

template <class T>
int binary_search(T*a,T num, int l, int h){
    if(l<=h){
        int mid=(l+h)/2;
        if(a[mid]==num){
            return mid;
        }else if(a[mid]>num){
            return binary_search(a,num,l,mid-1);
        }else{
            return binary_search(a,num,mid+1,h);
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
    int res=binary_search<int>(arr,num,0,n);
    if(res==-1){
        cout<<"Element not found.";
    }else{
        cout<<"Element found at index "<<res;
    }
}