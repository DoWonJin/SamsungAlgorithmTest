문자열 포함관계 조사
이전다음
문제
문자열 A와 B가 주어질 때, 문자열 B가 문자열 A에 포함되어 있는지를 조사하는 프로그램을 작성하시오. 단, 문자열 A와 B에는 알파벳으로만 이루어져 있으며, 공백은 포함되지 않는다고 가정한다.  

입력
첫 번째 줄에 문자열 A, 두 번째줄에 문자열 B가 주어진다. 각각의 길이는 1,000을 넘지 않는다.  

출력
문자열 B가 문자열 A에 포함되면 YES, 아니면 NO를 출력한다.

 

예제 입력
Watermelon
melon
예제 출력
YES
 
 
 #include<stdio.h>
#include<string.h>

/*
문제
문자열 A와 B가 주어질 때, 문자열 B가 문자열 A에 포함되어 있는지를 
조사하는 프로그램을 작성하시오. 단, 문자열 A와 B에는 알파벳으로만 이루어져 있으며
, 공백은 포함되지 않는다고 가정한다.

입력
첫 번째 줄에 문자열 A, 두 번째줄에 문자열 B가 주어진다. 각각의 길이는 1,000을 넘지 않는다.
"abWONJIN"
"WONJIN"

출력
문자열 B가 문자열 A에 포함되면 YES, 아니면 NO를 출력한다.
*/

int main() {
	char strA[1001];
	char strB[1001];
	int lenA, lenB;
	scanf("%s", strA);
	scanf("%s", strB);
	lenA = strlen(strA);
	lenB = strlen(strB);
	if (lenA < lenB)printf("NO\n");
	else {
		bool flag = false;
		for (int i = 0; i <= lenA - lenB; i++) {
			if (strncmp(strA + i, strB, lenB) == 0) {
				flag = true;
				printf("YES\n");
			}
		}
		if (!flag) {
			printf("NO\n");
		}
	}

	return 0;
}
