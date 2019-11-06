#include<cstdio>
#include<cstring>
const int MAX_LEN = 10005;
bool HashTable[128];		
int main()
{	char a[MAX_LEN], b[MAX_LEN];
	gets(a);
	gets(b);
	int lenA = strlen(a);	
	int lenB = strlen(b);
	for (int i = 0; i < lenB; i++)
	{
		HashTable[b[i]] = true;
	}
	for (int i = 0; i < lenA; i++)
	{
		if (HashTable[a[i]] == false) {
			printf("%c", a[i]);
		}
	}
}
