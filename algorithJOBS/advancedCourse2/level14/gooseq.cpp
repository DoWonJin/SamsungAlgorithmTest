문제
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것 이 있으면, 그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.

다음은 나쁜 수열의 예이다.

33

32121323

123123213

다음은 좋은 수열의 예이다.

2

32

32123

1232123

길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하는 프로그램 을 작성하라. 예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수 열 1213121이다.

 

입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.

 

출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내 는 수열만 출력한다. 수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.

 

예제 입력
7
예제 출력
1213121
 

출처
KOI 1997 중등부 1번

#include <stdio.h>

int arr[80];
int N;
bool find = false;
int validCheck(int step) {
	bool valid = true;
	for (int width = 1;width <= step / 2;width++)
	{

		int count = 0;
		for (int i = 0;i < width;i++) {

			if (arr[step - i] == arr[step - i - width])
				count++;
		}
		if (count == width)
			return false;
	}
	return true;
}
void func(int step, int add) {

	if (find == true)return;
	arr[step] = add;
	
	/*
	for (int i = 1;i < N + 1;i++)
		printf("%d", arr[i]);
	printf("\n");

	*/
	if (validCheck(step) == false) { //중복이 발생할 때
		arr[step] = 0;
		//printf("중복발생\n");
		return;
	}
	else //유효할 때
	{
		if (step == N) {

			find = true;
		}
		else {
			func(step + 1, 1);
			func(step + 1, 2);
			func(step + 1, 3);
		}
	}
}

int main() {

	//Please Enter Your Code Here
	scanf("%d", &N);
	func(0, 0);
	for (int i = 1;i < N + 1;i++)
		printf("%d", arr[i]);
	printf("\n");
	return 0;
}
