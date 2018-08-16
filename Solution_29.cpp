#include "Solution_29.h"

bool Solution_29::isInterleave(string & s1, string & s2, string & s3) {
	// write your code here

	string::iterator iter1 = s1.begin(), iter2 = s2.begin(), iter3 = s3.begin();
	
	if (!s1.empty() && !s2.empty()) {

		for (iter3 = s3.begin(); iter3 != s3.end();) {

			string::iterator temIter1 = iter1, temIter2 = iter2, temIter3;
			int maxLen1(0), maxLen2(0);
			temIter3 = iter3;
			while (temIter1 != s1.end() && *temIter1 == *temIter3) maxLen1++, temIter1++, temIter3++;
			temIter3 = iter3;
			while (temIter2 != s2.end() && *temIter2 == *temIter3) maxLen2++, temIter2++, temIter3++;

			if (maxLen1 == 0 && maxLen2 == 0) {
				return false;
			}
			else if (maxLen1 <= maxLen2) {
				iter2 = temIter2;
				iter3 += maxLen2;
			}
			else if (maxLen1 > maxLen2) {
				iter1 = temIter1;
				iter3 += maxLen1;
			}
		}

		if (iter3 == s3.end()) return true;
	}
	else if (!s1.empty()) {
		return s1 == s3;
	}
	else if (!s2.empty()) {
		return s2 == s3;
	}
	else {
		return s3.empty();
	}
}

//s1 = "";
//s2 = "";
//s3 = "1";
//
//s1 = "aab";
//s2 = "a";
//s3 = "aaab";
//
//s1 = "sdfjas;dfjoisdufzjkndfasdkfja;sdfa;dfa;dfaskdjhfasdhjdfakhdgfkajdfasdjfgajksdfgaksdhfasdkbfjkdsfbajksdfhakjsdfbajkdfbakdjsfgaksdhgfjkdsghfkdsfgadsjfgkajsdgfkjasdfh";
//s2 = "dfnakdjnfjkzghdufguweygfasjkdfgb2gf8asf7tgbgasjkdfgasodf7asdgfajksdfguayfgaogfsdkagfsdhfajksdvfbgkadsghfakdsfgasduyfgajsdkfgajkdghfaksdgfuyadgfasjkdvfjsdkvfakfgauyksgfajkefgjkdasgfdjksfgadjkghfajksdfgaskdjfgasjkdgfuyaegfasdjkfgajkdfygadjskfgjkadfg";
//s3 = "sdfjas;dfjoisdfnakdjnfjkzghdufguwdufzjkeygfasjkdfgb2gf8asf7ndtgbgasjkdfgasodf7asdfgfajkasdksdfguayfgaogfsdkagfsfjadhfajksdvfbgkadsghfa;sdkdsfgasduyfgajsdkfgafajkdghfaksdgfuyadgfas;dfjkdvfjsdkvfakfgauyksa;dgfajkefgjkdasgfdjksffaskdjhfasdhjdfakhdgadjkghfajgfkajdfksdfgaskdjfgasjkdgfuasdjfgajksdfgaksdhfasdkbfjkdsfbajksdfyaegfasdjkfgajkdfygadjskfgjkadfghakjsdfbajkdfbakdjsfgaksdhgfjkdsghfkdsfgadsjfgkajsdgfkjasdfh"";
