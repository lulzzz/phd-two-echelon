#include "Grafo.h"
#include "Rota.h"
#include <vector>
#include <string.h>
using namespace std;

struct RotaG {
	vector < int > vertices;
	int carga;
	float custo;

	void imprimir(){
		int tam = vertices.size();
		printf ("(%f | %d ) [ ", custo, carga);
		for (int i = 0; i < tam; ++i){
			printf ("%d ", vertices[i]);
		}
		printf ("]\n");
	}
};

struct Movimento{
	char tipo;
	int arg1;
	int arg2;

	Movimento (char t, int a1, int a2 = 0) : tipo(t), arg1(a1), arg2(a2) {}
};

class GRASP{
	private:
		float alfa;
		int nVertices;
		int nSatellites;
		vector < int >* verticesForaRota;
		vector < RotaG* > rotasNegativas;
		Grafo* g;

	public:
		GRASP(Grafo*, float);
		~GRASP();
		void preencheVerticesForaRota(RotaG*);
		RotaG* solucaoInicial();
		int remocao(RotaG*, int i = 1);
		int insercao(RotaG*, int i = 1);
		int swap(RotaG*);

		RotaG* pathRelinking(RotaG*, RotaG*);
		vector < Movimento > movimentosPR(RotaG*, RotaG*);
		vector < Movimento > match(vector < int >&, vector < int >&, int, int, int);
		int defineIndiceMovimento(vector < Movimento >&, RotaG*, float&);

		int run(int, float, Rota* rotaCplex = NULL);
		void insereRotaNegativa(vector < RotaG* >&, RotaG*, char);
		Rota* getRotaConvertida(int, int);
};

