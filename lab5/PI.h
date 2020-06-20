#include <iostream>
using namespace std;

template <typename T> const T pi = T(3.1415926535897932385L);
bool inPiRange(int arg){
    if(abs(arg) <  pi<int>)
    {
        cout<<endl;
        return true;   
    }
    else {
        cout<<endl;
        return false;
       
    }
};
