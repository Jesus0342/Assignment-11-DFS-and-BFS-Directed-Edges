/******************************************************************************
 * AUTHORS        : Jesus Sanchez & Frances Ohide
 * ASSIGNMENT #11 : DFS & BFS Directed Edges
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 11/20/2017
 *****************************************************************************/

#ifndef COMPARATORS_H_
#define COMPARATORS_H_

template<typename Type>
class TopGreatest {
public:
	bool operator()(const Type& greater, const Type& less) {
		return (greater.getData() > less.getData());
	}
};

template<typename Type>
class TopLowest {
public:
	bool operator()(const Type& less, const Type& greater) {
		return (less.getData() < greater.getData());
	}
};

template<typename Type>
class TopLowestWeight {
public:
	bool operator()(const Type& less, const Type& greater) {
		if (less.getData() != NULL && greater.getData() != NULL) {
			return (less.getData()->getDistance()
					< greater.getData()->getDistance());
		} else {
			return false;
		}
	}
};

#endif /* COMPARATORS_H_ */
