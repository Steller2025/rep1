#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool status = false ;
bool isNumber(const string& s)
{
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
class items{
int id;
string name;
int price;

};
// Driver code
int main()

{
    


do{
cout<<"Welcome! \nenter choice\n";

cout<<"1. Add stock\n2. Remove stock\n3. Update stock\n4. Exit\n";
    // Saving the input in a string
    string choice;  
    cin>>choice;
    int intchoice;
    // Function returns true if all characters
    // are in the range '0-9'
    if (isNumber(choice)) {
        int intchoice= stoi(choice);
        if (intchoice>4 || intchoice<1){
            cout<<"number out of range try again\n";
        }
        else{
        cout << " valid Integer";
        status= true ;

        }
    } else {
        cout << "invalid input ::typeString try again\n";
    }

} while (status==false);
/*
switch ( intchoice ){
    case 1:
    addstock();
    break;
    
    case 2:
    removestock();

    case 3:
    update();

    case 4:

    exitt();
    break;

}
*/
cout<<"i am out of loop";
    return 0;
}