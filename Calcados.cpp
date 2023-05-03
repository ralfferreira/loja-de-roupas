#include "Calcados.h"

Calcados::Calcados() : Produto(){}

Calcados::Calcados(int ID, string nomeProduto, double valorDoProduto, string tamanho, string cor, string tipo) : Produto(ID, nomeProduto, valorDoProduto){
  this->tamanho = tamanho;
  this->cor = cor;
  this->tipo = tipo;
}
string Calcados::getTamanho(){
  return tamanho;
}
string Calcados::getCor(){
  return cor;
}
string Calcados::getTipo(){
  return tipo;
}
void Calcados::setTamanho(string tamanho){
  this->tamanho = tamanho;

}
void Calcados::setCor(string cor){
  this->cor = cor;
}
void Calcados::setTipo(string tipo){
    this->tipo = tipo;
}

void Calcados::MostrarNaTela(){
  Produto::MostrarNaTela();
  cout << "Tamanho do produto: " << tamanho << endl;
  cout << "Cor do produto: " << cor << endl;
  cout << "Material do produto: " << tipo << endl;
}
