#pragma once
#include <string>

/**
 * @class View
 * @brief Interface abstrata para a camada de apresentação (View).
 */

class View {
    public:
        virtual ~View() = default;

         /** @brief Renderiza o conteúdo principal da aplicação. */
        virtual void render(const std::string& content) = 0;

        /** @brief Mostra uma mensagem de status ou informação para o usuário. */
        virtual void showMessage(const std::string& message) = 0;
};