# overdroid
a OverDroid transforma o seu smartphone-android em uma máquina de alto desempenho, sobrecarregando a CPU com cálculos intensivos, consumindo RAM com alocações de memória constantes e enchendo o armazenamento com arquivos grandes. Além disso, ele inunda a rede local com pacotes UDP, criando um verdadeiro caos digital que pode afetar a conectividade.

![demonstr](https://github.com/user-attachments/assets/dfa1bc24-8ec4-4a61-9fa5-0de0f683652d)

# consequencias
ao iniciar o OverDroid, o meu telefone rapidamente começa a ficar visivelmente lento. O processador está a todo vapor, calculando intensamente e causando um aumento significativo na temperatura do dispositivo. A memória RAM parece estar completamente ocupada, pois o telefone tenta alocar e liberar grandes quantidades de memória continuamente.

enquanto isso, o armazenamento é preenchido com arquivos enormes, ocupando uma quantidade considerável de espaço e tornando o telefone ainda mais lento. Meu acesso à rede local também começa a sofrer; a conexão Wi-Fi fica instável e parece que a internet está engasgada, com lentidão generalizada e interrupções na conexão.

em resumo, o telefone está completamente sobrecarregado, e a rede local está congestionada devido à enxurrada de pacotes UDP. A experiência é um caos digital, onde o dispositivo mal responde e a conectividade é comprometida.

#passo-a-passo

    $ git clone https://github.com/m1erphy/overdroid.git
    $ cd overdroid
    $ ./gradlew sync
    $ ./gradlew assembleDebug
    
Overdroid

Overdroid é um projeto Android que inclui código C/C++ integrado com Java para executar uma série de funções nativas. Este README fornece instruções sobre como clonar o repositório, configurar o ambiente de desenvolvimento, e construir o APK.
Requisitos

    Android Studio: Para desenvolvimento e construção do APK.
    Android NDK: Necessário para compilar o código nativo em C/C++.
    Gradle: Utilizado para construir o projeto.

Clonando o Repositório

Clone o repositório do GitHub para sua máquina local usando o seguinte comando:

sh

git clone https://github.com/m1erphy/overdroid.git

Navegue para o diretório do projeto:

sh

cd overdroid

Configurando o Ambiente

    Instalar o Android Studio:
        Baixe e instale o Android Studio.

    Instalar o Android NDK:
        No Android Studio, vá para File > Settings (ou Android Studio > Preferences no macOS).
        Navegue até Appearance & Behavior > System Settings > Android SDK.
        Clique na aba SDK Tools e marque a opção NDK (Side by side).

    Sincronizar o Projeto com Gradle:
        Abra o projeto no Android Studio.
        O Android Studio deve detectar automaticamente o arquivo build.gradle e solicitar para sincronizar o projeto. Caso contrário, clique no botão Sync Project with Gradle Files na barra de ferramentas.

Construindo o APK

Para construir o APK, você pode usar o Android Studio ou a linha de comando:
Usando o Android Studio

    No Android Studio, vá para o menu Build.
    Selecione Build Bundle(s) / APK(s).
    Escolha Build APK(s) e aguarde a conclusão do processo.

Usando a Linha de Comando

Se preferir usar a linha de comando, execute o seguinte comando para construir o APK de debug:

sh

./gradlew assembleDebug

O APK será gerado no diretório app/build/outputs/apk/debug/.
Estrutura do Projeto

    src/main/java/: Contém os arquivos Java.
    src/main/cpp/: Contém os arquivos C/C++.
    src/main/res/: Contém recursos como layouts e imagens.
    src/main/AndroidManifest.xml: Contém o manifesto do Android.
    CMakeLists.txt: Arquivo de configuração do CMake para construir o código nativo.
    build.gradle: Arquivo de configuração do Gradle para o módulo do aplicativo.
    settings.gradle: Arquivo de configuração do Gradle para o projeto.

Dependências

As dependências do projeto estão especificadas no arquivo build.gradle e serão baixadas automaticamente quando o projeto for sincronizado com Gradle.
Permissões e Configurações

O projeto requer permissões específicas que estão definidas no arquivo AndroidManifest.xml. Certifique-se de revisar e ajustar essas permissões conforme necessário para o seu uso.Claro! Aqui está um modelo de arquivo README.md que você pode usar para seu projeto no GitHub. Este README inclui instruções para clonar o repositório, configurar o ambiente, construir o APK, e considerações adicionais.

Permissões e Configurações

O projeto requer permissões específicas que estão definidas no arquivo AndroidManifest.xml. Certifique-se de revisar e ajustar essas permissões conforme necessário para o seu uso.
Contribuição

Se você quiser contribuir para o projeto, por favor, faça um fork do repositório, faça suas alterações e envie um pull request. Sinta-se à vontade para abrir problemas para relatar bugs ou sugerir melhorias.
Licença

Este projeto está licenciado sob a MIT License.
Contato

Para qualquer dúvida ou suporte, entre em contato através do issues page ou pelo e-mail.

    made by: m1erphy/wh0is. 
    contact:   m1erbonecom@proton.me
    contact_2: debonewtcom@proton.me
