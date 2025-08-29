#include <iostream>

void Convert(char *input, char  *output, int n_row)
{
	/*Your code start from here! */

	
}



/* input and output have been done by the author, and you needn't concern about following*/
int main() {
#ifdef Judge
	freopen("s5.in", "r", stdin);
	freopen("s5.out", "w", stdout);
#endif

	char * input = new char[10010]();
	char * output = new char[10010]();

	int n_row;
	
	scanf("%d", &n_row);
	scanf("%s", input);

	Convert(input, output, n_row);

	printf("%s\n", output);

	delete[] input;
	delete[] output;

	return 0;
}