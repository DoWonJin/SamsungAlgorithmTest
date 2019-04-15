70점짜리 정답코드임...

목수의 미로 탈출
이전다음
문제
아래와 같이 이동할 수 있는 길, 그리고 이동할 수 없는 벽으로 이루어진 크기 N x M 의 지도가 주어진다. 이 때, (N-1, 0) 에서 출발하여 (0, M-1) 까지 도착하는 최단거리를 찾으려 한다. 그런데 목수는 도끼 하나를 갖고 있으며, 이 도끼를 이용하여 벽을 깨부술 수 있다. 하지만 이 도끼는 내구성이 그렇게 좋지 않기 때문에, 벽을 최대 1개밖에 깰 수 없다. 목수가 출발점에서 도착점까지 이동하기 위한 최단거리를 출력하는 프로그램을 작성하시오. 물론, 벽은 최대 1개까지 깰 수 있다. 아래 예제의 경우 ‘X’ 로 표시된 벽을 깰 경우 거리 18만에 출발점에서 도착점으로 이동할 수 있다.

ec-20

 

입력
첫째 줄에 지도의 세로 길이 N과 지도의 가로 길이 M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 둘째 줄부터 지도의 정보가 주어진다. 0은 이동할 수 있는 부분, 1은 이동할 수 없는 부분을 나타낸다.

 

출력
목수가 (N-1, 0) 에서 출발하여 (0, M-1) 까지 이동하는 데 필요한 최단거리를 출력한다. 목수는 미로를 항상 탈출할 수 있다고 가정한다.

 

예제 입력
10 10
0 0 0 0 0 0 1 1 0 0
0 1 1 1 0 0 1 0 1 0 
0 1 1 1 0 0 1 0 1 0
0 0 0 0 0 0 0 0 1 0
0 0 1 1 1 1 0 0 1 0
0 0 0 0 0 0 1 1 0 0
0 0 1 1 1 0 1 1 0 0
0 0 1 1 1 0 0 0 0 0 
0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 1 0 0




예제 출력
18
 

예제 입력
10 10
0 0 0 0 0 0 1 1 0 0
0 1 1 1 0 0 1 1 1 0
0 1 1 1 0 0 1 1 1 0
0 0 0 0 0 0 0 1 1 0
0 0 1 1 1 1 0 1 1 0
0 0 0 0 0 0 1 1 0 0
0 0 1 1 1 0 1 1 0 0
0 0 1 1 1 0 0 1 0 0
0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 0 0 1 0 0





예제 출력
22


#include<cstdio>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<time.h>
using namespace std;
const int MAX = 1004;
int n;
int m;
vector <int> myGraph[MAX];
struct Point {
	int row;
	int col;
	int dis;
	bool hammer;
};
queue <Point> Queue[MAX];

int arr[MAX][MAX];
int visited[MAX][MAX];
int maxDis = 0;
void BFS() {
	Queue->push({ n - 1, 0, 0 ,true });

	while (!Queue->empty()) {
		Point curr = Queue->front();
		Queue->pop();
		if (curr.row == 0 && curr.col == m - 1 && maxDis < curr.dis)
		{
			maxDis = curr.dis;
			//printf("MaxDis: %d\n", maxDis);
			return;
		}
		if (curr.row < 0 || curr.row >= n || curr.col < 0 || curr.col >= m || visited[curr.row][curr.col])
			//경계를 벗어난 경우와 방문한 기록이 있는 경우
			continue;

		else if (arr[curr.row][curr.col] == 1) { // 벽에 막혀있는 경우
			if (!curr.hammer)//망치를 사용한 적이 있는 경우
				continue;
			else			//사용한 적 없는 경우
			{
				//사용
				//벽을 깨는 코드
				//arr[curr.row][curr.col] = 0;
				visited[curr.row][curr.col] = true;
				curr.hammer = false;
				//비사용 ----> 비효율발생하므로 없는 경우로 간주할 것
			}
		}

		else if (arr[curr.row][curr.col] == 0) { // 벽에 막혀있지 않는 경우
			visited[curr.row][curr.col] = true;
		}
		//test코드
			/*system("cls");
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < m;j++) {
					if (arr[i][j] == 0) {
						if (visited[i][j] == true)
							printf("1 ");
						else
							printf("0 ");
					}
					else
						printf("X ");
				}
				printf("\n");
			}
			printf("\n");
			_sleep(300);*/
		Queue->push({ curr.row, curr.col + 1,curr.dis + 1, curr.hammer });
		Queue->push({ curr.row - 1 ,curr.col ,curr.dis + 1 ,curr.hammer });
		Queue->push({ curr.row ,curr.col - 1 ,curr.dis + 1 ,curr.hammer });
		Queue->push({ curr.row + 1 ,curr.col ,curr.dis + 1 ,curr.hammer });
	}

}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			scanf("%d", &arr[i][j]);
	BFS();
	printf("%d\n", maxDis);

	return 0;
}
