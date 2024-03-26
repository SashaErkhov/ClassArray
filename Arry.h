#pragma once
#ifndef ARRAY_OUR_WORK
#define ARRAY_OUR_WORK
#include <iostream>
#include <stdexcept>

template <typename T> class Arry{
	T* m_bytes;
	size_t size = 1;
	size_t countElement = 0;
    size_t caret;
public:
    void rewindCaret();
    bool isCaretAtEnd(){
	    if(caret>=size){return true;}
	    return false;
    }
    T getElement();
	void moveToNextPos(){
		if (isCaretAtEnd()){
			throw std::out_of_range("Next pos is not in array");
		}
		caret++;
	}
	Arry(size_t size=1) {
	/*standart constructor with size*/
	    m_bytes = new T[size];
	}
	size_t getSize() const{ return size; }
	void addElement(T elem) {
	/*This function add new element. 
 	Its check size and if out size <
  	than count of element do resize 
	for size+1*/
	    if (countElement + 1 > size) {
	        resize(size + 1);
	    }
	    m_bytes[countElement] = elem;
	    countElement++;
	}
	void removeElement(size_t pos) {
	    /*This function remove eleemnt from pos
		and move for 1 point other element better(for pos)
	 	than this.*/
	    if (pos >= size) {
	        return;
	    }
	    
	    for (size_t i = pos; i < size - 1; ++i) {
	        m_bytes[i] = m_bytes[i + 1];
	    }
	    
	    countElement--;
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

		iterator operator++(int)//постфиксная форма 
		{
			T* tmp = current;
			++current;
			return iterator(tmp);
		}
		friend class Arry; 
	};

	iterator begin(){
	 	return iterator(m_bytes);
	}

	iterator end(){
		return iterator(m_bytes+countElement);
	}
};

template<typename T>
void Arry<T>::rewindCaret() {
    caret = 0;
}

#endif // !ARRAY_OUR_WORK
