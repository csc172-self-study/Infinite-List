/*
 * InfiniteList.h
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#ifndef INFINITELIST_H_
#define INFINITELIST_H_

#include <cmath>

template <typename E>
class InfiniteList {
private:
	int maxSize;
	int listSize;
	int curPos;
	int growthNum;
	E* array;

public:
	InfiniteList(int size = 100) {
		maxSize = size;
		listSize = curPos = 0;
		array = new E[maxSize];
		growthNum = 0;
	}

	~InfiniteList() {
		delete [] array;
	}

	void clear() {
		delete [] array;
		listSize = curPos = 0;
		array = new E[maxSize];
	}

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

	void append(const E& element) {
		if (listSize == maxSize*(1<<growthNum)) growArray();
		array[listSize++] = element;
	}

	E remove() {
		if (curPos < 0 || curPos > listSize) throw "No element.";
		E element = array[curPos];
		for (int i = curPos; i < listSize; ++i) {
			array[i] = array[i+1];
		}
		listSize--;
		return element;
	}

	void moveToFront() {
		curPos = 0;
	}

	void moveToEnd() {
		curPos = listSize;
	}

	void prev() {
		curPos--;
	}

	void next() {
		curPos++;
	}

	int length() {
		return listSize;
	}

	int getPos() {
		return curPos;
	}

	void moveToPos(int pos) {
		if (pos < 0 || pos > listSize) throw "Position out of range.";
		curPos = pos;
	}

	// get value at current position
	E getVal() {
		if (curPos < 0 || curPos > listSize) throw "No element.";
		return array[curPos];
	}

private:
	void growArray() {
		E* tempArray = new E[listSize];
		for (int i = 0; i < listSize; ++i) {
			tempArray[i] = array[i];
		}
		growthNum++;
		array = new E[maxSize*(1<<growthNum)];
		for (int i = 0; i < listSize; ++i) {
			array[i] = tempArray[i];
		}
	}

};



#endif /* INFINITELIST_H_ */
