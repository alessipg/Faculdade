package arquivos;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;

public class FileChooserTeste {
    public static void main(String[] args) {
        // Solicita a inserção da palavra
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite uma palavra: ");
        String palavra = scanner.nextLine();
        
        // Abre o FileChooser para salvar o arquivo
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setDialogTitle("Salvar arquivo");
        
        // Define as extensões permitidas
        FileNameExtensionFilter filter = new FileNameExtensionFilter("Arquivos de texto (.txt), PDF (.), Documentospdf (.x)","txt", "pdf", "docx");
        fileChooser.setFileFilter(filter);
        
        // Exibe o diálogo de salvamento
        int resultado = fileChooser.showSaveDialog(null);
        
        if (resultado == JFileChooser.APPROVE_OPTION) {
            File arquivoSelecionado = fileChooser.getSelectedFile();
            
            // Obtém a extensão do arquivo selecionado
            String extensao = "";
            String nomeArquivo = arquivoSelecionado.getName();
            int index = nomeArquivo.lastIndexOf('.');
            if (index > 0 && index < nomeArquivo.length() - 1) {
                extensao = nomeArquivo.substring(index + 1).toLowerCase();
            }
            
            // Verifica a extensão e salva o arquivo
            if (extensao.equals("txt") || extensao.equals("pdf") || extensao.equals("docx")) {
                try {
                    FileOutputStream fos = new FileOutputStream(arquivoSelecionado);
                    byte[] conteudo = palavra.getBytes();
                    fos.write(conteudo);
                    fos.close();
                    System.out.println("Arquivo salvo com sucesso.");
                } catch (IOException e) {
                    System.out.println("Erro ao salvar o arquivo.");
                }
            } else {
                System.out.println("Formato de arquivo não suportado.");
            }
        } else {
            System.out.println("Operação cancelada pelo usuário.");
        }
        
        scanner.close();
    }
}
