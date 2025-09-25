# -POO-251-E003--2024001644-EDITOR_SVG
Um editor svg para minha matéria de POO, que utiliza conceitos de herança, polimorfismo, RAII, sobrecarga de operadores.
# Projeto Final de POO - Editor de Imagens SVG

**Autor:** Gustavo do Nascimento Pereira
**Matrícula:** 2024001644

---

### Sobre a Etapa 1

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
