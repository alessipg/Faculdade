package dao;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

import entities.Aluno;
import entities.Curso;

public class AlunoDAOTeste {
	
	public static void cadastrarAlunoTeste() throws SQLException, IOException {
		Aluno aluno = new Aluno();
		Curso curso = new Curso();
		curso.setCodigo(2);
		aluno.setNome("João da Silva");
		aluno.setCurso(curso);
		aluno.setPeriodo(1);
		aluno.setCoeficiente(0.0);
		
		Connection conn = BancoDados.conectar();
		new AlunoDAO(conn).cadastrar(aluno);
		
		System.out.println("Cadastro efetuado com sucesso.");
	}
	
	public static void buscarTodos() throws SQLException, IOException {
		Connection conn = BancoDados.conectar();
		AlunoDAO aluno = new AlunoDAO(conn);
		for(Aluno a: aluno.buscarTodos()) {
			System.out.println(a.getRegistroAcademico() + " - " + a.getNome() + " - " + a.getCurso().getCodigo() + " - " + a.getPeriodo() + " - " + a.getCoeficiente());
		}
	}
	
public static void buscarPorCodigoTeste() throws SQLException, IOException {
		
		int raAluno = 1;
		
		Connection conn = BancoDados.conectar();
		Aluno aluno = new AlunoDAO(conn).buscarPorRA(raAluno);
		
		if (aluno != null) {
			System.out.println(aluno.getRegistroAcademico() + " - " + aluno.getNome() + " - " + aluno.getCurso().getCodigo() + " - " + aluno.getPeriodo() + " - " + aluno.getCoeficiente());
		} else {
			System.out.println("Registro acadêmico não encontrado.");
		}
	}
	
	public static void main(String[] args) {
		try {
			//AlunoDAOTeste.cadastrarAlunoTeste();
			AlunoDAOTeste.buscarTodos();
			AlunoDAOTeste.buscarPorCodigoTeste();
			AlunoDAOTeste.buscarPorCodigoTeste();
			
		} catch (SQLException | IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
