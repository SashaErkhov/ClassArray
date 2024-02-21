#include "Array.h"

Arry::~Arry() 
{
	delete m_bytes;
}

unsigned char Arry::getElement(size_t pos)
{
	return m_bytes[pos];
}