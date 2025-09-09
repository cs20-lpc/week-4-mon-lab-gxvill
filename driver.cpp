#include "LinkedList.hpp"


/* this is a cpp file to test the linked list
 *
 * test list:
 * - [x] append
 *   - [x] non-empty
 *   - [x] empty
 * - [x] getElement
 *   - [x] in bounds
 *   - [x] out of bounds
 * - [x] clear
 *   - [x] non-empty
 *   - [x] empty
 * - [x] replace
 *   - [x] in bounds
 *   - [x] out of bounds
*/

int main(){
	LinkedList<int> l;

	// append test
	// these test append an element to the linked list
	l.append(1);
	cout << "apended element with value 1" << endl;
	l.append(2);
	cout << "apended element with value 2" << endl;
	l.append(3);
	cout << "apended element with value 3" << endl;
	l.append(4);
	cout << "apended element with value 4" << endl;
	l.append(5);
	cout << "apended element with value 5" << endl;

	// getElement test: in bounds
	cout << "element 0 is: " << l.getElement(0) << endl;
	cout << "element 1 is: " << l.getElement(1) << endl;
	cout << "element 2 is: " << l.getElement(2) << endl;
	cout << "element 3 is: " << l.getElement(3) << endl;
	cout << "element 4 is: " << l.getElement(4) << endl;

	// getElement test: out of  bounds
    try {
        l.getElement(6);
    }
    catch (const string& e) {
        cout << e << endl;
    }

	// clear test
	l.clear();
	cout << "linked list cleared!" << endl;
    try {
        l.getElement(1);
    }
    catch (const string& e) {
        cout << e << endl;
    }

	//testing if the function still works on an empty linked list
	l.clear();

	
	l.append(1);
	l.append(2);
	l.append(3);
	l.append(4);
	l.append(5);

	cout << "element 5 is: " << l.getElement(4) << endl;
	
	// replace test: in bounds
	
	int const TEST = 6;

    try {
		l.replace(4, TEST);
		cout << "element 4 has been changed to value " << TEST << endl;
    }
    catch (const string& e) {
        cout << e << endl;
    }
	//check if the replace worked
	cout << "element 4 is: " << l.getElement(4) << endl;

	// replace test: out of bounds
	int const TEST2 = 7;
    try {
		l.replace(5, TEST);
		cout << "element 5 has been changed to value " << TEST << endl;
    }
    catch (const string& e) {
        cout << e << endl;
    }

	l.clear();

	//clear an empty list
	l.clear();

	return 0;
}
