#include<iostream>
using namespace std;
int binary_search(int arr[],int size, int key){
    int low=0;
    int high=size-1;
    while (low<=high){
        int mid =low+(high-low)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]<key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 30;
    int result = binary_search(arr, size, key);
    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}