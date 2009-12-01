Modelo de Projeto
------ -- -------

Conteúdo:
 * Project.sln     (Visual Studio Express)
 * Project.vcproj  (Visual C++ 2008 Express)
 * Project.pnproj  (Programmer's Notepad)

 * data/           (Pasta que contém dados binários)
 * filesystem/     (Pasta que contém arquivos do filesystem)
 * graphics/       (Pasta que contém imagens)
 * audio/          (Pasta que contém áudios)
 * include/        (Pasta que contém os includes .h)
 * source/         (Pasta que contém os fontes .c/.cpp)

 * Makefile        (Intruções de compilação)
 * source/main.cpp (Exemplo Hello World)

Modificar Metadados da ROM
--------- --------- -- ---
 * Alterar GAME_TITLE no Makefile
 * Alterar GAME_SUBTITLE1 no Makefile
 * Alterar GAME_SUBTITLE2 no Makefile
 * Adicionar icon.bmp (32x32) na raíz do projeto

Para utilizar modules e waves
---- -------- ------- - -----
 * Utilizar a pasta audio para armazenar as mídias
   .mod - músicas
   .wav - efeitos
 * Importar no projeto:
   #include <maxmod9.h>
   #include "soundbank.h"
   #include "soundbank_bin.h"

Para utilizar imagens
---- -------- -------
 * Utilizar a pasta graphics para armazenas as imagens
   .png  - imagem
   .grit - opções de conversão da imagem