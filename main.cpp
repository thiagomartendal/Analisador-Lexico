#include <iostream>
#include "analisador.h"

std::string token(TokenPalavra tk) {
  std::string t;
  switch (tk) {
    case TokenPalavra::ID:
      t = "ID";
    break;
    case TokenPalavra::IDI:
      t = "IDI";
    break;
    case TokenPalavra::IDF:
      t = "IDF";
    break;
    case TokenPalavra::IDS:
      t = "IDS";
    break;
    case TokenPalavra::IF:
      t = "IF";
    break;
    case TokenPalavra::ELS:
      t = "ELS";
    break;
    case TokenPalavra::FOR:
      t = "FOR";
    break;
    case TokenPalavra::DEF:
      t = "DEF";
    break;
    case TokenPalavra::NEW:
      t = "NEW";
    break;
    case TokenPalavra::INT:
      t = "INT";
    break;
    case TokenPalavra::FLT:
      t = "FLT";
    break;
    case TokenPalavra::STR:
      t = "STR";
    break;
    case TokenPalavra::BRK:
      t = "BRK";
    break;
    case TokenPalavra::PRT:
      t = "PRT";
    break;
    case TokenPalavra::RDI:
      t = "RDI";
    break;
    case TokenPalavra::RED:
      t = "RED";
    break;
    case TokenPalavra::RTN:
      t = "RNT";
    break;
    case TokenPalavra::NLL:
      t = "NLL";
    break;
    case TokenPalavra::IGL:
      t = "IGL";
    break;
    case TokenPalavra::MEN:
      t = "MEN";
    break;
    case TokenPalavra::MAI:
      t = "MAI";
    break;
    case TokenPalavra::MEG:
      t = "MEG";
    break;
    case TokenPalavra::MAG:
      t = "MAG";
    break;
    case TokenPalavra::IGG:
      t = "IGG";
    break;
    case TokenPalavra::DIF:
      t = "DIF";
    break;
    case TokenPalavra::ADD:
      t = "ADD";
    break;
    case TokenPalavra::SUB:
      t = "SUB";
    break;
    case TokenPalavra::MUL:
      t = "MUL";
    break;
    case TokenPalavra::DIV:
      t = "DIV";
    break;
    case TokenPalavra::MOD:
      t = "MOD";
    break;
    case TokenPalavra::VI:
      t = "VI";
    break;
    case TokenPalavra::FIN:
      t = "FIN";
    break;
    case TokenPalavra::P1:
      t = "P1";
    break;
    case TokenPalavra::P2:
      t = "P2";
    break;
    case TokenPalavra::CL1:
      t = "CL1";
    break;
    case TokenPalavra::CL2:
      t = "CL2";
    break;
    case TokenPalavra::CV1:
      t = "CV1";
    break;
    case TokenPalavra::CV2:
      t = "CV2";
    break;
    case TokenPalavra::AS:
      t = "AS";
    break;
    case TokenPalavra::ERR:
      t = "ERR";
    break;
    default:
      t = "";
    break;
  }
  return t;
}

int main(int argc, char *argv[]) {
  Analisador lexico;
  lexico.escanearEntrada(std::string(argv[1]));
  for (Token tk: lexico.getTokens()) {
    std::cout << tk.palavra << " " << tk.linha << " " << tk.coluna << " " << token(tk.tokenPalavra) << std::endl;
  }
  return 0;
}
