package arquivos;

import java.io.File;
import java.io.IOException;

public class ExemplosArquivos {
public static void main(String[] args) {
File file = new File("/home/gabriel/Documents/Dev/Java/Arquivos/src/arquivos/ManipulacaoAquivo.java");
	String nomeArquivo = file.getName();
	String diretorioArquivo = file.getPath();
	System.out.println(nomeArquivo);
	System.out.println(diretorioArquivo);
	
	File sourceFile = new File("/home/gabriel/Documents/Dev/Java/Arquivos/src/arquivos/ManipulacaoArquivo.java");
	File destinationFile = new File("/home/gabriel/Documents/Dev/Java/Arquivos/src/arquivos/ExemplosArquivos.java");
	
	if(sourceFile.renameTo(destinationFile))
		System.out.println("Arquivo renomeado com sucesso");
	else
		System.out.println("Erro ao renomear o arquivo");
	
	System.out.println(destinationFile.length() + " bytes.");
	
	try {
	File teste = new File("test.txt");
	teste.createNewFile();
	teste.delete();
	} catch (IOException e) {
		System.out.println("Erro: " + e.getMessage());
	}
	File diretorio = new File("/home/gabriel/Documents/Dev/Java/");
	String [] tree = diretorio.list();
	
	for (String arquivo: tree) {
		System.out.println(arquivo);
	}
	}
}
