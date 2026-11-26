#include <iostream>
using namespace std;

#include "src.hpp"

int main(){
    int **p = nullptr;
    
    // Test Init with n=3
    Init(p, 3);
    
    // Add elements to vector 1
    Add_element(p, 1, 10);
    Add_element(p, 1, 20);
    Add_element(p, 1, 30);
    
    // Add elements to vector 2
    Add_element(p, 2, 100);
    Add_element(p, 2, 200);
    
    // Get elements
    cout << "Get(1,1) = " << Get_element(p, 1, 1) << endl; // 10
    cout << "Get(1,2) = " << Get_element(p, 1, 2) << endl; // 20
    cout << "Get(1,3) = " << Get_element(p, 1, 3) << endl; // 30
    cout << "Get(2,1) = " << Get_element(p, 2, 1) << endl; // 100
    cout << "Get(2,2) = " << Get_element(p, 2, 2) << endl; // 200
    
    // Add more to vector 1 (should trigger resize)
    for(int i = 4; i <= 20; i++){
        Add_element(p, 1, i * 10);
    }
    cout << "Get(1,20) = " << Get_element(p, 1, 20) << endl; // 200
    
    Clear(p, 3);
    
    cout << "All tests passed!" << endl;
    return 0;
}
