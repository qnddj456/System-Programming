﻿#include <stdio.h>
#define MAXLINE 100

void copy(char from[], char to[]);




	int len;
	int max;
	max = 0;
	while (gets(line) != NULL) {
		len = strlen(line);
		if (len > max) {
			max = len;
			copy(line, longest);
 		}
	}
	 if (max > 0) // 입력 줄이 있었다면
		 printf("%s", longest);
	 return 0;
}
/* copy: from을 to에 복사; to가 충분히 크다고 가정*/

	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}