문제
n개의 오름차순으로 정렬된 숫자가 주어지고, 그 후 q개의 질문이 주어진다. 각각의 질문은 특정 숫자가 n개의 숫자 내에 존재하는지를 판별하는 것이다. 모든 q개의 질문에 대하여 답을 하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 숫자의 개수 n, 그리고 질문의 개수 q가 주어진다 ( 1 ≤ n ≤ 100,000, 1 ≤ q ≤ 100,000) 이는 오름차순으로 정렬되어 주어진다. 두 번째 줄에 n개의 숫자가 주어진다. 세 번째 줄에 q개의 질문이 주어진다. 각 수는 21억보다 작은 정수다.  

출력
각 질문에 대하여 숫자가 존재하면 YES, 아니면 NO를 한 줄에 하나씩 출력한다.

 

예제 입력
10 4
1 2 4 8 10 11 12 14 15 19
4 5 8 17
예제 출력
YES
NO
YES
NO

#include <stdio.h>
int arry[100000];
int qNum;

bool binarySearch(int arry[], int start, int end, int target) {

	if (start > end) {
		return false;
	}
	int mid = (start + end) / 2;
	if (arry[mid] == target)return true;
	else if (target < arry[mid]) return binarySearch(arry, start, mid - 1, target);
	else return binarySearch(arry, mid + 1, end, target);

}

bool binarySearch2(int arry[], int len, int target) {
	int start;
	int end;
	int mid;

	start = 0;
	end = len - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arry[mid] == target)return true;
		else if (target < arry[mid]) end = mid - 1;
		else start = mid + 1;
	}
	return false;
}
bool binarySearch3(int arry[], int len, int target) {
	int start;
	int end;
	int mid;
	start = 0;
	end = len - 1;
	if (target < arry[start])return false;
	else if (target == arry[start])return true;

	if (arry[end] < target)return false;
	else if (arry[end] == target)return true;

	while (start + 1 < end) {
		mid = (start + end) / 2;
		if (arry[mid] == target)return true;
		else if (target < arry[mid]) end = mid; // -1을 하지 않는다
		else start = mid;// +1을 하지 않는다
	}
	return false;
}

int main(void){
	
/*
문제
	n개의 오름차순으로 정렬된 숫자가 주어지고, 그 후 q개의 질문이 주어진다.
	각각의 질문은 특정 숫자가 n개의 숫자 내에 존재하는지를 판별하는 것이다.
	모든 q개의 질문에 대하여 답을 하는 프로그램을 작성하시오.
입력
	첫 번째 줄에 숫자의 개수 n, 그리고 질문의 개수 q가 주어진다 ( 1 ≤ n ≤ 100,000, 1 ≤ q ≤ 100,000) 이는 오름차순으로 정렬되어 주어진다. 두 번째 줄에 n개의 숫자가 주어진다. 세 번째 줄에 q개의 질문이 주어진다. 각 수는 21억보다 작은 정수다.
출력
	각 질문에 대하여 숫자가 존재하면 YES, 아니면 NO를 한 줄에 하나씩 출력한다.

예제 입력
10 4
1 2 4 8 10 11 12 14 15 19
4 5 8 17
예제 출력
YES
NO
YES
NO
*/
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i=0;i<n;i++)
		scanf("%d", arry + i);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &qNum);
		//bool res = binarySearch(arry, 0, n - 1, qNum);
		//if (binarySearch2(arry, 0, n - 1, qNum))printf("YES\n");
		if (binarySearch3(arry, n, qNum))printf("YES\n");
		else printf("NO\n"); 
	}
	return 0;
}
