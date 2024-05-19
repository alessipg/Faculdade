package dao;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

public class BancoDadosTeste {
	public static void main(String[] args) {
		try {
			Connection conn = BancoDados.conectar();
			System.out.println("Conexão estabelecida.");
			
			BancoDados.desconectar();
			System.out.println("Conexão finalizada.");
			
			conn = BancoDados.conectar();
			System.out.println("Conexão estabelecida.");
			
			BancoDados.desconectar();
			System.out.println("Conexão finalizada.");
		} catch (SQLException | IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
