﻿#include <stdio.h>

/* copy: from을 to에 복사; to가 충분히 크다고 가정*/

	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
