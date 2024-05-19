package lista01;

import java.util.ArrayList;
import java.util.List;

public class Cinema {
	private String nome;
	private List<Sessao> sessoes;
	public Cinema(String nome) {
		this.nome = nome;
		this.sessoes = new ArrayList<Sessao>();
	}
	
	public void venderIngresso() {
		
	}
	
}
