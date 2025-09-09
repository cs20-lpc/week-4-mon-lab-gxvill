#include "LinkedList.hpp"


/* this is a cpp file to test the linked list
 *
 * test list:
 * - [x] append
 * - [ ] clear
 * - [ ] getElement
 * - [ ] replace
*/

int main(){
	LinkedList<int> l;

	// append test
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

	cout << "element 1 is: " << l.getElement(1) << endl;
	cout << "element 2 is: " << l.getElement(2) << endl;
	cout << "element 3 is: " << l.getElement(3) << endl;
	cout << "element 4 is: " << l.getElement(4) << endl;
	cout << "element 5 is: " << l.getElement(5) << endl;

	// clear test
	l.clear();
	cout << "linked list cleared!" << endl;
    try {
        l.getElement(1);
    }
    catch (const string& e) {
        cout << e << endl;
    }

	
	// getElement test
	l.append(1);
	l.append(2);
	l.append(3);
	l.append(4);
	l.append(5);

	cout << "element 5 is: " << l.getElement(5) << endl;
	
	// replace test
	
	int const TEST = 6;

    try {
		l.replace(5, TEST);
		cout << "element 5 has been changed to value " << TEST << endl;
    }
    catch (const string& e) {
        cout << e << endl;
    }

	cout << "element 5 is: " << l.getElement(5) << endl;

	return 0;
}
