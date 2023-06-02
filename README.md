# Edge-Computing-and-Computer-Sytems---Global-Solution

Integrantes:

RM 99389 - Victor Flávio Demarchi Viana
RM 551117 - Lorenzo Gomes Andreata
RM 550695 - Gabriel Ferla
RM 97888 - Vinícius Almeida Bernardino de Souza
RM 98827 - André Coelho Solér

Conceito:

Se trata de um dispositivo que serve de extensão para uma IA Generativa especializada em plantas, dessa forma ela pode coletar dados precisos do ambiente e fornecer informações ainda mais precisas para o usuário que desejar utilizar a Inteligência Artificial, e funcionará utilizando 3 sensores (umidade do solo, temperatura e luminosidade) e enviará, através do Arduino, as informações coletadas por estes sensores utilizando de um módulo Wifi serial (em teoria) pelo Wifi da pessoa e, dessa forma, a Inteligência Artificial poderia coletar essas informações de qualquer dispositivo conectado na mesma rede que o Arduino, e também mostrar essas informações num display LCD.

Requisitos:

1	Arduino Uno R3
1 cabo USB
2 Protoboards
1	Fotorresistor
1	Sensor de temperatura [TMP36]
1	Sensor de umidade do solo
1	10 kΩ Resistor
1	LCD 16 x 2
1	220 Ω Resistor
1	Diodo
1	Botão (simulando um módulo Wifi serial ESP8266)
1	1 kΩ Resistor
10 jumpers pretos
10 jumpers vermelhos
4 jumpers verdes
1 jumper azul

Dependências:

Conexão com um computador com o Arduino IDE instalado (configurações iniciais), Obs. Não é necessária configuração inicial caso seja feita simulação com botão
Fonte de energia (bateria ou USB)
Conexão com a internet (se for simulado utilizando o botão, não é necessária conexão com a internet)

Instruções:

Após receber o dispositivo na sua casa, ele teria de ser conectado a um computador e, no programa Arduino IDE, enviar um código específico, alterando as varáveis nome e senha para o nome do wifi e senha do wifi, respectivamente, e finalizar a etapa indo na aba Tools e selecionando o Arduino e a porta correspondentes ao Arduino que o usuário possui e em seguida clicar em Sketch e Upload. (essa parte não funciona na demonstração por não conter o componente Wifi serial module ESP8266, responsável pela conexão com a internet, portanto ignorar esta etapa).

Em seguida, montar o esquema e alimentar o Arduino com alguma fonte de energia de até 9 Volts, em seguida o Arduino irá automaticamente conectar na rede com o nome mencionado com a senha mencionada (ignorar essa parte caso esteja simulando com o botão), mostrando no display LCD na primeira linha os valores dos sensores (umidade em porcentagem ou "%", temperatura em graus celsius ou "C", luminosidade em kilolux ou "klux"), e na segunda linha o status de conexão do arduino e a rede (e caso esteja utilizando o botão, clicar nele irá mudar o estado de conexão entre "Não conectado", "Conectando" e "Conectado").

Dependendo do valor que for registrado pelos sensores, a Inteligência Artificial pode utilizar como base para se tomar medidas em favor do cuidado ideal com as plantas que o usuário possui e, dessa forma, aumentar significantemente as chances de sucesso em cuidar da planta até onde o usuário desejar.

Informações relevantes:

Não é possível utilizar um módulo wifi serial ESP8266 sem modificar ambos o código e a esquemática, portanto a única utilidade real na simulação do Tinkercad é a leitura da primeira linha do display LCD, onde coleta informações do ambiente através dos sensores e as mostra no formato explicado acima, a segunda linha do LCD é meramente teórica e ilustrativa sobre como o projeto final funcionaria.

Na lista de componentes são citados jumpers de cores específicas em quantidades específicas, porém podem ser usados jumpers de qualquer cor para conectar qualquer parte do circuito, desde que o início e o final estejam conectados corretamente como indicados na esquemática, as cores servem apenas para organização.
