#include <stdio.h>
#include <queue>
using namespace std;

struct SHARK {
	int y, x, time;
};

int n;
int map[20][20];

int shark_size, shark_eat;
SHARK shark;//실제 이동할 상어
//				   동  서  남  북	
const int dy[] = {  0,  0, +1, -1 };
const int dx[] = { +1, -1,  0,  0 };

int main()
{
	scanf("%d", &n);
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 9) {
				shark.y = y, shark.x = x, shark.time = 0;
				shark_size = 2, shark_eat = 0;
				map[y][x] = 0;
			}
		}
	}

	bool is_update = true;
	// true : 먹이를 찾았을 때 반복잡업
	while (is_update) {//먹이찾고 먹이먹고 두가지작업
		queue q;
		is_update = false;
		bool visited[20][20] = { false, };

		SHARK candi;
		candi.y = 20, candi.time = -1;

		//첫 위치
		visited[shark.y][shark.x] = true;//is_Update마다 처음 아기상어가 있는 위치true로
		q.push(shark);
		
		//먹이찾기 -시작
		//BFS로 모든 먹이 탐색-시작
		while (!q.empty()) {
			
			SHARK cur = q.front();	q.pop();
			//그림자 상어의 위치에서 살펴볼 것 - 시작
			//그림자 분신같은 SHARK next가 Queue에 담기고
			//조건에 최적화된(먹이가 있거나 물고기크기가 아기상어와 같은 곳의 위치) 그림자분신 cur을 SHARK Candi에 갱신!!!!!!
					//문제의 처음 시작위치
					//혹은 먹이가 없는 곳으로 이동한 후 위치
					//혹은 먹이가 있는 곳으로 이동하고 먹이를 먹고난 후 위치
					//혹은 먹이가 있는 곳으로 이동했으나 크기가 같아 먹을 수 없을 때 위치
			//<거리가 멀때>-물고기 존재유무와 상관없이
			if (candi.time != -1 && candi.time < cur.time) {//조건에 최적화된 candi와 비교했을 때 candi보다 시간이 더걸리는 거리는 폐기한다.
				break;
			}

				//<거리가 더 가깝거나 같을 때>
					//<물고기가 존재하고 먹이로 인식될 때>
			if (map[cur.y][cur.x] != 0 && map[cur.y][cur.x] < shark_size ) {
				is_update = true;
					//먹이의 위치가 최적일 때 candi에 갱신
				if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)) {
					candi = cur;
				}
			}
					//<else 먹이가 없을 때>
			//현재 그림자 상어의 위치에서 살펴볼 것 - 끝
	
			//현재 그림자 상어의 위치에서 4방향으로 - 시작
			for (int dir = 0; dir < 4; ++dir) {
				SHARK next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				next.time = cur.time + 1;
				// <4방향에 대한 다음번 1칸에 대한 shark위치가 경계를 벗어날때>
				if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) {
					continue;
				}
				//<다음번 1칸의 위치에서 
				//다른 쪽 탐색 경로로 방문했던적 없을 때 
				//&& 물고기의 크기: 같을 때 + 작을 때 + 없을 때>
				if (visited[next.y][next.x] == false && shark_size >= map[next.y][next.x]) {
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
			//현재 상어의 위치에서 4방향으로 - 끝
		}
		//BFS로 모든 먹이 탐색-끝
		//먹이찾기 -끝

		//먹이 찾아졌을 때
		if (is_update) {
			//최종candi를 shark에 갱신( shark를 확정된 candi위치로 이동)
			shark = candi;
			//먹은거 기록(shark , 지도, 먹은 횟수)
			++shark_eat;
			map[shark.y][shark.x] = 0;
			if (shark_eat == shark_size) {
				++shark_size;
				shark_eat = 0;
			}
		}
	}

	printf("%d\n", shark.time);

	return 0;
}
