//
//  main.cpp
//  Radix
//
//  Created by Rudra Aiyar on 2/25/18.
//  Copyright © 2018 Rudra Aiyar. All rights reserved.
//

/**
 
 PSEUDOOOOOOOOCODEEEEE
 Radix-Sort(A, d)
 //It works same as counting sort for d number of passes.
 //Each key in A[1..n] is a d-digit integer.
 //(Digits are numbered 1 to d from right to left.)
 
 
 for j = 1 to d do
 //A[]-- Initial Array to Sort
 int count[10] = {0};
 //Store the count of "keys" in count[]
 //key- it is number at digit place j
 for i = 0 to n do
 count[key of(A[i]) in pass j]++
 
 for k = 1 to 10 do
 count[k] = count[k] + count[k-1]
 
 //Build the resulting array by checking
 //new position of A[i] from count[k]
 for i = n-1 downto 0 do
 result[ count[key of(A[i])] ] = A[j]
 count[key of(A[i])]--
 
 //Now main array A[] contains sorted numbers
 //according to current digit place
 for i=0 to n do
 A[i] = result[i]
 
 end for(j)
 end func
 
 **/


//-------Start here----------
#include <iostream>
#include <vector>

using namespace std;


//count sort
vector<vector<int>*> * countsort (vector<vector<int>*> *vec, int *A, int depth, int maxnum, int length)
{
    // new vector
    vector<vector<int>*> *newVec = new vector<vector<int>*>;
    // Initialize
    int B[depth];
    int C[maxnum];
    for (int i = 0; i <= maxnum; i++)
    {
        C[i] = 0;
    }
    // Count numbers
    for (int i = 0; i < depth; i++)
    {
        C[A[i]]++;
    }
    // C[i] contains number of elements equal to i
    // Take sum of i,i-1
    for (int i = 1; i <= maxnum; i++)
    {
        C[i] = C[i] + C[i-1];
    }
    //copy of vec
    newVec->insert(newVec->end(), vec->begin(), vec->end());
    // Place each element of A into correct sorted pos in B
    for (int i = depth - 1; i >= 0; i--)
    {
        int index = C[A[i]] - 1;
        B[index] = A[i];
        C[A[i]] = index;
        
        // Switch the inner vectors
        newVec->at(index) = vec->at(i);
    }
    // Overwrite A with B
    for (int i = 0; i < depth; i++)
    {
        A[i] = B[i];
    }
    vec = new vector<vector<int>*>;
    vec->insert(vec->end(), newVec->begin(), newVec->end());
    return vec;
}
//use count for radix
vector<vector<int>*> * radixsort (vector<vector<int>*> *vec, int depth, int length)
{
    int maxnum = 0;
    
    // Iterate through columns
    for (int i = length - 1; i >= 0 ; i--)
    {
        int count[depth];
        for (int j = 0; j < depth; j++)
        {
            if (vec->at(j)->at(i) > maxnum)
                maxnum = vec->at(j)->at(i);
            count[j] = vec->at(j)->at(i);
        }
        // count sort
        vec = countsort(vec, count, depth, maxnum, length);
        maxnum = 0;
    }
    return vec;
}



int main(int argc,char **argv)
{
    int depth;
    int length = 10;
    
    // Get the number of vec
    cin >> depth;
    
    // Create complete 2D vector
    vector<vector<int>*> *vec = new vector<vector<int>*>;
    
    // values in place
    for ( int i=0; i<depth; i++ ) {
        // Create inner vector to be placed in 2D vector
        vector<int>* inside = new vector<int>;
        vec->push_back(inside);
        for ( int j=0; j<length; j++ ) {
            int temp = 0;
            cin >> temp;
            vec->at(i)->push_back(temp);
        }
    }
    
    // Run radixsort vector
    vec = radixsort(vec, depth, length);
    
    //print
    for ( int i=0; i<depth; i++ ) {
        for ( int j=0; j<length; j++ ) {
            cout << vec->at(i)->at(j) << ";";
        }
        cout << endl;
    }
}
