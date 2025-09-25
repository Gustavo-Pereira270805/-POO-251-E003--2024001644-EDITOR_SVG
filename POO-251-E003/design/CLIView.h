#pragma once
#include "View.h"

/**
 * @class CLIView
 * @brief Implementação da View para a Interface de Linha de Comando (CLI).
 */
class CLIView : public View {
    public:
        void render(const std::string& content) override;
        void showMessage(const std::string& message) override;
};
