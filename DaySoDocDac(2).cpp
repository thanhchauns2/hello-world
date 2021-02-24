#include <bits/stdc++.h>
using namespace std;
bool check(int left, int right, vector<int> &C, unordered_map<int, int> &m)
{
	if (right <= left) return true;
	int sampleleft = left, sampleright = right;
	int indexleft = -1, indexright = -1;
	while (sampleleft <= sampleright)
	{
		if (m[C[sampleleft]] == 1)
		{
			indexleft = sampleleft;
			break;
		}
//		if (m[C[sampleright]] == 1)
//		{
//			index = sampleright;
//			break;
//		}
		sampleleft++;
//		sampleright--;
	}
	if (indexleft == -1) return false;
	while (sampleleft <= sampleright)
	{
//		if (m[C[sampleleft]] == 1)
//		{
//			index = sampleleft;
//			break;
//		}
		if (m[C[sampleright]] == 1)
		{
			indexright = sampleright;
			break;
		}
//		sampleleft++;
		sampleright--;
	}
//	if (indexright == -1) return false;
	m.erase(C[indexleft]);
	m.erase(C[indexright]);
//	int k = (right + left) / 2;
	unordered_map<int, int> m2, m3;
//	if (index - k > 0)
//	{
	for (int i = indexright + 1; i <= right; i++)
	{
		m[C[i]]--;
		m3[C[i]]++;
	}
//	return check(left, index - 1, C, m) && check(index + 1, right, C, m2);
//	}
//	else
//	{
	for (int i = left; i < indexleft; i++)
	{
		m[C[i]]--;
		m2[C[i]]++;
	}
	return check(left, indexleft - 1, C, m2) && check(indexleft + 1, indexright - 1, C, m) &&check(indexright + 1, right, C, m3);
//	}
}
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int a;
		cin>>a;
		vector<int> C(a);
		unordered_map<int, int> m;
		for (int i=0; i<a; i++) 
		{
			cin>>C[i];
			m[C[i]]++;
		}
		(check(0,a-1,C,m)) ? cout<<"YES" : cout<<"NO";
		cout<<endl;
	}
}
