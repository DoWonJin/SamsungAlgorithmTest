괄호의값
이전다음
문제
4개의 기호 ‘(’, ‘)’, ‘[’, ‘]’를 이용해서 만들어지는 괄호열 중에서 올바른 괄호열이란 다음과 같이 정의된다. 한 쌍의 괄호로만 이루어진 ‘()’와 ‘[]’는 올바른 괄호열이다. 만일 X가 올바른 괄호열이면 ‘(X)’이나 ‘[X]’도 모두 올바른 괄호열이 된다. X와 Y 모두 올바른 괄호열이라면 이들을 결합한 XY도 올바른 괄호열이 된다. 예를 들어 ‘(()[[]])’나 ‘(())[][]’ 는 올바른 괄호열이지만 ‘([)]’ 나 ‘(()()[]’ 은 모두 올바른 괄호열이 아니다. 우리는 어떤 올바른 괄호열 X에 대하여 그 괄호열의 값(괄호값)을 아래와 같이 정의하고 값(X)로 표시한다.

‘()’ 인 괄호열의 값은 2이다.
‘[]’ 인 괄호열의 값은 3이다.
‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.
예를 들어 ‘(()[[]])([])’ 의 괄호값을 구해보자. ‘()[[]]’ 의 괄호값이 2 + 3×3=11 이므로 ‘(()[[ ]])’의 괄호값은 2×11=22 이다. 그리고 ‘([])’의 값은 2×3=6 이므로 전체 괄호열의 값은 22 + 6 = 28 이다. 여러분이 풀어야 할 문제는 주어진 괄호열을 읽고 그 괄호값을 앞에서 정의한대로 계산하여 출력하는 것이다.

 

입력
첫째 줄에 괄호열을 나타내는 문자열(스트링)이 주어진다. 단 그 길이는 1 이상, 30 이하이다.  

출력
첫째 줄에 그 괄호열의 값을 나타내는 정수를 출력한다. 만일 입력이 올바르지 못한 괄호열이면 반드시 0을 출력해야 한다.

 

예제 입력
(()[[]])([])
예제 출력
28
 

출처
2008 한국 정보올림피아드 지역본선 중등부 2번

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
			if (y == '[' || y == '(') {
				data[len++] = y;
			}
			else if (len >= 1 && data[len - 1] != '[' && data[len - 1] != '(')
				data[len - 1] += y;
			else {
				data[len++] = y;
			}
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
	int nexttop() {
		if (len <= 1)
			return -1;
		else
			return data[len - 2];
	}
	int size() {
		return len;
	}
	void print() {
		printf("스택정보: ");
		for (int i = 0; i < len; i++)
			if (data[i] == '[' || data[i] == ']' || data[i] == '(' || data[i] == ')')
				printf("%c ", data[i]);
			else
				printf("%d ", data[i]);
		printf("\n");
	}

};

int main()
{
	Stack s;
	s.create(50);
	char arr[50];
	scanf("%s", arr);
	int len = strlen(arr);
	int i = 0;// 문자열 arr 표시자
	int res = 0;
	int flag = true;
	while (1) {
	//	s.print();
		if (i == len && s.top() == -1) {
			printf("%d\n", res);
			break;
		}
		else if ((i == len && s.top() != -1) || flag == false) {
			printf("0\n");
			break;
		}



		if (arr[i] == ')') {
			if (s.top() == '(')
			{
				/*
					( ) 만나는 경우
				*/
				i++;
				s.pop();
				s.push(2);
			}
			else if (s.top() == -1 || s.top() == '[' || s.top() == ']' || s.top() == ')')
			{
				s.push(')');
				flag = false;
			}
			else {
				//숫자일 경우
				int num = s.pop();
				if (s.top() == '(')
				{
					/*
						( ) 만나는 경우
					*/
					i++;
					s.pop();
					s.push(2 * num);
				}
				else if (s.top() == -1 || s.top() == '[' || s.top() == ']' || s.top() == ')')
				{
					s.push(')');
					flag = false;
				}
			}


		}
		else if (arr[i] == ']') {
			if (s.top() == '[')
			{
				/*
					[ ] 만나는 경우
				*/
				i++;
				s.pop();
				s.push(3);
			}
			else if (s.top() == -1 || s.top() == '(' || s.top() == ')' || s.top() == ']')
			{
				s.push(']');
				flag = false;
			}
			else {
				//숫자일 경우
				int num = s.pop();
				if (s.top() == '[')
				{
					/*
						[ ] 만나는 경우
					*/
					i++;
					s.pop();
					s.push(3 * num);
				}
				else if (s.top() == -1 || s.top() == '(' || s.top() == ')' || s.top() == ']')
				{
					s.push(']');
					flag = false;
				}
			}


		}
		else {
			s.push(arr[i++]);
		}

		if ((s.top() == '[' || s.top() == '(' || s.top() == ')' || s.top() == ']') == false) {
			/*
				스택안 데이터 갯수 1개이고 숫자일때
			*/
			if (s.len == 1)
				res += s.pop();
		}

	}

}
