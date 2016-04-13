#include<iostream>
using namespace std;

int main(void)
{
	int t, n, start, end, lastend, length;
	unsigned long long int p;
	unsigned long long int box[100010];
	unsigned long long int count;
	unsigned long long int tempSum;

	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> n >> p;

		for (int j = 0; j < n; j++)
			cin >> box[j];

		count = 0ull;
		tempSum = 0ull;

		start = end = -1;
		lastend = -1;

		for (int j = 0; j < n;)
		{
			if((tempSum + box[j]) > p)
			{
				if(tempSum > 0)
				{
					length = (end - start);
					count = count + ((length * (length+1)) / 2);

					if(lastend != -1)
					{
						length = (lastend - start);
						count = count - ((length * (length+1)) / 2);
					}
					lastend = end;

					tempSum = tempSum - box[start];
					start = start + 1;
				}
				else
				{
					start = end = lastend = -1;
					j++;
				}

			}
			else
			{
				if(start == -1)
					start = j;
				
				tempSum = tempSum + box[j];
				end = j+1;
				j++;
			}
		}

		if(tempSum > 0)
		{
			length = (end - start);
			count = count + ((length * (length+1)) / 2);
			if(lastend != -1)
			{
				length = (lastend - start);
				count = count - ((length * (length+1)) / 2);
			}
		}	

		cout << "Case #" << i << ": " << count << endl;
	}

	return 0;
}