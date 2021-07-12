#include <ui.h>

int main() {

    ui::dialog janela;
    janela.set_title("ola mundo!");
    
    ui::vbox box;

    ui::label texto;
    texto.set_text("Olá ");
    ui::label nome;
    nome.set_text("Olá Mundo!");

    box.add(&texto);
    box.add(&nome);

    janela.set_content(&box);
    janela.show();

    return 0;
}