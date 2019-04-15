findprime
이전다음
문제
주어진 숫자들 중 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.  

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 줄에 걸쳐 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

 

출력
주어진 수들 중 소수의 개수를 출력한다.

 

예제 입력
4
1
3
5
7
예제 출력
3

#include <stdio.h>


int main() {
	int size;
	int num[100];
	scanf("%d", &size);
	for (int i = 0;i < size;i++) {
		scanf("%d", &num[i]);
	}
	
	int max_idx = 0;
	int max;
	for (int i = 0;i < size;i++) {
		if (num[max_idx] < num[i])max_idx = i;
	}
	max = num[max_idx];
	for (int i = 2;i <= max;i++) {
		for (int j = 0;j < size;j++) {
			if (num[j] % i == 0 && num[j] != i)num[j] = 0;
			if (num[j] == 1)num[j] = 0;
		}
	}
	int count = 0;
	for (int j = 0;j < size;j++) {
		if (num[j])count++;
	}
	printf("%d\n", count);
	return 0;
}
