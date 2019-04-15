거듭제곱구하기L
이전다음
문제
n과 m이 주어질 때, n의 m승을 구하는 프로그램을 작성하시오. 단, n의 m승의 값이 커질 수 있기 때문에, 정답을 10,007 으로 나눈 나머지를 출력한다.

 

입력
첫 번째 줄에 숫자 n과 m이 주어진다. ( 1 ≤ n ≤ 100, 1 ≤ m ≤ 1,000,000,000,000,000,000 )  

출력
첫째 줄에 n의 m승을 10,007 으로 나눈 나머지를 출력한다.

 

예제 입력
3 4
예제 출력
81

#include <stdio.h>
#include <string.h>
/*
거듭제곱구하기L
이전다음
문제
n과 m이 주어질 때, n^m을 구하는 프로그램을 작성하시오. 단, n^m의 값이 커질 수 있기 때문에, 정답을 10,007 으로 나눈 나머지를 출력한다.



입력
첫 번째 줄에 숫자 n과 m이 주어진다. ( 1 ≤ n ≤ 100, 1 ≤ m ≤ 1,000,000,000,000,000,000 )

출력
첫째 줄에 nm을 10,007 으로 나눈 나머지를 출력한다.



예제 입력
3 4
예제 출력
81

*/

int func(int mit, long long int gisu) {
	//printf("밑 : %d, 지수: %d\n", mit, gisu);
	if (gisu == 1) {
		//	printf("지수가 1일 때) 밑 %d 반환\n", mit);
		return mit;
	}
	if (gisu % 2 == 0) {
		//	printf("지수가 짝수일 때\n");
		return func((mit*mit) % 10007, gisu / 2);
	}
	else {
		//	printf("지수가 홀수일 때\n");
		return ((mit ) * func(mit % 10007, gisu - 1)) % 10007;
	}
}
int main()
{
	int n;
	long long int m;
	scanf("%d %lld", &n, &m);
	printf("%d\n", func(n, m));


	return 0;
}
