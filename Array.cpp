#include "Array.h"

Arry::~Arry() 
{
	delete m_bytes;
}

Arry::getElement(size_t pos)
{
	return m_bytes[pos];
}