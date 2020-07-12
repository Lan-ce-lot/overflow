#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool last_ice = 0;
int hand[2][5], grave[2][5], field[2][5];
int p[2];
int deck[2][25];
void draw_card(int b)
{
	if (p[b] < 25)
	{
		//printf("draw card %d : %d\n", b, deck[b][p[b]]);
		hand[b][deck[b][p[b]]]++;
		p[b]++;
	}
}

bool haveEffect(int b,int ty)
{
	if (ty == 0)
		return p[b] < 25;
	if (ty == 1)
	{
		int cnt = 0;
		for (int i=0; i<5; i++)
			cnt += hand[b^1][i];
		return cnt>0;
	}
	if (ty == 2)
	{
		int cnt = 0;
		for (int i=0; i<5; i++)
			cnt += field[b^1][i];
		return cnt>0;
	}
	if (ty == 3)
		return 0;
	if (ty == 4)
	{
		int cnt = 0;
		for (int i=0; i<5; i++)
			cnt += grave[b][i];
		return cnt>0;
	}
		
}

void discard_card(int b)
{
	int ord[5] = {3,2,0,1,4};
	int mx = 0, id = 0;
	for (int i=0; i<5; i++)
		if (hand[b][ord[i]] > mx)
		{
			mx = hand[b][ord[i]];
			id = ord[i];
		}
	if (mx == 0)
		return;
	//printf("discard %d %d\n", b, id);
	hand[b][id]--;
	grave[b][id]++;
}

bool counter_attack(int b)
{
	if (!last_ice)
		return 0;
	int tys = 0, id = 0;
	for (int i=0; i<5; i++)
		if (field[b][i] == 0)
		{
			tys++;
			id = i;
		}
	if (tys != 1)
		return 0;
	if (grave[b][id] == 5)
		return 0;
	if (hand[b^1][3] == 0)
		return 0;
	int cnt = 0;
	for (int i=0; i<5; i++)
		cnt += hand[b^1][i];
	if (cnt < 2)
		return 0;
	hand[b^1][3]--;
	grave[b^1][3]++;
	//printf("do counter\n");
	discard_card(b^1);
	return 1;
}

void destory_card(int b)
{
	int ord[5] = {4,3,2,0,1};
	int mn = 10, id = 0;
	for (int i=0; i<5; i++)
		if (field[b][ord[i]] && field[b][ord[i]] < mn)
		{
			mn = field[b][ord[i]];
			id = ord[i];
		}
	if (mn == 10)
		return;
	//printf("destory %d : %d\n", b, id);
	field[b][id]--;
	grave[b][id]++;
}

void select_card(int b)
{
	int ord[5] = {4,1,2,3,0};
	int mn = 10, id = 0;
	for (int i=0; i<5; i++)
		if (grave[b][ord[i]] && hand[b][ord[i]]+field[b][ord[i]] < mn)
		{
			mn = hand[b][ord[i]] + field[b][ord[i]];
			id = ord[i];
		}
	if (mn == 10)
		return;
	//printf("select %d\n", b);
	grave[b][id]--;
	hand[b][id]++;
}

int main()
{
	int ttt;
	scanf("%d", &ttt);
	for (int tt=1; tt<=ttt; tt++)
	{
		for (int i=0; i<25; i++)
			scanf("%d", &deck[0][i]);
		for (int i=0; i<25; i++)
			scanf("%d", &deck[1][i]);
		p[0] = p[1] = 0;
		memset(hand, 0, sizeof(hand));
		memset(field, 0, sizeof(field));
		memset(grave, 0, sizeof(grave));
		bool finish = 0;
		last_ice = 0;
		for (int i=0; i<100; i++)
		{
			//printf("round %d\n", i);
			int b = i&1;
			//draw phase
			draw_card(b);
			//main phase
			/*printf("have_effect:");
			for (int i=0; i<5; i++) printf("%d ", haveEffect(b,i));
			printf("\n");*/
			int ord[5] = {1, 0, 2, 4, 3};
			int ty = -1, pri = 0;
			for (int i=0; i<5; i++)
				if (hand[b][ord[i]] && !field[b][ord[i]])
				{
					if (haveEffect(b,ord[i]))
					{
						if (pri<2)
						{
							pri = 2;
							ty = ord[i];
							break;
						}
					}
					else
					{
						if (pri<1)
						{
							pri = 1;
							ty = ord[i];
						}
					}
				}
			if (ty != -1)
			{
				if (counter_attack(b))
				{
					//nothing
				}
				else
				{
					//printf("move to field %d\n", ty);
					hand[b][ty]--;
					field[b][ty]++;
					last_ice = 0;
					switch (ty)
					{
						case 0:
							{
								draw_card(b);
								break;
							}
						case 1:
							{
								discard_card(b^1);
								break;
							}
						case 2:
							{
								destory_card(b^1);
								break;
							}
						case 3:
							{
								last_ice = 1;
								break;
							}
						case 4:
							{
								select_card(b);
								break;
							}
					}
				}
			}
			// end phase
			bool win = 1;
			for (int i=0; i<5; i++)
				if (!field[b][i])
				{
					win = 0;
					break;
				}
			if (win)
			{
				finish = 1;
				if (b)
					printf("Case %d: Bob %d\n", tt, i+1);
				else
					printf("Case %d: Alice %d\n", tt, i+1);
				break;
			}
			/*printf("Alice : \n");
			printf("hand: "); for (int i=0; i<5; i++) printf("%d",hand[0][i]); printf("\n");
			printf("field: "); for (int i=0; i<5; i++) printf("%d",field[0][i]); printf("\n");
			printf("grave: "); for (int i=0; i<5; i++) printf("%d",grave[0][i]); printf("\n");
			printf("Bob : \n");
			printf("hand: "); for (int i=0; i<5; i++) printf("%d",hand[1][i]); printf("\n");
			printf("field: "); for (int i=0; i<5; i++) printf("%d",field[1][i]); printf("\n");
			printf("grave: "); for (int i=0; i<5; i++) printf("%d",grave[1][i]); printf("\n");*/
			
		}
		if (!finish)
		{
			printf("Case %d: Draw 100\n", tt);
		}
		
	}
	return 0;
}

