#include <bits/stdc++.h>
using namespace std;
//Nếu một ngày tôi bỏ code, đó là ngày tôi trúng Vietlott =(
//By Nguyễn Thanh Châu
int prevone[1000005];
int nextone[1000005];
int lastone[1000005];
vector<int> C;
void discretize()
{
	vector<int> F = C;
	sort(F.begin(), F.end());
	F.resize(unique(F.begin(),F.end()) - F.begin());
	int k = C.size();
	for (int i=0; i<k; i++)
	{
		int x = lower_bound(F.begin(),F.end(),C[i]) - F.begin();
		C[i]=x;
	}
	for (int i=0; i<k; i++)
	{
		nextone[i]=k;
		prevone[i]=-1;
		lastone[i]=-1;
	}
	for (int i=0; i<k; i++)
	{
		if (lastone[C[i]] >= 0)
		{
			prevone[i] = lastone[C[i]];
			nextone[prevone[i]] = i;
		}
		lastone[C[i]] = i;
	}
}
bool possible(int left, int right)
{
	while(true)
	{
		if (left >= right) return true;
		int a = left;
		int b = right;
		bool found = false;
		while (!found && a <= b)
		{
			if (prevone[a] < left && nextone[a] > right)
			{
				if (!possible(left, a-1)) return false;
				left = a + 1;
				found = true;
				break;
			}
			a++;
			if (prevone[b] < left && nextone[b] > right)
			{
				if (!possible(b+1, right)) return false;
				right = b - 1;
				found = true;
				break;
			}
			b--;
		}
		if (!found) return false;
	}
}
bool check()
{
	if (C.size()==0) return true;
	discretize();
	return possible(0, C.size()-1);
}
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int a;
        cin>>a;
        C.resize(a);
        for (int i=0; i<a; i++) cin>>C[i];
        check() ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}
