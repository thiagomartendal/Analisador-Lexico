#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenPalavra {
  ID, // Identificador
  IDI, // Identificador Inteiro
  IDF, // Identificador Float
  IDS, // Identificador String
  IF, // if
  ELS, // else
  FOR, // for
  DEF, // def
  NEW, // new
  INT, // int
  FLT, // float
  STR, // string
  BRK, // break
  PRT, // print
  RDI, // read inteiro
  RED, // read
  RTN, // return
  NLL, // null
  IGL, // =
  MEN, // <
  MAI, // >
  MEG, // <=
  MAG, // >=
  IGG, // ==
  DIF, // !=
  ADD, // +
  SUB, // -
  MUL, // *
  DIV, // /
  MOD, // %
  VI, // ,
  FIN, // ;
  P1, // (
  P2, // )
  CL1, // [
  CL2, // ]
  CV1, // {
  CV2, // }
  AS, // "
  ERR // Erro
};

typedef struct Token {
  std::string palavra;
  int linha;
  int coluna;
  TokenPalavra tokenPalavra;
} Token;

#endif
