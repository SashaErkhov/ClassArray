#pragma once

Class Arry{
	unsigned char* m_bytes;
public:
	Arry(size_t size);
	void addElement(unsigned char elem);
	void removeEleent(size_t pos);
	unsigned char getElement(size_t pos);
	void setElement(size_t pos, unsigned char value);
	void resize(size_t new_size);
	~Arry() {
		delete m_bytes;
	}
};
