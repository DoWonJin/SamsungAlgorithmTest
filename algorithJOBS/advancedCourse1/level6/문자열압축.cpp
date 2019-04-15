문제
문자열의 길이가 굉장히 길 경우, 이를 압축하여 짧게 만들어야 할 때가 종종 있다. 이 문제에서는 문자열이 주어졌을 때, 다음과 같은 방법으로 압축한 결과를 출력하는 프로그램을 작성한다. 예를 들어, 문자열이 AAABBBBBCCCCDDDDEFFF 라고 하자. 이 문자열을 압축하면, 연속으로 같은 문자가 나오는 부분에, 그 문자가 몇번 나왔는지를 적어줌으로써 압축한다. 즉, 이 문자열은 3A5B4C4DE3F 로 압축된다. E는 1개밖에 없기 때문에 따로 1을 적어주지 않는다.

 

입력
첫 번째 줄에 압축하고자 하는 문자열이 주어진다. 문자열의 길이는 1000보다 작다. 문자열에 구성된 알파벳은 대문자다.  

출력
문자열을 압축한 결과를 출력한다.

 

예제 입력
AAABBBBBCCCCDDDDEFFF
예제 출력
3A5B4C4DE3F


#include<stdio.h>
#include<string.h>

/*
문제
문자열의 길이가 굉장히 길 경우, 이를 압축하여 짧게 만들어야 할 때가 종종 있다. 
이 문제에서는 문자열이 주어졌을 때, 다음과 같은 방법으로 압축한 결과를 출력하는 프로그램을 작성한다. 
예를 들어, 문자열이 AAABBBBBCCCCDDDDEFFF 라고 하자. 
이 문자열을 압축하면, 연속으로 같은 문자가 나오는 부분에, 그 문자가 몇번 나왔는지를 적어줌으로써 압축한다.
즉, 이 문자열은 3A5B4C4DE3F 로 압축된다. E는 1개밖에 없기 때문에 따로 1을 적어주지 않는다.

입력
첫 번째 줄에 압축하고자 하는 문자열이 주어진다. 문자열의 길이는 1000보다 작다. 문자열에 구성된 알파벳은 대문자다.

출력
문자열을 압축한 결과를 출력한다.
*/

int main() {
	//AAABBBBBCCCCDDDDEFFF
	//3A5B4C4DE3F
	char str[1001];
	scanf("%s", str);
	int len = strlen(str);
	int sum[1000];
	char spell[1000];
	char turn = str[0];
	int size = 0;
	int tot = 0;
	int i;
	spell[0] = str[0];
	for (i = 0; i < len; i++) {
		if (str[i] != turn ){
			sum[size] = tot;//총갯수적기
			tot = 1;
			spell[++size] = str[i];
			turn = str[i];
		}
		else if (i==len-1) {
			sum[size] = ++tot;
		}
		else {
			tot++;
		}
	}
	
	for (int i = 0; i <= size; i++) {
		if (sum[i] >1)printf("%d", sum[i]);
		printf("%c", spell[i]);
	}
	return 0;
}
