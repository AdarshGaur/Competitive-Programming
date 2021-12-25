#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
void calculate_primes(vector<int>& primes);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> primes(32001,1);
    calculate_primes(primes);
    int cases;
    cin >> cases;
    for(int t=0; t<cases; t++)
    {
        long long int m,n,i,j;
        cin >> m >> n;
        vector<int> sieve(n-m+1,1);
        for(i=2; i<=32000; i++)
        {
            if(primes[i]==1)
            {
                if(m%i == 0)
                {
                    j = m/i;
                }
                else
                {
                    j = m/i + 1;
                }
                if( j < i)
                {
                    j = i;
                }
                long long int temp = j*i;
                while(temp<=n)
                {
                    sieve[temp-m]=0;
                    j++;
                    temp = j*i;
                }
            }
        }
        if(m == 1)
        {
            sieve[0] = 0; // 1 is always composite
        }
        for(i=0; i<n-m+1; i++)
        {
            if(sieve[i]==1)
            {
                printf("%ld\n",m+i);
            }
        }
    }
}

void calculate_primes(vector<int>& primes)
{
    primes[0]=0;
    primes[1]=0;
    for(long long int i=2; i<=32000; i++)
    {
        long long int j = i;
        long long int temp = j*i;
        while(temp <= 32000)
        {
            primes[temp] = 0;
            j++;
            temp = j*i;
        }
    }
}