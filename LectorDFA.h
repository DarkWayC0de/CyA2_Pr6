/**
 * @file LectorDFA.h 
 * @version 1.0
 * @date 27/10/2019
 * @author Diego Cruz Rodríguez
 * @title Clase LectorDFA
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología 
 * @brief Grado en Ingeniería Informática
 * @brief Asignatura: Computabilidad y Algoritmia (CyA)
 * @brief Curso: 2º
 * @brief Práctica 6 CyA - Autómatas finitos deterministas
 * @brief Correo: alu0101105802@ull.edu.es
 * @brief 
 * @brief Este Archivo guarda un apartir de un archivo .dfa rellena
 * @brief un objeto de la clase DatosDFA
 *
 */

#ifndef LECTORDFA_H
#define LECTORDFA_H


#include <string>
#include "DatosDFA.h"

class LectorDFA {
  public:
    /**
     * @brief Constructor de la clase
     * @param readfile Nombre del Archivo .dfa del cual se extreran los datos
     * @param datosDFA Puntero a objeto datos que guardara los datos extraidos
     */ 
    LectorDFA(const std::string& readfile, DatosDFA *datosDfa);

  private:
    std::string getlinea(std::ifstream& readfile); //adquiere linieas de fichero, 
                                                   //descarta los comentarios
    bool pertenese(const std::string& estado, const std::set<std::string>& conjuntoEstados); //comprueba
                                                                     //si estado pertenece a el conjunto

    bool esSubconjunto(const std::set<std::string>& estadosSubconjunto, //comprueba si un conjunto es 
                                 const std::set<std::string>& estados); // subconjunto de otro

    void extraerPalabra(std::string &linea, std::string &palabra); //extrae la primera palabra de 
                                                                   //una cadena

    void inicializarTransiciones(std::vector<std::vector<std::string>> &transiciones,
                                 std::set<std::string> &alfabeto, //Inicializa transiciones y añade los
                                 std::set<std::string> &estados);// indicies de estados y alfabetos;
};


#endif //LECTORDFA_H
