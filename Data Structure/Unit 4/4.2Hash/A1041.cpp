#include<cstdio>
#include<cstring>
const int maxn = 10001;
int hashtable[maxn] = { 0 };
int main()
{
	int n = 0, a[100001] = { 0 }, ans = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		hashtable[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (hashtable[a[i]] == 1) {
			ans = a[i];
			break;
		}
	}
	if (ans == -1)printf("None");
	else printf("%d\n", ans);
	return 0;
}