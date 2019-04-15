미로찾기
이전다음
문제
아래와 같이 이동할 수 있는 길, 그리고 이동할 수 없는 벽으로 이루어진 크기 N x M 의 지도가 주어진다. 이 때, (N-1, 0) 에서 출발하여 (0, M-1) 까지 도착하는 최단거리를 출력하는 프로그램을 작성하시오. 아래 그림에 대하여 S에서 E까지 가는 최단거리는 22이다.

ec-16

 

입력
첫째 줄에 지도의 세로 길이 N과 지도의 가로 길이 M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 둘째 줄부터 지도의 정보가 주어진다. 0은 이동할 수 있는 부분, 1은 이동할 수 없는 부분을 나타낸다.

 

출력
(N-1, 0) 에서 출발하여 (0, M-1) 까지 이동하는 데 필요한 최단거리를 출력한다.

 

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
};
queue <Point> Queue[MAX];

int arr[MAX][MAX];
int visited[MAX][MAX];
int maxDis = 0;
void BFS() {
	Queue->push({ n - 1, 0, 0 });

	while (!Queue->empty()) {
		Point curr = Queue->front();
		Queue->pop();
		if (curr.row == 0 && curr.col == m - 1 && maxDis < curr.dis)
		{
			maxDis = curr.dis;
			//printf("MaxDis: %d\n", maxDis);
			return;
		}
		if (curr.row < 0 || curr.row >= n || curr.col < 0 || curr.col >= m || arr[curr.row][curr.col] == 1 || visited[curr.row][curr.col])
			continue;
		else {
			visited[curr.row][curr.col] = true;
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
			_sleep(200);*/

			Queue->push({ curr.row, curr.col + 1,curr.dis + 1 });
			Queue->push({ curr.row - 1 ,curr.col ,curr.dis + 1 });
			Queue->push({ curr.row ,curr.col - 1 ,curr.dis + 1 });
			Queue->push({ curr.row + 1 ,curr.col ,curr.dis + 1 });
		}
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



/*
중복없는구간
#include <stdio.h>

int n;
int arr[100000];

int NotOverlap(int start, int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
			if (arr[start+i] == arr[start+j])return false;
	return true;
}

int func(int len) {
	for (int i = 0; i <= n - len; i++) {
		if (NotOverlap(i, len)) {
		//	printf("start: %d len: %d\n",i, len);
			return true;
		}
	}
//	printf("len: %d로 가능한 경우 없음\n", len);
	return false;
}

int binarySearch(int s, int e) {
	//printf("탐색범위 : (%d, %d)\n", s, e);
	if (e - s == 1) {
		//printf("탈출\n");
		return s+1;
	}
	int mid = (s + e) / 2;
	if (func(mid+1) == true) {
		return binarySearch(mid, e);
	}
	else
		return binarySearch(s,mid);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	int res = binarySearch(0, n-1);
	printf("%d\n", res);
	return 0;
}
*/
