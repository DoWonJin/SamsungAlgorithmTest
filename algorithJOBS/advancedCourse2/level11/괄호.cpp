괄호
이전다음
문제
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나태내야 한다.

 

입력
첫째 줄에 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다.  

출력
만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다.

 

예제 입력
(())())
예제 출력
NO
 

출처
2012 ACM ICPC Asia Daejeon Regional 인터넷 예선 G
 
 
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

	int size() {
		return len;
	}

};

int main()
{
	Stack s;
	s.create(50);
	char arr[50];
	scanf("%s", arr);
	int len = strlen(arr);
	int con = 0;
	int i = 0;
	s.push(arr[i++]);

	while (1) {
		if (i == len && s.top() != -1) {
			printf("NO\n");
			break;
		}
		if (i == len && s.top() == -1) {
			printf("YES\n");
			break;
		}

		if (s.top() == '(' && arr[i] == ')') {
			i++;
			s.pop();
		}
		else {
			s.push(arr[i++]);
		}

		

	}

}
