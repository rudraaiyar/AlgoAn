#include <iostream>

using namespace std;

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    
    while (j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
}

void sort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        sort(arr, low, mid);
        sort(arr, mid+1, high);
        merge(arr, low, high, mid);
    }
}

int main()
{
    int n, i;
    cin>>n;
    
    int arr[n];
    for(i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    sort(arr, 0, n-1);
    
    // Printing sorted data.
    for (i = 0; i < n; i++)
        cout<<arr[i]<<";";
    
    return 0;
}
