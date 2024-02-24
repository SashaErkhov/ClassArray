#include "Arry.h"
Arry::Arry(){
	/*standart constructor without size*/
    m_bytes = new unsigned char[1];
}


Arry::Arry(size_t size) {
	/*standart constructor with size*/
    m_bytes = new unsigned char[size];
}


Arry::~Arry() 
{
	delete m_bytes;
}


void Arry::addElement(unsigned char elem) {
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

void Arry::removeElement(size_t pos) {
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

unsigned char Arry::getElement(size_t pos)
{
    /*You can get element from array */
	return m_bytes[pos];
}

void Arry::setElement(size_t pos, unsigned char value){
    /*This function change element on pos
    and set it on value*/
	m_bytes[pos]=value;
}

void Arry::resize(size_t new_size){
    /*this resize function do new_size 
    for array*/
	unsigned char* new_m_bytes=new unsigned char[new_size];
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
