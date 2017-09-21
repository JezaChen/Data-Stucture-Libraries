#include <iostream>
#include "../List/test.h"

using namespace std;
using namespace DSLibrary;


int main() {
    cout<<"Select one of the following data structures: "<<endl;
    cout<<"1.Array Based List 2. Linked List 3. Doubly Linked List"<<endl;
    int choice;
    cin>>choice;
    list_test(choice);
    return 0;
}