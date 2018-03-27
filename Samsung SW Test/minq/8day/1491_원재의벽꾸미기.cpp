#include <iostream>
using namespace std;

//A*abs(R-C)+B*(N-R*C);
long long int Min = 4000000001;
int main()
{
	int N, A, B;

	int testCaseSize;
	cin >> testCaseSize;
	for (int T = 1; T <= testCaseSize; T++)
	{ 
		cin >> N >> A >> B;
		Min = 4000000001;
	for (long long r = 1; r <= N; r++) //왜 r<=1000, c<=1000할 때가 더 많이 패스?20개가량
	{
		for (long long c = 1; r*c <=N; c++)
		{
				if ((A*abs(r - c) + B * (N - r * c))<Min )
				{
					Min = A * abs(r - c) + B * (N - r * c);
				}
		}
	}
	cout << '#' << T << ' ' << Min << endl;
	}
}