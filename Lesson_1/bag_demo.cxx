// FILE: bag_demo.cxx
// This is a small demonstration program showing how the bag class is used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "bag1.h"      // With value_type defined as an int

#define endl "\n"

typedef long long ll;

using namespace std;
using namespace main_switch_3;

void get_ages(bag& ages);
void check_ages(bag& ages);

void get_ages(bag& ages)
{
    int user_input=0;

    cout << "Type the ages in your family." << endl;
    cout << "Type a negative number when you are done:" << endl;
    while (user_input >= 0)
    {
        cin >> user_input;
        if (ages.size( ) < ages.CAPACITY)
            ages.insert(user_input);
        else
            cout << "I have run out of room and can�t add that age." << endl;
    }
}

void check_ages(bag& ages)
{
    int user_input;

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        if (ages.erase_one(user_input))
            cout << "Yes, I've got that age and will remove it." << endl;
        else
            cout << "No, that age does not occur!" << endl;
    }
}

// 01010110 01001100 01000001 01000100 01011001 01010011 01001100 01000001 01010110
// 01001000 01001001 01010010 01000011 01001000 01010101 01001011

void insertion_test(){
    bag b;
    cout << "Fully filling up the bag..." << endl;
    for(int i=0; i<b.CAPACITY; i++) b.insert(i);
    cout << "Adding one more element..." << endl;
    b.insert(100); // Adding one more element, which shouldn't get added
    cout << "Insert test passed." << endl;
}

void erase_test(){
    bag b;
    cout << "Adding 1 to 5 elements..." << endl;
    for(int i=0; i<5; ++i) b.insert(i);
    cout << "Erasing number 8..." << endl;
    b.erase(8);
}

void size_test(){
    bag b;
    for(int i=0; i<5; ++i) {
        cout << "Adding to the box item: " << i << "\n";
        b.insert(i);
    }

    if(b.size() == 5) cout << "Size: " << b.size() << endl;
    else cout << "Size test failed." << endl;

}
int main( )
{
    bag ages;

    bool t=1;
    while(t){
        cout << "Black Box Program\n";
        cout << "1. Insertion test\n";
        cout << "2. Erase test\n";
        cout << "3. Size test\n";
        cout << "4. Exit\n";

        ll c;
        cin >> c;

        switch(c){
            case 1:
                insertion_test();
                break;
            case 2:
                erase_test();
                break;
            case 3:
                size_test();
                break;
            case 4:
                return EXIT_SUCCESS;
            default:
                continue;
        }
    }
    return EXIT_SUCCESS;
}
