// Autores: Anna Livia e Ralf Ferreira
// Professores: Marcelo Iury e Derzu Omaia
// Data de Entrega: 08 de maio de 2023

#include "Acessorios.h"
#include "Calcados.h"
#include "Produto.h"
#include "Roupas.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// função para carregar os produtos do arquivo

// declaração de um conjunto não ordenado de inteiros chamado "idsCriados", 
// que será usado para armazenar todos os IDs já criados
unordered_set<int> idsCriados;

// vai retornar um vetor de ponteiros para a classe "Produto"
vector<Produto *> carregarProdutos() {
  vector<Produto *> produtos;
  ifstream arquivoEntrada("Produtos.txt"); // ler arquivo
  string linha;

  if (arquivoEntrada.is_open()) {
    while (getline(arquivoEntrada, linha)) {
      stringstream ss(linha);
      string idStr, tipo, nome, valor, tamanho, cor, material, quantidadeStr,
          subtipo;
      getline(ss, idStr, ':');
      int id = stoi(idStr); // string para inteiro
      idsCriados.insert(id); // ID é adicionado ao "idsCriados"
      getline(ss, nome, ',');
      getline(ss, valor, ',');
      getline(ss, quantidadeStr, ',');
      getline(ss, tamanho, ',');
      getline(ss, cor, ',');
      getline(ss, tipo, ',');
      getline(ss, subtipo, ',');
      int quantidade = stoi(quantidadeStr); // string para inteiro
      
      if (tipo == "Roupas") {
        getline(ss, material);
        produtos.push_back(new Roupas(nome, stod(valor), id, quantidade,
                                      tamanho, cor, material, tipo, subtipo));
      } else if (tipo == "Calcados") {
        produtos.push_back(new Calcados(nome, stod(valor), id, quantidade,
                                        tamanho, cor, tipo, subtipo));
      } else if (tipo == "Acessorios") {
        getline(ss, material);
        produtos.push_back(new Acessorios(nome, stod(valor), id, quantidade,
                                          tamanho, cor, material, tipo,
                                          subtipo));
      } else {
        cerr << "Tipo de produto inválido: " << tipo << endl;
      }
    }
    
    arquivoEntrada.close();
    cout << "Produtos carregados com sucesso do arquivo Produtos.txt" << endl;
  } else {
    cerr << "Erro ao abrir o arquivo Produtos.txt" << endl;
  }

  return produtos;
}

int gerarNovoId() {
  // incrementa o valor de novoId até que seja um valor único que ainda não foi criado
  int novoId = Produto::getProximoId();
  while (idsCriados.find(novoId) != idsCriados.end()) {
    novoId++;
  }
  idsCriados.insert(novoId);
  Produto::setProximoId(novoId + 1); // atualizar objeto
  return novoId;
}

// função pra salvar os produtos no arquivo

void salvarProdutos(const vector<Produto *> &produtos) {
  ofstream arquivoSaida("Produtos.txt");
  if (arquivoSaida.is_open()) {
    for (auto produto : produtos) {
      arquivoSaida << produto->getIdProduto() << ":"
                   << produto->getNomeProduto() << ","
                   << produto->getValorDoProduto() << ","
                   << produto->getQuantidadeDisponivel() << ","
                   << produto->getTamanhoProduto() << ","
                   << produto->getCorProduto() << ","
                   << produto->getTipoProduto() << ","
                   << produto->getSubTipoProduto();
      // verificar se o objeto Produto é do tipo Roupas, Calcados ou Acessorios
      // "dynamic_cast" pra fazer uma conversão de tipo segura em tempo de execução
      // ele tenta converter o ponteiro produto pra os tipos Roupas, Calcados e Acessorios
      // se funcionar, ou seja, o objeto apontado por produto for uma instância de um desses tipos
      // o ponteiro convertido é armazenado em uma nova variável (roupas, calcados ou acessorios),
      // que é usada pra acessar o "getMaterial()"
      if (Roupas *roupas = dynamic_cast<Roupas *>(produto)) {
        arquivoSaida << "," << roupas->getMaterial() << endl;
      } else if (Calcados *calcados = dynamic_cast<Calcados *>(produto)) {
        arquivoSaida << endl;
      } else if (Acessorios *acessorios = dynamic_cast<Acessorios *>(produto)) {
        arquivoSaida << "," << acessorios->getMaterial() << endl;
      }
    }
    arquivoSaida.close();
    cout << "Produtos salvos com sucesso no arquivo "
         << "Produtos.txt" << endl;
  } else {
    cerr << "Erro ao salvar produtos no arquivo "
         << "Produtos.txt" << endl;
  }
}

int main() {
  int id = 0;
  vector<Produto *> produtos = carregarProdutos();
  int opcao;
  bool houveEntradaProduto = false; // pra verificar se a entrada é vazia, antes de sair do programa

  do {
    cout << "\n\t\t ------ Olá funcionário da Viral Falx ------";
    cout << "\n\n";
    cout << "\n";
    cout << "\n \t\t\t 1. LISTAR PRODUTOS";
    cout << "\n \t\t\t 2. ADICIONAR PRODUTOS";
    cout << "\n \t\t\t 3. APAGAR PRODUTOS";
    cout << "\n \t\t\t 4. ATUALIZAR PRODUTOS";
    cout << "\n \t\t\t 5. SAIR";
    cout << "\n \t\t\t Digite sua opção: ";
    cin >> opcao;
    cout << "\n\n";

    switch (opcao) {
    case 1:
      if (produtos.empty()) {
        cout << "Não há produtos cadastrados." << endl;
      } else {
        cout << "Lista de produtos:" << endl;
        for (auto produto : produtos) {
          cout << "ID: " << produto->getIdProduto()
               << ", Nome: " << produto->getNomeProduto() << ", Preço: R$ "
               << produto->getValorDoProduto();
          if (opcao == 1) {
            cout << ", Quantidade: " << produto->getQuantidadeDisponivel();
          }
          cout << endl;
        }
      }
      break;
    case 2:
      int tipoProduto;
      cout << "Escolha o tipo de produto: " << endl;
      cout << "1. Roupas" << endl;
      cout << "2. Calçados" << endl;
      cout << "3. Acessórios" << endl;
      cout << "Digite sua opção: ";
      cin >> tipoProduto;
      cin.ignore();

      switch (tipoProduto) {
      case 1: {
        string nome;
        double preco;
        string tamanho;
        string cor;
        string material;
        string subtipo;
        int quantidade;

        cout << "Digite o nome da roupa: ";
        getline(cin, nome);
        if (nome.empty()) {
          cout << "Nome inválido." << endl;
          break;
        }

        cout << "Digite o preço da roupa: R$ ";
        cin >> preco;
        cin.ignore();

        cout << "Digite o tipo de roupa: ";
        getline(cin, subtipo);
        if (subtipo.empty()) {
          cout << "Tipo inválido." << endl;
          break;
        }

        cout << "Digite o tamanho da roupa: ";
        getline(cin, tamanho);
        if (tamanho.empty()) {
          cout << "Tamanho inválido." << endl;
          break;
        }

        cout << "Digite a cor da roupa: ";
        getline(cin, cor);
        if (cor.empty()) {
          cout << "Cor inválida." << endl;
          break;
        }

        cout << "Digite o material da roupa: ";
        getline(cin, material);
        if (material.empty()) {
          cout << "Material inválido." << endl;
          break;
        }

        cout << "Digite a quantidade disponível: ";
        cin >> quantidade;
        cin.ignore();

        produtos.push_back(new Roupas(nome, preco, gerarNovoId(), quantidade,
                                      tamanho, cor, material, "Roupas",
                                      subtipo));
        cout << "Roupa cadastrada com sucesso!" << endl;
        houveEntradaProduto = true;
        break;
      }
      case 2: {
        string nome;
        double preco;
        string tamanho;
        string cor;
        string subtipo;
        int quantidade;

        cout << "Digite o nome do calçado: ";
        getline(cin, nome);
        if (nome.empty()) {
          cout << "Nome inválido." << endl;
          break;
        }

        cout << "Digite o preço do calçado: R$ ";
        cin >> preco;
        cin.ignore();

        cout << "Digite o tipo de calçado: ";
        getline(cin, subtipo);
        if (subtipo.empty()) {
          cout << "Tipo inválido." << endl;
          break;
        }

        cout << "Digite o tamanho do calçado: ";
        getline(cin, tamanho);
        if (tamanho.empty()) {
          cout << "Tamanho inválido." << endl;
          break;
        }

        cout << "Digite a cor do calçado: ";
        getline(cin, cor);
        if (cor.empty()) {
          cout << "Cor inválida." << endl;
          break;
        }

        cout << "Digite a quantidade disponível: ";
        cin >> quantidade;
        cin.ignore();

        produtos.push_back(new Calcados(nome, preco, gerarNovoId(), quantidade,
                                        tamanho, cor, "Calcados", subtipo));
        cout << "Calçado cadastrado com sucesso!" << endl;
        houveEntradaProduto = true;
        break;
      }

      case 3: {
        string nome;
        double preco;
        string tamanho;
        string cor;
        string subtipo;
        string material;
        int quantidade;

        cout << "Digite o nome do acessório: ";
        getline(cin, nome);
        if (nome.empty()) {
          cout << "Nome inválido." << endl;
          break;
        }

        cout << "Digite o preço do acessório: R$ ";
        cin >> preco;
        cin.ignore();

        cout << "Digite o tipo de acessório: ";
        getline(cin, subtipo);
        if (subtipo.empty()) {
          cout << "Tipo inválido." << endl;
          break;
        }

        cout << "Digite o tamanho do acessório: ";
        getline(cin, tamanho);
        if (tamanho.empty()) {
          cout << "Tamanho inválido." << endl;
          break;
        }

        cout << "Digite a cor do acessório: ";
        getline(cin, cor);
        if (cor.empty()) {
          cout << "Cor inválida." << endl;
          break;
        }

        cout << "Digite o material do acessório: ";
        getline(cin, material);
        if (material.empty()) {
          cout << "Material inválido." << endl;
          break;
        }

        cout << "Digite a quantidade disponível: ";
        cin >> quantidade;
        cin.ignore();

        produtos.push_back(new Acessorios(nome, preco, gerarNovoId(),
                                          quantidade, tamanho, cor, material,
                                          "Acessorios", subtipo));
        cout << "Acessório cadastrado com sucesso!" << endl;
        houveEntradaProduto = true;
        break;
      }
      default:
        cout << "Opção inválida!" << endl;
        break;
      }
      break;
    case 3:
      if (produtos.empty()) {
        cout << "Não há produtos cadastrados." << endl;
      } else {
        int id;
        cout << "Digite o ID do produto que deseja remover: ";
        cin >> id;
        cin.ignore();
        for (auto it = produtos.begin(); it != produtos.end(); ++it) {
          if ((*it)->getIdProduto() == id) {
            produtos.erase(it);
            cout << "Produto removido com sucesso!" << endl;
            houveEntradaProduto = true;
            break;
          }
        }
      }
      break;
    case 4:
      if (produtos.empty()) {
        cout << "Não há produtos cadastrados." << endl;
      } else {
        int idProduto;
        cout << "Digite o ID do produto que deseja atualizar: ";
        cin >> idProduto;
        cin.ignore();

        bool produtoEncontrado = false;

        for (auto produto : produtos) {
          if (produto->getIdProduto() == idProduto) {
            double novoPreco;
            string novoNome;
            int quantidadeAtualizada;

            cout << "Digite o novo preço para o produto: R$ ";
            cin >> novoPreco;
            cin.ignore();

            cout << "Digite o novo nome do produto: ";
            getline(cin, novoNome);
            if (novoNome.empty()) {
              cout << "Nome inválido." << endl;
              break;
            }

            cout << "Digite a quantidade disponível atualizada: ";
            cin >> quantidadeAtualizada;
            cin.ignore();

            produto->setNomeProduto(novoNome);
            produto->setValorDoProduto(novoPreco);
            produto->setQuantidadeDisponivel(quantidadeAtualizada);
            produtoEncontrado = true;
            cout << "Produto atualizado com sucesso!" << endl;
            houveEntradaProduto = true;
            break;
          }
        }

        if (!produtoEncontrado) {
          cout << "Produto não encontrado." << endl;
        }
      }
      break;
    case 5:
      if (!houveEntradaProduto) {
        cout << "Não houve entrada de produtos. Encerrando o programa..."
             << endl;
        break;
      }
      salvarProdutos(produtos);
      cout << "Encerrando o programa..." << endl;
      break;
    default:
      cout << "Opção inválida!" << endl;
      break;
    }
  } while (opcao != 5);

  return 0;
}