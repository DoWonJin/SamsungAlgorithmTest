#include<cstdio>
#include<queue>
#include<time.h>
#include<cstdlib>
using namespace std;
const int MAX = 55;
char map[MAX][MAX];
int n, m;
struct Node {
	int i;
	int j;

};
int main() {

	scanf("%d %d", &n, &m);
	getchar();

	Node dochi;
	Node biber;
	Node waterList[MAX];
	int waterNum = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'D')
			{
				biber.i = i;
				biber.j = j;
			}
			else if (map[i][j] == 'S') {
				dochi.i = i;
				dochi.j = j;
			}
			else if (map[i][j] == '*') {
				waterList[waterNum].i = i;
				waterList[waterNum].j = j;
				waterNum++;
			}
		}
		getchar();
	}

	bool is_update = true;
	const int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };
	for(int step=1;;step++){
		//is_update = false; // S가 안찾아지면 반복멈춤

	

		queue <Node> dochiQ[MAX];
		bool is_dochi[MAX][MAX] = { false, };
		bool visited[MAX][MAX] = { false, };
		for(int i=0;i<n;i++)
			for (int j = 0;j < m;j++) {
				if (map[i][j] == 'S' && visited[i][j] ==false) {
					dochiQ->push({ i,j });
					while (!dochiQ->empty()) {
						
						Node curr = dochiQ->front();dochiQ->pop();
						int i = curr.i;
						int j = curr.j;

						if (i >= 0 && i < n && j >= 0 && j < m) {
							if (map[i][j] == '.' || map[i][j] == 'D') {
								is_dochi[i][j] = true;
							}
							else if ((visited[i][j] == false) && map[i][j] == 'S') {
								visited[i][j] = true;
								Node next;
								for (int dir = 0;dir < 4;dir++)
								{
									next.i = i + dy[dir];
									next.j = j + dx[dir];
									dochiQ->push(next);
								}
							}
						}
						
					}
				}
				
			}
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				if (is_dochi[i][j] == true)
					map[i][j] = 'S';

		if (map[biber.i][biber.j] == 'S') {
			printf("%d\n", step);
			break;
		}

		queue <Node> waterQ[MAX];
		bool is_water[MAX][MAX] = { false, };
		for (int i = 0;i < waterNum;i++)
		{
			int visited[MAX][MAX] = { false, };
			waterQ->push(waterList[i]);
			while (!waterQ->empty()) {
				//testCode
				
				
				Node  curr = waterQ->front();waterQ->pop();
				int i = curr.i;
				int j = curr.j;
				
				if (i >= 0 && i < n && j >= 0 && j < m) {
					//통로나 고슴도치일 경우 물로 변환
					if (is_water[i][j] == false
						&& (map[i][j] == '.' || map[i][j] == 'S')) {
						is_water[i][j] = true;
					}
						
					//방문하지 않은 물일 경우
					else if (map[i][j] == '*' && visited[i][j] == false) {
						//방문체크
						visited[i][j] = true;
						// 1번 퍼지게 주변을 탐색한다
						Node next;
						for (int dir = 0;dir < 4;dir++) {
							next.i = i + dy[dir];
							next.j = j + dx[dir];
							waterQ->push(next);
						}
					}
					
				}

				
			}//waterBFS끝
		}//waterList끝

		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				if (is_water[i][j] == true)
					map[i][j] = '*';
		

		/*system("cls");
		printf("step: %d\n", step);
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
				printf("%c ", map[i][j]);
			printf("\n");
		}
		getchar();*/


		
		
		int dociCnt = 0;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				if (map[i][j] == 'S')
					dociCnt++;
		if (dociCnt == 0) {
			printf("KAKTUS\n");
			break;
		}

	}




	return 0;
}
