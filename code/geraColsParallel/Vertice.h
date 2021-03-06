#ifndef VERTICE_H_
#define VERTICE_H_
const double MAIS_INFINITO=10e6;

class Vertice{
	public:
		//construtor
		Vertice(int n) : numArestas(n){
			existeArestas = new bool[numArestas];
			custoArestas = new double[numArestas];
			custoArestasDual = new double[numArestas];
			for ( int i = 0; i < numArestas; ++i ) existeArestas[i] = false;
		}

		//destrutor
		~Vertice(){
			delete [] existeArestas;
			delete [] custoArestas;
			delete [] custoArestasDual;
		}
		//quantidade de arestas que o vertice tem
		int numArestas;

		//cada celula da matriz representara se o grafo tem (true) ou nao (false) a celula (i,j)
		bool* existeArestas;
		
		//custoArestas[i] representará o custo da aresta entre o vertice e seu sucessor i
		double* custoArestas;
		
		//custoArestasVertice[i] eh a soma do custo da aresta armazenado em custoArestas[i] + custoDual de i
		//estes custos sao uteis para o calculo dos caminhos elementares e nao elementares, pois evitam 
		//calcular a todo passo o custo de se atravessar o arco, considerando o custo dual do vertice sucessor
		double* custoArestasDual;

		//demanda/oferta do vertice
		int carga;
		
		//tempo de inicio para atendimento do fornecedor/consumidor
		int tInicio;
		
		//tempo final para atendimento do fornecedor/consumidor
		int tFim;
		
		//tempo necessario para atender este fornecedor/consumidor
		int tServico;

		//custo associado ao vertice, dado pelos custos duais na relaxação do master restrito
		double custoDual;
};

#endif /*VERTICE_H_*/
