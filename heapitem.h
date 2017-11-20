/******************************************************************************
 * AUTHORS        : Jesus Sanchez & Frances Ohide
 * ASSIGNMENT #11 : DFS & BFS Directed Edges
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 11/20/2017
 *****************************************************************************/

#ifndef HEAPOBJECT_
#define HEAPOBJECT_

template<typename DataType>
class HeapItem {
public:
	HeapItem();
	HeapItem(DataType newData);

	~HeapItem();
	void setData(DataType newData);
	void setItem(const HeapItem<DataType> &item);
	DataType getData() const;

private:
	DataType data;

};

template<typename DataType>
HeapItem<DataType>::HeapItem() :
		data(DataType()) {

}
template<typename DataType>
HeapItem<DataType>::HeapItem(DataType newData) :
		data(newData) {

}

template<typename DataType>
HeapItem<DataType>::~HeapItem() {
}

template<typename DataType>
void HeapItem<DataType>::setData(DataType newData) {
	data = newData;
}

template<typename DataType>
void HeapItem<DataType>::setItem(const HeapItem<DataType> &item) {
	data = item.data;
}

template<typename DataType>
DataType HeapItem<DataType>::getData() const {
	return data;
}

#endif /* HEAPOBJECT_ */
