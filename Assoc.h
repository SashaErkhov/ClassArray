#pragma once
#include "Arry.h"
#include "Para.h"
#include "Containers.h"

template < class Key, class Data> class Assoc {
private:
	Arry<Para<Key, Data>> m_storage;

	// Finds and returns the insertion point for a key in the sorted array.
	typename Arry<Para<Key, Data>>::iterator findInsertionPoint(const Key& key) {
		auto it = m_storage.begin();
		while (it != m_storage.end() && (*it).first < key) {
			++it;
		}
		return it;
	}

public:
	Assoc() {
		m_storage = Arry<Para<Key, Data>>(0);
	}

	void addPair(Key k, Data d) {
		Para<Key, Data> newNode;
		newNode.first = k;
		newNode.second = d;
		auto pos = findInsertionPoint(k);
		m_storage.insert(pos, newNode);
	}

	Data findByKey(Key k) {
		typename Arry<Para<Key, Data>>::iterator res = binarySearch(k, m_storage.begin(), m_storage.end());

		if (res != m_storage.end()) {
			return (*res).second;
		}
		else {
			throw std::runtime_error("Key not found");
		}
	}


	class iterator {
		typename Arry<Para<Key, Data>>::iterator current;
	public:
		iterator(typename Arry<Para<Key, Data>>::iterator p = nullptr) : current(p) {}

		Para<Key, Data>& operator*() {
			return *current;
		}

		const Para<Key, Data>& operator*() const {
			return *current;
		}

		iterator& operator++() {
			++current;
			return *this;
		}

		iterator operator++(int) {
			iterator tmp = *this;
			++(*this);
			return tmp;
		}

		bool operator==(const iterator& other) const {
			return current == other.current;
		}

		bool operator!=(const iterator& other) const {
			return current != other.current;
		}
	};

	iterator begin() {
		return iterator(m_storage.begin());
	}

	iterator end() {
		return iterator(m_storage.end());
	}

	size_t getSize(){return m_storage.getSize();}
};