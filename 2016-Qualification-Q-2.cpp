#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t, n;
	string s1, s2;
	int count;
	int index;
	int len;

	cin >> t;

	for(int k = 1; k <= t; k++)
	{
		cin >> n;
		cin >> s1 >> s2;
		
		count = 0;
		
		len = 0;
		index = -1;
		
		for (int i = 0; i < n; i++)
		{
			if(s1[i] == 'X')
			{
				if(index != -1)
				{
					if(len > 1)
					{
						count++;

						for(int j = index; j < n && s1[j] == '.'; j++)
							s1[j] = 'X';

						for(int j = index - 1; j >= 0 && s1[j] == '.'; j--)
							s1[j] = 'X';

						if(s2[index] == '.' && (index+1 >= n || s2[index+1] == 'X') && (index-1 < 0 || s2[index-1] == 'X'))
							s2[index] = 'X';
					}
					index = -1;
				}

				len = 0;
			}
			else
			{
				len++;

				if(index == -1)
					index = i;
				else
				{
					if(s2[i] == '.' && (i+1 >= n || s2[i+1] == 'X') && (i-1 < 0 || s2[i-1] == 'X'))
						index = i;
				}
			}
		}

		if(len > 1 && index != -1)
		{
			count++;

			for(int j = index; j < n && s1[j] == '.'; j++)
				s1[j] = 'X';

			for(int j = index - 1; j >= 0 && s1[j] == '.'; j--)
				s1[j] = 'X';

			if(s2[index] == '.' && (index+1 >= n || s2[index+1] == 'X') && (index-1 < 0 || s2[index-1] == 'X'))
				s2[index] = 'X';
		}

		len = 0;
		index = -1;

		for (int i = 0; i < n; i++)
		{
			if(s2[i] == 'X')
			{
				if(index != -1)
				{
					count++;

					for(int j = index; j < n && s2[j] == '.'; j++)
						s2[j] = 'X';

					for(int j = index - 1; j >= 0 && s2[j] == '.'; j--)
						s2[j] = 'X';

					s1[index] = 'X';

					index = -1;			
				}

				len = 0;
			}
			else
			{
				len++;

				if(index == -1)
					index = i;
				else
				{
					if(s1[i] == '.')
						index = i;
				}
			}
		}

		if(index != -1)
		{
			count++;

			for(int j = index; j < n && s2[j] == '.'; j++)
				s2[j] = 'X';

			for(int j = index - 1; j >= 0 && s2[j] == '.'; j--)
				s2[j] = 'X';

			s1[index] = 'X';
		}

		for(int i = 0; i < n; i++)
		{
			if(s1[i] == '.')
			{
				s1[i] = 'X';
				count++;
			}
			if(s2[i] == '.')
			{
				s2[i] = 'X';
				count++;
			}
		}

		cout << "Case #" << k << ": " << count << endl;
	}

	return 0;
}
