package dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import entities.Aluno;
import entities.Curso;

public class AlunoDAO {

	private Connection conn;
	
	public AlunoDAO(Connection conn) {
		this.conn = conn;
	}
	
	public void cadastrar(Aluno aluno) throws SQLException {
		PreparedStatement st = null;
		System.out.println("entrou dao");
		
		try {
			st = conn.prepareStatement("insert into aluno (nome, sexo, codigo_curso, data_insercao, periodo, coeficiente) values (?, ?, ?, ?, ?, ?)");
			System.out.println("entrou try");
			st.setString(1, aluno.getNome());
			st.setString(2, aluno.getSexo());
			//st.setInt(2, aluno.getCurso().getCodigo());
			st.setInt(3, 1);
			st.setString(4, aluno.getDataIngresso());
			st.setInt(5, aluno.getPeriodo());
			st.setDouble(6, aluno.getCoeficiente());
			aluno.toString();
			
			st.executeUpdate();
			
		} finally {
			System.out.println("Entrou finally");
			BancoDados.finalizarStatement(st);
			BancoDados.desconectar();
		}
	}
	
	public List<Aluno> buscarTodos() throws SQLException {
		PreparedStatement st = null;
		ResultSet rs = null;
		
		try {
			st = conn.prepareStatement("select * from aluno order by nome");
			
			rs = st.executeQuery();
			
			List<Aluno> listaAlunos = new ArrayList<>();
			
			while(rs.next()) {
				Aluno aluno = new Aluno();

				
				aluno.setRegistroAcademico(rs.getInt("registro_academico"));
				aluno.setNome(rs.getString("nome"));
				aluno.setSexo(rs.getString("sexo"));
				aluno.setDataIngresso(rs.getString("data_insercao"));
				aluno.setPeriodo(rs.getInt("periodo"));
				aluno.setCoeficiente(rs.getDouble("coeficiente"));
				aluno.getCurso().setCodigo(rs.getInt("codigo_curso"));
				System.out.println(aluno.getCurso().getCodigo());
				listaAlunos.add(aluno);
			}
			return listaAlunos;
		} finally {
			BancoDados.finalizarStatement(st);
			BancoDados.finalizarResultSet(rs);
			BancoDados.desconectar();
		}
	}
	
	public Aluno buscarPorRA(int ra) throws SQLException {
		PreparedStatement st = null;
		ResultSet rs = null;
		
		try {
			st = conn.prepareStatement("select * from aluno where registro_academico = ?");
			
			st.setInt(1, ra);
			
			rs = st.executeQuery();
			
			if(rs.next()) {
				Aluno aluno = new Aluno();

				
				aluno.setRegistroAcademico(rs.getInt("registro_academico"));
				aluno.setNome(rs.getString("nome"));
				aluno.setPeriodo(rs.getInt("periodo"));
				aluno.setCoeficiente(rs.getDouble("coeficiente"));
				aluno.getCurso().setCodigo(rs.getInt("codigo_curso"));
				
				return aluno;
			}
			return null;
		} finally {
		BancoDados.finalizarStatement(st);
		BancoDados.finalizarResultSet(rs);
		BancoDados.desconectar();
		}
	}
	
	public void atualizar(Aluno aluno) {
		
	}
	
	public int excluir(int ra) {
		return 0;
	}
}
