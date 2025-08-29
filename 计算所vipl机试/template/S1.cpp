#include <iostream>

int  min_positive_integer(int *input, int n)//input代表输入的数组，n代表输入的个数
{
	bool *temp=new bool [1000];//保存有哪些正整数出现过，出现了的为true
	for (int i = 0; i < 1000; i++)
	{
		temp[i] = false;
	}
	int result = 0;
	/*Your code start from here! */
	for (int i = 0; i < n+1; i++)
	{
		if (input[i]>0)
		{
			temp[input[i]] = true;
		}
	}
	for (int i = 1; i < 1000; i++)
	{
		if (temp[i] == false)
		{
			result = i;
			break;
		}
	}

	return result;

}

/* input and output have been done by the author, and you needn't concern about following*/
int main() {
#ifdef Judge
	freopen("s1.in", "r", stdin);
	freopen("s1.out", "w", stdout);
#endif

	int * input = new int[10000]();
	int result = 0;
	
	int i = 0;
	int n = 0;
	int index = 0;
	i = scanf("%d", &input[index]);
	index++;
	while (i != EOF){
		i = scanf("%d", &input[index]);
		index++;
	}
	n = index - 1;

	result = min_positive_integer(input, n);
	printf("%d\n", result);

	delete[] input;

	return 0;
}