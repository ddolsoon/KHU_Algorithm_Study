#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
//dx[5] {0,0,0 -1,1} �̷� ������ ����Ǿ� �־���..
//������ : 5�оȿ� �� ������� �Ұ����ϴٸ� f5 or f10�� ������ �ִ��� ���� ������� ��������.
//			������ ��������ε� ��Ƴ� �� �ִ� ��������.
//				�������� ������� ���ο� ������ �����ؼ� �ڵ尡 �Ѵ��� �� �� �ְԲ� ¥��.
int dx[5]{ 0 , 0, 0, -1 , 1 }; // 0�� ��. �� �� �� ��
int dy[5] = { 0, -1, 1, 0, 0 }; //0�� ��.

struct microOrgarnism {
	int nowsize = 0;
	int nextSize = 0;
	int moveDirection;
	int nextMoveDirection;
};
struct position {
	int x;
	int y;
};

microOrgarnism microOrgaInfo[101][101];

int ans;
int main()
{
	int testcaseSize;
	int N, afterHours, microOrgarnismSize;
	int height, width, tempDirection, tempMicOrgarNum;
	cin >> testcaseSize;
	for (int T = 1; T <= testcaseSize; T++)
	{
		cin >> N >> afterHours >> microOrgarnismSize;
		ans = 0;
		memset(microOrgaInfo, 0, sizeof(microOrgaInfo)); //�����ؾ���.
		for (int i = 1; i <= microOrgarnismSize; i++)
		{
			//���εǾ��ִ� microOrgarnism�迭�� �ֵ�.
			cin >> height >> width >> tempMicOrgarNum >> tempDirection;
			microOrgaInfo[height][width].moveDirection = tempDirection;
			microOrgaInfo[height][width].nowsize = tempMicOrgarNum;								   
		}

		//�б�� 1�ʸ��� �Ͼ��. �˻��ϴ� ��ġ���� 4�������� �̵��� �� �̵��� ĭ���� ���� �̵�ĭ�� �˻��ϴ� ĭ���� Ȯ��.
		while (afterHours--)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N; j++)
				{
					int inLoopMax = 0;
					position maxPosition;

					for (int k = 1; k <= 4; k++) //�� ���� �˻�����.
					{
						if (i + dy[k] >= 0 && j + dx[k] >= 0 && (i == i + dy[k] + dy[microOrgaInfo[i + dy[k]][j + dx[k]].moveDirection]) && (j == j + dx[k] + dx[microOrgaInfo[i + dy[k]][j + dx[k]].moveDirection]) && i + dy[k]<N && i + dx[k] <N) //�̵� ������ �迭�� �ε����� �ʰ��ϸ� �ȵǰ�, �ش���ġ���� �����¿쿡 �ִ� �̻������� ���� ��ġ�� �ش���ġ�̸�. �Ǽ�Ȯ������.
						{
							//�ش� ��ġ�� �Ͼ���̶��. �ƽ��� ���ؼ�. �׿� �ش��ϴ� �𷺼��Ҵ�.
							if (i >= 1 && j >= 1 && i < N - 1 && j < N - 1)
							{
								microOrgaInfo[i][j].nextSize += microOrgaInfo[i + dy[k]][j + dx[k]].nowsize; //�� ������ ������ �迭�� �־���.
								if (inLoopMax < microOrgaInfo[i + dy[k]][j + dx[k]].nowsize)// �� ������ ���� ���Ϳ� �����, �����Ͽ� �ְ� ã�� �� ���� �𷺼��� �� ��ġ�� �𷺼����� ��´�. ������� ��� �����ش�.
								{
									inLoopMax = microOrgaInfo[i + dy[k]][j + dx[k]].nowsize;
									microOrgaInfo[i][j].nextMoveDirection = microOrgaInfo[i + dy[k]][j + dx[k]].moveDirection;
								}
							}
							else { //�ش� ��ġ ������.
								   //���⼳�� �ؽ�Ʈ������.
								microOrgaInfo[i][j].nextSize = microOrgaInfo[i + dy[k]][j + dx[k]].nowsize / 2;
								if (microOrgaInfo[i + dy[k]][j + dx[k]].moveDirection % 2 == 0)
									microOrgaInfo[i][j].nextMoveDirection = microOrgaInfo[i + dy[k]][j + dx[k]].moveDirection - 1;
								else
									microOrgaInfo[i][j].nextMoveDirection = microOrgaInfo[i + dy[k]][j + dx[k]].moveDirection + 1;
							}
						}
					}
				}
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)//�̻��� ũ��� ������ �������ְ� �� ������ ��ģ��.
				{
					microOrgaInfo[i][j].nowsize = microOrgaInfo[i][j].nextSize;
					microOrgaInfo[i][j].nextSize = 0;
					microOrgaInfo[i][j].moveDirection = microOrgaInfo[i][j].nextMoveDirection;
					microOrgaInfo[i][j].nextMoveDirection = 0;
				}//now����� next������� �������ְ� next����� 0���� �ʱ�ȭ. movedirection�� nextmovedirection���� �ٲ��ְ� nextmovedirection 0���� �ʱ�ȭ.
		}
		//��� �ð��� ������ �� (afterHours==0) �����ִ� �̻������� ���� ans�� ++ ���ش�.
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans += microOrgaInfo[i][j].nowsize;

		cout << "#" << T << ' ' << ans << endl;
	}

}