#include <bits/stdc++.h>
using namespace std;
bool check(int left, int right, vector<int> &C, map<int, int> &m)
{
	if (right <= left) return true;
	int sampleleft = left, sampleright = right;
	int index = -1;
	while (sampleleft <= sampleright)
	{
		if (m[C[sampleleft]] == 1)
		{
			index = sampleleft;
			break;
		}
		if (m[C[sampleright]] == 1)
		{
			index = sampleright;
			break;
		}
		sampleleft++;
		sampleright--;
	}
	if (index == -1) return false;
	m.erase(C[index]);
	int k = (right + left) / 2;
	map<int, int> m2;
	if (index - k > 0)
	{
		for (int i = index + 1; i <= right; i++)
		{
			m[C[i]]--;
			m2[C[i]]++;
		}
		return check(left, index - 1, C, m) && check(index + 1, right, C, m2);
	}
	else
	{
		for (int i = left; i < index; i++)
		{
			m[C[i]]--;
			m2[C[i]]++;
		}
		return check(left, index - 1, C, m2) && check(index + 1, right, C, m);
	}
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
		map<int, int> m;
		for (int i=0; i<a; i++) 
		{
			cin>>C[i];
			m[C[i]]++;
		}
		(check(0,a-1,C,m)) ? cout<<"YES" : cout<<"NO";
		cout<<endl;
	}
}
