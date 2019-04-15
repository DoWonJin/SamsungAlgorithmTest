계산기
이전다음
문제
덧셈, 뺄셈, 곱셈, 나눗셈을 할 수 있는 계산기 프로그램을 만드세요.

 

입력
첫째 줄에는 숫자 a가 입력되고, 둘째 줄에는 +, -, /, * 연산자가 입력된다. 마지막 줄에는 숫자 b가 입력된다.

 

출력
a와 b를 주어진 연산자를 활용하여 연산한 결과를 출력해라.

 

예제 입력
5
+
5
예제 출력
10
 

예제 입력
5
-
12
예제 출력
-7
 

예제 입력
2
*
105
예제 출력
210
 

예제 입력
125
/
5
예제 출력
25

#include<stdio.h>



int main() {

	int a, b;
	char op;//int로 받았을 때 문제가 생기나?
	int res;
	scanf("%d %c %d",&a,&op,&b);
	switch (op)
	{
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	case '*':
		res = a * b;
		break;
	case '/':
		res = a / b;
		break;
	default:
		break;
	}
	printf("%d\n", res);
	return 0;
}
