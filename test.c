#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>



//struct
//{
//	int a;
//	char c;
//}sa;
//
//struct
//{
//	int a;
//	char c;
//}*psa;
//
//int main()
//{
//	*psa = &sa;//error  上面两个结构体并不是同一个类型
//	return 0;
//}











//结构体的自引用
//struct Node
//{
//	int data;
//	//struct Node n;//error
//	struct Node* next;
//};
//int main()
//{
//
//	return 0;
//}




//结构体重定义

//typedef struct
//{
//	int data;
//	Node* next;
//}Node; // error

//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;
//
//int main()
//{
//	struct Node n1;
//	Node n2;
//	return 0;
//}







//结构体初始化

//struct T
//{
//	double weight;
//	short age;
//};
//
//struct S
//{
//	char c;
//	struct T st;
//	int a;
//	double d;
//	char arr[20];
//};
//
//int main()
//{
//	//struct S s = { 'c',100,3.14,"hello bit" };
//	struct S s = { 'c',{55.6,30}, 100,3.14,"hello bit" };
//	//printf("%c %d %lf %s\n",s.c,s.a,s.d,s.arr);
//	printf("%lf\n",s.st.weight);
//	return 0;
//}










//结构体内存对齐


//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{	
//	char c;
//	struct S3 s3;
//	double d;
//};
//
//int main()
//{
//	struct S1 s1 = { 0 };
//	printf("%d\n",sizeof(s1));//12
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));//8
//	struct S3 s3;
//	printf("%d\n",sizeof(s3));
//	struct S4 s4;
//	printf("%d\n", sizeof(s4));
//	return 0;
//}


// #pragma预处理指令 可以改变我们的默认对齐数
//#pragma pack(4)//设置默认对齐数为4
//struct S
//{
//	char c1;
//	double d;
//};
//#pragma pack()//取消设置的默认对齐数
//
//int main()
//{
//	struct S s;
//	printf("%d\n",sizeof(s));
//	return 0;
//}







//#include <stddef.h>
//struct S
//{
//	char c;
//	int i;
//	double d;
//};
//
//int main()
//{
//	//offsetof();//计算结构体成员相对与结构体起始位置的偏移量
//	printf("%d\n",offsetof(struct S,c));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, d));
//	return 0;
//}






//结构体传参

struct S
{
	int a;
	char c;
	double d;
};

//void Init(struct S tmp) //error
//{
//	tmp.a = 100;
//	tmp.c = 'w';
//	tmp.d = 3.14;
//}

void Init(struct S* ps)
{
	ps->a = 100;
	ps->c = 'w';
	ps->d = 3.14;
}

//传值
void Print1(struct S tmp)
{
	printf("%d %c %lf\n",tmp.a,tmp.c,tmp.d);
}
//传址更好
void Print2(const struct S* ps)
{
	printf("%d %c %lf\n", ps->a, ps->c, ps->d);
}

int main()
{
	struct S s = { 0 };
	//Init(s);
	Init(&s);
	Print1(s);
	Print2(&s);
	/*s.a = 100;
	s.c = 'w';
	s.d = 3.14;*/
	return 0;
}



