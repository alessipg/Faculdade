package service;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.List;

import dao.AlunoDAO;
import dao.BancoDados;
import dao.CursoDAO;
import entities.Aluno;
import entities.Curso;

public class AlunoService {

	Connection conn = null;
	public List<Aluno> buscarTodos() throws SQLException, IOException {
				conn = BancoDados.conectar();
				List<Aluno> alunos = new AlunoDAO(conn).buscarTodos();
				
				CursoService cursoService = new CursoService();
				for(Aluno aluno : alunos) {
					aluno.setCurso(cursoService.buscarPorCodigo(aluno.getCurso().getCodigo()));
				}
				return alunos;
			
	}

	public void cadastrar(Aluno aluno) throws SQLException, IOException {
			conn = BancoDados.conectar();
			new AlunoDAO(conn).cadastrar(aluno);
		
		
	}

}
