#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node
{
	char val;
	vector<struct node*> child;
};

int main(void)
{
	int t;
	
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		int n;
		
		cin >> n;
		
		unsigned long long count = 0ull;
		
		node *root[26];
		
		for(int j = 0; j < 26; j++)
			root[j] = NULL;
				
		string str;
		
		while(n--)
		{
			cin >> str;
			
			node *temp, *tmp;
			
			temp = root[str[0]-97];
			
			if(temp == NULL)
			{
				count++;
				
				temp = new node;
				root[str[0]-97] = temp;
				temp->val = str[0];
				
				tmp = new node;
				
				(temp->child).push_back(tmp);
				
				temp = tmp;
				
				for(int j = 1; j < str.length(); j++)
				{					
					temp->val = str[j];
					
					tmp = new node;
					
					(temp->child).push_back(tmp);
					
					temp = tmp;
				}
			}
			else
			{
				count++;
				
				for(int j = 1; j < str.length(); j++)
				{					
					tmp = NULL;
					
					for(int k = 0; k < (temp->child).size(); k++)
					{
						if((temp->child)[k] && ((temp->child)[k]->val == str[j]))
						{
							tmp = (temp->child)[k];
							break;
						}
					}
					
					if(tmp)
					{
						count++;
						temp = tmp;
					}
					else
					{
						count++;
						
						for(j; j < str.length(); j++)
						{					
							tmp = new node;
							
							tmp->val = str[j];
					
							(temp->child).push_back(tmp);
					
							temp = tmp;
						}
					}
				}
			}	
		}

		cout << "Case #" << i << ": " << count << endl;
	}
	
	return 0;
}
