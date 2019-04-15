문제
숫자박스에는 자연수들이 적혀있는 종이들이 N장 들어있다. 숫자 M개가 주어졌을 때, 이 숫자가 적혀있는 숫자가 상자 안에 있는지 아닌지를 구하는 프로그램을 작성하시오.  

입력
첫째 줄에 윤성이가 가지고 있는 숫자 정보의 개수 N (1 ≤ N ≤ 300,000)이가 주어진다. 둘째 줄에는 숫자 정보들이 주어진다. 숫자는 1,000,000이하의 정수이다. 두 숫자 카드에 같은 숫자가 적혀있는 경우는 없다.

셋째 줄에는 M (1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 윤성이가 숫자 박스에 있는지 아닌지를 구해야 할 M개의 숫자가 주어지며, 이 숫자는 공백으로 구분되어져 있다. 이숫자도 1,000,000이하의 정수이다.  

출력
첫째 줄에 입력으로 주어진 M개의 숫자에 대해서, 각 숫자가 숫자 상자안에 있으면 1, 아니면 0을 개행으로 구분해 출력한다.

 

예제 입력
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10
예제 출력
1
0
0
1
1
0
0
1

#include <stdio.h>
#include <stdlib.h>
/*
문제
숫자박스에는 자연수들이 적혀있는 종이들이 N장 들어있다. 숫자 M개가 주어졌을 때, 이 숫자가 적혀있는 숫자가 상자 안에 있는지 아닌지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 윤성이가 가지고 있는 숫자 정보의 개수 N (1 ≤ N ≤ 300,000)이가 주어진다. 둘째 줄에는 숫자 정보들이 주어진다. 숫자는 1,000,000이하의 정수이다. 두 숫자 카드에 같은 숫자가 적혀있는 경우는 없다.

셋째 줄에는 M (1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 윤성이가 숫자 박스에 있는지 아닌지를 구해야 할 M개의 숫자가 주어지며, 이 숫자는 공백으로 구분되어져 있다. 이숫자도 1,000,000이하의 정수이다.

출력
첫째 줄에 입력으로 주어진 M개의 숫자에 대해서, 각 숫자가 숫자 상자안에 있으면 1, 아니면 0을 개행으로 구분해 출력한다.



예제 입력
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10
예제 출력
1
0
0
1
1
0
0
1
*/
int arr[300000];
int ques[500000];
int temp[300000];
void merge(int arr[], int start, int mid, int end) {
	int s = start;
	int e = mid + 1;
	int temIdx = 0;
	while (s <= mid && e <= end) {
		if (arr[s] < arr[e])
			temp[temIdx++] = arr[s++];
		else
			temp[temIdx++] = arr[e++];
	}
	if (s > mid)
		for (int i = e; i <= end; i++)
			temp[temIdx++] = arr[i];
	else
		for (int i = s; i <= mid; i++)
			temp[temIdx++] = arr[i];
	for (int i = start; i <=end; i++)arr[i] = temp[i-start];
}
void mergeSort(int arr[], int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}
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
int main(void){
	int n,m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", arr + i);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)scanf("%d", ques + i);
	mergeSort(arr, 0, n - 1);
	for(int i=0;i<n;i++)
		printf("%d ", arr[i]);
	printf("\n");
	for (int i = 0; i < m; i++)
	{
		/*if (binarySearch(arr , 0, n-1, ques[m]))printf("1\n");
		else printf("0\n");*/
		printf("%d\n", binarySearch2(arr, n, ques[m]));
	}

	return 0;
}
