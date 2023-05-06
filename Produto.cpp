// Autores: Anna Livia e Ralf Ferreira
// Professores: Marcelo Iury e Derzu Omaia
// Data de Entrega: 08 de maio de 2023

#include "Produto.h"

Produto::Produto() {}

Produto::Produto(string nomeProduto, double valorDoProduto, int idProduto,
                 int quantidadeDisponivel, string tamanhoProduto,
                 string corProduto, string tipoProduto, string subTipoProduto) {
  this->nomeProduto = nomeProduto;
  this->valorDoProduto = valorDoProduto;
  this->idProduto = idProduto;
  this->quantidadeDisponivel = quantidadeDisponivel;
  this->tamanhoProduto = tamanhoProduto;
  this->corProduto = corProduto;
  this->tipoProduto = tipoProduto;
  this->subTipoProduto = subTipoProduto;
}

Produto::~Produto() {}

string Produto::getNomeProduto() { return nomeProduto; }
double Produto::getValorDoProduto() { return valorDoProduto; }
int Produto::getIdProduto() { return idProduto; }
int Produto::getQuantidadeDisponivel() { return quantidadeDisponivel; }
string Produto::getTamanhoProduto() { return tamanhoProduto; }
string Produto::getCorProduto() { return corProduto; }
string Produto::getTipoProduto() { return tipoProduto; }
string Produto::getSubTipoProduto() { return subTipoProduto; }

void Produto::setNomeProduto(string nomeProduto) {
  this->nomeProduto = nomeProduto;
}
void Produto::setValorDoProduto(double valorDoProduto) {
  this->valorDoProduto = valorDoProduto;
}
void Produto::setTamanhoProduto(string tamanhoProduto) {
  this->tamanhoProduto = tamanhoProduto;
}
void Produto::setCorProduto(string corProduto) {
  this->corProduto = corProduto;
}
void Produto::setSubTipoProduto(string subTipoProduto) {
  this->subTipoProduto = subTipoProduto;
}
bool Produto::verificarEstoque() { return true; }
void Produto::setQuantidadeDisponivel(int quantidadeDisponivel) {
  this->quantidadeDisponivel = quantidadeDisponivel;
}
int Produto::proximoId = 1;