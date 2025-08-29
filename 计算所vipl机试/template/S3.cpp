#include <iostream>

void flip(int h, int w, int** image) {
	
	/*Your code start from here! */
	int temp;//hÎª¸ß£¬¿íÎªw
	for (int  i = 0; i < h; i++)
	{
		for (int j = 0; j < w/2; j++)
		{
			temp=image[i][j];
			image[i][j] = image[i][w-1-j];
			image[i][w - 1 - j] = temp;
		}
	}


}

/* input and output have been done by the author, and you needn't concern about following*/
int main() {
#ifdef Judge
	freopen("s3.in", "r", stdin);
	freopen("s3.out", "w", stdout);
#endif

	int h, w;

	scanf("%d%d", &h, &w);
	int** image = new int*[h]();
	for (int i = 0; i < h; ++i) {
		image[i] = new int[w]();
		for (int j = 0; j < w; ++j)
			scanf("%d", &image[i][j]);
	}
	flip(h, w, image);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			printf("%d", image[i][j]);
			if (j == w - 1) printf("\n");
			else printf(" ");
		}
	}

	for (int i = 0; i < h; ++i){
		if (image[i]){
			delete[] image[i];
		}
	}

	delete[] image;

	return 0;
}