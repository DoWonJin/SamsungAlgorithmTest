100점짜리 코드는 아님.
tip. 입력노드의 번호의 연결관계를 입력으로 넣을 때, 
크기순이아닌 섞여있는 번호일 때
즉, 0 1 / 0 2 / 0 3 순이 아닌 0 3/ 0 1 / 0 2 일때도 잘 동작하도록 수정할것.

문제
그래프가 주어질 때, 0번 정점을 시작으로 하여 깊이우선탐색과 너비우선탐색의 결과를 출력하는 프로그램을 작성하시오. 단, 노드를 방문할 때는 노드 번호가 작은 순서대로 방문한다고 하자.

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다.

 

출력
첫 번째 줄에 깊이우선탐색 결과, 두 번째 줄에 너비우선탐색 결과를 출력한다.

 

예제 입력
9 12
0 1
0 2
0 3
1 5
2 5
3 4
4 5
5 6
5 7
5 8
6 7
7 8


예제 출력
0 1 5 2 4 3 6 7 8
0 1 2 3 5 4 6 7 8

#include <cstdio>
#include <vector>
#include <queue>
/*

*/
using namespace std;
const int MAX = 10000;

int n, m;
vector <int> myGraph[MAX];
bool visited[MAX];

void DFS(int x) {
	visited[x] = true;
	printf("%d ", x);
	for (int i = 0; i < myGraph[x].size(); i++) {
		int y = myGraph[x][i];
		if (visited[y] == false)
			DFS(y);
	}
}

bool check[MAX];
queue <int> Queue;
void BFS() {
	
	Queue.push(0);
	check[0] = true;
	while (!Queue.empty()) {
		int curr = Queue.front();
		Queue.pop();
		printf("%d ", curr);
		for (int i = 0; i < myGraph[curr].size(); i++) {
			int next = myGraph[curr][i];
			if (check[next] == false)
			{
				check[next] = true;
				Queue.push(next);
			}
		}
	}

}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		myGraph[a].push_back(b);
		myGraph[b].push_back(a);
	}
	DFS(0);
	printf("\n");
	BFS();
	printf("\n");
	return 0;
}
 


