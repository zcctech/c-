#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DATATYPE char
struct string {
	DATATYPE* arr;
	int size;
	int capacity;
};
void Init_string(struct string* s)
{
	s->arr = (DATATYPE*)malloc(10*sizeof(DATATYPE));
	s->capacity = s->size = 0;
}
void Destroy_string(struct string* s)
{
	s->arr = NULL;
	s->capacity = s->size = 0;
}
void text1()
{
	struct string s;
	Init_string(&s);
	Destroy_string(&s);
}
void text2()
{
	struct string s;
	Init_string(&s);
	char* tep = "hello world";
	int length = strlen(tep);
	for (int i = 0; i < length; i++)
	{
		s.arr[i] = tep[i];
	}
	printf("%s",s.arr);
}
int main()
{
	/*text1();*/
	text2();
	return 0;
}

