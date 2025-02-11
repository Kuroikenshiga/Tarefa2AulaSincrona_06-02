## Tarefa da aula síncrona do dia 06 de fevereiro de 2025

### 🗒️Enunciado:
Com o emprego do módulo PWM (do inglês, Pulse Width Modulation),
presente no microcontrolador RP2040, projete um sistema com a
ferramenta Pico SDK para simular o controle do ângulo de um
servomotor. Esta simulação contemplará o motor micro servo
padrão, presente no simulador de eletrônica online Wokwi. Para
condução desta prática, será necessário simular os componentes
listados abaixo.
1) Microcontrolador Raspberry Pi Pico W.
2) Servomotor – motor micro servo padrão – Wokwi.

### 📝Requisitos do projeto:
1) Considerando a GPIO 22, defina a sua frequência de PWM para,
aproximadamente, 50Hz – período de 20ms. (20% da nota)
2) Defina o ciclo ativo do módulo PWM para 2.400µs
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto
ajustará a flange (braço) do servomotor para a posição de,
aproximadamente, 180 graus. Aguarde 05 segundos nesta
posição. (10% da nota)
3) Defina o ciclo ativo do módulo PWM para 1.470µs
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%.
Isto ajustará a flange do servomotor para a posição de,
aproximadamente, 90 graus. Aguarde 05 segundos nesta
posição. (10% da nota)
4) Defina o ciclo ativo do módulo PWM para 500µs
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%.
Isto ajustará a flange do servomotor para a posição de,
aproximadamente, 0 graus. Aguarde 05 segundos nesta
posição. (10% da nota)
5) Após a realização das proposições anteriores, crie uma rotina
para movimentação periódica do braço do servomotor entre os
ângulos de 0 e 180 graus. Obs.: a movimentação da flange deve
ser suave, recomenda-se o incremento de ciclo ativo de ±5µs,
com um atraso de ajuste de 10ms. (35% da nota)
6) Com o emprego da Ferramenta Educacional BitDogLab, faça
um experimento com o código deste exercício utilizando o LED
RGB – GPIO 12. O que o discente observou no c

### ❗Requisitos para execução do projeto (Software)
- Compilador Arm gcc instalado
- PICO SDK intalado
- Visual Studio Code instalado
- Extensão do Respberry Pi Pico instalada
- Extensão do Wokwi Simulator instalada e configurada
- Extensões Cmake e Cmake tools instaladas 
- Serial monitor instalado no Visual Studio Code

### Instruções para a execução do projeto

1. Baixe o projeto na sua maquina atráves do cmd pelo comando: 
    ```bash 
    git clone https://github.com/Kuroikenshiga/Tarefa2AulaSincrona_06-02.git
2. Abra o Visual Studio Code.
3. No menu lateral esquerdo, encontre a extensão do Respberry Pi Pico e clique nela.
4. Selecione a opção "Import Project"
5. No campo "Location" clique no botão "Change" e selecione o projeto que você acabou de baixar na sua maquina.
6. Clique no botão "Import"
7. Após carregar todos os arquivos necessários, clique na opção "Compile" presente no menu inferior direito.

### [Vídeo de demonstração do projeto](https://youtu.be/0XgOc4uvvcU)