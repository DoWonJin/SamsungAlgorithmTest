트리에서의 거리
이전다음
문제
트리가 주어지고, 두 노드 X, Y가 주어질 때, 이 두 노드 사이의 거리를 출력하는 프로그램을 작성하시오. 트리에서는 두 노드를 잇는 경로가 유일하기 때문에, 정답은 항상 유일하다는 것을 참고한다. 예를 들어, 다음과 같은 트리에서 노드 3, 노드 6 사이의 거리는 4이다.

alt text

 

입력
첫 번째 줄에 트리의 노드 개수 n, 두 노드 X, Y의 번호가 주어진다. ( 0 ≤ X, Y ≤ n < 1000 ) 두 번째 줄부터 트리의 간선 정보가 주어진다. 각 줄은 2개의 숫자 a, b로 이루어지며, 이는 노드 a가 노드 b의 부모노드라는 것을 의미한다. 루트는 노드 0이라고 가정한다.  

출력
두 노드 X, Y 사이의 거리를 출력한다.

 

예제 입력
11 3 6
0 1
0 2
1 3
1 4
1 5
2 6
2 10
6 7
6 8
6 9
예제 출력
4

#include <stdio.h>
const int MAX = 1000;

int conn[MAX][MAX];

int parent(int start) {
	for (int i = 0;i < start;i++)
		if (conn[start][i] == 1)
			return i;
};

int main() {
	
	int n,start,end;
	scanf("%d %d %d", &n, &start,&end);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a][b] = 1;
		conn[b][a] = 1;
	}
	
	int arr1[MAX], arr2[MAX];
	int start1 = start, end1 = end;
	int i = 1;
	arr1[0] = start;
	while (start != 0) {
		arr1[i] = parent(start);
		start = arr1[i];
		i++;
	}
	int j = 1;
	arr2[0] = end;
	while (end != 0) {
		arr2[j] = parent(end);
		end = arr2[j];
		j++;
	}
	int conmonNode;
	for (int k = 0;k < i;k++)
	{
		int flag = false;
		for (int g = 0;g < j;g++)
			if (arr1[k] == arr2[g])
			{
				conmonNode = arr1[k];
				flag = true;
				break;
			}
		if (flag == true)break;
	}

	 i = 0;
	int dis = 0;
	while (start1 != conmonNode) {
		start1 = parent(start1);
		dis++;
		i++;
	}
	 j = 0;
	while (end1 != conmonNode) {
		end1 = parent(end1);
		dis++;
		j++;
	}

	
	printf("%d\n", dis);

	return 0;
}
