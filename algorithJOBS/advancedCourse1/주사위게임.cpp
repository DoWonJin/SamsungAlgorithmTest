문제
1에서부터 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다.

* 규칙(1) 같은 눈이 3개가 나오면 10,000원+(같은 눈)*1,000원의 상금을 받게 된다. 

* 규칙(2) 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)*100원의 상금을 받게 된다. 

* 규칙(3) 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)*100원의 상금을 받게 된다.  
예를 들어, 3개의 눈 3, 3, 6이 주어지면 상금은 1,000+3 * 100으로 계산되어 1,300원을 받게 된다. 또 3개의 눈이 2, 2, 2로 주어지면 10,000+2 * 1,000 으로 계산되어 12,000원을 받게 된다. 3개의 눈이 6, 2, 5로 주어지면 그 중 가장 큰 값이 6이므로 6 * 100으로 계산되어 600원을 상금으로 받게 된다.

N(2≤N≤1,000) 명이 주사위 게임에 참여하였을 때, 가장 많은 상금을 받은 사람의 상금을 출력하는 프로그램을 작성하시오.

 

입력
첫째 줄에는 참여하는 사람 수 이 주어지고 그 다음 줄부터 N개의 줄에 사람들이 주사위를 던진 3개의 눈이 빈칸을 사이에 두고 각각 주어진다.

 

출력
첫째 줄에 가장 많은 상금을 받은 사람의 상금을 출력한다.

 

예제 입력
3
3 3 6
2 2 2
6 2 5
예제 출력
12000 
 

출처
KOI 2010 지역본선 초등부 2번

#include <stdio.h>
typedef struct 
{
	int num;
	int count;
}SameNum;

SameNum checkSameNum(int *ptr) {
	SameNum sn;
	if (*ptr == *(ptr + 1)) {
		if (*ptr == *(ptr + 2)) { // 1 1 1
			sn.count = 3;
			sn.num = *ptr;
		}
		else {// 1 1 2
			sn.count = 2;
			sn.num = *ptr;
		}
	}
	else { 
		if (*ptr == *(ptr + 2)) { // 1 2 1
			sn.count = 2;
			sn.num = *ptr;
		} 
		else if(*(ptr + 1) == *(ptr + 2)) { // 1 2 2
			sn.count = 2;
			sn.num = *(ptr + 1);
		}
		else {// 1 2 3 
			int max_idx = 0;
			for(int i=0;i<3;i++)
				if (*(ptr + max_idx) < *(ptr + i)) {
					max_idx = i;
				}
			sn.count = 0;
			sn.num = *(ptr + max_idx);
		}

	}
	return sn;
}

int main() {

	//Please Enter Your Code Here
	int n;
	int arr[3000];
	int score[1000];
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 3;j++) {
			scanf("%d", arr + 3 * i + j);
		}
	}
	
	for (int i = 0;i < n;i++) {
		SameNum sn = checkSameNum(arr + 3 * i);
		if (sn.count == 3)score[i] = 10000 + sn.num * 1000;
		else if (sn.count == 2)score[i] = (1000 + sn.num * 100);
		else score[i] = sn.num * 100;
	}
	int maxScore_idx = 0;
	for (int i = 0;i < n;i++) {
		if (score[maxScore_idx] < score[i])maxScore_idx = i;
	}

	printf("%d\n", score[maxScore_idx]);
	return 0;
}

