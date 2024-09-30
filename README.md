# Arquivo indexado
Trabalho da faculdade de arquivos indexados simulando um sistema de gerenciamento de hospital em C++

Escreva um programa para criar as seguintes estruturas que simularão arquivos indexados para uma aplicação de gerenciamento para um Hospital:

**Cidades:** código_cidade, nome, UF

**Especialidades Médicas:** código_especialidade, descrição

**Médicos:** código_médico, nome, codigo_especialidade, endereço, telefone, codigo_cidade

**Pacientes:** código_paciente, nome, endereço, codigo_cidade

**CID:** código_CID, descrição

**Medicamentos:** código_medicamento, descrição, quant_estoque, estoque_minimo, estoque_maximo, preço_unitario

**Consultas:** código_consulta, código_paciente, código_médico, data, horario, cod_CID, cod_medicamento, qtde_medicamento <br><br>

- [ ] 1) Escreva funções específicas para a leitura dos dados das estruturas: Cidades, Especialidades, CID, Medicamentos.

- [ ] 2) Escreva uma função para permitir a inclusão de novos registros na tabela de Médicos.

- [ ] 2.1) O programa deverá garantir que o código do médico a ser inserido não existe na tabela de Médicos.

- [ ] 2.2) Quando o usuário digitar o código da especialidade, o programa deverá buscar este código na tabela de Especialidades e exibir a descrição.

- [ ] 2.3) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e UF.

- [ ] 3) Escreva uma função para permitir a inclusão de novos registros na tabela de Pacientes.

- [ ] 3.1) O programa deverá garantir que o código do paciente a ser inserido não existe na tabela de pacientes.

- [ ] 3.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e UF.

- [ ] 4) Escreva uma função para permitir a exclusão de registros na tabela de Pacientes.

- [ ] 4.1) O programa não deverá permitir a exclusão de pacientes que possuam consultas agendadas

- [ ] 5) Escreva uma função para permitir a exclusão de registros na tabela de Médicos.

- [ ] 5.1) O programa não deverá permitir a exclusão de médicos que possuam registros na tabela de consultas 

- [ ] 6) Escreva uma função para permitir o agendamento de uma consulta.

- [ ] 6.1) Quando o usuário digitar o código do paciente, o programa deverá buscar este código na tabela de Pacientes e exibir o nome do paciente e o nome da cidade e UF.

- [ ] 6.2) Quando o usuário digitar o código do médico, o programa deverá buscar este código na tabela de Médicos e exibir o nome do médico e a descrição da especialidade.

- [ ] 6.3) Quando o usuário digitar o código CID, o programa deverá buscar este código na tabela de CID e exibir a descrição.

- [ ] 6.4) Quando o usuário digitar o código do medicamento, o programa deverá buscar este código na tabela de Medicamentos e exibir a descrição.

- [ ] 6.5) Quando o usuário digitar a qtde_medicamento, o programa deverá acessar a tabela de Medicamentos e verificar se a quantidade em estoque é suficiente para atender a quantidade receitada na consulta.

- [ ] 6.5.1) O programa não deverá permitir a digitação de uma quantidade maior do que a quantidade disponível em estoque.

- [ ] 6.6) A quantidade do medicamento receitada deverá ser subtraída da quantidade em estoque do medicamento.

- [ ] 7) Escreva uma função para permitir ao usuário consultar os dados de determinado medicamento.

- [ ] 7.1) Para cada medicamento consultado, exibir: todos os seus dados e o valor total em estoque do medicamento (quant_estoque * preço_unitário).

- [ ] 8) Escreva uma função para exibir todos os registros da tabela de medicamentos que estejam com a quantidade em estoque abaixo do estoque mínimo. 

- [ ] 8.1) As seguintes informações devem ser exibidas: código, descrição, qtde estoque, estoque máximo, qtde a ser comprada, valor da compra.

- [ ] 8.1.1) A quantidade a ser comprada é calculada subtraindo o estoque máximo da quantidade em estoque.

- [ ] 8.2) Ao final, a função deverá exibir o valor total ser comprado.

- [ ] 9) Escreva uma função para exibir o valor total arrecadado com todas as consultas, que deve ser calculado pelo valor de cada consulta (R$100) acrescido do valor do medicamento receitado para cada consulta.

- [ ] 9.1) O valor do medicamento receitado para cada consulta deve ser calculado multiplicando a quantidade de medicamento receitada pelo preço unitário do medicamento.

- [ ] 10) Escreva uma função para reorganização da tabela de Pacientes.


<br>**Todas as funções descritas acima deverão ser chamadas através de um menu de opções que será chamado a partir da função main().**

**Obs: não utilizar variáveis globais.**
