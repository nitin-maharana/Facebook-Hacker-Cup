#include <iostream>

using namespace std;

unsigned long findCount(int *data, unsigned long n)
{
	unsigned long count = 0ul;
	int cnt = 0;
	int temp;

	for(unsigned long i = 0ul; i < n; i++)
	{
		if(cnt % 4 == 3)
		{
			cnt = 0;
			continue;
		}

		if(i+1 < n)
		{
			if(data[i] < data[i+1])
			{
				if((data[i+1] - data[i]) <= 10)
					cnt = (cnt + 1) % 4;
				else
				{
					if(cnt % 4 == 2)
					{
						cnt = 0;
						count += 1ul;
						continue;
					}

					if(cnt % 4 == 1)
					{
						cnt = (cnt+1) % 4;
						count += 1ul;

						if(data[i+1]-data[i]-10 <= 10)
							cnt = (cnt+1) % 4;
						else
						{
							cnt = 0;
							count += 1ul;
						}
						continue;
					}

					if(cnt % 4 == 0)
					{
						cnt = (cnt+1) % 4;
						count += 1ul;

						if(data[i+1]-data[i]-10 <= 10)
						{
							cnt = (cnt + 1) % 4;
						}
						else
						{
							cnt = (cnt + 1) % 4;
							count += 1ul;

							if(data[i+1]-data[i]-20 <= 10)
								cnt = (cnt + 1) % 4;
							else
							{
								cnt = 0;
								count += 1ul;
							}
						}
						continue;
					}
				}
			}
			else
			{
				count += (unsigned long)(3 - cnt);
				cnt = 0;
			}
		}
		else
		{
			count += (unsigned long)(3 - cnt);
			cnt = 0;
		}
	}

	return count;
}

int main(void)
{
	int t;
	int *data;
	unsigned long n;

	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> n;

		data = new int[n];

		for(unsigned long j = 0ul; j < n; j++)
			cin >> data[j];

		cout << "Case #" << i << ": " << findCount(data, n) << endl;

		delete[] data;
	}

	return 0;
}