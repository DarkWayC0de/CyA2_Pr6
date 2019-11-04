/**
 *@file DFA2dot.cpp 
 *@version 1.0
 *@date 29/10/2019
 *@author Diego Cruz Rodríguez
 *@title Archivo Principal
 *@brief Universidad de La Laguna
 *@brief Escuela Superior de Ingeniería y Tecnología 
 *@brief Grado en Ingeniería Informática
 *@brief Asignatura: Computabilidad y Algoritmia (CyA)
 *@brief Curso: 2º
 *@brief Práctica 6 CyA - Autómatas finitos deterministas
 *@brief Correo: alu0101105802@ull.edu.es
 *@brief 
 *@brief Este Archivo contiene la funcion principal del programa,
 *@brief en ella se realiza la gestiosn y comprobacion de los
 *@brief argumentos, y ejecucion de la clase grafo y peticon de 
 *@brief escritura en formato DOT
 *
 */

#include <iostream>
#include <string>
#include "DatosDFA.h"

int main(int argc, char *argv[]){
  std::string const AYUDA = "--help";
  std::string const ARCHIVO_DFA = ".dfa";
  std::string const ARCHIVO_DOT = ".gv";
  switch (argc) {
    case 3 : {
      std::string nombreArchivoLectura = argv[1];
      std::string nombreArchivoEscritura = argv[2];
      std::string extencion_dfa = nombreArchivoLectura.substr(nombreArchivoLectura.length() - 4, 4);
      std::string extencion_dot = nombreArchivoEscritura.substr(nombreArchivoEscritura.length() - 3, 3);
     
      if (extencion_dfa == ARCHIVO_DFA) {
        if (extencion_dot == ARCHIVO_DOT) {
          DatosDFA dfa(nombreArchivoLectura);
          dfa.crearArchivoDot(nombreArchivoEscritura);
          break;
        }
      }
    }
    case 2 : {
      std::string comando = argv[1]; 
      if (comando == AYUDA) {
        std::cout<<"\nEste programa tranfora ficheros con formato .dfa a\n"
                 <<"archivos de formato DOT con extencion .gv para su\n"
                 <<"correcto funcionamiento se debe introducir un fichero de\n"
                 <<"entrada input.dfa y un fichero de salida output.gv\n\n"
                 <<"---------------------------------------------------------\n\n"
                 <<"Ejemplo de uso:\n"
                 <<"$ ./DFA2dot input.dfa output.gv\n\n";
        break;
      }
    }
    case 1 :
    default :
      std::cout<<"Modo de empleo: ./DFA2dot input.dfa output.gv\n"
               <<"Pruebe './DFA2dot --help' para más información.\n";
  }
  return 0;
}

