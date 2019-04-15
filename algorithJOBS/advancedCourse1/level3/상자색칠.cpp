문제
box

면이 6개인 상자가 있다. 이를 여러 가지 색으로 칠하려 하는데, 단 조건이 있다. 인접한 면에 같은 색깔을 칠하면 안 된다는 것이다. 여러 가지 색깔이 주어졌을 때, 그 색깔들로 조건을 만족하여 상자의 모든 면을 칠할 수 있는지 판별하는 프로그램을 작성하시오.

 

입력
첫째 줄에 색깔의 개수 N ( 1 <= N <= 1,000 ) 이 주어진다. 둘째 줄에 색깔을 나타내는 N개의 숫자가 주어진다. 색깔은 양의 정수로 이루어져 있고, 1부터 N까지의 범위의 수이다.

 

출력
조건을 만족하면서 상자를 칠할 수 있으면 “YES”, 아니면 “NO”를 출력한다.

 

예제 입력
6
1 2 1 2 1 3
예제 출력
NO
 

예제 입력
6
1 2 3 4 5 6
예제 출력
YES
 

예제 입력
6
1 2 3 1 2 3
예제 출력
YES
 

예제 입력
8
1 2 2 2 1 1 1 3
예제 출력
NO


#include <stdio.h>



int main() {

	int arr[1000];
	int dice[1000];
	int typeNum;
	scanf("%d", &typeNum);

	for (int i = 0;i < 1000;i++) {
		dice[i] = 0;
	}

	

	for (int i = 0;i < typeNum;i++) {
		scanf("%d", arr + i);
	}
	for (int i = 0;i < typeNum;i++) {
		dice[arr[i]] ++;
	}
	

	int phase = 6;
	int flag = 0;
	for (int i = 0;i < typeNum+1;i++) {
		if (dice[i] == 1)phase--;
		else if(dice[i] >= 2)phase -= 2;
		if (phase <= 0) {
			flag = 1;
		}
	}
	if (flag == 1)printf("YES\n");
	else printf("NO\n");





	return 0;
}
