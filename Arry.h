#pragma once
#ifndef ARRAY_OUR_WORK
#define ARRAY_OUR_WORK
#include <iostream>
#include <stdexcept>

template <typename T> class Arry{
	T* m_bytes;
	size_t size;
public:
	Arry(size_t size = 0) : size(size) {
	    m_bytes = new T[size];
	}
	size_t getSize() const{ return size; }
	void addElement( const T& elem) {
	    T* new_bytes = new T[++size];
        for (size_t i = 0; i < (size-1); ++i) {
            new_bytes[i] = m_bytes[i];
        }
        new_bytes[size-1] = elem;
        if(size!=1) delete[] m_bytes;
        m_bytes = new_bytes;
	}
	void removeElement(size_t pos) {
	    if (pos >= size) {
	        return;
	    }

	    for (size_t i = pos; i < size - 1; ++i) {
	        m_bytes[i] = m_bytes[i + 1];
	    }
        --size;
	}

	T getElement(size_t pos)
	{
		/*You can get element from array */
		return m_bytes[pos];
	}
	void setElement(size_t pos, T value){
		if (pos>size-1){
			std::cout<<"position is out of range"<<std::endl;
		}
		else{
		m_bytes[pos]=value;
		}
	}
	void resize(size_t new_size){
		/*this resize function do new_size 
    	for array*/
		T* new_m_bytes=new T[new_size];
		size_t old_size = size;
		if (old_size>=new_size){
			for(size_t i=0; i<new_size; ++i){
				new_m_bytes[i]=m_bytes[i];
			}
		} else {
			for(size_t i=0; i<old_size; ++i){
				new_m_bytes[i]=m_bytes[i];
			}
			for(size_t i=old_size; i < new_size; ++i){
				new_m_bytes[i]=0;
			}
		}
		delete[] m_bytes;
		m_bytes=new_m_bytes;
		size = new_size;
	}
	~Arry()
	{
		delete[] m_bytes;
	}
	const T& operator[](size_t pos)const {return m_bytes[pos];}
	T& operator[](size_t pos) {return m_bytes[pos];}

	class iterator {
		T* current;
	public:
		iterator(T* p = nullptr) : current(p) {};
		T& operator*() {
			return *current;
		}
		T& operator*() const {
			return *current;
		}
		iterator& operator++() {
			++current;
			return *this;
		}

		iterator operator++(int)
		{
			T* tmp = current;
			++current;
			return iterator(tmp);
		}

		iterator operator+(int n) const {
			return iterator(current + n);
		}


		int operator-(const iterator& other) const {
			return current - other.current;
		}

		bool operator!=(const iterator& other) const {
			return current != other.current;
		}

		bool operator==(const iterator& other) const {
			return current == other.current;
		}

		bool operator<(const T& other) const {
			return *current < other;
		}

		friend class Arry; 
	};

	iterator begin(){
	 	return iterator(m_bytes);
	}

	iterator end() {
		return iterator(m_bytes + size);
	}

    void insert(const iterator& pos, const T& value);
};

template<typename T>
void Arry<T>::insert(const typename Arry<T>::iterator& pos, const T& value)
{
	//Добавление элемента по итератору
	T* new_bytes = new T[++size];
	size_t i = 0;
	while (((m_bytes + i) != (pos.current))and (i<(size-1)))
	{
		new_bytes[i] = m_bytes[i];
		++i;
	}
	new_bytes[i++] = value;
	for (size_t j = i; j < size; ++j)
	{
		new_bytes[j] = m_bytes[j - 1];
	}
	delete[] m_bytes;
	m_bytes = new_bytes;
}

#endif // !ARRAY_OUR_WORK
