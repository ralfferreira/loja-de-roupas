#include "Calcados.h"

Calcados::Calcados() : Produto(){}

Calcados::Calcados(string nomeProduto, double valorDoProduto, int tamanhoCalcado, string cor, string tipo) : Produto(nomeProduto, valorDoProduto), tamanhoCalcado(tamanhoCalcado), cor(cor), tipo(tipo){
  this->tamanhoCalcado = tamanhoCalcado;
  this->cor = cor;
  this->tipo = tipo;
}

Calcados::~Calcados(){}

int Calcados::getTamanho(){
  return tamanhoCalcado;
}
string Calcados::getCor(){
  return cor;
}
string Calcados::getTipo(){
  return tipo;
}
void Calcados::setTamanho(int tamanhoCalcado){
  this->tamanhoCalcado = tamanhoCalcado;
}
void Calcados::setCor(string cor){
  this->cor = cor;
}
void Calcados::setTipo(string tipo){
    this->tipo = tipo;
}