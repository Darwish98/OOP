#include <iostream>
#include "BubbleSort.h"
#include "container.h"
#include "PI.h"




int main(){
    std::cout<<"EXERCISE 1"<<endl;
    std::cout<<inPiRange(3);
    std::cout<<inPiRange(40);
    std::cout<<inPiRange(-1)<<endl;
    std:: cout<<"_______________________"<<endl;

    std:: cout<<"EXERCISE 2 ";
    double arr[]={13,45,23,9,2};
    BubbleSort <double> temp;   //explicit template initialization
    temp.bubbleSort(arr,5);
    std::cout<< "\n_______________________"<<endl;

    std:: cout<<"EXERCISE 3"<<endl;
    
    Container<int> list;
    list.push_front(8);
    list.push_back(29);
    list.insert(1,5);
    list.Print_list();
    list.erase(1); 
    list.pop_front();
    list.Print_list();

    Container<double> list2;
    list2.push_back(9.8);
    list2.push_front(11.3);
    list2.Print_list();
    list2.clearList();
    list2.insert(0, 7.6);
   
    list2.push_front(4.2);
    list2.push_back(1.7);
    list2.Print_list();




   
   

    

    return 0;
}