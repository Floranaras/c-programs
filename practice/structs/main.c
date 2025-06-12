#include "functions.c"  // directly include your functions

#define GREEN   "\x1b[32m"
#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

void test_pass_fail(int condition, const char *desc) {
	if (condition)
		printf("%s[PASS]%s %s\n", GREEN, RESET, desc);
	else
		printf("%s[FAIL]%s %s\n", RED, RESET, desc);
}

int main() {
	cType c1 = {{'A', 10}, {1.5f, 2.5}, {1, 2, 3, 4, 5}};
	cType c2 = {{'B', 20}, {2.5f, 3.5}, {6, 7, 8, 9, 10}};
	cType cArr[2] = {c1, c2};
	cType cCopy[2];

	aType aArr[3] = {{'X', 5}, {'Y', 3}, {'Z', 7}};
	bType bArr[3] = {{3.0f, 1.1}, {1.5f, 2.2}, {2.5f, 3.3}};

	// --- OutputFunc1 and OutputFunc2 ---
	printf("Testing OutputFunc1 and OutputFunc2 visually:\n");
	OutputFunc1(&c1);
	OutputFunc2(&c2);

	// --- Total1 ---
	test_pass_fail(Total1(aArr, 3) == 15, "Total1: Sum of aArr.i == 15");

	// --- Total2 ---
	test_pass_fail(Total2(c1) == 15, "Total2: Sum of c1.A[] == 15");

	// --- Total3 ---
	test_pass_fail(Total3(cArr, 2) == 55, "Total3: Total of all C.A[] == 55");

	// --- Minimum ---
	test_pass_fail(Minimum(c1) == 0, "Minimum: Index of min in c1.A[] == 0");

	// --- fMinimum ---
	test_pass_fail((int)fMinimum(bArr, 3) == 1, "fMinimum: Index of min .f in bArr == 1");

	// --- SortFunc1 ---
	SortFunc1(aArr, 3);
	test_pass_fail(aArr[0].i == 3 && aArr[1].i == 5 && aArr[2].i == 7, "SortFunc1: aArr sorted ascending by i");

	// --- SortFunc2 ---
	SortFunc2(bArr, 3);
	test_pass_fail(
				   bArr[0].f == 3.0f && bArr[1].f == 2.5f && bArr[2].f == 1.5f,
				   "SortFunc2: bArr sorted descending by f"
				  );

	// --- CopyFunc ---
	CopyFunc(cArr, cCopy, 2);
	int copied = 1;
	for (int i = 0; i < 2 && copied; ++i) {
		if (
			cArr[i].a.ch != cCopy[i].a.ch ||
			cArr[i].a.i  != cCopy[i].a.i  ||
			cArr[i].b.f  != cCopy[i].b.f  ||
			cArr[i].b.d  != cCopy[i].b.d
		   ) {
			copied = 0;
		}

		for (int j = 0; j < 5 && copied; ++j) {
			if (cArr[i].A[j] != cCopy[i].A[j]) {
				copied = 0;
			}
		}
	}
	test_pass_fail(copied, "CopyFunc: cArr successfully copied to cCopy");

	return 0;
}
