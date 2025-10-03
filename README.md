# -POO-251-E003--2024001644-EDITOR_SVG
Um editor svg para minha matéria de POO, que utiliza conceitos de herança, polimorfismo, RAII, sobrecarga de operadores.
# Projeto Final de POO - Editor de Imagens SVG

**Autor:** Gustavo do Nascimento Pereira
**Matrícula:** 2024001644

---

## Sobre a Etapa 1

Este diretório (`design/`) contém os artefatos de design e arquitetura para a primeira etapa de entrega do projeto, conforme solicitado na especificação. O objetivo desta fase é apresentar uma arquitetura de software robusta e bem planejada que atenda aos princípios da Programação Orientada a Objetos.

Os artefatos inclusos são:
* **`README.md`**: Este arquivo.
* **`uml_diagram.png`**: O Diagrama de Classes UML que descreve visualmente a estrutura do sistema.
* **`relatorio.pdf`**: Um relatório que aprofunda e justifica as decisões de design e o uso dos conceitos de POO.
* **(Cópias dos `.h`)**: Cópias dos arquivos de cabeçalho, incluídas para cumprir a especificação da entrega. A estrutura principal do código-fonte se encontra nos diretórios `include/` e `src/` na raiz do projeto.

### Visão Geral da Arquitetura

A arquitetura escolhida para o projeto é a **Model-View-Controller (MVC)**. A principal motivação para essa escolha foi a necessidade de separar a lógica de negócio da interface do usuário, garantindo que o núcleo da aplicação funcione de forma independente e possa ser facilmente adaptado para uma interface de linha de comando (Etapa 2) e, posteriormente, uma interface gráfica (Etapa 3).

* **Model**: Representado pelas classes `Canvas`, `Shape`, `Polygon`, etc. É responsável por gerenciar os dados das formas e a lógica de manipulação.
* **View**: Representada pela interface `View` e a implementação inicial `CLIView`. É responsável por apresentar os dados do Modelo ao usuário.
* **Controller**: A classe `EditorController` age como o cérebro, recebendo comandos, atualizando o Modelo e instruindo a View.

### Próximos Passos

Com esta base arquitetural definida, os próximos passos do projeto são:
1.  **Etapa 2:** Finalizar a implementação para criar uma aplicação de linha de comando (CLI) totalmente funcional.
2.  **Etapa 3:** Desenvolver uma nova `View` com uma biblioteca gráfica (Qt) para criar a interface visual final do editor.
---
## Sobre a Etapa 2

A segunda etapa consiste em um programa de terminal (CLI) que funciona como um editor básico de imagens SVG.

O programa permite a criação de polígonos via comandos de texto e salva o resultado em um arquivo `.svg`, que pode ser visualizado em navegadores web.

### Como Compilar e Executar

#### Pré-requisitos
* **CMake** (versão 3.10+)
* Um compilador C++ (ex: **g++** do MinGW-w64)

#### Passos para Compilação
Com os pré-requisitos instalados, a compilação é feita com os seguintes comandos a partir da raiz do projeto:

1.  **Criar e entrar no diretório de build:**
    ```bash
    mkdir build
    cd build
    ```
2.  **Configurar com CMake:**
    ```bash
    # Para Windows com MinGW:
    cmake -G "MinGW Makefiles" ..
    
    # Para Linux/macOS:
    cmake ..
    ```
3.  **Compilar o projeto:**
    ```bash
    cmake --build .
    ```

#### Execução do Programa
O executável será gerado na pasta `build`. Para rodar o programa:

* **No Windows:** `.\svg_editor_app.exe`
* **No Linux/macOS:** `./svg_editor_app`

### Comandos e Exemplo de Uso

A aplicação opera através de um prompt `>`. Os seguintes comandos estão disponíveis:

* `help`: Mostra a lista de todos os comandos.
* `add polygon x,y ...`: Adiciona um polígono ao canvas a partir de uma lista de vértices.
* `render`: Exibe o código SVG do canvas atual diretamente no terminal.
* `save [nome_do_arquivo]`: Salva o canvas em um arquivo `.svg`.
* `exit`: Encerra a aplicação.

#### Exemplo de Uso
O cenário abaixo demonstra a criação de duas formas e o salvamento do resultado.

1.  **Adicionar um triângulo:**
    ```
    add polygon 150,50 50,250 250,250
    ```
2.  **Adicionar um retângulo:**
    ```
    add polygon 300,100 500,100 500,200 300,200
    ```
3.  **Salvar o arquivo:**
    ```
    save meu_desenho.svg
    ```
    Este comando cria o arquivo `meu_desenho.svg` dentro da pasta `build`.

4.  **Visualizar o resultado:**
    O arquivo SVG gerado pode ser aberto em qualquer navegador web para visualizar a imagem.

5.  **Sair do programa:**
    ```
    exit
    ```
