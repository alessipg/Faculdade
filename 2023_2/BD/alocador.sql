CREATE DATABASE ALOCADOR;
USE ALOCADOR;
CREATE TABLE DEPARTAMENTO (
    IDDepartamento INT PRIMARY KEY,
    Nome VARCHAR(255),
    Sigla VARCHAR(10)
);

-- Criação da tabela CURSO
CREATE TABLE CURSO (
    IDCurso INT PRIMARY KEY,
    Nome VARCHAR(255),
    Sigla VARCHAR(10),
    CargaHoraria INT,
    IDDepartamento INT,
    FOREIGN KEY (IDDepartamento) REFERENCES DEPARTAMENTO (IDDepartamento)
);

-- Criação da tabela EQUIPAMENTO
CREATE TABLE EQUIPAMENTO (
    IDEquipamento INT PRIMARY KEY,
    Nome VARCHAR(255),
    QuantExistente INT
);

-- Criação da tabela SALAEQUIPAMENTO
CREATE TABLE SALAEQUIPAMENTO (
    IDSala INT,
    IDEquipamento INT,
    QuantAlocada INT,
    PRIMARY KEY (IDSala, IDEquipamento),
    FOREIGN KEY (IDSala) REFERENCES SALA (IDSala),
    FOREIGN KEY (IDEquipamento) REFERENCES EQUIPAMENTO (IDEquipamento)
);

-- Criação da tabela SALA
CREATE TABLE SALA (
    IDSala INT PRIMARY KEY,
    Sigla VARCHAR(10),
    TipoSala VARCHAR(20),
    Capacidade INT,
    IDDepartamento INT,
    FOREIGN KEY (IDDepartamento) REFERENCES DEPARTAMENTO (IDDepartamento)
);

-- Criação da tabela FUNCIONARIO
CREATE TABLE FUNCIONARIO (
    IDFuncionario INT PRIMARY KEY,
    Nome VARCHAR(255),
    CPF VARCHAR(14),
    Email VARCHAR(255),
    DataAdmissao DATE,
    DataDemissao DATE,
    Salario DECIMAL(10, 2),
    IDEndereco INT,
    IDDepartamento INT,
    FOREIGN KEY (IDEndereco) REFERENCES ENDERECO (IDEndereco),
    FOREIGN KEY (IDDepartamento) REFERENCES DEPARTAMENTO (IDDepartamento)
);

-- Criação da tabela ENDERECO
CREATE TABLE ENDERECO (
    IDEndereco INT PRIMARY KEY,
    UF VARCHAR(2),
    Cidade VARCHAR(255),
    Bairro VARCHAR(255),
    Rua VARCHAR(255),
    CEP VARCHAR(10)
);

-- Criação da tabela EVENTO
CREATE TABLE EVENTO (
    IDEvento INT PRIMARY KEY,
    Nome VARCHAR(255),
    Descricao TEXT,
    Sigla VARCHAR(10)
);

-- Criação da tabela ALOCACAO
CREATE TABLE ALOCACAO (
    IDAlocacao INT PRIMARY KEY,
    IDEvento INT,
    IDSala INT,
    DataAlocacao DATE,
    DataInicioReserva DATE,
    DataTerminoReserva DATE,
    HoraInicioReserva TIME,
    HoraTerminoReserva TIME,
    DiaSemana VARCHAR(10),
    IDFuncionario INT,
    PRIMARY KEY (IDAlocacao, IDEvento, IDSala)
    FOREIGN KEY (IDFuncionario) REFERENCES FUNCIONARIO (IDFuncionario),
    FOREIGN KEY (IDEvento) REFERENCES EVENTO (IDEvento),
    FOREIGN KEY (IDSala) REFERENCES SALA (IDSala)
);
