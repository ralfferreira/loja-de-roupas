#include "Produto.h"

Produto::Produto(){}

Produto::Produto(string nomeProduto, double valorDoProduto){
  this->nomeProduto = nomeProduto;
  this->valorDoProduto = valorDoProduto;
}

Produto::~Produto(){}

string Produto::getNomeProduto(){
  return nomeProduto;
}
double Produto::getValorDoProduto(){
  return valorDoProduto;
}
void Produto::setNomeProduto(string nomeProduto){
  this->nomeProduto = nomeProduto;
}
void Produto::setValorDoProduto(double valorDoProduto){
  this->valorDoProduto = valorDoProduto;
}
bool Produto::verificarEstoque(){
  return true;
}