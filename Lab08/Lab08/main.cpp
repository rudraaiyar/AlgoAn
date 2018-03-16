//
//  main.cpp
//  Lab08
//
//  Created by Rudra Aiyar on 3/15/18.
//  Copyright © 2018 Rudra Aiyar. All rights reserved.
//


/*
 PSUEDO:
 
 Cut-Rod(p, n)
 if n = 0 then
 return 0
 
 q = MinInt
 
 for i in 1 .. n loop
 q = max(q, p(i) + Cut-Rod(p, n-i) //recurision
 end loop
 
 return q //high value
 */

#include <iostream>

using namespace std;


int cutRod(int price[], int n)
{
    if (n <= 0)
        return 0;
    int high = INT_MIN;
    
    for (int i = 0; i<n; i++)
        high = max(high, price[i] + cutRod(price, n-i-1));
    return high;
}

int main()
{
    int n=0;
    cin>>n;
    
    int arr[n];

    
    for (int i=0; i<n;i++)
        cin>>arr[i];
    
    printf("%d", cutRod(arr, n));
    cout<<endl;
    return 0;
}
