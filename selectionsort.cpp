#include<bits/stdc++.h>
using namespace std;

void selectionSort(int* arr, int size){

    for(int i = 0; i < size; i++){
        int min_index = i;
        for(int j = i + 1 ; j < size; j++){
            if(arr[j] < arr[min_index]) min_index = j;
        }
        swap(arr[i],arr[min_index]);
    }
}

int main(){

    int size;
    cout << "Enter size of array : " ;
    cin >> size;

    int arr[size];
    cout << "Enter elements of array : ";
    for(int i = 0; i < size; i++) cin >> arr[i];


    cout << "Array : ";
    for(auto i : arr) cout << i <<  " ";

    cout << "\n";
    selectionSort(arr,size);

    cout << "Sorted Array : ";
    for(auto i : arr) cout << i <<  " ";


    return 0;
}