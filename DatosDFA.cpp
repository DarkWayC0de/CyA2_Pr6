/**
 *@file DatosDFA.cpp 
 *@version 1.0
 *@date 28/10/2019
 *@author Diego Cruz Rodríguez
 *@title Clase DatosDFA
 *@brief Universidad de La Laguna
 *@brief Escuela Superior de Ingeniería y Tecnología 
 *@brief Grado en Ingeniería Informática
 *@brief Asignatura: Computabilidad y Algoritmia (CyA)
 *@brief Curso: 2º
 *@brief Práctica 6 CyA - Autómatas finitos deterministas
 *@brief Correo: alu0101105802@ull.edu.es
 *@brief 
 *@brief Este Archivo guarda un DFA
 *
 */
#include <fstream>
#include <iostream>
#include "DatosDFA.h"
#include "LectorDFA.h"

DatosDFA::DatosDFA(std::string nombreArchivo){
  LectorDFA lecturadfa(nombreArchivo, this);
}

const std::set<std::string> &DatosDFA::getAlfabelto() const {
  return Alfabelto_;
}

void DatosDFA::setAlfabelto(const std::set<std::string> &alfabelto) {
  Alfabelto_ = alfabelto;
}

const std::set<std::string> &DatosDFA::getEstados() const {
  return Estados_;
}

void DatosDFA::setEstados(const std::set<std::string> &estados) {
  Estados_ = estados;
}

const std::string &DatosDFA::getEstadoInicial() const {
  return EstadoInicial_;
}

void DatosDFA::setEstadoInicial(const std::string &estadoInicial) {
  EstadoInicial_ = estadoInicial;
}

const std::set<std::string> &DatosDFA::getEstadosAceptacion() const {
  return EstadosAceptacion_;
}

void DatosDFA::setEstadosAceptacion(const std::set<std::string> &estadosAceptacion) {
  EstadosAceptacion_ = estadosAceptacion;
}

const std::vector<std::vector<std::string>> &DatosDFA::getFuncionTransicion() const {
  return FuncionTransicion_;
}

void DatosDFA::setFuncionTransicion(
                    const std::vector<std::vector<std::string>> &funcionTransicion) {
  FuncionTransicion_ = funcionTransicion;
}


void  DatosDFA::crearArchivoDot(std::string nombreArchivo){
  std::string const CABECERADOT = "/* Universidad de La Laguna\n"
                                  "   Grado en Ingenieria Informatica\n"
                                  "   Computabilidad y Algoritmia\n\n"
                                  "   Fichero DOT de representacion de un DFA\n"
                                  "   Fichero Generado por Programa de la practica numero 6\n"
                                  "   Creado por Diego Cruz Rodríguez\n"
                                  "*/\n"
                                  "digraph DFA {\n"
                                  "  rankdir=LR;\n"
                                  "  size = \"10, 4\";\n"
                                  "  d2tstyleonly = true;\n"
                                  "  node [share = none]; \"\";"
                                  "  node [share = doublecircle];";

  std::ofstream writefile(nombreArchivo);
  if (writefile.is_open()){
    writefile<<CABECERADOT; //Se Introduce la cabecera
    for (auto i = this -> EstadosAceptacion_.begin();
          i != EstadosAceptacion_.end(); i++){
        writefile<<" \""<< *i <<"\"";          //Se añaden los estados finales 
    }
    writefile<<";\n"
               "  node [share = circle];\n"
               "  \"\" -> \"" << this -> EstadoInicial_ << "\";\n"; //Se señala el arranque 
    for (int j = 1; j < FuncionTransicion_.size() ; ++j) {
        for (int i = 1; i < FuncionTransicion_[i].size(); ++i) {
            if( !FuncionTransicion_[j][i].empty()){     //En caso de que la tabla de transicion no sea
                writefile << "  \"" << FuncionTransicion_[j][0] <<"\" -> \""     //vacia, se añade  la
                          << FuncionTransicion_[j][i] << "\" [ label=\""         //Transicion
                          << FuncionTransicion_[0][i] << "\" ];\n";
            }
        }
    }
    writefile<<"}\n";
    writefile.close();
  } else {
    std::cout<<"\nERROR, apertura de archivo de escritura de formato DOT\n";
    exit(6);
  }
}
