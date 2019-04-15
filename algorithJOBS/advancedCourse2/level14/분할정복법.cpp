#include<stdio.h>

using namespace std;

const int MAX = 100;

int n;
int data[MAX];

int getSubMax(int start,int end) {
	//data의 연속부분 최대합을 구해주는 함수.
	if (start == end) return data[start];
	int mid = (start+end) / 2;

	//중간부분을 포함하는 연속부분합
	int leftSum = 0, leftMax = -987987987;
	int rightSum = 0, rightMax = -987987987;

	for (int i = mid; i >= start; i--) {
		leftSum = leftSum + data[i];
		if (leftMax < leftSum)
			leftMax = leftSum;
	}
	
	for (int i = mid + 1; i <= end; i++) {
		rightSum = rightSum + data[i];
		if (rightMax < rightSum)
			rightMax = rightSum;
	}
	
	int left = getSubMax(start, mid);
	int right = getSubMax(mid + 1, end);
	int myMax = leftMax + rightMax;

	if (left >= right && left >= myMax)return left;
	else if (right >= left && right >= myMax) return right;
	else return myMax;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	printf("%d\n", getSubMax(0, n - 1));
	return 0;
}
