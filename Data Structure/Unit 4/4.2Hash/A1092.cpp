#include<cstdio>
#include<cstring>
const int MAXN = 1010;
//hashTable ��¼��һ���е�ÿ����ɫ�ĸ�������miss��¼ȱ�ٵ����Ӹ���
int hashTable[80] = { 0 }, miss = 0;
//�����ֺ���ĸת��ΪhashTable���±�
int change(char c)
{
	if (c >= '0' && c <= '9')return c - '0';	//����
	if (c >= 'a' && c <= 'z')return c - 'a'+10;		//Сд��ĸ
	if (c >= 'A' && c <= 'Z')return c - 'A'+36;		//��д��ĸ
}
int main()
{
	char whole[MAXN], target[MAXN];
	gets(whole);		//��һ��
	gets(target);		//�ڶ���
	int len1 = strlen(whole);		//��һ���ĳ���
	int len2 = strlen(target);		//�ڶ����ĳ���
	for (int i = 0; i < len1; i++) {		//������һ��
		int id = change(whole[i]);			//�ַ�->hashTable�±�
		hashTable[id]++;			//����ɫ�ĸ�����1
	}
	for (int i = 0; i < len2; i++) {		//�����ڶ���
		int id = change(target[i]);			//�ַ�->hashTable�±�
		hashTable[id]--;					//����ɫ������һ
		if (hashTable[id] < 0) {			//����ɫ����С��0
			miss++;							//ȱ�ٵ����Ӹ�����1
		}
	}
	if (miss > 0)printf("No %d\n", miss);	//��ȱ��
	else printf("Yes %d\n", len1 - len2);	//�ж���
	return 0;
}