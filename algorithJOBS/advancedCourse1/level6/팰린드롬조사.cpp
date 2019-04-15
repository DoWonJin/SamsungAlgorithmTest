문제
문자열이 주어질 때, 이것이 팰린드롬인지 조사하는 프로그램을 작성하시오. 팰린드롬이란, 앞으로 읽을 때와 뒤로 읽을 때의 결과가 같은 문자열을 말한다.  

입력
첫 번째 줄에 문자열이 주어진다. ( 1 ≤ 문자열의 길이 ≤ 1,000 )  

출력
입력된 문자열이 팰린드롬이면 YES, 아니면 NO를 출력한다.

 

예제 입력
abcba
예제 출력
YES
 

예제 입력
abcbd
예제 출력
NO

#include<stdio.h>
#include<string.h>

/*
문제
문자열이 주어질 때, 이것이 팰린드롬인지 조사하는 프로그램을 작성하시오. 팰린드롬이란, 앞으로 읽을 때와 뒤로 읽을 때의 결과가 같은 문자열을 말한다.

입력
첫 번째 줄에 문자열이 주어진다. ( 1 ≤ 문자열의 길이 ≤ 1,000 )

출력
입력된 문자열이 팰린드롬이면 YES, 아니면 NO를 출력한다.


*/

int main() {
	char str[1001];
	scanf("%s", str);
	int len = strlen(str);
	int flag = true;

	// 0 1 2 3   len = 4
	// 0 1 2 3 4 len = 5
	for (int i = 0; i <= len / 2 - 1; i++) {
		if (str[i] != str[len - 1 - i])flag = false;
	}
	if (flag == true) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	
	
	return 0;
}
