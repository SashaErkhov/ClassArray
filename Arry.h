#pragma once
#ifndef ARRAY_OUR_WORK
#define ARRAY_OUR_WORK
#include <iostream>
#include <stdexcept>

template <typename T> class Arry {
	T* m_bytes;
	size_t size;
	void swap(Arry& other){
		std::swap(m_bytes, other.m_bytes);
		std::swap(size, other.size);
	}
public:
	Arry(size_t size = 0) : size(size) {
		if (size != 0)
		{
			m_bytes = new T[size];
		}
		else {
			m_bytes = nullptr;
		}
	}
	Arry(const Arry& other){
		size = other.size;
		m_bytes = new T[size];
		for(size_t i=0; i<size; ++i){
			m_bytes[i] = other.m_bytes[i];
		}
	}
	Arry(Arry&& other){
		size=0;
		m_bytes=nullptr;
		swap(other);
	}
	Arry& operator=(Arry&& other){
		if (this != &other){
			size=0;
			m_bytes=nullptr;
			swap(other);
		}
		return *this;
	}

	Arry& operator=(const Arry& other){
		if (this != &other){
			Arry<T> tmp(other);
			swap(tmp);
		}
		return *this;
	}
	size_t getSize() const { return size; }
	void addElement(const T& elem) {
		T* new_bytes = new T[++size];
		for (size_t i = 0; i < (size - 1); ++i) {
			new_bytes[i] = m_bytes[i];
		}
		new_bytes[size - 1] = elem;
		delete[] m_bytes;
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
		return m_bytes[pos];
	}
	void setElement(size_t pos, T value) {
		if (pos > size - 1) {
			throw std::out_of_range("Position " + std::to_string(pos) + " is out of range. Maximum allowed index is " + std::to_string(size - 1) + ".");
		}
		else {
			m_bytes[pos] = value;
		}
	}
	void resize(size_t new_size) {
		/*this resize function do new_size
		for array*/
		T* new_m_bytes = new T[new_size];
		size_t old_size = size;
		if (old_size >= new_size) {
			for (size_t i = 0; i < new_size; ++i) {
				new_m_bytes[i] = m_bytes[i];
			}
		}
		else {
			for (size_t i = 0; i < old_size; ++i) {
				new_m_bytes[i] = m_bytes[i];
			}
			for (size_t i = old_size; i < new_size; ++i) {
				new_m_bytes[i] = 0;
			}
		}
		delete[] m_bytes;
		m_bytes = new_m_bytes;
		size = new_size;
	}
	~Arry()
	{
		delete[] m_bytes;
	}
	const T& operator[](size_t pos)const { return m_bytes[pos]; }
	T& operator[](size_t pos) { return m_bytes[pos]; }

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

	iterator begin() {
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
	T* new_bytes = new T[size + 1]; // Allocate new array with incremented size
	size_t i = 0;

	// Copy elements until the insertion point
	while ((m_bytes + i) != pos.current && i < size) {
		new_bytes[i] = m_bytes[i];
		++i;
	}

	// Insert the new element
	new_bytes[i] = value;

	// Copy remaining elements
	for (size_t j = i; j < size; ++j) {
		new_bytes[j + 1] = m_bytes[j];
	}

	// Delete old array and update pointer and size
	delete[] m_bytes;

	m_bytes = new_bytes;
	size++; // Only increment size after all operations are done
}

#endif // !ARRAY_OUR_WORK
