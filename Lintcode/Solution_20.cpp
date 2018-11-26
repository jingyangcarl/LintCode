#include "Solution_20.h"

vector<pair<int, double>> Solution_20::dicesSum(int n) {
	// Write your code here

	vector<int> count;
	for (int i = 1 * n; i <= 6 * n; i++) {
		if (i <= 3.5 * n) {
			int availableCount(0), currentSum(0);
			countAvailableSum(i, currentSum, n, availableCount);
			count.push_back(availableCount);
		}
		else {
			count.push_back(count.at(6 * n - i));
		}
	}

	vector<pair<int, double>> result;
	for (vector<int>::iterator iter = count.begin(); iter != count.end(); iter++) {
		int points = iter - count.begin() + n;
		double possibility(0);
		for (int i = 0; i < *iter; i++)
			possibility += (1 / pow(6, n));
		result.push_back(pair<int, double>(points, possibility));
	}

	return result;
}

void Solution_20::countAvailableSum(int &sum, int &currentSum, int &diceCount, int &availableCount) {

	if (diceCount == 0 && sum == currentSum) {
		availableCount++;
		return;
	}
	else if (currentSum < sum) {
		for (int i = 1; i <= 6; i++) {
			if (currentSum + diceCount * 6 < sum) continue;
			if (i + currentSum <= sum) {
				currentSum += i;
				diceCount--;
				countAvailableSum(sum, currentSum, diceCount, availableCount);
				currentSum -= i;
				diceCount++;
			}
			else break;
		}
	}
	else if (currentSum > sum) return;

}

vector<pair<int, double>> Solution_20::dicesSum_2(int n) {
	
	vector<pair<int, double>> result;

	double **dp = new double *[n + 1];
	for (int i = 0; i < n + 1; i++)
		dp[i] = new double[6 * n + 1];

	for (int i = 1; i <= 6; i++)
		dp[1][i] = 1.0 / 6.0;

	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= 6 * i; j++) {
			for (int k = 1; k <= 6; k++) {
				if (j > k) {
					dp[i][j] += dp[i - 1][j - k];
				}
			}
			dp[i][j] /= 6.0;
		}
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < 6 * n + 1; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}


	for (int i = n; i <= 6 * n; i++) {
		result.push_back(pair<int, double>(i, dp[n][i]));
	}

	return result;
}
