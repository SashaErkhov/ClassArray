#pragma once
#ifndef ARRAY_OUR_WORK
#define ARRAY_OUR_WORK

template <typename T> class Arry{
	T* m_bytes;
	size_t size = 1;
	size_t countElement = 0;
public:
	Arry(size_t size = 1);
	void addElement(T elem);
	void removeElement(size_t pos);
	T getElement(size_t pos)
	{
		/*You can get element from array */
		return m_bytes[pos];
	}
	void setElement(size_t pos, T value);
	void resize(size_t new_size);
	~Arry()
	{
		delete[] m_bytes;
	}
};

#endif // !ARRAY_OUR_WORK
