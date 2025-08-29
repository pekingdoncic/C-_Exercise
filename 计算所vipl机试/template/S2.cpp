#include<iostream>

void remove_vowels(char *input_str, char *out_str)
{	
	/*Your code start from here! */
	int j = 0;
	for (int i = 0; i < 100010; i++)
	{
		if (input_str[i] == ' ')
			return;
		if ((input_str[i] != 'a') &&( input_str[i] != 'e') && (input_str[i] != 'i') && (input_str[i] != 'o') && (input_str[i] != 'u'))

		{
			out_str[j] = input_str[i];
			j++;
		}
	}

	
}

/* input and output have been done by the author, and you needn't concern about following*/
int main() {
#ifdef Judge
	freopen("s2.in", "r", stdin);
	freopen("s2.out", "w", stdout);
#endif

	char *input_str = new char[100010]();
	char *out_str = new char[100010]();

	scanf("%s", input_str);
	remove_vowels(input_str, out_str);
	printf("%s\n", out_str);
	delete[] input_str;
	delete[] out_str;
	return 0;
}