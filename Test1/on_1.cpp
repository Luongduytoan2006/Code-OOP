#include <iostream>
using namespace std;


int main(){
    int var_x = 2, var_y = 6;
    int& ref_x = var_x;
    int& ref_y = var_y;

    var_x++;
    cout<<var_x<<" "<<ref_x<<endl;
    ref_x++;
    cout<<var_x<<" "<<ref_x<<endl;


    var_x = ref_x++; 
    cout<<var_x<<" "<<ref_x<<endl;
    // ref_x = var_x++;
    // cout<<var_x<<" "<<ref_x<<endl;
    // var_y = ref_y++; 
    // cout<<var_y<<" "<<ref_y<<endl;
    // ref_y = var_y++;
    // cout<<var_y<<" "<<ref_y<<endl;

}