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
	int answer;
	cin >> testCaseSize;

	for (int T = 1; T <= testCaseSize; T++)
	{
		memset(sequence, 0, sizeof(sequence));
		memset(D, 0, sizeof(D));

		answer = 0;
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
			if (answer < D[j])
				answer = D[j];
		}
		cout << "#" << T << " " << answer << endl;
	}
	return 0;
}