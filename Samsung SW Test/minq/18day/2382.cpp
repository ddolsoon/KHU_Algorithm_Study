#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
//dx[5] {0,0,0 -1,1} 이런 식으로 선언되어 있었다..
//느낀점 : 5분안에 눈 디버깅이 불가능하다면 f5 or f10을 눌러서 최대한 빨리 디버깅을 시작하자.
//			간단한 디버깅으로도 잡아낼 수 있는 문제였다.
//				변수명이 길어지면 새로운 변수를 선언해서 코드가 한눈에 볼 수 있게끔 짜자.
int dx[5]{ 0 , 0, 0, -1 , 1 }; // 0은 빈값. 상 하 좌 우
int dy[5] = { 0, -1, 1, 0, 0 }; //0은 빈값.

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
		memset(microOrgaInfo, 0, sizeof(microOrgaInfo)); //신중해야함.
		for (int i = 1; i <= microOrgarnismSize; i++)
		{
			//매핑되어있는 microOrgarnism배열에 애드.
			cin >> height >> width >> tempMicOrgarNum >> tempDirection;
			microOrgaInfo[height][width].moveDirection = tempDirection;
			microOrgaInfo[height][width].nowsize = tempMicOrgarNum;								   
		}

		//분기는 1초마다 일어난다. 검사하는 위치에서 4방향으로 이동후 그 이동한 칸에서 다음 이동칸이 검사하는 칸인지 확인.
		while (afterHours--)
		{
			for (int i = 0; i<N; i++)
				for (int j = 0; j < N; j++)
				{
					int inLoopMax = 0;
					position maxPosition;

					for (int k = 1; k <= 4; k++) //네 방향 검사위해.
					{
						if (i + dy[k] >= 0 && j + dx[k] >= 0 && (i == i + dy[k] + dy[microOrgaInfo[i + dy[k]][j + dx[k]].moveDirection]) && (j == j + dx[k] + dx[microOrgaInfo[i + dy[k]][j + dx[k]].moveDirection]) && i + dy[k]<N && i + dx[k] <N) //이동 범위가 배열의 인덱스를 초과하면 안되고, 해당위치에서 상하좌우에 있는 미생물들의 다음 위치가 해당위치이면. 실수확률높다.
						{
							//해당 위치가 하얀색이라면. 맥스값 구해서. 그에 해당하는 디렉션할당.
							if (i >= 1 && j >= 1 && i < N - 1 && j < N - 1)
							{
								microOrgaInfo[i][j].nextSize += microOrgaInfo[i + dy[k]][j + dx[k]].nowsize; //각 방향의 값마다 배열에 넣어줌.
								if (inLoopMax < microOrgaInfo[i + dy[k]][j + dx[k]].nowsize)// 각 방향의 값을 벡터에 어펜딕스, 정렬하여 최고값 찾고 그 값의 디렉션을 이 위치의 디렉션으로 삼는다. 사이즈는 모두 더해준다.
								{
									inLoopMax = microOrgaInfo[i + dy[k]][j + dx[k]].nowsize;
									microOrgaInfo[i][j].nextMoveDirection = microOrgaInfo[i + dy[k]][j + dx[k]].moveDirection;
								}
							}
							else { //해당 위치 빨간색.
								   //방향설정 넥스트값설정.
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
				for (int j = 0; j < N; j++)//미생물 크기와 방향을 갱신해주고 한 루프를 마친다.
				{
					microOrgaInfo[i][j].nowsize = microOrgaInfo[i][j].nextSize;
					microOrgaInfo[i][j].nextSize = 0;
					microOrgaInfo[i][j].moveDirection = microOrgaInfo[i][j].nextMoveDirection;
					microOrgaInfo[i][j].nextMoveDirection = 0;
				}//now사이즈를 next사이즈로 변경해주고 next사이즈를 0으로 초기화. movedirection을 nextmovedirection으로 바꿔주고 nextmovedirection 0으로 초기화.
		}
		//모든 시간이 끝나고 즉 (afterHours==0) 남아있는 미생물들의 수를 ans에 ++ 해준다.
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans += microOrgaInfo[i][j].nowsize;

		cout << "#" << T << ' ' << ans << endl;
	}

}