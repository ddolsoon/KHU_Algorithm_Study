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
			
			if (rollingTrend[i][0] == 1)//ù��°�� ������ ��� //�ܰ������� �ϴ°� �ƴ�. 
			{
				if (adjacent12 == adjacent21) //1�� ������ ��.
				{
					Rolling(1, rollingTrend[i][1]);
				}
				else //1,2�� �⺻������ ����. 
				{
					Rolling(1, rollingTrend[i][1]);//1������
					rollingTrend[i][1] = rollingTrend[i][1] * -1;
					Rolling(2, rollingTrend[i][1]);//2������.
					if (adjacent23 != adjacent32)
					{
						rollingTrend[i][1] = rollingTrend[i][1] * -1;
						Rolling(3, rollingTrend[i][1]);//3������
						
						if (adjacent34 != adjacent43)
						{
							//4������
							rollingTrend[i][1] = rollingTrend[i][1] * -1;
							Rolling(4, rollingTrend[i][1]);
						}
					}
						
				}
			}
			else if (rollingTrend[i][0] == 2) //2�� ������ ����.
			{
				Rolling(2, rollingTrend[i][1]);//2������
				if (adjacent12 == adjacent21) //1�� �ȵ�����
				{
					if (adjacent23 != adjacent32) //3������
					{
						rollingTrend[i][1] = rollingTrend[i][1] * -1;
						Rolling(3, rollingTrend[i][1]);//3������
						if (adjacent34 != adjacent43)
						{
							rollingTrend[i][1] = rollingTrend[i][1] * -1;
							Rolling(4, rollingTrend[i][1]);//4������
						}
					}
				}
				else //1�� ������ ������.
				{
					Rolling(1, rollingTrend[i][1]*-1);//1������

					if (adjacent23 != adjacent32) //3������
					{
						rollingTrend[i][1] = rollingTrend[i][1] * -1;
						Rolling(3, rollingTrend[i][1]); //3������
						if (adjacent34 != adjacent43)
						{
							rollingTrend[i][1] = rollingTrend[i][1] * -1;
							Rolling(4, rollingTrend[i][1]);
							//4������
						}
						
					}
					
				}
				
			}
			else if (rollingTrend[i][0] == 3)//3�� ������ ������.
			{
				Rolling(3, rollingTrend[i][1]);
				
				if (adjacent34 != adjacent43)
				{
					Rolling(4, rollingTrend[i][1] * -1);
				}//4������.}
				
				if (adjacent23 != adjacent32)//2�� ������ ������.
				{
					rollingTrend[i][1] = rollingTrend[i][1] * -1;
					Rolling(2, rollingTrend[i][1]);
					if (adjacent12 != adjacent21)
					{
						rollingTrend[i][1] = rollingTrend[i][1] * -1;
						Rolling(1, rollingTrend[i][1]);
					}//1������.
				}
			}
			else//4�� ������ ������.
			{
				Rolling(4, rollingTrend[i][1]);
				if(adjacent34 == adjacent43)
				{ }
				else//3�� ������ ������.
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
						}//1�� ������ ������
						 //2�� ������ ������.
					}
				}
					
			}
			// �����鼭 ������.
			// ������ ���� ������ �ڼ��� �����ϴ� �κ��� �� �ӽú����� ����.
		}
		int answer = 0;
		answer += (1 * magnet[1][1] + 2 * magnet[2][1] + 4 * magnet[3][1] + 8 * magnet[4][1]);
		cout << '#' << T << ' ' << answer << endl;
	}
}

void Rolling(int magnetSequence, int rollingtrend)
{
	int temp[9];
	
	for (int i = 1; i <= 8; i++)//�ӽù迭 ����.
	{
		temp[i] = magnet[magnetSequence][i];
	}

	if (rollingtrend == 1) // �ð����
	{		
		for (int i = 2; i <= 8; i++)
		{
			magnet[magnetSequence][i] = temp[i - 1];
		}
		magnet[magnetSequence][1] = temp[8];
	}
	else // �ݽð� ����.
	{
		for (int i = 1; i <= 7; i++)
		{
			magnet[magnetSequence][i] = temp[i + 1];
		}
		magnet[magnetSequence][8] = temp[1];
	}
}