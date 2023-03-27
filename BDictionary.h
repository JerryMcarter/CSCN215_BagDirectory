// Jeremiah Carter - CSCN215 - LAB 1

#pragma once

// includes
#include "kvpair.h"
#include "dictionaryADT.h"
#include "ABag.h"

template <typename Key, typename E>

class BDictionary: public Dictionary<Key,E> {

private:
	std::unique_ptr<ABag<KVpair<Key, E>>> dict; // dictionary

public:

	// constructor
	BDictionary<Key, E>(const size_t s) {
		dict = std::make_unique<ABag<KVpair<Key, E>>>(int(s));
	}

	// deconstructor
	~BDictionary<Key, E>() {}

	// clears the dictionary
	void clear() {

		dict->emptyBag();
	}

	// inserts new kvpairs
	bool insert(const Key& k, const E& e) {
		KVpair<Key, E>* tPair = new KVpair<Key,E>(k, e);
		return (*dict += (*tPair));
		delete tPair;
	}

	// removes selected kvpair in bag
	bool remove(const Key& k, E& rtnVal) {
		KVpair<Key, E>* tPair = new KVpair<Key,E>(k, rtnVal);

		bool removed = dict->remove(*tPair);

		rtnVal = tPair->value();

		return removed;
		delete tPair;
	}

	// remove any "random" element in bag
	bool removeAny(E& returnValue) {

		Key k = (dict->peek()).key();
		KVpair<Key, E>*tPair = new KVpair<Key,E>(k, returnValue);
		
		bool removed = dict->removeTop(*tPair);
		
		returnValue = tPair->value();
		return removed;
		delete tPair;
	}

	// find selected element
	bool find(const Key& k, E& returnValue) const {

		KVpair<Key, E> *tPair = new KVpair<Key, E>(k, returnValue);
		
		bool found = dict->find(*tPair);

		returnValue = tPair->value();

		return found;
		delete tPair;
	}

	// return current number of elements
	int size() {
		return dict->size();
	}

};