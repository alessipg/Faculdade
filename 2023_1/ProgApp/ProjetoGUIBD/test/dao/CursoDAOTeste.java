package dao;

import java.io.IOException;
import java.sql.SQLException;

public class CursoDAOTeste {

	public static void cadastrarCursoTeste() throws SQLException, IOException {
//		Curso curso = new Curso();
//		
//		curso.setNome("Bacharelado em Ciência da Computação");
//		curso.setPeriodo("Integral");
//		curso.setDuracao(8);
//		Connection conn = BancoDados.conectar();
//		new CursoDAO(conn).cadastrar(curso);
//		
//		
//		curso.setNome("Análise e Desenvolvimento de Sistemas");
//		curso.setPeriodo("Noturno");
//		curso.setDuracao(6);
//		
//		conn = BancoDados.conectar();
//		new CursoDAO(conn).cadastrar(curso);
//		
//		curso.setNome("Engenharia Mecânica");
//		curso.setPeriodo("Integral");
//		curso.setDuracao(10);
//		conn = BancoDados.conectar();
//		new CursoDAO(conn).cadastrar(curso);
//		
//		curso.setNome("Licenciatura em Ciências Biológicas");
//		curso.setPeriodo("Integral");
//		curso.setDuracao(8);
//		
//		conn = BancoDados.conectar();
//		new CursoDAO(conn).cadastrar(curso);
//		
//		System.out.println("Cadastro");
	}
	
	public static void main(String[] args) {
		try {
			//CursoDAOTeste.cadastrarCursoTeste();
			CursoDAO.buscarTodosCursosTeste();
		} catch (SQLException | IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
