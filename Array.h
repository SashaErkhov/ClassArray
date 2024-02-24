#pragma once
#ifndef ARRAY_OUR_WORK
#define ARRAY_OUR_WORK

class Arry{
	unsigned char* m_bytes;
	size_t size = 1;
	size_t countElement = 0;
public:
   	Arry();
	Arry(size_t size);
	void addElement(unsigned char elem);
	void removeElement(size_t pos);
	unsigned char getElement(size_t pos);
	void setElement(size_t pos, unsigned char value);
	void resize(size_t new_size);
	~Arry();
};

#endif // !ARRAY_OUR_WORK
