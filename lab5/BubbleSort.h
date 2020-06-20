#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#include<iostream>
#include<string>
#include <algorithm>  
using namespace std;


template <typename T>
class BubbleSort
{

    public:
    //algorithm to sort the array
    //Two pointer that iterates throw the array and compare the two pointers 
    void bubbleSort(T array[], int arr_size) 
    { 
        int i, j,k;
        for (i = 0; i < arr_size-1; i++) 
        { 
            for (j = 0; j < arr_size-i-1; j++) 
            { 
                if (array[j] > array[j+1]) 
                { 
                    swap(array[j], array[j+1]); 
                }
            }
           
        }

         //to print the array after sorting 
        cout<<"array after sorting ["<< arr_size <<"]={";
        for (k=0; k < arr_size;k ++){
            cout<<array[k]<<",";
        }
        cout<<"}";
        
    }
    
    
  
};



#endif