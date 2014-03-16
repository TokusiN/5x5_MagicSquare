#include <stdio.h>
#include <time.h>

int g_count = 0;
int g_multiply;

inline void func1();
inline void func2(int a1, int* num, int* line);
inline void func3(int* num, int* line);
inline void func4(int* num, int* line);
inline void func5(int* num, int* line);
inline void func6(int* num, int* line);
inline void func7(int* num, int* line);
inline void func8(int* num, int* line);

int main()
{
	time_t start = time(NULL);
	func1();
	printf("合　計　:%9d解\n", g_count);
	printf("time=%d\n", int(time(NULL) - start));
	return 0;
}

void func1()
{
	int num[25];
	int line[12];
	int i;
	int last = 0;
	int c, a1,a2,a3,a4;
	for(i = 0 ; i < 25 ; i++)
	{
		num[i] = 0;
	}
	g_multiply = 8;
	for(c = 0; c < 13 ; c++)
	{
		if(c == 12)
		{
			g_multiply = 4;
		}
		num[c] = 1;
		line[2]=line[7]=line[10]=line[11]=60-c;
		for(a1 = 0; a1 < 13 ; a1++)
		{

			if(num[a1]) continue;
			num[a1] = 2;
			line[0]=line[5]=60-a1;
			line[10]-=a1;
			for(a2=a1+1;a2<25;a2++)
			{
				if(num[a2]) continue;
				num[a2] = 3;
				line[1]=line[6]=60-a2;
				line[10]-=a2;
				for(a3=a2+1;a3<25&&a3<=line[10];a3++)
				{
					if(num[a3]) continue;
					a4 = line[10]-a3;
					if(a3==a4 || num[a4] || a4 < a1 || a4 >= 25) continue;
					num[a3] = 4;
					num[a4] = 5;
					line[3]=line[8]=60-a3;
					line[4]=line[9]=60-a4;
					func2(a1, num, line);
					num[a4] = 0;
					num[a3] = 0;
				}
				num[a2] = 0;
				line[10]+=a2;
			}
			num[a1] = 0;
			line[10]+=a1;
		}
		num[c] = 0;
		printf("中心数%2d:%9d解\n",c, (g_count - last)/(c==12?1:2));
		last = g_count;
	}
}

inline void func2(int a1, int* num, int* line)
{
	int b1,b2,b3,b4;
	for(b1 = a1+1; b1 < 25 ; b1++)
	{
		if(num[b1]) continue;
		num[b1] = 6;
		line[0]-=b1;
		line[9]-=b1;
		line[11]-=b1;
		for(b2=a1+1;b2<25;b2++)
		{
			if(num[b2]) continue;
			num[b2] = 7;
			line[1]-=b2;
			line[8]-=b2;
			line[11]-=b2;
			for(b3=a1+1;b3<25 && b3 < line[11];b3++)
			{
				if(num[b3]) continue;
				b4 = line[11]-b3;
				if(b3==b4 || num[b4] || b4 < a1 || b4 >= 25) continue;
				if(b1 > b4) continue;
				num[b3] = 8;
				num[b4] = 9;
//				line[3]-=b3;
				line[6]-=b3;
				line[4]-=b4;
				line[5]-=b4;
				func3(num, line);
//				line[3]+=b3;
				line[6]+=b3;
				line[4]+=b4;
				line[5]+=b4;
				num[b3] = 0;
				num[b4] = 0;
			}
			num[b2] = 0;
			line[1]+=b2;
			line[8]+=b2;
			line[11]+=b2;
		}
		num[b1] = 0;
		line[0]+=b1;
		line[9]+=b1;
		line[11]+=b1;
	}
}
inline void func3(int* num, int* line)
{
	int c1, c2, c3;
	for(c1 = 0; c1 < 25 ; c1++)
	{
		if(num[c1]) continue;
		num[c1] = 10;
		line[0]-=c1;
		line[6]-=c1;
		for(c2=line[0]<25?0:line[0]-24;c2<25;c2++)
		{
			if(num[c2]) continue;
			c3 = line[0]-c2;
			if(c3 < 0) break;
			if(num[c3] || c2==c3) continue;
			num[c2] = 11;
			num[c3] = 12;
			line[7]-=c2;
			line[8]-=c3;
			func4(num, line);
			num[c2] = 0;
			num[c3] = 0;
			line[7]+=c2;
			line[8]+=c3;
		}
		num[c1] = 0;
		line[0]+=c1;
		line[6]+=c1;
	}
}

inline void func4(int* num, int* line)
{
	int a, b;
	for(a=line[6]<25?0:line[6]-24;a<25;a++)
	{
		if(num[a]) continue;
		b = line[6]-a;
		if(b < 0) break;
		if(num[b] || a==b) continue;
		num[a] = 13;
		num[b] = 14;
		line[2]-=a;
		line[4]-=b;
		func5(num, line);
		num[a] = 0;
		num[b] = 0;
		line[2]+=a;
		line[4]+=b;
	}
}

inline void func5(int* num, int* line)
{
	int a, b, c;
	if(line[4] == line[8]) return;
	for(a=line[8]<25?0:line[8]-24;a<25;a++)
	{
		if(num[a]) continue;
		b = line[8]-a;
		c = line[4]-b;
		if(b < 0) break;
		if(c > 24)break;
		if(c < 0) continue;
		num[a] = 15;
		if(num[b]) goto errfunc51;
		num[b] = 16;
		if(num[c]) goto errfunc52;
		num[c] = 17;
		line[2]-=a;
		line[7]-=c;
		func6(num, line);
		num[c] = 0;
		line[2]+=a;
		line[7]+=c;
		errfunc52:
		num[b] = 0;
		errfunc51:
		num[a] = 0;
	}
}

inline void func6(int* num, int* line)
{
	int a, b;
	for(a=line[2]<25?0:line[2]-24;a<25;a++)
	{
		if(num[a]) continue;
		b = line[2]-a;
		if(b < 0) break;
		if(num[b] || a==b) continue;
		num[a] = 18;
		num[b] = 19;
		line[5]-=a;
		line[9]-=b;
		func7(num, line);
		num[a] = 0;
		num[b] = 0;
		line[5]+=a;
		line[9]+=b;
	}
}

inline void func7(int* num, int* line)
{
	int a, b;
	for(a=line[5]<25?0:line[5]-24;a<25;a++)
	{
		if(num[a]) continue;
		b = line[5]-a;
		if(b < 0) break;
		if(num[b] || a==b) continue;
		num[a] = 20;
		num[b] = 21;
		line[1]-=a;
//		line[3]-=b;
		func8(num, line);
		num[a] = 0;
		num[b] = 0;
		line[1]+=a;
//		line[3]+=b;
	}
}


inline void func8(int* num, int* line)
{
	int a, b, c;
	if(line[1] == line[7]) return;
	if(line[1] == line[9]) return;
	for(a=line[1]<25?0:line[1]-24;a<25;a++)
	{
		if(num[a]) continue;
		b = line[1]-a;
		c = line[7]-a;
		if(b < 0) break;
		if(c < 0) break;
		if(c > 24)continue;
		if(num[a] || num[b] || num[c]) continue;
		if(a != b && a != c)
		{
			g_count += g_multiply;
			if(0)
			if(!(g_count & (1<<20)-1))
			{
				printf("%d", g_count);
				if(1){
					int i;
					int data[25];
					int t[] = {12,0,6,18,24,4,8,16,20,1,2,3,11,21,13,23,22,10,14,5,15};
					for(i = 0 ; i < 25 ; i++)
					{
						if(num[i])
							data[t[num[i]-1]] = i;
					}
					data[7]=a;
					data[9]=b;
					data[17]=c;
					data[19]=line[9]-b;
					for(i = 0 ; i < 25 ; i++)
					{
						if(i%5 == 0)
						{
							puts("");
						}
						printf("%2d ", data[i]);
					}
					puts("");
				}
			}
		}
	}
}