단지번호 붙이기
이전다음
문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

ec-17

 

입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

 

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

 

예제 입력
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000


예제 출력
3
7
8
9


 

출처
KOI 1996 초등부 1번  

#include<cstdio>
#include<vector>
#include<queue>

using namespace std;


const int MAX = 30;
int n;
//vector <int> myGraph[MAX];
int arr[MAX][MAX];
int danArr[MAX][MAX]; // 0으로 초기화 DFS돌면서 단지번호(ex. 1,2,3) 부여할 것
vector <int> HomeCount(1);   // 단지 1,2,3 에 각각 몇개 집이 있는지 갯수카운팅)
struct Point {
	int row;
	int col;
};
queue <Point> Queue[MAX];


void BFS(int i, int j, int dan) {
	Queue->push({ i,j });
	while (!Queue->empty()) {
		Point curr = Queue->front();
		Queue->pop();
		if (curr.row < 0
			|| curr.row >= n
			|| curr.col < 0
			|| curr.col >= n
			|| arr[curr.row][curr.col] == '0'
			|| danArr[curr.row][curr.col] != 0) {
			//printf("(%d %d) 무시\n",curr.row,curr.col);
			continue;
		}

		danArr[curr.row][curr.col] = dan;
		HomeCount[dan]++;
		//testCode
		/*for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (arr[i][j] == '1') {
					if (danArr[i][j] != 0)
						printf("%d ", danArr[i][j]);
					else
						printf("0 ");
				}
				else {
					printf("0 ");
				}
			}
			printf("\n");
		}
		printf("\n");
		for (int i = 1;i <= dan;i++) {
			printf("%d ", HomeCount[i]);
		}
		printf("\n");
		*/
		Queue->push({ curr.row, curr.col + 1 });
		Queue->push({ curr.row, curr.col - 1 });
		Queue->push({ curr.row + 1, curr.col });
		Queue->push({ curr.row - 1, curr.col });

	}



}


int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%c", &arr[i][j]);
		getchar();
	}

	/*printf("arr출력\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}*/

	int dan = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '1' && danArr[i][j] == 0) {//집이 있고   && 단지값이 없을 때
				//printf("(%d, %d)체크\n", i, j);
				HomeCount.push_back(0);
				dan++;
				BFS(i, j, dan);
			}
		}
	}
	//정렬
	for (int i = 1;i < dan;i++)
	{
		for (int j = 1;j <= dan - 1;j++) {
			if (HomeCount[j] > HomeCount[j + 1]) {
				int tmp = HomeCount[j];
				HomeCount[j] = HomeCount[j + 1];
				HomeCount[j + 1] = tmp;
			}
		}
	}

	printf("%d\n", HomeCount.size() - 1);
	for (int i = 0; i < dan; i++)
		printf("%d\n", HomeCount[i + 1]);
	return 0;
}

