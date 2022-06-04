#include "stdio.h"
#include "string.h"
#include "malloc.h"

char * my_strcpy(char *restrict dst, const char *restrict src) {
	int idx = 0;
	while (src[idx] != 0) {
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;

	return dst;
}

char* my_strcpy1(char* restrict dst, const char* restrict src) {
	char* p = dst;
	while (*dst++ = *src++) {
		;
	}
	*dst = 0;
	return p;
}

#ifndef __UNIX
#pragma warning(disable : 4996).
#endif // !__UNIX


int test_strcpy() {
	char a[] = "abc";

	//char *a = (char *) malloc(20);
	//*a = "abc";

	// ֻҪʹ��malloc ����Ŀռ���Ϊdst���ͻ�Ƿ����ʵ�ַ�Ĵ���
	// ��֪��Ϊʲô��
	// �ҵ�ԭ����һ��Ҫ include "malloc.h"
	// ��֪������include ��ʱ���õ����ĸ�������

	char *b = (char *) malloc(strlen(a) + 1);
	//char *b = (char *) malloc(20);
	//char b[20];

	//my_strcopy(b, a);
	my_strcpy1(b, a);
	//strcpy(b, a);

	printf("%s", b);

}

