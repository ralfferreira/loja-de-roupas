//Autores: Anna Livia e Ralf Ferreira
//Professores: Marcelo Iury e Derzu Omaia
//Data de Entrega: 05 de maio de 2023

#include "Roupas.h"

Roupas::Roupas() : Produto(){}

Roupas::Roupas(int ID, string nomeProduto, double valorDoProduto, string tamanho, string cor, string material) : Produto(ID, nomeProduto, valorDoProduto){
  this->tamanho = tamanho;
  this->cor = cor;
  this->material = material;
}
string Roupas::getTamanho(){
  return tamanho;
}
string Roupas::getCor(){
  return cor;
}
string Roupas::getMaterial(){
  return material;
}
void Roupas::setTamanho(string tamanho){
  this->tamanho = tamanho;

}
void Roupas::setCor(string cor){
  this->cor = cor;
}
void Roupas::setMaterial(string material){
    this->material = material;
}

void Roupas::MostrarNaTela(){
  Produto::MostrarNaTela();
  cout << "Tamanho do produto: " << tamanho << endl;
  cout << "Cor do produto: " << cor << endl;
  cout << "Material do produto: " << material << endl;
}