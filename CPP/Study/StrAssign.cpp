//实验6提示及部分源程序：
#include "stdio.h"
#define MAX 20
typedef int Status;
typedef unsigned char SString[MAX+1];/*顺序串的定义，其中0号单元存放串的长度*/
void StrAssign(SString s,char p[])
{
	char *q;
	int i=1;
	q=p;
	while(*q)
	{
		s[i++]=*q++;
	}
	s[0]=i-1;
}
void StrCopy(SString s,SString t)
{
	/*请完成函数*/
	s[0] = t[0];
	for(int i = 1; i <= t[0]; i++) {
		s[i] = t[i];
	}
}
void StrPrint(SString s)
{
	int i;
	for(i=1;i<=s[0];i++)
	{
		printf("%c",s[i]) ;
	}
	printf("\n");
}
int StrLength(SString s)
{
	return s[0];
}
int StrEmpty(SString s)
{
	return s[0]==0;
}
void SubString(SString sub,SString s,int pos,int len)
{/*求串s中从第pos位开始长度为len的子串，结果在sub中返回*/
	int i,j=0;
	for(i=pos;i<=s[0]&&i<=pos+len-1;i++)
		sub[++j]=s[i];
	sub[0]=j;
}
int StrCompare(SString s,SString t)
{/*比较两串的大小，若s>t返回1，若s=t返回0，若s<t返回-1*/
/*请完成函数*/
	int i, flag = 0;
	int min_len = s[0] > t[0] ? t[0] : s[0];
	for(i = 1; i <= min_len; i++) {
		if(s[i] > t[i]) {
			flag = 1;
			break;
		} else if (s[i] < t[i]) {
			flag = -1;
			break;
		}
	}
	return flag;
}
int StrIndex1(SString s,SString t,int pos)
{/*用回溯法来实现模式匹配算法，寻找模式串t在主串s中从第pos位开始是否出现，若出现则返回第一次出现的位置，否则返回0*/
	/*请完成函数*/
	int i = pos - 1;
	int j;
	for(; i <= s[0] - t[0] + 1; i++) {
		int flag = 0;
		for(j = 1; j <= t[0]; j++) {
			if(s[i+j] != t[j]) {
				break;
			}
		}
		if (j > t[0]) return i;
		i++;
	}
	return 0;
}
int StrIndex2(SString s,SString t,int pos)
{/*利用其他函数来实现模式匹配算法*/
	int m,n,i;
	SString sub;
	n=StrLength(s);
	m=StrLength(t);
	i=pos;
	while(i<=n-m+1)
	{
		SubString(sub,s,i,m);
		if(StrCompare(sub,t)!=0) ++i;
		else return i;
	}
	return 0;
}
int StrIndex_KMP(SString s,SString t,int pos)
{/*用KMP算法来实现模式匹配算法，效率较高*/
	int i,j;
	int next[MAX+1];
	i=1;
	next[i]=0;
	j=0;
	while(i<t[0])
	{
		if(j==0||t[i]==t[j])
		{
			i++;
			j++;
			if(t[i]!=t[j]) next[i]=j;
			else next[i]=next[j];
		}
		else j=next[j];
	}


	i=pos;
	j=1;
	while(i<=s[0]&&j<=t[0])
	{
		if(j==0 || s[i]==t[j])
		{
			i++;
			j++;
		}
		else
			j=next[j];
	}
	if(j>t[0])return i-t[0];
	else return 0;
}

void ClearString(SString s)
{
	s[0]=0;
}

Status StrConcat(SString t,SString s1,SString s2)
{/*串连接，若有截尾返回0，无截尾返回1*/
	int i,j,uncut;
	if(s1[0]+s2[0]<=MAX)
	{
		t[0]=s1[0]+s2[0];
		j=1;
		for(i=1;i<=s1[0];i++) t[j++]=s1[i];
		for(i=1;i<=s2[0];i++) t[j++]=s2[i];
		uncut=1;
	}
	else
	{
		j=1;
		t[0]=MAX;
		for(i=1;i<=s1[0];i++) t[j++]=s1[i];
		while(j<=MAX) t[j++]=s2[j-s1[0]];
		uncut=0;
	}
	return uncut;

}

void StrInsert(SString s,int pos,SString t)
{ /*在串s的pos位置处插入子串t*/
/*请完成函数*/
	int i;
	for(i = s[0]; i >= pos; i--) {
		s[i+t[0]] = s[i];
	}
	for(i = pos; i <= pos + t[0] - 1; i++) {
		s[i] = t[i - pos + 1];
	}
	s[0] += t[0];
}
void StrDelete(SString s,int pos,int len)
{/*在串s的pos位置开始删除长度为len的子串*/
/*请完成函数*/
	int i;
	for(i = pos; i < pos + len; i++) {
		s[i] = s[i + len];
	}
	s[0] -= len;
}
void Replace(SString s,SString t,SString v)
{/*将串s中所有出现的子串t全替换成子串v*/
	int pos,loc;
	pos=1;
	loc=StrIndex_KMP(s,t,pos);
	while(loc)
	{
		StrDelete(s,loc,t[0]);
		StrInsert(s,loc,v);
		pos=loc+v[0];
		loc=StrIndex_KMP(s,t,pos);
	}

}
main()
{/*此处编写主函数，调用前面的函数，自己设计测试数据来验证*/
	char p[] = {'z', 'a', 'b', 'c', 'd', '\0'};
	SString s;
	SString sub;
	StrAssign(s, p);
	printf("%d\n", StrLength(s));
	printf("s = ");
	StrPrint(s);
	SubString(sub, s, 1, 2);
	printf("sub = ");
	StrPrint(sub);
	printf("Is compare: %d\n", StrCompare(s, sub));
	printf("start simple: %d\n", StrIndex1(s, sub, 1));
	StrInsert(s, 3, sub);
	printf("after insert = ");
	StrPrint(s);
	StrDelete(s, 1, 3);
	printf("after delete = ");
	StrPrint(s);
}

