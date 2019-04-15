문자열 뒤집기
이전다음
문제
문자열이 주어질 때, 이를 뒤집어서 출력하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 문자열이 주어진다. ( 1 ≤ 문자열의 길이 ≤ 1,000 )  

출력
문자열을 뒤집은 결과를 출력한다.

 

예제 입력
Hello World!
예제 출력
!dlroW olleH

#include<stdio.h>
#include<string.h>

/*
문제
문자열이 주어질 때, 이를 뒤집어서 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에 문자열이 주어진다. ( 1 ≤ 문자열의 길이 ≤ 1,000 )

출력
문자열을 뒤집은 결과를 출력한다.
*/

int main() {
	char str[1001];

	fgets(str, 1000, stdin);
	int len = strlen(str);
	for (int i = len-1; i >=0; i--) {
		printf("%c", str[i]);
	}
	

	return 0;
}
