#include "Array.h"

Arry::~Arry() 
{
	delete m_bytes;
}

unsigned char Arry::getElement(size_t pos)
{
	return m_bytes[pos];
}

void Arry::resize(size_t new_size){
	unsigned char* new_m_bytes=new unsigned char[new_size];
	size_t old_size=((size_t(getElement(3))))|((size_t(getElement(4)))<<8)|((size_t(getElement(5)))<<16)((size_t(getElement(6)))<<24);
	if (old_size>=new_size){
		for(size_t i=0; i<new_size; ++i){
			new_m_bytes[i]=m_bytes[i];
		}
	} else {
		for(size_t i=0; i<old_size; ++i){
			new_m_bytes[i]=m_bytes[i];
		}
		for(size_t i=old_size; i<new_size; ++i){
			new_m_bytes[i]=0;
		}
	}
	delete[] m_bytes;
	m_bytes=new_m_bytes;
}