/*
 * InfiniteList.h
 *
 * Template for the infinite list.
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#ifndef INFINITELIST_H_
#define INFINITELIST_H_

template <typename E>
class InfiniteList {
private:
	int maxSize;
	int listSize;
	int curPos;
	int growthNum;	// Number of times array has grown
	E* array;

public:
	// Constructor
	InfiniteList(int size = 100) {
		maxSize = size;
		listSize = curPos = 0;
		array = new E[maxSize];
		growthNum = 0;
	}

	// Destructor
	~InfiniteList() {
		delete [] array;
	}

	// Delete and reinitialize list array
	void clear() {
		delete [] array;
		listSize = curPos = 0;
		array = new E[maxSize];
	}

	// Insert element at current position
	void insert(const E& element) {
		// Grow array if we've reached maximum size
		if (listSize == maxSize*(1<<growthNum)) growArray();
		// Insert element (note that last element is at listSize-1)
		for (int i = listSize; i > curPos; --i) {
			array[i] = array[i-1];
		}
		array[curPos] = element;
		listSize++;
	}

	// Append element at end
	void append(const E& element) {
		if (listSize == maxSize*(1<<growthNum)) growArray();
		array[listSize++] = element;
	}

	// Remove element, returning removed item
	E remove() {
		if (curPos < 0 || curPos > listSize) throw "No element.";
		E element = array[curPos];
		for (int i = curPos; i < listSize; ++i) {
			array[i] = array[i+1];
		}
		listSize--;
		return element;
	}

	// Move to front of list
	void moveToFront() {
		curPos = 0;
	}

	// Move to end of list
	void moveToEnd() {
		curPos = listSize;
	}

	// Move to previous position in list
	// Note: Does not guard against going OB
	void prev() {
		curPos--;
	}

	// Move to next position in list
	// Note: Does not guard against going OB
	void next() {
		curPos++;
	}

	// Return length of (number of elements in) list
	int length() {
		return listSize;
	}

	// Return current position in list
	int getPos() {
		return curPos;
	}

	// Move to specified position in list
	void moveToPos(int pos) {
		if (pos < 0 || pos > listSize) throw "Position out of range.";
		curPos = pos;
	}

	// Get value at current position
	E getVal() {
		if (curPos < 0 || curPos > listSize) throw "No element.";
		return array[curPos];
	}

private:
	// Grow array when list exceeds current array size
	void growArray() {
		E* tempArray = new E[listSize];
		// Have to create temporary array to store old values
		for (int i = 0; i < listSize; ++i) {
			tempArray[i] = array[i];
		}
		// Keep track of number of times we've grown (rather than updating maxSize) - either ought to work
		growthNum++;
		array = new E[maxSize*(1<<growthNum)];	// maxSize*(2**growthNum)
		for (int i = 0; i < listSize; ++i) {
			array[i] = tempArray[i];
		}
	}

};

#endif /* INFINITELIST_H_ */
