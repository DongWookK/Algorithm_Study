#include <iostream>
#include <vector>
using namespace std;

// Traveling Salesman Problem
int  n; // 도시 수
constexpr int MAX = 10;
double dist[MAX][MAX]; // 도시간의 거리
uint32_t aMin = 999999999;
vector<int> aAnswerPath;

double ShortestPath(vector<int>& pPath, vector<bool>& pVisited, double pCurrentLegnth)
{
	if (pPath.size() == n)
	{
		return pCurrentLegnth + (dist[pPath.back()][0]);
	}

	for (int next = 1; next < n; ++next)
	{
		if (pVisited[next])
		{
			continue;
		}

		pCurrentLegnth += dist[pPath.back()][next];
		pPath.push_back(next);
		uint32_t aRv = ShortestPath(pPath, pVisited, pCurrentLegnth);
		if (aRv < aMin)
		{
			aAnswerPath = pPath;
		}
	}
}

void main()
{
	vector<int> aPath;
	aPath.push_back(0);
	vector<bool> aVisited;
	ShortestPath(aPath, aVisited, 0);

	// answer = aPath
	return;
}