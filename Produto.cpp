#include "Produto.h"

Produto::Produto(){}

Produto::Produto(int ID, string nomeProduto, double valorDoProduto){
  this->ID = ID;
  this->nomeProduto = nomeProduto;
  this->valorDoProduto = valorDoProduto;
}
int Produto::getID(){
  return ID;
}
string Produto::getNomeProduto(){
  return nomeProduto;
}
double Produto::getValorDoProduto(){
  return valorDoProduto;
}
void Produto::setID(int ID){
  this->ID = ID;
}
void Produto::setNomeProduto(string nomeProduto){
  this->nomeProduto = nomeProduto;
}
void Produto::setValorDoProduto(double valorDoProduto){
  this->valorDoProduto = valorDoProduto;
}
void Produto::MostrarNaTela(){
  cout << "ID do Produto: " << ID << endl;
  cout << "Nome do Produto: " << nomeProduto << endl;
  cout << "Valor do Produto: R$ " << setprecision(2) << valorDoProduto << endl;
}

virtual ~Produto(){}