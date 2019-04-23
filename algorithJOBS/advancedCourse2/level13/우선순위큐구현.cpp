#include<stdio.h>
const int MAX = 100;

struct PriorityQueue {
	//트리에서 0번은 안쓰고 1번부터 ~n번까지 쓰임
	/*
		1
	  2	      3
      4       5   6       7
   8     9

*/
	int data[MAX];
	int len = 1;
	void push(int x) {
		data[len++] = x;
		int inx = len - 1;
		while (inx > 1) {// 루트가 아니고
			if (data[inx] < data[inx / 2]) {//부모 나 사이가 이상하면 자리이동
				int temp = data[inx];
				data[inx] = data[inx / 2];
				data[inx / 2] = temp;
			}
			else break;

			//나의 부모가 될 노드의 인덱스를 새로 업뎃
			inx = inx / 2;
		}
	}
	void pop() {
		data[1] = data[len - 1]; 
		data[len - 1] = 0;
		len--;
		int inx = 1;
		while (1) {
			/*
			1.자식들 중에서 우선순위가 높은 친구를 알아내야함.
			2. 나와 그 우선순위가 높은 친구를 비교해서 자리를 바꾸어야함.
			*/
			int pInx = -1;//우선순위가 높은 노드번호
			
			//경우를 분리
			//A. 자식이 모두 없는 경우
			//B. 자식이 모두 있는 경우
			//C. 왼쪽 자식만 존재하는 경우
			//오른쪽만 존재하는 경우(불가능한 케이스)
			
			if (len <= inx * 2)break;//A.
			else if ((1 <= inx * 2 && inx * 2 < len)
				&& len <= inx * 2 + 1)//C.
			{
				pInx = inx * 2;
			}
			else//B.
			{
				if (data[inx * 2] < data[inx * 2 + 1])//값이 작을수록 우선순위가 높음
					pInx = inx * 2;
				else
					pInx = inx * 2 + 1;
			}//pInx 구하기 완료함
			if (data[inx] > data[pInx]) { // 부모자식관계가 맞지않을 경우
				int temp = data[inx];
				data[inx] = data[pInx];
				data[pInx] = temp;
				inx = pInx;
			}
			else break;
		}
	}
	int top() {
		return data[1];
	}
};


int main() {
	PriorityQueue myPQ;
	myPQ.push(3);
	myPQ.push(1);
	myPQ.push(88);
	myPQ.push(2);
	
	printf("%d\n", myPQ.top());
	myPQ.pop();
	printf("%d\n", myPQ.top());
	myPQ.pop();
	printf("%d\n", myPQ.top());
	myPQ.pop();






	return 0;
}
