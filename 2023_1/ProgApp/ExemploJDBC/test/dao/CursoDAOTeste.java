package dao;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

import entities.Curso;

public class CursoDAOTeste {

	public static void cadastrarCursoTeste() throws SQLException, IOException {
		
		Curso curso = new Curso();
		curso.setNome("Tecnologia em Automação Industrial");
		curso.setPeriodo("Diurno");
		curso.setDuracao(6);
		
		Connection conn = BancoDados.conectar();
		new CursoDAO(conn).cadastrar(curso);
		
		System.out.println("Cadastro efetuado com sucesso.");
	}
	
	public static void buscarPorCodigoTeste() throws SQLException, IOException {
		
		int codigoCurso = 1;
		
		Connection conn = BancoDados.conectar();
		Curso curso = new CursoDAO(conn).buscarPorCodigo(codigoCurso);
		
		if (curso != null) {
			System.out.println(curso.getCodigo() + " - " + curso.getNome() + " - " + curso.getPeriodo() + " - " + curso.getDuracao());
		} else {
			System.out.println("Código não encontrado");
		}
	}
	
	public static void atualizarCursoTeste() throws SQLException, IOException {
		Curso curso = new Curso();
		curso.setCodigo(1);
		curso.setDuracao(5);
		curso.setPeriodo("Noturno");
		
		Connection conn = BancoDados.conectar();
		new CursoDAO(conn).atualizar(curso);
		
		System.out.println("Dados do curso atualizados com sucesso.");
	}
	public static void main(String[] args) {
		try {
			
			//CursoDAOTeste.cadastrarCursoTeste();
			//CursoDAOTeste.buscarPorCodigoTeste();
			//CursoDAOTeste.atualizarCursoTeste();
			CursoDAOTeste.buscarPorCodigoTeste();
		} catch (SQLException | IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
