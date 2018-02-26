//
//  main.cpp
//  lab4
//
//  Created by Rudra Aiyar on 2/13/18.
//  Copyright © 2018 Rudra Aiyar. All rights reserved.
//

#include <iostream>

using namespace std;

//need to declare here so we can call them everywhere
void swap(int *x, int *y);
void heaps(int arr[], int size);
void buildMaxHeap(int arr[], int k, int size);

void swap(int *x, int *y) {//move current to end
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void heaps(int arr[], int size) { //heapsort
    for(int k = size/2; k >= 0; k--) { //rearrange array
        buildMaxHeap(arr, k, size);
    }
    while(size - 1 > 0) { //take out one by one from heeeeeaaapppp
        swap(arr[size - 1], arr[0]);
        buildMaxHeap(arr, 0, size - 1);
        size--;
    }
}

void buildMaxHeap(int arr[], int k, int size) { //reduce heap
    while(k*2 + 1 < size) {
        int child = 2*k + 1;
        if((child + 1 < size) && (arr[child] < arr[child + 1])) {
            child++;
        }
        if(arr[k] < arr[child]) {
            swap(arr[child], arr[k]);
            k = child;
        } else {
            return;
        }
    }
}

int main() {
    int i, size;
    cin >> size;
    int arr[size];
    for(i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    heaps(arr, size);
    
    for (i = 0; i < size; i++) {
        cout << arr[i] <<";";
    }
    return 0;
}
