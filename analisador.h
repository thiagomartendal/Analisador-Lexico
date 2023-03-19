#ifndef ANALISADOR_H
#define ANALISADOR_H

#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <fstream>
#include "token.h"

class Analisador {
private:
  std::map<std::string, TokenPalavra> palavraChave;
  std::map<std::string, TokenPalavra> operador;
  std::map<std::string, TokenPalavra> delimitador;
  std::vector<Token> tokens;
  void tokenizar(std::string palavra, int linha, int coluna);
  void analisar(std::string texto, int linha);

public:
  Analisador();
  void escanearEntrada(std::string nomeArquivo);
  std::vector<Token> getTokens();
};

#endif
