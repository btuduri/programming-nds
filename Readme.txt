Modelo de Projeto
------ -- -------

Conte�do:
 * Project.sln     (Visual Studio Express)
 * Project.vcproj  (Visual C++ 2008 Express)
 * Project.pnproj  (Programmer's Notepad)

 * data/           (Pasta que cont�m dados bin�rios)
 * filesystem/     (Pasta que cont�m arquivos do filesystem)
 * graphics/       (Pasta que cont�m imagens)
 * audio/          (Pasta que cont�m �udios)
 * include/        (Pasta que cont�m os includes .h)
 * source/         (Pasta que cont�m os fontes .c/.cpp)

 * Makefile        (Intru��es de compila��o)
 * source/main.cpp (Exemplo Hello World)

Modificar Metadados da ROM
--------- --------- -- ---
 * Alterar GAME_TITLE no Makefile
 * Alterar GAME_SUBTITLE1 no Makefile
 * Alterar GAME_SUBTITLE2 no Makefile
 * Adicionar icon.bmp (32x32) na ra�z do projeto

Para utilizar modules e waves
---- -------- ------- - -----
 * Utilizar a pasta audio para armazenar as m�dias
   .mod - m�sicas
   .wav - efeitos
 * Importar no projeto:
   #include <maxmod9.h>
   #include "soundbank.h"
   #include "soundbank_bin.h"

Para utilizar imagens
---- -------- -------
 * Utilizar a pasta graphics para armazenas as imagens
   .png  - imagem
   .grit - op��es de convers�o da imagem