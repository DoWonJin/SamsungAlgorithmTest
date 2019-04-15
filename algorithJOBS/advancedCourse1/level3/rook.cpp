rook
이전다음
문제
체스에서 룩이라는 기물은 막혀있지만 않으면 룩의 위치에서 같은 행, 같은 열에 해당하는 칸 중 하나로 한 번 이동할 수 있다. 단, 특정 칸이 막혀있다면 그 칸에서부터 더 나아갈 수는 없다. 만약 룩이 아래 그림과 같이 5행 4열에 존재하고 같은 행열에 기물이 없다면 5행이나 4열에 존재하는 칸 중 어디로든 갈 수 있다. 예를 들어, 5행 2열 혹은 1행 4열로 움직일 수 있다. 차례에 주어진 이동 횟수는 한 번이므로 이동이 완료되었다면 상대방의 차례로 넘어간다.

alt text

체스는 킹만 잡히면 지게 되는 게임이다. 그 중에서도 알랩이는 룩으로 인해 게임을 지는 것을 극도로 싫어한다!

현재 차례가 상대의 차례일 때, 주어진 체스판의 상태에서 알랩이의 킹이 상대방의 룩에게 잡힐 가능성이 있는지 알아보자.

 

입력
8줄에 걸쳐 8x8 체스판의 상태가 주어진다. 이때 0은 기물이 없는 상태이고, 1은 알랩이의 킹을 의미하고, 2는 상대의 룩을 의미하며 3은 그 외 다른 기물들을 의미한다. (킹은 하나만 존재하며, 상대의 룩은 최대 2개까지 있을 수 있다. 그 외 기물들은 최대 29개까지 있을 수 있다.)

 

출력
킹이 룩에게 잡힐 가능성이 있으면 1, 아니면 0을 출력한다.

 

예제 입력 1
0 3 0 0 0 0 0 0
3 1 0 0 0 0 2 0
0 3 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
예제 출력 1
1
 

예제 입력 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 3 3 0 0 0 0 0
3 0 1 0 3 0 2 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
예제 출력 2
0

#include<stdio.h>

typedef struct {
	int row;
	int col;
}Point;
void printPoint(Point p) {
	printf("row: %d\n", p.row);
	printf("col: %d\n", p.col);
}
int main(void) {

	int arry[8][8] = { 0 };
	Point king;
	Point rook[2];
	int order = 0;

	int defence[2] = { 1,1 }; //잡힐 가능성있으면 1 안잡히면 0

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			scanf("%d", *(arry + i) + j);
			if (arry[i][j] == 1) {
				king.row = i;
				king.col = j;
			}
			
		}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			if (arry[i][j] == 2 && (i == king.row || j == king.col)) {
				rook[order].row = i;
				rook[order].col = j;
				order++;
			}

		}

	//printPoint(king);
	//printPoint(rook[0]);
	//printPoint(rook[1]);
	//printf("Order: %d\n", order);
	for (int i = 0; i < order; i++) {
		if (king.row == rook[i].row) {
			if (king.col < rook[i].col) {
				for (int col = king.col + 1; col < rook[i].col; col++) {
					if (arry[king.row][col] == 3) {
						defence[i] = 0;
						break;
					}
				}
				
			}
			else {
				for (int col = rook[i].col + 1; col < king.col; col++) {
					if (arry[king.row][col] == 3) {
						defence[i] = 0;
						break;
					}
				}
				
			}
		}
		else if(king.col == rook[i].col) {
			if (king.row < rook[i].row) {
				for (int row = king.row + 1; row < rook[i].row; row++) {
					if (arry[row][king.col] == 3) {
						defence[i] = 0;
						break;
					}
				}
				
			}
			else {
				for (int row = rook[i].row + 1; row < king.row; row++) {
					if (arry[row][king.col] == 3) {
						defence[i] = 0;
						break;
					}
				}
				
			}
		}

	}

	//printf("defence0 : %d\n", defence[0]);
	//printf("defence1 : %d\n", defence[1]);
	int check = 0;
	for (int i = 0; i < order; i++) {
		if (defence[i] == 1) {
			check = 1;
			break;
		}
	}
	
	
	if (check == 0) {
		printf("0\n");
	}
	else {
		printf("1\n");
	}
		
	


	return 0;
}
