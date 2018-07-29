#include "Solution_24.h"

LFUCache::LFUCache(int capacity) {
	// do intialization if necessary
	this->capacity = capacity;
}

void LFUCache::set(int key, int value) {
	// write your code here
	if (key <= capacity) {
		mapValue.insert(pair<int, int>(key, value));
		mapFrequency.insert(pair<int, int>(key, 1));
	}
	else {
		if (key > capacity) {
			int min(65535), minKey(0);
			for (map<int, int>::iterator iter = mapFrequency.begin(); iter != mapFrequency.end(); iter++) {
				if ((*iter).second < min) {
					min = (*iter).second;
					minKey = (*iter).first;
				}
			}

			map<int, int>::iterator iter;
			iter = mapValue.find(minKey);
			mapValue.erase(iter);
			iter = mapFrequency.find(minKey);
			mapFrequency.erase(iter);
		}

		mapValue.insert(pair<int, int>(key, value));
		mapFrequency.insert(pair<int, int>(key, 1));

	}
}

int LFUCache::get(int key) {
	// write your code here
	map<int, int>::iterator iter = mapValue.find(key);
	if (iter != mapValue.end()) {
		(*mapFrequency.find(key)).second++;
		return (*iter).second;
	}
	else return -1;
}
