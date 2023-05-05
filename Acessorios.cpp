#include "Acessorios.h"

Acessorios::Acessorios() : Produto(){}

Acessorios::Acessorios(string nomeProduto, double valorDoProduto, string tamanho, string cor, string tipo) : Produto(nomeProduto, valorDoProduto), tamanho(tamanho), cor(cor), tipo(tipo){
  this->tamanho = tamanho;
  this->cor = cor;
  this->tipo = tipo;
}

Acessorios::~Acessorios(){}

string Acessorios::getTamanho(){
  return tamanho;
}
string Acessorios::getCor(){
  return cor;
}
string Acessorios::getTipo(){
  return tipo;
}
void Acessorios::setTamanho(string tamanho){
  this->tamanho = tamanho;
}
void Acessorios::setCor(string cor){
  this->cor = cor;
}
void Acessorios::setTipo(string tipo){
    this->tipo = tipo;
}