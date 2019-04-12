#include <stdio.h>
#include <string.h>
void insertstr(char *s, char *t, int x) {
	if (x < 1 || x > strlen(s) + 1)
		printf("位置不合法\n");
	else {
		while (*t) {
			if (*t >= '0' && *t <= '9') {
				for (int i = strlen(s); i >= x - 1; i--)
					s[i + 1] = s[i];
				s[x - 1] = *t;
				x++;
			}
			t++;
		}
	}
}
int main() {
	char s[100] = "aaaabbbbcc";
	char t[20] = "%^99B2N0c2";
	insertstr(s, t, 5);
	printf("%s\n", s);
	return 0;
}
