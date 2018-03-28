#include <iostream>
#include <vector>
using namespace std;

int magnet[5][9];
int rollingTrend[21][2]; //int [rollingMagnetNum], [rollingTrend];
void Rolling(int magnetSequence, int rollingtrend);
int main()
{
	int testCaseSize;
	int rollingSize;
	cin >> testCaseSize;
	
	for (int T = 1; T <= testCaseSize; T++)
	{
		cin >> rollingSize;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 8; j++)
			{
				cin >> magnet[i][j];
			}

		for (int i = 1; i <= rollingSize; i++)
		{
			cin >> rollingTrend[i][0] >> rollingTrend[i][1];
			int adjacent12 = magnet[1][3]; int adjacent21 = magnet[2][7];
			int adjacent23 = magnet[2][3]; int adjacent32 = magnet[3][7];
			int adjacent34 = magnet[3][3]; int adjacent43 = magnet[4][7];
			
			if (rollingTrend[i][0] == 1)//첫번째꺼 돌리는 경우 //단계적으로 하는게 아님. 
			{
				if (adjacent12 == adjacent21) //1만 돌리면 됌.
				{
					Rolling(1, rollingTrend[i][1]);
				}
				else //1,2는 기본적으로 돌림. 
				{
					Rolling(1, rollingTrend[i][1]);//1돌리기
					rollingTrend[i][1] = rollingTrend[i][1] * -1;
					Rolling(2, rollingTrend[i][1]);//2돌리기.
					if (adjacent23 != adjacent32)
					{
						rollingTrend[i][1] = rollingTrend[i][1] * -1;
						Rolling(3, rollingTrend[i][1]);//3돌리기
						
						if (adjacent34 != adjacent43)
						{
							//4돌리기
							rollingTrend[i][1] = rollingTrend[i][1] * -1;
							Rolling(4, rollingTrend[i][1]);
						}
					}
						
				}
			}
			else if (rollingTrend[i][0] == 2) //2는 무조건 돌림.
			{
				Rolling(2, rollingTrend[i][1]);//2돌리기
				if (adjacent12 == adjacent21) //1은 안돌리기
				{
					if (adjacent23 != adjacent32) //3돌리기
					{
						rollingTrend[i][1] = rollingTrend[i][1] * -1;
						Rolling(3, rollingTrend[i][1]);//3돌리기
						if (adjacent34 != adjacent43)
						{
							rollingTrend[i][1] = rollingTrend[i][1] * -1;
							Rolling(4, rollingTrend[i][1]);//4돌리기
						}
					}
				}
				else //1은 무조건 돌리기.
				{
					Rolling(1, rollingTrend[i][1]*-1);//1돌리기

					if (adjacent23 != adjacent32) //3돌리기
					{
						rollingTrend[i][1] = rollingTrend[i][1] * -1;
						Rolling(3, rollingTrend[i][1]); //3돌리기
						if (adjacent34 != adjacent43)
						{
							rollingTrend[i][1] = rollingTrend[i][1] * -1;
							Rolling(4, rollingTrend[i][1]);
							//4돌리기
						}
						
					}
					
				}
				
			}
			else if (rollingTrend[i][0] == 3)//3은 무조건 돌리기.
			{
				Rolling(3, rollingTrend[i][1]);
				
				if (adjacent34 != adjacent43)
				{
					Rolling(4, rollingTrend[i][1] * -1);
				}//4돌리기.}
				
				if (adjacent23 != adjacent32)//2는 무조건 돌리기.
				{
					rollingTrend[i][1] = rollingTrend[i][1] * -1;
					Rolling(2, rollingTrend[i][1]);
					if (adjacent12 != adjacent21)
					{
						rollingTrend[i][1] = rollingTrend[i][1] * -1;
						Rolling(1, rollingTrend[i][1]);
					}//1돌리기.
				}
			}
			else//4는 무조건 돌리기.
			{
				Rolling(4, rollingTrend[i][1]);
				if(adjacent34 == adjacent43)
				{ }
				else//3은 무조건 돌리기.
				{
					rollingTrend[i][1] = rollingTrend[i][1] * -1;
					Rolling(3, rollingTrend[i][1]);
					if (adjacent23 != adjacent32) 
					{
						rollingTrend[i][1] = rollingTrend[i][1] * -1;
						Rolling(2, rollingTrend[i][1]);
						if (adjacent12 != adjacent21)
						{
							rollingTrend[i][1] = rollingTrend[i][1] * -1;
							Rolling(1, rollingTrend[i][1]);
						}//1은 무조건 돌리기
						 //2는 무조건 돌리기.
					}
				}
					
			}
			// 넣으면서 돌리기.
			// 돌리기 전에 인접한 자석과 인접하는 부분의 극 임시변수에 저장.
		}
		int answer = 0;
		answer += (1 * magnet[1][1] + 2 * magnet[2][1] + 4 * magnet[3][1] + 8 * magnet[4][1]);
		cout << '#' << T << ' ' << answer << endl;
	}
}

void Rolling(int magnetSequence, int rollingtrend)
{
	int temp[9];
	
	for (int i = 1; i <= 8; i++)//임시배열 복사.
	{
		temp[i] = magnet[magnetSequence][i];
	}

	if (rollingtrend == 1) // 시계방향
	{		
		for (int i = 2; i <= 8; i++)
		{
			magnet[magnetSequence][i] = temp[i - 1];
		}
		magnet[magnetSequence][1] = temp[8];
	}
	else // 반시계 방향.
	{
		for (int i = 1; i <= 7; i++)
		{
			magnet[magnetSequence][i] = temp[i + 1];
		}
		magnet[magnetSequence][8] = temp[1];
	}
}