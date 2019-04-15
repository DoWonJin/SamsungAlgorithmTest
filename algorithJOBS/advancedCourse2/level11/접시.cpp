접시
이전다음
문제
접시가 a, b, c, d 가 있고, 알파벳 순으로 한쪽이 막혀 있는 세척기에 들어간다고 할 때, b a c d 순으로 꺼내기 위해서는 push, push, pop, pop, push, pop, push, pop을 하면 된다. 세척기에서 꺼내는 순서가 주어질 때 그 동작을 출력하는 프로그램을 작성하시오. 만약 주어진 순서대로 접시를 꺼낼 수 없다면 “impossible”을 출력한다.

 

입력
첫째 줄에 소문자 알파벳이 주어진다. 중복된 소문자 알파벳은 입력되지 않는다. 알파벳 소문자는 26개이다.  

출력
접시를 꺼내는 것이 가능한 경우 push, pop의 순서를 출력한다. 이것이 불가능하다면 impossible을 출력한다.  

예제 입력
bacd
예제 출력
push
push
pop
pop
push
pop
push
pop

예제 입력
dabc
예제 출력
impossible

#include <stdio.h>
#include <string.h>
/*
문제
접시가 a, b, c, d 가 있고, 알파벳 순으로 한쪽이 막혀 있는 세척기에 들어간다고 할 때, b a c d 순으로 꺼내기 위해서는 push, push, pop, pop, push, pop, push, pop을 하면 된다. 세척기에서 꺼내는 순서가 주어질 때 그 동작을 출력하는 프로그램을 작성하시오. 만약 주어진 순서대로 접시를 꺼낼 수 없다면 “impossible”을 출력한다.

입력
첫째 줄에 소문자 알파벳이 주어진다. 중복된 소문자 알파벳은 입력되지 않는다. 알파벳 소문자는 26개이다.

출력
접시를 꺼내는 것이 가능한 경우 push, pop의 순서를 출력한다. 이것이 불가능하다면 impossible을 출력한다.

예제 입력
bacd
예제 출력
push
push
pop
pop
push
pop
push
pop

예제 입력
dabc
예제 출력
impossible

*/
struct Stack {
	int data[100];
	int len = 0;
	int capacity;

	void create(int y) {
		capacity = y;
	}
	int push(int y) {
		if (len >= capacity) {
			printf("overflow\n");
			return -1;
		}
		else {
			data[len++] = y;
			return y;
		}
	}
	int pop() {
		if (len <= 0) {
			printf("underflow\n");
			return -1;
		}
		else {
			int res = data[len - 1];
			len--;
			return res;
		}
	}
	int top() {
		if (len <= 0)
			return -1;
		else
			return data[len - 1];
	}
	void print() {
		for (int i = 0;i < len;i++)
			printf("%c ", data[i]);
		printf("\n");
	}
	int size() {
		return len;
	}

};

int main()
{
	Stack s;
	s.create(30);
	int flag = true;
	int res[52];
	int size = 0;
	char user[30];
	char i = 0;
	char j = 0;

	scanf("%s", user);
	int n = strlen(user);

	while (1) {
	//	s.print();
		//printf("i: %d , j:%d\n", i, j);
		if (i == n && j == n && s.top() == -1)break;
		if (i == n && s.top() != user[j]) {
			flag = false;
			break;
		}
		if (s.top() == user[j])
		{
			s.pop();
			j++;
			res[size++] = 1;
		}
		else {
			s.push('a' + i);
			i++;
			res[size++] = 2;
		}
	}
	if (flag == false)
		printf("impossible\n");
	else {
		for (int i = 0;i < size;i++)
			if (res[i] == 1)
				printf("pop\n");
			else
				printf("push\n");
	}
}
