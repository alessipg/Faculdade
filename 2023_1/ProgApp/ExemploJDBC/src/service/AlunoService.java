package service;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import dao.AlunoDAO;
import dao.BancoDados;
import entities.Aluno;
import entities.Curso;

public class AlunoService {
	public List<Aluno> alunos;
	
	public AlunoService() {
		
		//alunos = new ArrayList<Aluno>();
		//alunos.add(new Aluno(111111, "João da Silva", "Masculino", new Curso(2, "Tecnologia em Análise e Desenvolvimento de Sistemas", "Noturno", 6), "01/02/2020", 4, 0.58));
		//alunos.add(new Aluno(333333, "Ricardo Carvalho", "Masculino", new Curso(1, "Bacharelado em Ciências da Computação", "Integral", 8), "01/08/2020",6,0.83));
				
	}
	
	public List<Aluno> buscarTodos() throws SQLException, IOException{
		
		Connection conn = BancoDados.conectar();
		return new AlunoDAO(conn).buscarTodos();
	}
	
	public void cadastrar(Aluno aluno) throws SQLException, IOException {
		Connection conn = BancoDados.conectar();
		new AlunoDAO(conn).cadastrar(aluno);
		//this.alunos.add(aluno);
	}
}
