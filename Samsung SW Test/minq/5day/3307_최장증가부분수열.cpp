#include <iostream>
#include <cstring>
using namespace std;
//dp·Î Ç®±â.
int sequence[1000];
int D[1000];
int main()
{
	
	int seQuenceSize;
	int testCaseSize;
	cin >> testCaseSize;
	
	for (int T = 1; T <= testCaseSize; T++)
	{
		memset(sequence, 0, sizeof(sequence));
		memset(D, 0, sizeof(D));
		
		scanf("%d", &seQuenceSize);

		for (int i = 0; i < seQuenceSize; i++)
		{
			scanf("%d", &sequence[i]);
		}
		D[0] = 1;
		for (int j = 1; j < seQuenceSize; j++)
		{
			D[j] = 1;
			for (int k = 0; k < j; k++)
			{
				if (sequence[j] > sequence[k] && D[j] < D[k] + 1)
				{
					D[j] = D[k] + 1;
				}
			}
		}
		cout << "#" << T << " " << D[seQuenceSize -1 ] << endl;
	}
	return 0;
}