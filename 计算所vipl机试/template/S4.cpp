#include <iostream>

void smooth(int n, int** image, int** res)
{		
	/*Your code start from here! */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int sum = 0;
		//边缘相关的情况：上边缘
			if (i == 0)
			{
				//左边缘
				if (j - 1 < 0)
				{
					sum = image[i][j] + image[i + 1][j] + image[i][j + 1] + image[i + 1][j + 1];
					res[i][j] = (int)sum / 4;
				}
				//右边缘
				if (j + 1 >= n)
				{
					sum = image[i][j] + image[i + 1][j] + image[i][j - 1] + image[i + 1][j - 1];
					res[i][j] = (int)sum / 4;
				}
				//在最上面一层边缘上，中间的区域
				else
				{
					sum = image[i][j] + image[i][j - 1] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j - 1] + image[i + 1][j + 1];
					res[i][j] = sum / 6;
				}

			}
		
			//边缘的情况：下边缘
			if (i == n-1)
			{
				//左边缘
				if (j - 1 < 0)
				{
					sum = image[i][j] + image[i - 1][j] + image[i][j + 1] + image[i - 1][j + 1];
					res[i][j] = (int)sum / 4;
				}
				//右边缘
				if (j + 1 >= n)
				{
					sum = image[i][j] + image[i - 1][j] + image[i][j - 1] + image[i - 1][j - 1];
					res[i][j] = (int)sum / 4;
				}
				//在最下面一层边缘上，中间的区域
				else
				{
					sum = image[i][j] + image[i][j - 1] + image[i][j + 1] + image[i - 1][j] + image[i - 1][j - 1] + image[i - 1][j + 1];
					res[i][j] = sum / 6;
				}
			}
			
			//中间的情况：可以访问到9个位置！
			else
			{
				//左边缘
				if (j ==0)
				{
					sum = image[i-1][j] + image[i - 1][j+1] + image[i][j + 1]+ image[i][j] + image[i + 1][j] + image[i + 1][j + 1];
					res[i][j] = (int)sum / 6;
				}
				//右边缘
				if (j + 1 >= n)
				{
					sum = image[i-1][j-1] + image[i - 1][j-1]+ image[i + 1][j-1]+ image[i -1][j ] + image[i ][j ] + image[i+1 ][j ];
					res[i][j] = (int)sum / 6;
				}
				//最中间的区域：
				else {
					sum = image[i - 1][j - 1] + image[i - 1][j] + image[i - 1][j + 1] + image[i][j - 1] + image[i][j] + image[i][j + 1] + image[i + 1][j - 1] + image[i + 1][j] + image[i + 1][j + 1];
					res[i][j] = (int)sum / 9;
					}
				}
				
		}

		



	}
}

/* input and output have been done by the author, and you needn't concern about following*/
int main() {
#ifdef Judge
	freopen("s4.in", "r", stdin);
	freopen("s4.out", "w", stdout);
#endif

	int n;
	int h, w;

	scanf("%d", &n);
	h = n;
	w = n;
	int** image = new int*[h]();
	for (int i = 0; i < h; ++i) {
		image[i] = new int[w]();
		for (int j = 0; j < w; ++j)
			scanf("%d", &image[i][j]);
	}

	int** result = new int*[h]();
	for (int i = 0; i < h; ++i) {
		result[i] = new int[w]();
	}

	smooth(n, image, result);

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			printf("%d", result[i][j]);
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

	for (int i = 0; i < h; ++i){
		if (result[i]){
			delete[] result[i];
		}
	}
	delete[] result;

	return 0;
}