#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n[100];
	int i = 0;
	ifstream file("pack.txt");
	while(!file.eof())
	{
		file >> n[i];	
		int max_n = n[i], min_n = n[i];
		for (int j = 0; j < i; j++) 
		{
			if(n[j] >= max_n)
				max_n = n[j];
			if(n[j] <= min_n)
				min_n = n[j];
		}
		cout <<"Pack:" << min_n << "-"<< max_n;
		i++;
		int counter = 0;
		cout<<endl<<"Missing elements:"<<endl;
		for(int l = min_n; l < max_n; l++)
		{
			bool result = 0;
			for(int t = 0; t < i; t++)
			{
				if(l == n[t])
					result = 1;
			}
			if (!result)
			{
				counter++;
				cout << l << " ";			
			}
		}
		if(counter == 0)
			cout << "None. Full pack";
		cout << endl;
	}
	return 0;
}
