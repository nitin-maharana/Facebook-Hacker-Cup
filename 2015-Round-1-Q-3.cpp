/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

#include <iostream>
#include <map>

using namespace std;

int t, a, b;
map<pair<int, int>, unsigned long long> mem;
map<pair<int, int>, unsigned long long>::iterator it;

unsigned long long stressFree(int x, int y)
{
	if(x == a && y <= b)
	{
		return 1ull;
	}

	it = mem.find(make_pair(x, y));
	
	if(it != mem.end())
		return it->second;
	
	unsigned long long res1, res2;
	
	res1 = res2 = 0ull;
	
	res1 = stressFree(x+1, y);
	
	if(y+1 <= b && y+1 < x)
		res2 = stressFree(x, y+1);
		
	res1 = ((res1 + res2) % 1000000007ull);
		
	mem.insert(make_pair(make_pair(x, y), res1));
	
	return res1;
}

unsigned long long stressFull(int x, int y)
{
	if(x <= a && y == b)
	{
		return 1ull;
	}
	
	it = mem.find(make_pair(x, y));
	
	if(it != mem.end())
		return it->second;
	
	unsigned long long res1, res2;
	
	res1 = res2 = 0ull;
	
	res1 = stressFull(x, y+1);
	
	if(x+1 <= a && x+1 <= y)
		res2 = stressFull(x+1, y);
		
	res1 = ((res1 + res2) % 1000000007ull);
		
	mem.insert(make_pair(make_pair(x, y), res1));
	
	return res1;	
}

int main(void)
{
	char temp;
	
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		cin >> a >> temp >> b;
				
		cout << "Case #" << i << ": ";
		
		mem.clear();		
		cout << stressFree(0, 0) << " ";
		
		mem.clear();		
		cout << stressFull(0, 0) << endl;
	}
	
	return 0;
}
