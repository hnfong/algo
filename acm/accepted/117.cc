#include <stdio.h>
#include <string.h>

int w[256][256];
int d[256];

int main() {
	while (!feof(stdin)) {
		char word[1000];
		int z = 0;
		memset(d,0,sizeof(d));

		for (int i = 0 ; i < 256; i++) {
		for (int j = 0 ; j < 256; j++) {
			w[i][j] = 99999;
		}}

		while (scanf("%s\n", (char*) &word), strcmp(word,"deadend"))
		{
			int l = strlen(word);
			int a = word[0];
			int b = word[l-1];

			w[a][b] = l;
			w[b][a] = l;

			d[a]++;
			d[b]++;

			z += l;
		}

		int needfixing = 0;
		char x[2];

		for (int i = (int) 'a'; i <= (int) 'z'; i++) {
			if (d[i] % 2) {
				x[needfixing] = (char) i;
				needfixing++;
			}
		}

		if (needfixing) {
			for (int k = 0+'a'; k <= 0+'z'; k++)
				for (int i = 0+'a'; i <= 0+'z'; i++)
					for (int j = 0+'a'; j <= 0+'z'; j++)
						if (w[i][k] + w[k][j] < w[i][j]) w[i][j] = w[i][k]+w[k][j];

			z += w[(int)x[0]][(int)x[1]];
		}

		printf("%d\n", z);

		
	}
}
