문제
분자 분모가 모두 자연수인 두 분수의 합 또한 분자 분모가 자연수인 분수로 표현할 수 있다.

두 분수가 주어졌을 때, 그 합을 기약분수의 형태로 구하는 프로그램을 작성하시오.

기약분수란 더 이상 약분되지 않는 분수를 의미한다.  

입력
첫째 줄과 둘째 줄에, 각 분수의 분자와 분모를 뜻하는 두 개의 자연수가 순서대로 주어진다. 입력되는 네 자연수는 모두 30,000 이하이다.

 

출력
첫째 줄에 구하고자 하는 기약분수의 분자와 분모를 뜻하는 두 개의 자연수를 공백으로 구분하여 순서대로 출력한다.

 

예제 입력
2 7
3 5
예제 출력
31 35

#include <stdio.h>
/*
	a  b  r
   24 21  3
   21  3  0
*/

int GCD2(int x, int y)
{
	int res;
	while (1) {
		res = x % y;
		if (res != 0) {
			x = y;
			y = res;
		}
		else {
			return y;
		}
	}
}

int main() {
	int n[2];
	int m[2];
	int a, b;
	int tmp;
	int GCD;
	scanf("%d %d", n, n + 1);
	scanf("%d %d", m, m + 1);
	a = n[0] * m[1] + n[1] * m[0];
	b = n[1] * m[1];
	if (a > b) {
		GCD = GCD2(a, b);
	}
	else {
		GCD = GCD2(b,a);
	}
	a /= GCD;
	b /= GCD;

	printf("%d %d\n", a, b);



	return 0;
}
