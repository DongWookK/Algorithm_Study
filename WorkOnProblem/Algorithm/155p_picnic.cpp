#include <iostream>
using namespace std;

uint32_t n = 0;	// �׽�Ʈ ���̽� ��
uint32_t m = 0; // �л� ��
uint32_t p = 0; // ģ��¦�� ��  
bool aAreFriends[10][10];

int CountPair(bool taken[10])
{
	int aFirstFree = -1;
	for (int i = 0; i < n; ++i)
	{
		if (!taken[i])
		{
			aFirstFree = i;
			break;
		}
	}

	if (-1 == aFirstFree) return 1; //�������
	int aRv = 0;

	for (int aPairWith = aFirstFree + 1; aPairWith < n; ++aPairWith)
	{
		if (!taken[aPairWith] && aAreFriends[aFirstFree][aPairWith]) {
			taken[aFirstFree] = taken[aPairWith] = true;
			aRv += CountPair(taken);
			taken[aFirstFree] = taken[aPairWith] = false;
		}
	}

	return aRv;
}

void main() 
{
	//input

	return;
}                    