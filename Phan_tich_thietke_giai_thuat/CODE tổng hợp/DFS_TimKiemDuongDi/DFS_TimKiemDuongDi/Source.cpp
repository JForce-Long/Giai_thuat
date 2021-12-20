#include<iostream>

using namespace std;

const int sodinh = 7;
int value[sodinh][sodinh] = { {0,0,0,1,0,1,1},
							  {0,0,1,1,0,0,0},
							  {0,1,0,1,0,1,0},
							  {1,0,1,0,0,0,0},
							  {0,0,0,0,1,1,0},
							  {1,0,0,0,1,0,0},
							  {1,0,0,1,0,0,0}
};
bool daxet[sodinh];
int dinhketthuc = 4;
int back[sodinh];

void DFS(int dinh) {
	if (dinhketthuc == dinh) {
		return;
	}
	for (int i = 0; i < sodinh; i++) {
		if (!daxet[i] && value[dinh][i] == 1) {
			back[i] = dinh;
			daxet[i] = true;
			DFS(i);
		}
	}
}

void main() {

	for (int i = 0; i < sodinh; i++)
	{
		daxet[i] = false;
	}

	DFS(0);

	back[0] = -1;
	
	int t = dinhketthuc;
	printf("%d", dinhketthuc);
	while (back[t] != -1) {
		printf(" <- %d", back[t]);
		t = back[t];
	}
	printf("\n\n");

	system("pause");
}