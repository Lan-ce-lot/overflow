#include<bits/stdc++.h>
using namespace std;

const int P=0;
const int S=1;
const int M=2;
const int I=3;
const int F=4;

const int MOST=10;
const int LEAST=11;
int _,__;
struct pai {
	int cnt[5];
	int &operator [](int x) {
		return cnt[x];
	}
	void init() {
		for (int i=0;i<5;i++) cnt[i]=0;
	}
	int chu(int ty,int r1,int r2,int r3,int r4,int r5) {
		int cc=0;
		int s=0;
		for (int i=0;i<5;i++) s+=cnt[i];
		if (s==0) return -1;
		if (ty==LEAST) {
			cc=10;
			for (int i=0;i<5;i++) if (cnt[i]>0) cc=min(cc,cnt[i]);
		} else {
			for (int i=0;i<5;i++) cc=max(cc,cnt[i]);
		}
		if (cnt[r1]==cc) return r1;
		if (cnt[r2]==cc) return r2;
		if (cnt[r3]==cc) return r3;
		if (cnt[r4]==cc) return r4;
		if (cnt[r5]==cc) return r5;
	}
};

struct player {
	queue<int> deck;
	pai hand,field,grave;

	bool win() {
		for (int i=0;i<5;i++) if (field[i]==0) return 0;
		return 1;
	}
	bool empty() {
		if (!deck.empty()) return 0;
		for (int i=0;i<5;i++) if (hand[i]!=0) return 0;
		return 1;
	}

	void read() {
		deck=queue<int>();
		hand.init(); field.init(); grave.init();
		for (int i=0;i<25;i++) {
			int x;
			scanf("%d",&x);
			deck.push(x);
		}
	}
	void choupai() {
		if (!deck.empty()) {
			int x=deck.front(); deck.pop();
			hand[x]++;
		}
	}
	int dapai() {
		if (field[S]==0&&hand[S]>0) return S;
		if (field[P]==0&&hand[P]>0) return P;
		if (field[M]==0&&hand[M]>0) return M;
		if (field[F]==0&&hand[F]>0) return F;
		if (field[I]==0&&hand[I]>0) return I;
		return -1;
	}
	void discard() {
		int x=hand.chu(MOST,I,M,P,S,F);
		if (x==-1) return;
		assert(hand[x]>0);
		hand[x]--; grave[x]++;
	}
	void distroy() {
		int x=field.chu(LEAST,F,I,M,P,S);
		if (x==-1) return;
		field[x]--; grave[x]++;
	}
	int recycle() {
		int cc=10;
		for (int i=0;i<5;i++) {
			if (grave[i]>0) cc=min(cc,field[i]+hand[i]);
		}
		if (cc==10) return -1;
		if (grave[F]>0&&field[F]+hand[F]==cc) return F;
		if (grave[S]>0&&field[S]+hand[S]==cc) return S;
		if (grave[M]>0&&field[M]+hand[M]==cc) return M;
		if (grave[I]>0&&field[I]+hand[I]==cc) return I;
		if (grave[P]>0&&field[P]+hand[P]==cc) return P;
	}
}p[10];

bool countera(player &you,player &enemy,int k) {
	int sw=0,sp=10;
	for (int i=0;i<5;i++) if (you.field[i]>0) sw++,sp-=i;
	if (sw<4) return 0;
	assert(sw==4);
	if (you.grave[sp]==5) return 0;
	if (enemy.hand[I]==0) return 0;
//	if (enemy.field[I]==0) return 0;
	int ss=0;
	for (int i=0;i<5;i++) {
		ss+=enemy.hand[i];
	}
	if (ss<2) return 0;
	enemy.hand[I]--; enemy.grave[I]++;
	enemy.discard();
	assert(you.hand[k]>0);
	you.hand[k]--; you.grave[k]++;
	return 1;
}
void printwin(int op,int rd) {
	if (op==0) {
		printf("Alice %d\n",rd);
	} else {
		printf("Bob %d\n",rd);
	}
}
void gao() {
	for (int i=0;i<5;i++) p[0].choupai();
	for (int i=0;i<5;i++) p[1].choupai();
	for (int i=0;i<100;i++) {
		int op=i&1;
		p[op].choupai();
		int x=p[op].dapai();
//		printf("dapai %d %d\n",op,x);
		if (x==-1) goto end;
		if (countera(p[op],p[op^1],x)) goto end;
		assert(p[op].hand[x]);
		p[op].hand[x]--;
		p[op].field[x]++;

		if (p[op].win()) {
			printwin(op,i+1);
			return;
		}

		if (x==P) {
			p[op].choupai();
		} else if (x==S) {
			p[op^1].discard();
		} else if(x==M) {
			p[op^1].distroy();
		} else if (x==F) {
			int x=p[op].recycle();
			if (x==-1) goto end;
			p[op].grave[x]--;
			p[op].hand[x]++;
		}
		end:
		if (p[op].empty()&&p[op^1].empty()) {
			printf("Draw %d\n",i+1);
		}
	}
	printf("Draw %d\n",100);
}


int main() {
	for (scanf("%d",&_);_;_--) {
		p[0].read();
		p[1].read();
		printf("Case %d: ",++__);
		gao();
	}
}
