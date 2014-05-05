#include <stdio.h>
#include <string.h>
#define  ms0(s) memset(s,0,sizeof s)

#define SZ 1030

int bit[SZ][SZ];
int data[SZ][SZ];
int R, C;

void update(int r, int c, int val)
{
    int i,j;
	for (i = r; i <= R; i += i & -i)
		for (j = c; j <= C; j += j & -j)
			bit[i][j] += val;
}

int sum(int r, int c)
{
	int i,j,s = 0;
	for (i = r; i > 0; i &= i - 1)
		for (j = c; j > 0; j &= j - 1)
			s += bit[i][j];
	return s;
}

int main()
{

	int t,cs=1;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		R = C = n;

		ms0(bit); ms0(data);

		char s[30];

		while(scanf("%s",&s))
		{
			if(!strcmp(s,"SET"))
            {
				int r,c,val;

				scanf("%d %d %d",&r,&c,&val);
				r++,c++;
				update(r, c, -data[r][c] + val);
				data[r][c] = val;
			}
			else if(!strcmp(s,"SUM"))
			{
                int r1,c1,r2,c2;

				scanf("%d %d %d %d",&r1,&c1,&r2,&c2);

				r1++,c1++,r2++,c2++;

                int res =0;

                res+=sum(r2, c2) ;
                res-=sum(r1 - 1, c2);
                res-=sum(r2, c1 - 1);
                res+=sum(r1 - 1, c1 - 1);

				printf("%d\n",res);
			}
			else  break;
		}
		printf("\n");
	}
	return 0;
}

