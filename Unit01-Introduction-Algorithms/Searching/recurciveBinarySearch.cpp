#include<iostream>
using namespace std;
int recursive_binary_search(int arr[], int low,int high,int key){
    if (low>high){
        return -1;

    }
    int  mid =low+(high-low)/2;
    if (arr[mid]==key){
        return mid;
    }
   else if(arr[mid]<key){
        return recursive_binary_search(arr,mid+1,high,key);
    }
    else{
        return recursive_binary_search(arr,low,mid-1,key);
    }
return -1;
}
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 30;
    int result = recursive_binary_search(arr,0,size-1,key);
    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}