package service;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.List;

import dao.BancoDados;
import dao.CursoDAO;
import entities.Curso;

public class CursoService {
	
	Connection conn = null;

	public List<Curso> buscarTodos() throws SQLException, IOException {
			conn = BancoDados.conectar();
			return new CursoDAO(conn).buscarTodos();
	}
	
	public Curso buscarPorCodigo(int codigoCurso) throws SQLException, IOException {
		
		conn = BancoDados.conectar();
		return new CursoDAO(conn).buscarPorCodigo(codigoCurso);
		
		
	}

}
