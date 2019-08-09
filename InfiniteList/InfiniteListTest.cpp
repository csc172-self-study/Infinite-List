/*
 * InfiniteListTest.cpp
 *
 * Test driver for the infinite array-based list.
 *
 *  Created on: Aug 8, 2019
 *      Author: alex
 */

#include "InfiniteList.h"
#include <iostream>
using std::cout;

int main() {
	InfiniteList<int> list;

	// Test append and length
	for (int i = 0; i < 100; ++i) {
		list.append(i);
	}
	cout << "List should be 100 elements (default) long: " << list.length() << "\n";

	// Test growth
	for (int i = 100; i < 1000; ++i) {
		list.append(i);
	}
	cout << "List should be at least 1000 elements long: " << list.length() << "\n";

	// Test moveToFront, getVal
	list.moveToFront();
	cout << "First value is " << list.getVal() << "\n";

	// Test next
	list.next();
	cout << "Next value is " << list.getVal() << "\n";

	// Test moveToPos, getPos
	list.moveToPos(176);
	cout << "The value at " << list.getPos() << " is " << list.getVal() << "\n";

	// Test prev and insert
	list.prev();
	list.insert(929);
	cout << "The value at " << list.getPos() << " is " << list.getVal() << "; the length is now " << list.length() << "\n";

	// Test clear
	list.clear();
	cout << "List should be cleared: " << list.length() << "\n";

}

