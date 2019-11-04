/**
 * @file DatosDFA.h 
 * @version 1.0
 * @date 28/10/2019
 * @author Diego Cruz Rodríguez
 * @title Clase DatosDFA
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología 
 * @brief Grado en Ingeniería Informática
 * @brief Asignatura: Computabilidad y Algoritmia (CyA)
 * @brief Curso: 2º
 * @brief Práctica 6 CyA - Autómatas finitos deterministas
 * @brief Correo: alu0101105802@ull.edu.es
 * @brief 
 * @brief Este Archivo guarda un DFA
 *
 */
#ifndef DATOSDFA_H
#define DATOSDFA_H
#include <string>
#include <set>
#include <vector>

class DatosDFA{
  public:
    /**
     * @brief Constructor datos apartir de archivo dfa
     * @param nombreArchivo string con archivo dfa con los datos
     */ 
    DatosDFA(std::string nombreArchivo);

    ~DatosDFA() = default;

    const std::set<std::string> &getAlfabelto() const;

    void setAlfabelto(const std::set<std::string> &alfabelto);

    const std::set<std::string> &getEstados() const;

    void setEstados(const std::set<std::string> &estados);

    const std::string &getEstadoInicial() const;

    void setEstadoInicial(const std::string &estadoInicial);

    const std::set<std::string> &getEstadosAceptacion() const;

    void setEstadosAceptacion(const std::set<std::string> &estadosAceptacion);

    const std::vector<std::vector<std::string>> &getFuncionTransicion() const;

    void setFuncionTransicion(const std::vector<std::vector<std::string>> &funcionTransicion);
    /**
     * @brief Apartir de los datos de la clase crea un archivo tipo DOT
     * @param nombreArchivo string con el nombre del archivo a crear 
     */
    void  crearArchivoDot(std::string nombreArchivo);
private:
    std::set<std::string> Alfabelto_;
    std::set<std::string> Estados_;
    std::string EstadoInicial_;
    std::set<std::string> EstadosAceptacion_;
    std::vector<std::vector<std::string>> FuncionTransicion_;
};

#endif //DATOSDFA_H
