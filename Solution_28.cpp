#include "Solution_28.h"

bool Solution_28::searchMatrix(vector<vector<int>>& matrix, int target) {
	// write your code here

	if (matrix.size() != 0) {

		int up(0), down(matrix.size() - 1), left(0), right(matrix.at(0).size() - 1);
		int udMiddle, lrMiddle;

		while (up < down - 1) {
			udMiddle = (up + down) / 2;
			int udMiddleNum = matrix.at(udMiddle).at(0);
			if (target < udMiddleNum) down = udMiddle - 1;
			else if (target > udMiddle) up = udMiddle;
		}

		if (target < matrix.at(down).at(0)) down = up;
		else up = down;

		while (left < right) {
			lrMiddle = (left + right) / 2;
			int lrMiddleNum = matrix.at(down).at(lrMiddle);
			if (target < lrMiddleNum) right = lrMiddle - 1;
			else if (target > lrMiddleNum) left = lrMiddle + 1;
			else return true;
		}
	}

	return false;

}