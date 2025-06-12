#include <stdio.h>
#include <string.h>

struct aTag {
	char ch;
	int i;
};

struct bTag {
	float f;
	double d;
};

struct cTag {
	struct aTag a;
	struct bTag b;
	int A[5];
};

typedef struct aTag aType;
typedef struct bTag bType;
typedef struct cTag cType;

