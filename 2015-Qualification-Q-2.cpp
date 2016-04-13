#include <iostream>

using namespace std;

int t, n, gp, gc, gf;
bool flag;

void findOutput(int *p, int *c, int *f, int in, int sum1, int sum2, int sum3)
{
	if(sum1 == gp && sum2 == gc && sum3 == gf)
		flag = true;
	
	if(in == n)
		return;

	if(!flag && sum1 <= gp && sum2 <= gc && sum3 <= gf)
	{	
		findOutput(p, c, f, in+1, sum1+p[in], sum2+c[in], sum3+f[in]);
		findOutput(p, c, f, in+1, sum1, sum2, sum3);
	}
}

int main(void)
{	
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		cin >> gp >> gc >> gf;
		
		cin >> n;
		
		int p[n], c[n], f[n];
		
		for(int j = 0; j < n; j++)
			cin >> p[j] >> c[j] >> f[j];
			
		cout << "Case #" << i << ": ";
	
		flag = false;
			
		findOutput(p, c, f, 0, 0, 0, 0);
		
		if(flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	
	return 0;
}
