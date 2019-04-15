tetris
이전다음
문제
테트리스를 해본 사람이라면 작대기 모양 테트리미노가 나오길 간절히 기다렸던 적이 있을 것이다. 지금 윤성이가 그러하다. 기다리고 기다리던 작대기 모양 테트리미노가 드디어 나온 것이다.

테트리스 맵은 가로로 C칸, 세로로 R칸의 C×R격자형 모양이다. 예를 들어보자. 아래 그림은 가로가 6칸, 세로가 6칸인 테트리스 맵의 상태이다.

tetrismapex

(검정색 칸은 이미 메워져있던 칸이고, 회색칸은 이번에 메울 작대기 모양 테트리미노를 의미한다.)

이때 가로가 1칸이고 세로가 4칸인 1×4 직사가형 작대기 모양의 테트리미노(테트리미노는 항상 1×4)를 왼쪽에서 5번째 칸에 둘 경우 총 세줄의 수평선을 메울 수 있다. 테트리스는 한번에 여러 수평선을 메울수록 큰 점수를 얻는 게임이므로, 위 경우에서는 이 방법이 가장 높은 점수를 얻을 수 있는 방법이다.

윤성이를 도와 작대기 모양 테트리미노를 어디에 두었을 때 가장 높은 점수를 얻을 수 있는지 알려주자. (윤성이는 작대기 모양 테트리미노가 나왔을때 게임오버를 당할지언정 가로가 더 길도록 눕혀서 두지 않는다는 나름의 테트리스 철학이 있다.)

그리고 테트리스는 무조건 일자로 떨어진다. (오른쪽에서 왼쪽으로 공간을 비집고 들어가는 등의 스킬은 윤성이에겐 존재하지않는다.)

 

입력
첫 줄에는 격자 크기를 나타내는 정수 C와 R이 하나의 공백을 사이에 두고 차례대로 주어진다. 두 값의 범위는 5 ≤ C, R ≤ 20이다. 그다음 줄 부터 총 R줄에 걸쳐 맵의 상태를 나타내는 숫자들이 공백을 사이에 두고 주어진다. 0은 아직 채워지지 않은 칸을 나타내며 1은 채워져있는 칸을 나타낸다.

 

출력
작대기를 왼쪽에서 X번째 자리에 두었을 때 가장 높은 점수를 얻을 수 있고 그 때 완전히 메워지는 수평선의 개수가 Y개라면, Y를 최대로 만드는 X와 그 때의 Y를 하나의 공백을 사이에 두고 출력해야 한다.

만약 어떤 자리에 두어도 수평선을 하나도 메울 수 없거나 게임오버가 일어나는 경우라면 X와 Y를 둘다 0으로 출력한다.(게임오버는 새로 내려온 작대기가 맵상을 벗어난 경우에 일어난다. 새로나온 작대기가 맵의 가장자리에 걸쳐있는 경우는 게임오버가 아니다.)

 

예제 입력
6 7
0 0 0 0 0 0
0 0 0 0 0 0
1 1 1 0 0 1
1 1 1 0 0 1
1 1 1 0 1 1
1 1 1 0 1 1
1 1 1 0 1 1
예제 출력
4 3

#include <stdio.h>

int IsGameOver(int(*arry)[100],int *possi,int row,int col) {
	//printf("0의 갯수: \n");
	for (int i = 0;i < col;i++) {
		int check = 0;
		for (int j = 0;j < row;j++) {
			if (arry[j][i] == 0)check++;
			else break;
		}
		//printf("%d ", check);
		if (check <= 3)possi[i] = -1;// -1 : 테트리미노가 올수없는 상태
	}
	/*for (int i = 0;i < col;i++)printf("%d ", possi[i]);
	printf("\n");*/
	
	for (int i = 0;i < col;i++) {
		if (possi[i] == 0)return 0;
	}
	return 1;//possi[] 가 모두 -1 인 상태로 모두 올 수 없는 상태이므로 true;
}

void CalcuScore(int(*arry)[100], int *score,int row,int col, int col_posi) {
	int last0_idx = 0;
	for (int i = 0;i < row;i++) {
		if (arry[i][col_posi] == 0)last0_idx++;
		else break;
	}
	last0_idx--;//맨 아래에 있는 0의 위치 (last0_idx, col)
	//printf("last0_idx: %d\n", last0_idx);
	// 가로 줄별로 점수계산하기
	int total = 0;
	for (int i = last0_idx - 3;i <= last0_idx;i++) {
		int check = 1;
		for (int j = 0;j < col;j++) {
			if (arry[i][j] == 0 && j != col_posi)check = 0;
		}
		if (check == 1)total++;
	}
	score[col_posi] = total;
	
	/*printf("Score: \n");
	for (int i = 0;i < col;i++)printf("%d ", score[i]);
	printf("\n");*/
}

int main() {

	int row, col;
	int arry[20][100];
	int possible[100];
	int score[100] = { 0 };
	scanf("%d %d", &col, &row);
	for (int i = 0;i < row;i++)
		for (int j = 0;j < col;j++)
			scanf("%d", *(arry + i) + j);

	if (IsGameOver(arry, possible, row, col))printf("0 0\n");
	else {
		for (int i = 0;i < col;i++) {
			if (possible[i] == 0) {//긴 막대기가 놓여도 괜찮은 곳
			//	printf("긴 막대기가 놓여도 괜찮은 곳: %d\n", i);
				CalcuScore(arry, score, row, col, i);
			}
		}
		int max_idx = 0;
		int dup = 0; // score가 모두 0일 때 0, 하나라도 점수가 있으면 1
		for (int i = 0;i < col;i++) {
			if (score[i]) {
				dup = 1;
				break;
			}
		}
		if (dup) {
			for (int i = 0;i < col;i++)
				if (score[max_idx] < score[i]) max_idx = i;

			printf("%d %d\n", max_idx + 1, score[max_idx]);
		}
		else {
			printf("0 0\n");
		}

		
		


	}
	
	return 0;
}
