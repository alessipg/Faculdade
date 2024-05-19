package dao;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import entities.Curso;

public class CursoDAO {

	private Connection conn;
	
	public CursoDAO(Connection conn) {
		this.conn = conn;
	}
	
	public void cadastrar(Curso curso) throws SQLException {
		PreparedStatement st = null;
		
		try {
			st = conn.prepareStatement("insert into curso (nome, periodo, duracao) values (?, ?, ?)");
			
			st.setString(1, curso.getNome());
			st.setString(2, curso.getPeriodo());
			st.setInt(3, curso.getDuracao());
			
			st.executeUpdate();
		} finally {
			BancoDados.finalizarStatement(st);
			BancoDados.desconectar();
		}
	}
	
	public List<Curso> buscarTodos() throws SQLException {
		PreparedStatement st = null;
		ResultSet rs = null;
		
		try {
			st = conn.prepareStatement("select * from curso order by nome");
			
			rs = st.executeQuery();
			
			List<Curso> listaCursos = new ArrayList<>();
			
			while (rs.next()) {
				Curso curso = new Curso();
				
				curso.setCodigo(rs.getInt("codigo"));
				curso.setNome(rs.getString("nome"));
				curso.setPeriodo(rs.getString("periodo"));
				curso.setDuracao(rs.getInt("duracao"));
				
				listaCursos.add(curso);
			}
			return listaCursos;
		} finally {
			BancoDados.finalizarStatement(st);
			BancoDados.finalizarResultSet(rs);
			BancoDados.desconectar();
		}
	}
	
	public static void buscarTodosCursoTeste() throws SQLException, IOException {
		
		Connection conn = BancoDados.conectar();
		List<Curso> listaCursos = new CursoDAO(conn).buscarTodos();
		
		for(Curso curso : listaCursos) {
			
			System.out.println(curso.getCodigo() + " - " + curso.getNome() + " - " + curso.getPeriodo() + " - " + curso.getDuracao());
		}
	}
	public Curso buscarPorCodigo(int codigoCurso) throws SQLException {
		
		PreparedStatement st = null;
		ResultSet rs = null;
		
		try {
			st = conn.prepareStatement("select * from curso where codigo = ?");
			
			st.setInt(1, codigoCurso);
			
			rs = st.executeQuery();
			
			if(rs.next()) {
				Curso curso = new Curso();
				
				curso.setCodigo(rs.getInt("codigo"));
				curso.setNome(rs.getString("nome"));
				curso.setPeriodo(rs.getString("periodo"));
				curso.setDuracao(rs.getInt("duracao"));
				
				return curso;
			}
			return null;
		} finally {
		BancoDados.finalizarStatement(st);
		BancoDados.finalizarResultSet(rs);
		BancoDados.desconectar();
		}
	}
	
	public void atualizar(Curso curso) throws SQLException {
		PreparedStatement st = null;
		
		try {
			
			st = conn.prepareStatement("update curso set periodo = ?, duracao = ? where codigo = ?");
			
			st.setString(1, curso.getPeriodo());
			st.setInt(2, curso.getDuracao());
			st.setInt(3, curso.getCodigo());
			
			st.executeUpdate();
		} finally {
			BancoDados.finalizarStatement(st);
			BancoDados.desconectar();
		}
	}
	
	public int excluir(int codigo) {
		return 0;
	}
}
