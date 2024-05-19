package lista04;

import java.util.ArrayList;
import java.util.List;

public class Locadora {
	
	private	String nome;
	private List<Filme> filmes;
	private List<Cliente> clientes;
	public Locadora(String nome) {
		this.nome = nome;
		this.filmes = new ArrayList<Filme>();
		this.clientes = new ArrayList<Cliente>();
	}
	private void adicionarSocio(String nome, String dataNascimento, String fone, int cpf, String logradouro, int numero, String bairro, int cep,
			String cidade, String uF) {
		Socio s1 = new Socio(nome, dataNascimento, fone, cpf, logradouro, numero, bairro, cep, cidade, uF);
		clientes.add(s1);
		System.out.println("Cliente adicionado com sucesso.");
		System.out.println("===============================");
	}

	private void adicionarDependente(int cpfSocio, String nome, String dataNascimento, String fone, String logradouro, int numero, String bairro,
			int cep, String cidade, String uF) {
		for(Cliente socio : clientes) {
			if(cpfSocio == ((Socio) socio).getCpf()) {
				((Socio) socio).criarDependente(nome, dataNascimento, fone, logradouro, numero, bairro, cep, cidade, uF);
			}
		}
	}
	
 	private void realizarLocacao(String nome, int diaLocacao, String titulo) {
 		try {
 			for(Filme filme : filmes) {
 				if(filme.getTitulo() == titulo) {
 					filme.locarFilme(nome, diaLocacao);
 				}
 			}
 		} catch(FilmeIndisponivelException fie) {
 			System.out.println(fie.getMessage());
 		}
	}
 	
 	private void realizarDevolucao(String titulo, int diaDevolucao) {
 		try {
 			for(Filme filme : filmes) {
 				if(filme.getTitulo() == titulo) {
 					filme.devolverFilme(nome, diaDevolucao);
 				}
 			}
 		} catch(FilmeNaoLocadoException fnle) {
 			System.out.println(fnle.getMessage());
 		}
 		
 	}
	
}
