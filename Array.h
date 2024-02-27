#pragma once
#ifndef ARRAY_OUR_WORK
#define ARRAY_OUR_WORK

template <typename T> class Arry{
	T* m_bytes;
	size_t size = 1;
	size_t countElement = 0;
public:
	Arry(size_t size) {
	/*standart constructor with size*/
	    m_bytes = new T[size];
	}
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

	T getElement(size_t pos);
	void setElement(size_t pos, T value);
	void resize(size_t new_size);
	~Arry();
};

#endif // !ARRAY_OUR_WORK
