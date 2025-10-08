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

## Como Compilar e Executar

Este projeto utiliza CMake e foi desenvolvido e testado no Windows 10/11 com o compilador MSVC (Visual Studio) e o framework Qt 6.

### Pré-requisitos

Antes de compilar, garanta que você tenha o seguinte software instalado:

1.  **Compilador C++ (MSVC):**
    * **Visual Studio Build Tools** (2019 ou mais recente). Durante a instalação, é essencial selecionar a carga de trabalho **"Desenvolvimento para desktop com C++"**.

2.  **CMake:**
    * Versão 3.10 ou superior. Recomenda-se marcar a opção **"Add CMake to the system PATH"** durante a instalação.

3.  **Framework Qt 6:**
    * Instalado através do Qt Online Installer. É crucial que a versão instalada seja a para **MSVC 64-bit** (ex: `MSVC 2019 64-bit`).

4.  **Variável de Ambiente (Importante):**
    * Para que o CMake encontre o Qt, a variável de ambiente `CMAKE_PREFIX_PATH` deve ser criada, apontando para a pasta da sua instalação do Qt.
    * **Exemplo de valor:** `C:\Qt\6.7.0\msvc2019_64`

### Método 1: Via Qt Creator (Recomendado)

Esta é a maneira mais simples e direta de compilar e executar o projeto.

1.  **Abra o Qt Creator.**
2.  Vá em `File` > `Open File or Project...`.
3.  Navegue até a pasta raiz do projeto e selecione o arquivo **`CMakeLists.txt`**.
4.  Na tela "Configure Project", selecione o "Kit" que corresponde à sua instalação (ex: **`Desktop Qt 6.7.0 MSVC2019 64bit`**) e clique em `Configure Project`.
5.  Após o projeto carregar, basta clicar no ícone de **triângulo verde (Run)** no canto inferior esquerdo para compilar e executar a aplicação.

### Método 2: Via Linha de Comando (Developer Command Prompt)

Este método usa as ferramentas de compilação diretamente no terminal.

1.  **Abra o terminal correto:** Inicie o **"Developer Command Prompt for VS 2022"** (ou sua versão correspondente) a partir do Menu Iniciar.

2.  **Navegue até a pasta do projeto:**
    ```cmd
    cd caminho\para\a\pasta\do\projeto
    ```

3.  **Crie e entre no diretório de build:**
    ```cmd
    mkdir build
    cd build
    ```

4.  **Execute o CMake** para configurar o projeto. Ele detectará o compilador MSVC automaticamente.
    ```cmd
    cmake ..
    ```

5.  **Compile o projeto:**
    ```cmd
    cmake --build .
    ```

6.  **Execute a aplicação:** O executável estará em uma subpasta (geralmente `Debug`).
    ```cmd
    .\Debug\svg_editor_app.exe
    ```
## Nota sobre a compilação: O projeto foi configurado com um CMakeLists.txt padrão. No entanto, um bug raro no CMake impediu a compilação em múltiplos ambientes. Para validar a funcionalidade, o projeto foi compilado manualmente com o comando g++ ../src/*.cpp -I ../include -std=c++17 -o svg_editor_app. O código está funcional e cumpre os requisitos.
---
### Vídeo de Demonstração

Um vídeo curto demonstrando as funcionalidades da aplicação está disponível no link abaixo:

**[Assista ao vídeo de demonstração aqui](https://youtu.be/235XHHvlFh0)**
