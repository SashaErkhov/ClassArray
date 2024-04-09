#pragma once
#include "Arry.h"

template < class Key, class Data> class Assoc{
private:
	// Key - то , по чему находим, 
	// Data - то, что находим
	struct node {
		Key key;
		Data data;
	};
	Arry<node> m_storage;

	typename Arry<node>::iterator findInsertionPoint(const Key& key) {
        auto it = m_storage.begin();
        while (it != m_storage.end() && it->key < key) {
            	++it;
        }
        	return it;
    	}
public:
	Assoc() {}		
	addPair(Key k, Data d) { // Добавляем соответствие
		node newNode;
    		newNode.key = k;
    		newNode.data = d;
    		auto pos = findInsertionPoint(k, m_storage);
    		m_storage.insert(pos, newNode);
	}

	Data findByKey(Key k) {
		Arry<node>::iterator res = binarySearch(k, m_storage.begin(), m_storage.end());
		if (res != m_storage.end()) {
        		return (*res).data;
    		} else {
        		throw std::runtime_error("Key not found");;
    		}
	}
};
