#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
	p = new int*[n];
	for(int i = 0; i < n; i++){
		p[i] = new int[3];
		p[i][0] = 0;
		p[i][1] = 1;
	}
}
void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
	int *q = p[x-1];
	if(q[0] >= q[1]){
		int oldCap = q[1];
		int newCap = oldCap * 2;
		int *newArr = new int[newCap + 2];
		newArr[0] = q[0];
		newArr[1] = newCap;
		for(int i = 0; i < q[0]; i++){
			newArr[i+2] = q[i+2];
		}
		delete[] q;
		p[x-1] = newArr;
		q = newArr;
	}
	q[0]++;
	q[q[0]+1] = y;
}
int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
	return p[x-1][k+1];
}
void Clear(int **&p,int n){//回收空间
	for(int i = 0; i < n; i++){
		delete[] p[i];
	}
	delete[] p;
	p = nullptr;
}
