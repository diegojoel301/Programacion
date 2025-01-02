#include<bits/stdc++.h>
#define M 10000000
 
using namespace std;
 
bool prime[M + 1];
 
void criba()
{
    for(int p = 2; p * p <= M; p++)
    {
        if(prime[p])
        {
            for(int i = p * 2; i <= M; i += p)
                prime[i] = false;
        }
    }
 
}
 
int primeFactors(int n)
{
    int sum = 0;
 
    while(n % 2 == 0)
    {
        sum += 2;
        n /= 2;
    }
 
    for(int i = 3; i * i <= n; i = i + 2)
    {
        while(n % i == 0)
        {
            sum += i;
            n = n/i;
        }
    }
 
    if(n > 2)
        sum += n;
 
    return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    memset(prime, true, sizeof(prime));
    criba();
    vector<bool> v;
 
    for(int i = 1; i <= 100000; i++)
    {
        v.push_back(prime[primeFactors(i)]);
    }
 
     
    int T, n;
    cin >> T;
 
    while(T--)
    {
        cin >> n;
 
        if(v[n - 1])
            cout << "ES PRIMO\n";
        else
            cout << "NO ES PRIMO\n";
    }
 
    return 0;
}