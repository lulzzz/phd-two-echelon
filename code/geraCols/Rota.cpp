#include "Rota.h"

Rota::Rota(){
	custo = 0;
	custoReduzido = 0;
	numApontadores = 0;
	ciclo = false;
}

Rota::~Rota(){

}

void Rota::setVertices(vector<int> v){
	vertices = v;
}

vector<int> Rota::getVertices(){
	return vertices;
}

void Rota::setCusto(Grafo* G){
	int tam = vertices.size();
	custo = G->getCustoAresta(vertices[0], vertices[1]);
	for (int i = 2; i < tam; ++i){
		custo += G->getCustoAresta(vertices[i-1], vertices[i]);
	}
}

double Rota::getCusto(){
	return custo;
}

void Rota::setCustoReduzido(double custoR){
	custoReduzido = custoR;
}

void Rota::setCustoReduzido(Grafo* G){
	int tam = vertices.size();
	custoReduzido = G->getCustoArestaDual(vertices[0], vertices[1]);
	for (int i = 2; i < tam; ++i){
		custoReduzido += G->getCustoArestaDual(vertices[i-1], vertices[i]);
	}
}

double Rota::getCustoReduzido(){
	return custoReduzido;
}

void Rota::incrNumApontadores(){
	++numApontadores;
}

bool Rota::decrNumApontadores(){
	if (--numApontadores <= 0) return true;
	return false;
}

int Rota::getNumApontadores(){
	return numApontadores;
}

void Rota::inserirVerticeFim(int v){
	vertices.push_back(v);
}

void Rota::inserirVerticeInicio(int v){
	vertices.insert(vertices.begin(), 1, v);
}

void Rota::imprimir(){
	int tam = vertices.size();
	printf ("(%05.3f | %05.3f) [ ", custo, custoReduzido);
	for (int i = 0; i < tam; ++i){
		printf ("%d ", vertices[i]);
	}
	printf ("]\n");
}
