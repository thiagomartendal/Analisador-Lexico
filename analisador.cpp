#include "analisador.h"

Analisador::Analisador() {
  palavraChave = {
    {"def", TokenPalavra::DEF},
    {"int", TokenPalavra::INT},
    {"float", TokenPalavra::FLT},
    {"string", TokenPalavra::STR},
    {"break", TokenPalavra::BRK},
    {"print", TokenPalavra::PRT},
    {"read_int", TokenPalavra::RDI},
    {"read", TokenPalavra::RED},
    {"return", TokenPalavra::RTN},
    {"if", TokenPalavra::IF},
    {"else", TokenPalavra::ELS},
    {"for", TokenPalavra::FOR},
    {"new", TokenPalavra::NEW},
    {"null", TokenPalavra::NLL}
  };
  operador = {
    {"=", TokenPalavra::IGL},
    {"<", TokenPalavra::MEN},
    {">", TokenPalavra::MAI},
    {"<=", TokenPalavra::MEG},
    {">=", TokenPalavra::MAG},
    {"==", TokenPalavra::IGG},
    {"!=", TokenPalavra::DIF},
    {"+", TokenPalavra::ADD},
    {"-", TokenPalavra::SUB},
    {"*", TokenPalavra::MUL},
    {"/", TokenPalavra::DIV},
    {"%", TokenPalavra::MOD},
    {",", TokenPalavra::VI},
    {";", TokenPalavra::FIN}
  };
  delimitador = {
    {"(", TokenPalavra::P1},
    {")", TokenPalavra::P2},
    {"[", TokenPalavra::CL1},
    {"]", TokenPalavra::CL2},
    {"{", TokenPalavra::CV1},
    {"}", TokenPalavra::CV2}
  };
}

void Analisador::tokenizar(std::string palavra, int linha, int coluna) {
  TokenPalavra tk;
  if (palavraChave.find(palavra) != palavraChave.end()) {
    tk = palavraChave[palavra];
  } else if (operador.find(palavra) != operador.end()) {
    tk = operador[palavra];
  } else if (delimitador.find(palavra) != delimitador.end()) {
    tk = delimitador[palavra];
  } else {
    std::regex identificador = std::regex("^[a-zA-Z_][a-zA-Z0-9_]*$");
    std::regex identificadorInteiro = std::regex("^[0-9_]*$");
    std::regex identificadorFlutuante = std::regex("^[0-9]+[.][0-9]+$");
    if (std::regex_match(palavra, identificador)) {
      tk = TokenPalavra::ID;
    } else if (std::regex_match(palavra, identificadorInteiro)) {
      tk = TokenPalavra::IDI;
    } else if (std::regex_match(palavra, identificadorFlutuante)) {
      tk = TokenPalavra::IDF;
    } else if ((palavra[0] == '"') && (palavra[palavra.length()-1] == '"')) {
      tk = TokenPalavra::IDS;
    } else {
      tk = TokenPalavra::ERR;
    }
  }
  if (tk == TokenPalavra::IDS) {
    std::string aspa = std::string(1, '"');
    int novaColuna = coluna-(palavra.length()-1);
    palavra.erase(0, 1);
    palavra.erase(palavra.length()-1, 1);
    tokens.push_back({aspa, linha, novaColuna, TokenPalavra::AS});
    tokens.push_back({palavra, linha, novaColuna+1, tk});
    tokens.push_back({aspa, linha, coluna, TokenPalavra::AS});
  } else {
    tokens.push_back({palavra, linha, coluna, tk});
  }
}

void Analisador::analisar(std::string texto, int linha) {
  std::string palavra = "";
  bool formandoString = false;
  for (int i = 0; i < texto.length(); i++) {
    int coluna = i+1;
    if ((texto[i] == '"') || (texto[i] == '\0')) {
      formandoString = !formandoString;
    }
    if (formandoString) {
      palavra += texto[i];
    } else {
      if (texto[i] != ' ') {
        if (delimitador.find(std::string(1, texto[i])) != delimitador.end()) {
          Analisador::tokenizar(std::string(1, texto[i]), linha, coluna);
          palavra = "";
        } else if (operador.find(std::string(1, texto[i])) != operador.end()) {
          Analisador::tokenizar(std::string(1, texto[i]), linha, coluna);
          palavra = "";
        } else {
          palavra += texto[i];
        }
      }
    }
    bool fimPalavra = ((texto[i+1] == ' ') || (texto[i+1] == ';') || (texto[i+1] == '\0')
    || (delimitador.find(std::string(1, texto[i+1])) != delimitador.end()))
    || (operador.find(std::string(1, texto[i+1])) != operador.end());
    if ((fimPalavra && (!formandoString) && (palavra != ""))
      || ((formandoString) && (texto[i+1] == '\0'))) {
      Analisador::tokenizar(palavra, linha, coluna);
      palavra = "";
    }
  }
}

void Analisador::escanearEntrada(std::string nomeArquivo) {
    std::ifstream arquivo = std::ifstream(nomeArquivo);
    int linha = 1;
    std::string texto;
    while (getline(arquivo, texto)) {
      Analisador::analisar(texto, linha);
      linha++;
    }
    arquivo.close();
}

std::vector<Token> Analisador::getTokens() {
  return tokens;
}
