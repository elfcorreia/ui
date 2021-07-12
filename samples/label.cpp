#include <ui.h>

int main() {

    ui::dialog janela;
    janela.set_title("ola mundo!");

    ui::label texto;
    texto.set_text("Olá Mundo!");
    janela.set_content(&texto);

    janela.show();

    return 0;
}