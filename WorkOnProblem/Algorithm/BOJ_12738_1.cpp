#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int32_t GetPartPermutation(vector<int32_t>& pNumbers, int32_t pStartIndex)
{
	stack<int32_t> aPermutation;
	aPermutation.push(pNumbers[pStartIndex]);
	for (int32_t i = pStartIndex + 1; i < pNumbers.size(); ++i)
	{
		if (aPermutation.top() < pNumbers[i])
		{
			aPermutation.push(pNumbers[i]);
		}
	}
	
	return aPermutation.size();
}

int32_t BinarySearch(vector<int32_t>& pNumbers, int32_t aStart, int32_t aEnd)
{
	if (aStart == aEnd)
	{
		return aStart;
	}
	if (1 == (aEnd - aStart))
	{
		if (pNumbers[aStart] <= pNumbers[aEnd])
		{
			return aStart;
		}
		else
		{
			return aEnd;
		}
	}

	int32_t aMedian = aStart + ((aEnd - aStart) / 2);
	int32_t aLeft = BinarySearch(pNumbers, aStart, aMedian);
	int32_t aRight = BinarySearch(pNumbers, aMedian + 1, aEnd);

	if (aRight < aLeft)
	{
		if (GetPartPermutation(pNumbers, aLeft) < GetPartPermutation(pNumbers, aRight))
		{
			return aRight;
		}
	}
	else
	{
		return aLeft;
	}
}

int main()
{
	int32_t aLength = 0;
	vector<int32_t> aNumbers{};
	stack<int32_t> aPermutation;
	int32_t aCurrentCount = 0;
	aNumbers.clear();
	int32_t aNumber;

	// input
	cin >> aLength;
	for (int32_t i = 0; i < aLength; i++)
	{
		cin >> aNumber;
		aNumbers.push_back(aNumber);
	}

	int32_t aIndex = BinarySearch(aNumbers, 0, aNumbers.size() - 1);
	int32_t aAnswer = GetPartPermutation(aNumbers, aIndex);
	cout << aAnswer << endl;
	return 0;
}