//Autores: Anna Livia e Ralf Ferreira
//Professores: Marcelo Iury e Derzu Omaia
//Data de Entrega: 05 de maio de 2023

#include "Roupas.h"

Roupas::Roupas() : Produto(){}

Roupas::Roupas(string nomeProduto, double valorDoProduto, string tamanho, string cor, string material) : Produto(nomeProduto, valorDoProduto), tamanho(tamanho), cor(cor), material(material){
  this->tamanho = tamanho;
  this->cor = cor;
  this->material = material;
}

Roupas::~Roupas(){}

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