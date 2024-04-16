#pragma once
#include "Arry.h"

template < class Key, class Data> class Assoc {
private:
	// Key - то , по чему находим, 
	// Data - то, что находим
	struct node {
		Key key;
		Data data;
	};

	Arry<node> m_storage;

	// Finds and returns the insertion point for a key in the sorted array.
	typename Arry<node>::iterator findInsertionPoint(const Key& key) {
		auto it = m_storage.begin();
		while (it != m_storage.end() && it->key < key) {
			++it;
		}
		return it;
	}

public:
	Assoc() {}

	void addPair(Key k, Data d) {
		node newNode;
		newNode.key = k;
		newNode.data = d;
		auto pos = findInsertionPoint(k, m_storage);
		m_storage.insert(pos, newNode);
	}

	Data findByKey(Key k) {
		typename Arry<typename Assoc<Key, Data>::node>::iterator res = binarySearch(k, m_storage.begin(), m_storage.end());

		if (res != m_storage.end()) {
			return (*res).data;
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
	};

	iterator begin() {
		return iterator(m_storage.begin());
	}

	iterator end() {
		return iterator(m_storage.end());
	}

	size_t getSize(){return m_storage.getSize();}
};
