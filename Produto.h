// Autores: Anna Livia e Ralf Ferreira
// Professores: Marcelo Iury e Derzu Omaia
// Data de Entrega: 08 de maio de 2023

#include <iostream>
#include <string>
#pragma once

using namespace std;

class Produto {
protected:
  string nomeProduto;
  double valorDoProduto;
  int idProduto;
  int quantidadeDisponivel;
  string tamanhoProduto;
  string corProduto;
  string tipoProduto;
  string subTipoProduto;
  static int proximoId;

public:
  Produto();
  virtual ~Produto();
  Produto(string nomeProduto, double valorDoProduto, int idProduto,
          int quantidadeDisponivel, string tamanhoProduto, string corProduto,
          string tipoProduto, string subTipoProduto);
  string getNomeProduto();
  double getValorDoProduto();
  int getIdProduto();
  string getTamanhoProduto();
  string getCorProduto();
  string getTipoProduto();
  string getSubTipoProduto();
  void setNomeProduto(string nomeProduto);
  void setValorDoProduto(double valorDoProduto);
  void setTamanhoProduto(string tamanhoProduto);
  void setCorProduto(string corProduto);
  void setSubTipoProduto(string subTipoProduto);
  bool verificarEstoque();
  int getQuantidadeDisponivel();
  void setQuantidadeDisponivel(int quantidadeDisponivel);
  static int getProximoId() { return proximoId; }
  static void setProximoId(int novoId) { proximoId = novoId; }
};