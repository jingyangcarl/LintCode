#include "Solution_8.h"

void Solution_8::rotateString(string & str, int offset) {

	if (str != "") {
		string extendString = str + str;
		str = extendString.substr(str.size() - offset%str.size(), str.size());
	}

}
