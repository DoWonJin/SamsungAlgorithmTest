스택구현하기
이전다음
문제
이 문제에서는 스택을 구현한다. 스택은 다음 세 개의 연산을 지원한다.

Push X : 스택에 정수 X를 push한다. 만약 스택이 꽉 차서 push를 할 수 없다면, “Overflow”를 출력한다.
Pop : 스택에서 정수 하나를 pop한다. 만약 스택이 비어있어서 pop을 할 수 없다면, “Underflow”를 출력한다.
Top : 스택의 top에 있는 정수를 출력한다. 만약 스택이 비어있다면 “NULL”을 출력한다.
크기가 n인 스택에 m개의 연산을 하는 프로그램을 작성하시오. 입력의 편의를 위해서 Push는 “1”, Pop은 “2”, Top은 “3”으로 표현한다.

 

입력
첫째 줄에 스택의 크기 n, 연산의 개수 m이 주어진다. ( 1 <= n <= 100, 1 <= m <= 1,000 ) 두 번째 줄부터 연산이 주어진다. 1은 Push, 2는 Pop, 3은 Top 연산을 의미한다.  

출력
연산의 결과를 출력한다.

 

예제 입력 1
4 10
1 1
1 2
1 3
2
3
1 4
1 5
3
1 6
3
예제 출력 1
2
5
Overflow
5
 

예제 입력 2
4 11
1 1
1 2
1 4
3
2
3
2
3
2
3
2
예제 출력 2
4
2
1
NULL
Underflow

#include <stdio.h>

struct Stack {
	int data[100];
	int len = 0;
	int capacity = 0;
	void creat(int y) {
		capacity = y;
	}

	void push(int y) {
		if (len >= capacity)
			printf("Overflow\n");
		else
			data[len++] = y;
	}

	void pop() {
		if (len == 0)
			printf("Underflow\n");
		else
		{
			data[len - 1] = 0;
			len--;
		}
	}
	
	void top() {
		if (len == 0)
			printf("NULL\n");
		else
			printf("%d\n",data[len - 1]);
	}
};

int arr[2];
int main() {
	Stack s;
	int n;
	int m;
	scanf("%d %d", &n,&m);
	s.creat(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", arr);
		
		if (arr[0] == 1) {
			scanf("%d", arr + 1);
			s.push(arr[1]);
		}
		else if (arr[0] == 2) {
			s.pop();
		}
		else {
			s.top();
		}
	}
	return 0;
}
