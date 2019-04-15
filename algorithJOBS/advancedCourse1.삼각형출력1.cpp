소수 판별2
이전다음
문제
자연수n,m이 주어질 때, n부터m까지 존재하는 소수를 모두 출력하는 프로그램을 작성하여라. 여기서 소수란, 약수가 1과 자기자신밖에 존재하지 않는 수를 말한다.

 

입력
첫째 줄에 자연수 n, m이 주어진다. (1≤n,m≤20,000)

 

출력
첫째 줄에 n부터m까지 존재하는 소수를 모두 출력한다.

 

예제 입력
1 10
예제 출력
2 3 5 7 
 

예제 입력
13 30
예제 출력
13 17 19 23 29

#include <stdio.h>
#include <math.h>
int checkPrimeNum(int num) {
	if (num == 1)return 0;

	for (int i = 2;i <= (int)sqrt(num);i++)
		if (num%i == 0)return 0;
	return 1;
}
void printPrimeNum(int start, int end) {
	for (int i = start;i <= end;i++) {
		if (checkPrimeNum(i))
		{
			printf("%d ", i);
		}
	}
}

int main() {

	//Please Enter Your Code Here
	int a, b;
	scanf("%d %d", &a, &b);

	printPrimeNum(a, b);
	return 0;
}
