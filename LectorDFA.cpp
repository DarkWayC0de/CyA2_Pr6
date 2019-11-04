#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include "LectorDFA.h"

LectorDFA::LectorDFA(const std::string& nombreArchivo, DatosDFA *datosDfa) {
  std::ifstream readfile(nombreArchivo);
  if (readfile.is_open()){
    std::set<std::string> alfabeto;
    int  tamanolfabeto  = std::stoi(this -> getlinea(readfile));
    for (int i = 0; i <tamanolfabeto ; ++i) {
      alfabeto.insert(this-> getlinea(readfile));
    }
    datosDfa -> setAlfabelto(alfabeto);
    std::set<std::string> estados;
    int  numeroEstados  = std::stoi(this -> getlinea(readfile));
    for (int j = 0; j < numeroEstados; ++j) {
      estados.insert( this -> getlinea(readfile));
    }
    datosDfa -> setEstados(estados);
    std::string estadoInicial = this -> getlinea(readfile);
    if ( !this -> pertenese(estadoInicial, estados)){
      std::cout << "\nEl estado de aceptacion no pertenese a el conjunto de estados\n";
      exit(2);
    }
    datosDfa ->setEstadoInicial(estadoInicial);
    std::set<std::string> estadoFinal;
    int  numeroFinales  = std::stoi(this -> getlinea(readfile));
    for (int k = 0; k < numeroFinales; ++k) {
      estadoFinal.insert(this -> getlinea(readfile));
    }
    if ( !this -> esSubconjunto(estadoFinal, estados)){
      std::cout << "\nEl conjunto de estados finales no pertenesen a el conjunto de estados\n";
      exit(3);
    }
    datosDfa -> setEstadosAceptacion(estadoFinal);
    std::vector<std::vector<std::string>> transiciones;
    this -> inicializarTransiciones(transiciones,alfabeto,estados);
    int  numerotransiciones  = std::stoi(this -> getlinea(readfile));
    for (int l = 0; l <numerotransiciones ; ++l) {
      std::string linea = getlinea(readfile);
      std::string palabra;
      this -> extraerPalabra( linea, palabra);
      if ( !this -> pertenese(palabra, estados)){
            std::cout << "\nTransiciones mal definidas\n";
            exit(4);
      }
      for (int i = 1; i < transiciones.size() ; ++i) {
        if (palabra == transiciones[i][0]){
          this -> extraerPalabra( linea, palabra);
          if ( !this -> pertenese(palabra, alfabeto)){
            std::cout << "\nTransiciones mal definidas\n";
            exit(5);
          }
          for (int j = 1; j <transiciones[0].size() ; ++j) {
            if( transiciones[0][j] == palabra){
                transiciones[i][j] = linea;
            }
          }
        }
      }
    }
    datosDfa -> setFuncionTransicion(transiciones);
    readfile.close();
  } else {
    std::cout<<"\nERROR, en la apertura de archivo .dfa";
    exit(1);
  }
}

std::string LectorDFA::getlinea(std::ifstream &readfile){
  std::string const comentario = "//";
  std::string linea;
  do {
      std::getline(readfile, linea);
  }while (linea.substr(0,2) == comentario && !readfile.eof());
  return linea;
}
bool LectorDFA::pertenese(const std::string& estado, const std::set<std::string>& conjuntoEstados){
    auto i = conjuntoEstados.begin();
  for ( ; i != conjuntoEstados.end(); i++){
    if( *i == estado){
        break;
    }
  }
    return (i != conjuntoEstados.end());
}
bool LectorDFA::esSubconjunto(const std::set<std::string>& estadosSubconjunto,
                              const std::set<std::string>& estados){
    bool esSubconjunto = true;
    auto i = estadosSubconjunto.begin();
    for (; i != estadosSubconjunto.end(); i++) {
        esSubconjunto &= pertenese(*i,estados);
    }
    return esSubconjunto;
}

void LectorDFA::extraerPalabra(std::string &linea, std::string &palabra){
    char const ESPACIO =' ';
    int i = 0;
    for ( ; i < linea.length() ; ++i) {
        if (linea[i] == ESPACIO){
            break;
        }
    }
    palabra = linea.substr(0,i);
    linea = linea.substr(i+1,linea.length());
}

void LectorDFA::inicializarTransiciones(std::vector<std::vector<std::string>>& transiciones,
                                       std::set<std::string> &alfabeto,
                                       std::set<std::string>& estados){
    transiciones.resize(estados.size()+1);
    for (int i = 0; i <=estados.size() ; ++i) {
        transiciones[i].resize(alfabeto.size()+1);
    }
    int contador = 1;
    for (const auto & simbolo : alfabeto) { //añadimos indice simbolos
        transiciones[0] [contador++] = simbolo;
    }
    contador = 1;
    for (const auto & estado : estados) { //añadimos indice estados
        transiciones[contador++] [0] = estado;
    }
}
