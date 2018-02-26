#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    //INPUTS AND DEFINITIONS
    int length, arr[20],i;
    cin>>length; //take in length
    
    for(i=0;i<length;i++)
    {
        cin>>arr[i];//take in element values
    }
    
    //INSERTION SORT
    int j, key, p;
    for(i=1; i<length; i++)
    {
        key=arr[i]; //set key at current position
        j=i-1; //set j to one value less than inc
        
        while((key<arr[j]) && (j>=0)) //moves element to a position one ahead of curr/also compares to move up or stay
        {
            arr[j+1]=arr[j]; //set curr value to one spot up
            j=j-1; //dec so that you can compare  value to the next one
        }
        arr[j+1]=key; //set at curr position
        
        for(p=0; p<i+1; p++) //print out each inc step list, i+1 so it only takes sorted and latest addition elements
        {
            cout<<arr[p]<<";"; //print in loop
        }
        cout<<""<<endl; //space after
    }
    
    /*FINAL LIST PRINT
    for(i=0; i<length; i++)
    {
        cout<<arr[i]<<"; ";
    }
    cout<<" "<<endl;
     */

    return 0;// int return
}
