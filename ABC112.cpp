#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int c()
{
	int n;
	cin >> n;
	struct info{
		int x;
		int y;
		long long int h;
	};
	vector<info> infos(n);
	for(int i = 0; i < n; i++)
	{
		int x, y, h;
		cin >> x >> y >> h;
		info temp = {x, y, h};
		infos[i] = temp;
	}
	for(int cx = 0; cx <= 100; cx++)
	{
		for(int cy = 0; cy <= 100; cy++)
		{
			long long int h = -1;
			long long int upper = -1;
			bool flag = true;
			for(int i = 0; i < n; i++)
			{
				if(infos[i].h == 0)
				{
					long long int temp = abs(infos[i].x - cx) + abs(infos[i].y - cy);
					if(upper == -1)
					{
						upper = temp;
					}else{
						upper = min(upper, temp);
					}
				}else{
					long long int temp = infos[i].h + abs(infos[i].x - cx) + abs(infos[i].y - cy);
					if(h == -1 || h == temp)
					{
						h = temp;
					}else{
						flag = false;
						break;
					}
				}
			}
			if(flag)
			{
				if(upper == -1 || h <= upper)
				{
					cout << cx << " " << cy << " " << h << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> divides;
	for(int i = 1; i * i <= m; i++)
	{
		if(m % i == 0)
		{
			divides.push_back(i);
			if(i == m / i) continue;
			divides.push_back(m / i);
		}
	}
	sort(divides.begin(), divides.end());
	int i = 0;
	for(; i < divides.size(); i++)
	{
		if(n <= divides[i]) break;
	}
	cout << m / divides[i] << endl;
	return 0;
}
