#include<bits/stdc++.h>
#define MAX 2 * 1000 * 1000 * 1000
#define MIN -2 * 1000 * 1000 * 1000

using namespace std;
 
void interseccion(long long int intervals[][2], int N)
{
	long long int l = intervals[0][0];
	long long int r = intervals[0][1];
 
	bool ans = true;
 
	for(int i = 1; i < N; i++)
	{
		if(intervals[i][0] > r or intervals[i][1] < l)
		{
			ans = false;
			break;
		}
		else
		{
			l = max(l, intervals[i][0]);
			r = min(r, intervals[i][1]);
		}
	}
	
	if(not ans)
		cout << "Impossible";
	else
	{
		//long long int res = rand()%(l - r + 1) + l;
		//long long int res = (l + r) / 2;
		cout << (l + r) / 2;
		
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, pointer = 0;
 
	cin >> n;
 
	long long int x;
 
	string ec, conf;
 
	long long int intervals[n][2];
 
 
	while(n--)
	{
		cin >> ec >> x >> conf;
 
		//cout << ec << " " << x << " " << conf << "\n";
 
		if(conf == "Y")
		{
			if(ec == ">=")
			{
				intervals[pointer][0] = x;
				intervals[pointer][1] = MAX;
			}
			else if(ec == "<=")
			{
				intervals[pointer][0] = MIN;
				intervals[pointer][1] = x;
			}
			else if(ec == ">")
			{
				if(x < 0)
					intervals[pointer][0] = x + 1;
				else
					intervals[pointer][0] = x + 1;
				intervals[pointer][1] = MAX;
			}
			else if(ec == "<")
			{
				intervals[pointer][0] = MIN;
				if(x < 0)
					intervals[pointer][1] = x - 1;
				else
					intervals[pointer][1] = x - 1;
			}
		}
		else
		{
			if(ec == "<")
			{
				intervals[pointer][0] = x;
				intervals[pointer][1] = MAX;
			}
			else if(ec == ">")
			{
				intervals[pointer][0] = MIN;
				intervals[pointer][1] = x;
			}
			else if(ec == "<=")
			{
				if(x < 0)
					intervals[pointer][0] = x + 1;
				else
					intervals[pointer][0] = x - 1;
				intervals[pointer][1] = MAX;
			}
			else if(ec == ">=")
			{
				intervals[pointer][0] = MIN;
				if(x < 0)
					intervals[pointer][1] = x + 1;
				else
					intervals[pointer][1] = x - 1;
			}
		}
		//cout << intervals[pointer][0] << " " << intervals[pointer][1] << "\n";
		pointer++;
 
	}
 
	int N = sizeof(intervals) / sizeof(intervals[0]);
 
	interseccion(intervals, N);
	
	return 0;
}