# Práctica 6 Computabilidad y Algoritmia 2019-2020
### Objetivos
Consolidar conocimientos de Autómatas Finitos Deterministas(DFAs).
Conocer Graphviz, visualizador de grafos.
Implementar un c++ una clase para representar DFAs.
Profundizar en las capacidades de diseñar y desarrollar programas orientados
a objetos en C++.

### Caracterizacion de un DFA
Formalmente se caracteriza por una quíntupla (Σ, Q, q0, F, δ) dond cada uno
de estos elementos tiene el siguiente significado:
- Σ es el alfabeto de entrada del automata. Conjunto de símbolos que el
autómata acepta como entrada.
- Q es el conjunto finito de los estados del autómata. El autómata siempre
se encontrará en uno de los estados de este conjunto.
- q0 es el estado inicial o de arranque del autómata (q0 ∈  Q). 
- F es el conjunto de estados finales o de aceptación del autómata 
(F ⊆ Q).
- δ es la función de transición. Q x Q×Σ → Q que determina el único 
estado siguiente para un par (q i , σ) correspondiente al estado actual y
la entrada.

### Ejercicio práctico 
Desarrollar un programa DFA2dot que lea un fichero de texto en el que figura
la especificación de un DFA y genere un fichero DOT con la especificación de
ese DFA a partir del cual pueda generarse un fichero gráfico con el digrama
de transiciones del DFA. El programa debiera ejecutarse como:
```bash
$ ./DFA2dot imput.dfa output.gv
```
Donde input.dfa es el fichero contenido de descripción del DFA y output.gv es
el correspondiente fichero en formato DOT.

El comportamiento del programa DFA2dot al ejecutarse en lı́nea de comandos 
debiera ser similar al de los comandos de Unix. Este es un requisito que 
solicitaremos para todos los programas de prácticas de la asignatura a 
partir de ésta. Ası́ por ejemplo, si se ejecuta grep en una terminal Unix 
(se recomienda estudiar este programa) se obtiene:

```bash
$ grep
Modo de empleo: grep [OPCIÓN]... PATRÓN [FICHERO]...
Pruebe 'grep --help' para más información.
```

En caso de DFA2dot:
```bash
$ ./DFA2dot
Modo de empleo: ./DFA2dot imput.dfa output.gv
Pruebe 'DFA2dot --help' par más información.
```

La opción --help en línea de comandos ha de producir que se imprima en
pantalla un breve tecto explicativo del funcionamiento del programa.

###### Ejemplo de formato de los ficheros de entrada con extensión .dfa.
```bash
// Universodad de La Laguna
// Grado en Ingenieria Informatica
// Computabilidad y Algoritmia
//
// Fichero de representacion de un DFA
// Lenguaje reconocido: Cadenas binarias que representan numeros enteros
//  divisibles por 3
// ER: (1(01*0)*1|0)+
//////////////////////////////////////////////////////////////////////////////
2
0
1
5
q0
cero
0mod3
1mod3
2mod3
q0
2
cero
0mod3
8
q0 0 cero
q0 1 1mod3
1mod3 0 2mod3
1mod3 1 0mod3
2mod3 0 1mod3
2mod3 1 2mod3
0mod3 0 0mod3
0mod3 1 1mod3
```

Los ficheros de especificación de DFAs definen en este orden el alfabeto,
los estados, el estado inicial, los estados finales y las transiciones. 
El formato de cada uno de estos elementos en el fichero es el siguiente:
1. Alfabeto: una lı́nea que contiene N, el número de sı́mbolos en el 
alfabeto (primera lı́nea después de los comentarios) 
seguida de N lı́neas, cada una de las cuales contiene un sı́mbolo del 
alfabeto. Cada sı́mbolo del alfabeto debe ser una cadena de caracteres 
imprimibles, sin incluir espacios en blanco.
2. Estados: una lı́nea que contiene M, el número de estados, seguida de M
lı́neas, cada una de las cuales contiene el identificador (etiqueta) de un
estado. Cada identificador de estado debe ser una cadena alfanumérica sin
espacios.
3. Estado inicial: una lı́nea que contiene el identificador del estado
inicial. El estado inicial ha de ser uno de los estados relacionados
anteriormente.
4. Estados de aceptación: una lı́nea que contiene F, el número de estados 
finales, seguido por F lı́neas, cada una de las cuales contiene el 
identificador de un estado final. Cada estado final ha de ser uno de los 
relacionados anteriormente.
5. Transiciones: una lı́nea que contiene T, el número de transiciones en la
función δ, seguida de T lı́neas, cada una de las cuales contiene tres 
cadenas qi, sim, qf separadas por espacios. Cada una de estas lı́neas indica
una transición del estado qi al qf con sı́mbolo sim, es decir,
δ(qi, sim) = qf . qi y qf han de estar listados en la lista de estados y 
sim debe estar en la lista de sı́mbolos del alfabeto.

Todas las lı́neas de un fichero .dfa que comiencen con los caracteres // corresponden
a comentarios, y deben ser ignorados por el programa a la hora de procesar el fichero.


###### Ejemplo formato de fichero DOT de salida con extensión .gv
```bash
/* Universidade La Laguna
   Grado en Ingenieria Informatica
   Computabilidad y Algoritmia

   Fichero DOT de represintacionde un DFA
   Lenguaje reconocido: Cadenas binarias que representan numeros
     enteros divisibles por 3 sin ceros por la izquierda
   ER: 0|(1(01*)*10*)+
*/
digraph DFA {
  rankdir=LR;
  size = "10, 4";
  d2tstyleonly = true;
  node [share = none]; "";
  node [share = doublecircle]; "cero" "0mod3";
  node [share = circle];
  "" -> "q0";
  "1mod3" -> "2mod3" [ label="0" ];
  "1mod3" -> "0mod3" [ label="1" ];
  "0mod3" -> "0mod3" [ label="0" ];
  "0mod3" -> "1mod3" [ label="1" ];
  "2mod3" -> "1mod3" [ label="0" ];
  "2mod3" -> "2mod3" [ label="1" ];
  "q0" -> "cero" [ label="0" ];
  "q0" -> "1mod3" [ label="1" ];
}
```

El fichero DOT correspondiente al diagrama de transiciones del DFA en ejemplo 
de archivo .dfa. En este fichero, las lı́neas 1–8 corresponden con 
comentarios. Deberı́a escribirse con tildes en ese texto. No se hace aquı́
por limitaciones del software que se utiliza para generar este documento. Las
lı́neas 13–15 especifican el tipo de trazo que ha de usarse en el 
gráfico para cada uno de los estados, dependiendo de si son o no de 
aceptación. Téngase en cuenta que se contempla un estado “ficticio”,
que no tiene trazo (lı́nea 13 del fichero) del que partirı́a el arco que
marca el estado de arranque. Por último las lı́neas (16) 17–24 especifican
las transiciones entre estados.



Los archivos en formato DOT pueden usar para generar ficheros gráficos
en formato SVG con Graphviz. Una vez instalado, se puede generar un 
fichero gráfico en formato SVG ejecutando:
```bash
$dot -Tsvg < DFA.gv > DFA.svg
```

### Rúbrica de evaluación del ejercicio
- Capacidad del programador(a) de introducir cambios en el programa
desarrollado.
- El comportamiento del programa debe ajustarse a lo solicitado en el
enunciado.
- El programa diseñado ha de seguir el paradigma Orientacion a Objetos.
- Modularidad: el programa ha de escribirse de modo que las diferentes
funcionalidades que se precisen sean encapsuladas en métodos cuya extensión
textual se mantenga acotada.
- El programa ha de ceñirse al formato de escritura de programas adoptado en
las prácticas de la asignatura.
- Se requiere en esta práctica que, en la sesión de evaluación de la misma,
todos los ficheros con códido fuente se alojen en un único directorio junto
con el fichero Makefile de compilación.
- Se requiere en esta práctica que todos los atributos de las clases
definidas en el proyecto tengan un comentario descriptivo de la finalidad 
del atributo en cuestión. 
- Se valorará que los comentarios del código fuente sigan el formato de los
comentarios de Doxygen

