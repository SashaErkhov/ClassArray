#pragma once
#include "Arry.h"

template < class Key, class Data> class Assoc{ 
	// Key - то , по чему находим, 
	// Data - то, что находим
	struct node {
		Key key;
		Data data;
	};
	Arry<node> m_storage;
public:
	Assoc() {}		
	addPair(Key k, Data d) { // Добавляем соответствие
		node newNode;
    		newNode.key = k;
    		newNode.data = d;
    		m_storage.addElement(newNode);
	}

	Data findByKey(Key k) { // Здесь генерируется исключение!!! (Возможно)
		Arry<node>::iterator res = binarySearch(k, m_storage.begin(), m_storage.end());
		if (res != m_storage.end()) {
        		return (*res).data;
    		} else {
        		throw ... ;
    		}
	}
};
