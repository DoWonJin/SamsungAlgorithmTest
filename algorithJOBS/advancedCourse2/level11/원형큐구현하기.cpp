원형큐구현하기
이전다음
문제
이 문제에서는 원형 큐를 구현한다. 선형 큐는 “큐가 실제로는 비어있어도 Push와 Pop을 할 수 없는" 문제가 발생할 수 있다. 원형 큐는 이 문제를 해결한다. 원형 큐 역시 큐와 마찬가지로 다음 세 개의 연산을 지원한다.

Push X : 큐에 정수 X를 push한다. 만약 rear 포인터가 더 이상 뒤로 갈 수 없다면, “Overflow”를 출력한다.
Pop : 큐에서 정수 하나를 pop한다. 만약 front 포인터가 더 이상 뒤로 갈 수 없다면, “Underflow”를 출력한다.
Front : 큐의 front에 있는 정수를 출력한다. 만약 큐가 비어있다면 “NULL”을 출력한다.
크기가 n인 원형 큐에 m개의 연산을 하는 프로그램을 작성하시오. 입력의 편의를 위해서 Push는 “1”, Pop은 “2”, Front는 “3”으로 표현한다. 아래 예제를 보면 크기 4인 큐에 15개의 연산이 입력으로 주어졌을 때의 입력과 출력의 예가 적혀있다. 참고로, 다음 연산은 “큐 구현하기" 문제와 동일하지만, 선형 큐의 문제를 잘 해결한다는 것에 주목하자.

 

입력
첫째 줄에 큐의 크기 n, 연산의 개수 m이 주어진다. ( 1 ≤ n ≤ 100, 1 ≤ m ≤ 1,000 ) 두 번째 줄부터 연산이 주어진다. 1은 Push, 2는 Pop, 3은 Front 연산을 의미한다.  

출력
연산의 결과를 출력한다.

 

예제 입력
4 15
1 1
1 2
1 3
3
2
2
3
1 4
1 5
3
2
2
1 6
2
3
예제 출력
1
3
3
6


#include <stdio.h>

struct Queue {
	int data[100];
	int f, r;
	int capacity;
	int num;
	void create(int y) {
		capacity = y;
		f = 0;
		r = 0;
		num = 0;
	}
	void push(int y) {
		if (num == capacity)
			printf("Overflow\n");
		else {
			data[r++] = y;
			r = r % capacity;
			num++;
		}
			
	}
	void pop() {
		if (num <= 0)
			printf("Underflow\n");
		else {
			data[f++] = 0;
			f = f % capacity;
			num--;
		}
			
	}
	int front() {
		if (num <= 0)
		{
			printf("NULL\n");
			return -1;
		}
		else
		{
			printf("%d\n", data[f]);
			return data[f];
		}
			
	}
	int size() {
		return num;
	}

};

int main() {
	/*
	0 1 2 3
	      

	*/
	Queue q;
	int n, m;
	int inp[2];
	scanf("%d %d", &n, &m);
	q.create(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", inp);
		if (inp[0] == 1) {
			scanf("%d", inp + 1);
			q.push(inp[1]);

		}
		else if(inp[0]==2) {
			q.pop();
		}
		else {
			q.front();
		}
	}
	return 0;
}
