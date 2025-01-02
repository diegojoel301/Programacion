#include<bits/stdc++.h>
#include<vector>

using namespace std;

const int NAX = 1e6 + 5;

char s[NAX];

vector<int> ocurrences[26];

int consider(const vector<int>& A, const vector<int>& B)
{
	if(A.empty() || B.empty())
		return 0;

	//union de los dos vectores dentro uno con -1 y +1

	vector<int> seq;
	int pointer2 = 0;

	for(int i : A)
	{
		while(pointer2 < (int) B.size() and B[pointer2] < i)
		{
			seq.push_back(-1); // indices desde B son cambiados a -1
			++pointer2;
		}

		seq.push_back(1); // indices desde A son cambiados a +1
	}

	while(pointer2 < (int) B.size())
	{
		seq.push_back(-1);
		++pointer2;
	}

	//buscando la maxima suma de un subarray que contiene por lo menos un -1
	const int n = seq.size();

	vector<int> pref{0};

	for(int x : seq)
		pref.push_back(pref.back() + x); // suma de prefijos

	vector<int> pref_min(n + 1);

	for(int i = 1; i <= n; ++i)
		pref_min[i] = min(pref_min[i - 1], pref[i]); //minima de suma de prefijos

	int answer = 0;
	int last_negative = -1; //valor falso, significa que no hubo valores negativos hasta ahora

	for(int i = 0; i < n; ++i)
	{
		if(seq[i] == -1)
			last_negative = i;
		if(last_negative != -1)
			answer = max(answer, pref[i + 1] - pref_min[last_negative]);
	}

	return answer;
}

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);

	assert(n == (int) strlen(s));

	for(int i = 0; i < n; ++i)
		ocurrences[s[i] - 'a'].push_back(i);

	int answer = 0;

	for(int a = 0; a < 26; a++)
	{
		for(int b = 0; b < 26; b++)
		{
			if(a != b)
				answer = max(answer, consider(ocurrences[a], ocurrences[b]));
		}
	}
	printf("%d\n", answer);
}