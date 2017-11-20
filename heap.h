/******************************************************************************
 * AUTHORS        : Jesus Sanchez & Frances Ohide
 * ASSIGNMENT #11 : DFS & BFS Directed Edges
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 11/20/2017
 *****************************************************************************/

#ifndef HEAP_H_
#define HEAP_H_

#include "heapitem.h"
#include <iostream>

template<typename KeyType, typename DataType>
class Heap {
public:
	Heap(int size = 30);
	Heap(const Heap<KeyType, DataType>& otherHeap);
	~Heap();
	Heap<KeyType, DataType>& operator=(
			const Heap<KeyType, DataType>& otherHeap);

	void insert(HeapItem<DataType> &item);
	void insert(DataType data);
	HeapItem<DataType> removeTop();
	int getNumElements();
	int getHeight();
	void printAll();

private:
	void heapifyDown();
	void heapifyUp();
	bool isLeftChild(int pos);

	HeapItem<DataType> *elements;
	KeyType comparator;
	int numElements;
	int heapSize;
	int root;
	int last;

};

template<typename KeyType, typename DataType>
Heap<KeyType, DataType>::Heap(int size) :
		elements(NULL), numElements(0), heapSize(size), root(1), last(0) {
	elements = new HeapItem<DataType> [size];
}

template<typename KeyType, typename DataType>
Heap<KeyType, DataType>::~Heap() {
	if (elements != NULL) {

		delete[] elements;
		elements = NULL;
	}
}

template<typename KeyType, typename DataType>
Heap<KeyType, DataType>& Heap<KeyType, DataType>::operator=(
		const Heap<KeyType, DataType>& otherHeap) {
	if (this != &otherHeap) {
		if (otherHeap.heapSize > 0) {
			if (elements != NULL) {
				delete[] elements;
				elements = NULL;
			};
			elements = new HeapItem<DataType> [otherHeap.heapSize];

			numElements = otherHeap.numElements;
			heapSize = otherHeap.heapSize;
			root = otherHeap.root;
			last = otherHeap.last;

			int index = 0;
			while (index < heapSize) {
				elements[index].setData(otherHeap.elements[index].getData());
				index++;
			}
		}
	}

	return *this;
}

template<typename KeyType, typename DataType>
void Heap<KeyType, DataType>::insert(HeapItem<DataType> &item) {
	if (numElements < heapSize) {
		last++;
		numElements++;
		elements[last] = item;
		heapifyUp();
	} else {
		std::cout << "FULL!";
	}
}

template<typename KeyType, typename DataType>
void Heap<KeyType, DataType>::insert(DataType data) {
	if (numElements < heapSize) {
		HeapItem<DataType> temp;
		temp.setData(data);
		insert(temp);
	} else {
		std::cout << "FULL!";
	}
}

template<typename KeyType, typename DataType>
HeapItem<DataType> Heap<KeyType, DataType>::removeTop() {
	if (numElements != 0) {

		HeapItem<DataType> temp;

		temp = elements[root];

		numElements--;

		heapifyDown();

		return temp;
	} else {

		std::cout << "FULL!";
	}
}

template<typename KeyType, typename DataType>
int Heap<KeyType, DataType>::getNumElements() {
	return numElements;
}

template<typename KeyType, typename DataType>
int Heap<KeyType, DataType>::getHeight() {
	return numElements;
}

template<typename KeyType, typename DataType>
void Heap<KeyType, DataType>::heapifyDown() {
	if (last == root) {
		elements[root].setData(DataType());
	} else {
		int leftChild = root * 2;
		int rightChild = root * 2 + 1;
		int current = root;
		bool finished = false;
		int index = 0;
		HeapItem<DataType> temp;
		elements[root] = elements[last];

		// set last to initialized value
		elements[last].setData(DataType());

		last--;
		while (index < this->getHeight() && !finished) {
			temp = elements[current];
			if (comparator(elements[leftChild], elements[rightChild])
					|| elements[rightChild].getData() == DataType()) {
				if (comparator(elements[leftChild], elements[current])
						&& elements[leftChild].getData() != DataType()) {
					elements[current] = elements[leftChild];
					elements[leftChild] = temp;
					current = leftChild;
				} else {
					finished = true;
				}
			}
			// swap with the GREATER child
			else if (comparator(elements[rightChild], elements[leftChild])) {
				// do not swap with empty positions
				if (comparator(elements[rightChild], elements[current])
						&& elements[rightChild].getData() != DataType()) {
					elements[current] = elements[rightChild];
					elements[rightChild] = temp;
					current = rightChild;
				} else {
					finished = true;
				}
			}
			// if the same, don't swap
			else {
				//
				if (elements[rightChild].getData() == DataType()) {

				} else if (elements[leftChild].getData() == DataType()) {

				} else {
					finished = true;
				}
			}
			leftChild = current * 2;
			rightChild = current * 2 + 1;

			index++;
		}

	}
}

template<typename KeyType, typename DataType>
void Heap<KeyType, DataType>::heapifyUp() {
	if (last != root) {
		int parent;
		int current;

		HeapItem<DataType> temp;

		current = last;

		if (isLeftChild(current)) {
			parent = current / 2;
		} else {
			parent = (current - 1) / 2;
		}
		while (comparator(elements[current], elements[parent])
				&& current != root) {
			// swap current and parent
			temp = elements[parent];
			elements[parent] = elements[current];
			elements[current] = temp;

			// set current to parent
			current = parent;

			// find new parent
			if (isLeftChild(current)) {
				parent = current / 2;
			} else {
				parent = (current - 1) / 2;
			}
		}
	}

}
template<typename KeyType, typename DataType>
bool Heap<KeyType, DataType>::isLeftChild(int pos) {
	if (pos % 2 == 0) {
		return true;
	} else {
		return false;
	}
}

#endif /* HEAP_H_ */
