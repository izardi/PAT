#include <cstdio>

struct Money{
	int Galleon, Sickle, Knut;
	Money(int _G, int _S, int _K) : Galleon(_G), Sickle(_S), Knut(_K){}
	Money(const Money& M) : Galleon(M.Galleon), Sickle(M.Sickle), Knut(M.Knut){}
	bool operator<=(const Money& M){
		if(Galleon != M.Galleon)
			return Galleon < M.Galleon; 
		else if(Sickle != M.Sickle)
			return Sickle < M.Sickle;
		else if(Knut != M.Knut)
			return Knut < M.Knut;
		else return true;
	}

	Money operator-(const Money& M){
		int G = Galleon, S = Sickle, K = Knut;
		if(K < M.Knut){
			K = K + 29 - M.Knut;
			if( S == 0){
				S = 16;
				G--;
			}
			else {
				S--;	
			}
		}
		else
			K -= M.Knut;
		if(S < M.Sickle){
			S = S + 17 - M.Sickle;
			G--;
		}
		else S = S - M.Sickle;
		G = G - M.Galleon;
		return Money(G, S, K);
	}
};
int main(){
	// freopen("d.in", "r", stdin);
	int G, S, K;
	scanf("%d.%d.%d", &G, &S, &K);
	Money m1(G,S,K);
	scanf("%d.%d.%d", &G, &S, &K);
	Money m2(G,S,K);
	if(m1 <= m2){
		Money* m3 = new Money(m2-m1);
		printf("%d.%d.%d", m3->Galleon, m3->Sickle, m3->Knut);
	}
	else{
		Money* m3 = new Money(m1-m2);
		printf("-%d.%d.%d", m3->Galleon, m3->Sickle, m3->Knut);
	}
	return 0;
}