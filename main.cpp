#include <iostream>
#include "LList.h"
//DO NOT SUBMIT FINAL
using namespace std;

int main() {
    int test0[0] = {};
    int test1[1] = {0};
    int test2[2] = {0,1};
    int test3[3] = {0,1,2};

    LList list;
    LList list0(test0, 0);
    LList list1(test1, 1);
    LList list2(test2, 2);
    LList list3(test3, 3);
    LList list4(list0);
    LList list5(list3);

    //checked by mia: works
    cout << "******** Testing << ********" << endl;
    cout << "List: " << list << endl;
    cout << "List0: " << list0 << endl;
    cout << "List1: " << list1 << endl;
    cout << "List2: " << list2 << endl;
    cout << "List3: " << list3 << endl;
    cout << "List4: " << list4 << endl;
    cout << "List5: " << list5 << endl;
    cout << endl;

    /*
    //tested by mia: does not work, seg fault
    cout << "******** Testing = ********" << endl;
    list4 = list2;
    list0 = list2 = list5;
    cout << "List0 = list2 = list5: " << list0 << "\t" << list2 << endl;
    cout << endl;
    // Reset
    list2 = list4;
    list4 = list0 = list;
    */

    //checked by mia: works
    cout << "******** Testing == ********" << endl;
    cout << "list == list0: " << (list == list0) << endl;
    cout << "list3 == list5: " << (list3 == list5) << endl;
    cout << "list3 == list2: " << (list3 == list2) << endl;
    cout << "list0 == list1: " << (list0 == list1) << endl;
    cout << endl;


    cout << "******** Testing insert ********" << endl;
    list0.insert(0, 10);
    cout << "list0.insert(0,10): " << list0 << endl;
    list3.insert(-1, 10);
    cout << "list3.insert(-1,10): " << list3 << endl;
    list2.insert(1, 10);
    cout << "list2.insert(1,10): " << list2 << endl;
    list5.insert(10, 10);
    cout << "list2.insert(10,10): " << list5 << endl;
    cout << endl;

    cout << "******** Testing + ********" << endl;
    LList list6 = list1 + list;
    cout << "list1 + list: " << list6 << endl;
    LList list7 = list + list1;
    cout << "List + list1: " << list7 << endl;
    LList list8 = list0 + list1;
    cout << "List0 + list1: " << list8 << endl;
    LList list9 = list2 + list3 + list1;
    cout << "List2 + list1 + list3: " << list9 << endl;
    cout << endl;

    //checked by mia: segmentation fault after "list9[100]: 2"
    cout << "******** Testing Right [] Indexing ********" << endl;
    int print = list9[3];
    cout << "list9[3]: " << print << endl;
    print = list9[0];
    cout << "list9[0]: " << print << endl;
    print = list9[-1];
    cout << "list9[-1]: " << print << endl;
    print = list9[7];
    cout << "list9[7]: " << print << endl;
    print = list9[list9.size()];
    cout << "list9[list9.size()]: " << print << endl;
    print = list9[100];
    cout << "list9[100]: " << print << endl;
    print = list[0];
    cout << "list[0]: " << print << endl;
    cout << endl;

    //checked by mia: segmentation fault after "list7.indexOf(5): -1"
    cout << "******** Testing indexOf ********" << endl;
    cout << "list9.indexOf(1): " << list9.indexOf(1) << endl;
    cout << "list9.indexOf(10): " << list9.indexOf(10) << endl;
    cout << "list9.indexOf(20): " << list9.indexOf(20) << endl;
    cout << "list7.indexOf(0): " << list7.indexOf(0) << endl;
    cout << "list7.indexOf(5): " << list7.indexOf(5) << endl;
    cout << "list.indexOf(3): " << list.indexOf(3) << endl;
    cout << endl;

    cout << "******** Testing Remove ********" << endl;
    cout << "list9.remove(0): " << list9.remove(0) << "\t" << list9 << endl;
    cout << "list9.remove(-1): " << list9.remove(-1) << "\t" << list9 << endl;
    cout << "list9.remove(2): " << list9.remove(2) << "\t" << list9 << endl;
    cout << "list9.remove(4): " << list9.remove(4) << "\t" << list9 << endl;
    cout << "list9.remove(list9.size()): " << list9.remove(list9.size()) << "\t" << list9 << endl;
    cout << "list.remove(0): " << list.remove(0) << endl;
    cout << endl;

    //checked by mia: works
    cout << "******** Testing contains ********" << endl;
    cout << "list9.contains(10): " << list9.contains(10) << endl;
    cout << "list9.contains(100): " << list9.contains(100) << endl;
    cout << "list.contains(20): " << list.contains(20) << endl;
    cout << "list7.contains(2): " << list7.contains(2) << endl;
    cout << "list7.contains(0): " << list7.contains(0) << endl;
    cout << endl;

    //checked by mia: works
    cout << "******** Testing isEmpty ********" << endl;
    cout << "list9.isEmpty(): " << list9.isEmpty() << endl;
    cout << "list7.isEmpty(): " << list7.isEmpty() << endl;
    cout << "list.isEmpty(): " << list.isEmpty() << endl;
    cout << endl;

    //checked by mia: seg fault at insert
    cout << "******** Testing clear ********" << endl;
    list9.clear();
    cout << "list9.clear(): " << list9 << endl;
    list7.clear();
    cout << "list7.clear(): " << list7 << endl;
    list.clear();
    cout << "list.clear(): " << list << endl;
    list9.insert(0,10);
    cout << "list9.insert(0,10): " << list9 << endl;
    list7.insert(0,10);
    cout << "list7.insert(0,10): " << list7 << endl;
    cout << endl;

    cout << "******** Testing >> ********" << endl;
    LList list10;
    cout << "Input a number to append to list10: ";
    cin >> list10;
    cout << "10 >> list10: " << list10 << endl;
    cout << "Input a number to append to list10: ";
    cin >> list10;
    cout << "11 >> list10: " << list10 << endl;
    LList list11(test3, 3);
    cout << "Input a number to append to list11: ";
    cin >> list11;
    cout << "4 >> list11: " << list11 << endl;
    cout << endl;

    cout << "******** Testing Left [] Indexing ********" << endl;
    list11[0] = 5;
    cout << "list11[0] = 5: " << list11 << endl;
    list11[-1] = 4;
    cout << "list11[-1] = 4: " << list11 << endl;
    list11[3] = 5;
    cout << "list11[3] = 5: " << list11 << endl;
    list11[list11.size()] = 10;
    cout << "list11[list11.size()] = 5: " << list11 << endl;
    list11[100] = 100;
    cout << "list11[100] = 5: " << list11 << endl;
    list[0] = 5;
    cout << "list[0] = 5: " << list << endl;
    
    list.~LList();
    list1.~LList();
    list2.~LList();
    list3.~LList();
    list4.~LList();
    list5.~LList();
    list6.~LList();
    list7.~LList();
    list8.~LList();
    list9.~LList();
    list10.~LList();
    list11.~LList();
}