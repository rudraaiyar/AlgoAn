#include<iostream>

using namespace std;

/**
 pseudo:
 MaxSubarray(A,low,high)
 if high == low // base case: only one element
    return (low, high, A[low])
 else
    divide
    mid = floor( (low + high)/2 )
    conquer
    (leftlow,lefthigh,leftsum) = MaxSubarray(A,low,mid)
    (rightlow,righthigh,rightsum) = MaxSubarray(A,mid+1,high)
    (xlow,xhigh,xsum) = MaxXingSubarray(A,low,mid,high)
    
    combine
    if leftsum >= rightsum and leftsum >= xsum
        return (leftlow,lefthigh,leftsum)
    else if rightsum >= leftsum and rightsum >= xsum
        return (rightlow,righthigh,rightsum)
    else
        return (xlow,xhigh,xsum)
    end if
 end if
 
 MaxXingSubarray(A,low,mid,high)
    leftsum = -infty; sum = 0 // Find max-subarray of A[i..mid]
    for i = mid downto low
        sum = sum + A[i]
        if sum > leftsum
            leftsum = sum
            maxleft = i
        end if
    end for
    rightsum = -infty; sum = 0 // Find max-subarray of A[mid+1..j]
    for j = mid+1 to high
        sum = sum + A[j]
        if sum > rightsum
            rightsum = sum
            maxright = j
        end if
    end for
    // Return the indices i and j and the sum of two subarrays
    return (maxleft,maxright,leftsum + rightsum)
 **/

//FIND THE MAX OF A AND B INTS
int max(int a, int b)
{
    return (a > b)? a:b;
}

//left->mid, mid+1->right
int maxSum(int arr[], int low, int mid, int high)
{
    //less than or equal to the mid.
    int sum = 0;
    int leftsum = -1;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];
        if (sum > leftsum)
            leftsum = sum;
    }
    
//mid->right
    sum = 0;
    int rightsum = -1;
    for (int i = mid+1; i <= high; i++)
    {
        sum = sum + arr[i];
        if (sum > rightsum)
            rightsum = sum;
    }
    
//both sides
    return rightsum+leftsum;
}

// maxium subarray sum.
int MaxSubArraySum(int arr[], int low, int high)
{
    int mid;
    //one element.
    if (low == high)
        return arr[low];
    
    mid = (low + high)/2;
    
    //left, right, cross
    return max(max(MaxSubArraySum(arr, low, mid), MaxSubArraySum(arr, mid+1, high)), maxSum(arr, low, mid, high));
}

int main()
{
    int input, i;
    cin>>input;
    
    int array[input];
    for(i = 0; i < input; i++)
    {
        cin>>array[i];
    }
    cout<<MaxSubArraySum(array, 0, input-1);
    return 0;
}
