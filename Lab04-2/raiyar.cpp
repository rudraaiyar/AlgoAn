#include <iostream>
//https://www.geeksforgeeks.org/quick-sort/
//^reference

using namespace std;

void swap(int *a, int *b);
int partion(int arr[], int p, int r);
void quick_sort(int arr[], int p, int r);

void swap(int *a, int *b) {
    //wee is a temp value
    //swapping base foe two elements
    int wee;
    
    wee = *a;
    *a = *b;
    *b = wee;
}

int partion(int arr[], int p, int r) {
    //last element as pivot
    //sorts based on pivot value
    //high vs low --right vs left
    int pivot_num = p + rand()%(r - p + 1);
    int piv; //pivot
    int i = p - 1;
    int j;
    
    piv = arr[pivot_num];
    
    swap(&arr[pivot_num], &arr[r]);
    
    for(j = p; j < r; j++) {
        if(arr[j] <= piv) { //breaks into 2 groups
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[r]); //call swap
    
    return i + 1;
}

void quick_sort(int arr[], int p, int r) {
    //yay finally sorts
    if(p < r) {
        //p is first
        //q is high
        int q = partion(arr, p, r);
        
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}

int main() {
    //takes input assignments and provides the output list ;
    int i, size;
    cin >> size;
    int arr[size];
    
    for(i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    quick_sort(arr, 0, size-1);
    
    for(i = 0; i < size; i++) {
        cout << arr[i] <<";";
    }
    return 0;
}
