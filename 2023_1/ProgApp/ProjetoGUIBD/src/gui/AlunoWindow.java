package gui;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.sql.SQLException;
import java.text.ParseException;
import java.util.List;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFormattedTextField;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JSpinner;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableModel;
import javax.swing.text.MaskFormatter;

import entities.Aluno;
import entities.Curso;
import service.AlunoService;
import service.CursoService;


public class AlunoWindow extends JFrame {
	private JTextField txtRegistroacademico;
	private JTextField txtNome;
	private JFormattedTextField txtDataingresso;
	private JPanel painelAlunos;
	private JButton btnCadastrar;
	private JButton btnLimparCampos;
	private JSeparator separator;
	private JTextField txtCoeficiente;
	private JLabel lblCoeficiente;
	private JSpinner spPeriodo;
	private JLabel lblPeriodo;
	private JLabel lblDataDeIngresso;
	private JComboBox cbCurso;
	private JLabel lblCurso;
	private JPanel painelSexo;
	private JLabel lblNome;
	private JLabel lblRegistroAcadmico;
	private JPanel contentPane;
	private JMenuBar menuBar;
	private JTable tblAlunos;
	private JScrollPane scrollPane;
	private MaskFormatter mascaraData;
	private ButtonGroup btnGroupSexo;
	private CursoService cursoService;
	private AlunoService alunoService;
	private JRadioButton rbNaoInformar;
	private JRadioButton rbFeminino;
	private JRadioButton rbMasculino;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					AlunoWindow frame = new AlunoWindow();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 * @throws IOException 
	 * @throws SQLException 
	 */
	public AlunoWindow() throws SQLException, IOException {
		this.criarMascaraData();
		this.initComponents();

		this.cursoService = new CursoService();
		this.alunoService = new AlunoService();
		
		this.buscarCursos();
		this.buscarAlunos();
		this.limparComponentes();
	}
	
	private void limparComponentes() {
		this.txtRegistroacademico.setText("");
		this.txtNome.setText("");
		this.rbMasculino.setSelected(true);
		this.cbCurso.setSelectedIndex(0);
		this.txtDataingresso.setText("");
		this.spPeriodo.setValue(1);
		this.txtCoeficiente.setText("");
	}
	
	public void buscarAlunos() throws SQLException, IOException {
		DefaultTableModel modelo = (DefaultTableModel) tblAlunos.getModel();
		modelo.fireTableDataChanged();
		modelo.setRowCount(0);
		
		List<Aluno> alunos = this.alunoService.buscarTodos();
		
		if(alunos == null) return;
		for (Aluno aluno : alunos) {
			modelo.addRow(new Object[] {
					aluno.getRegistroAcademico(),
					aluno.getNome(),
					aluno.getSexo(),
					aluno.getCurso().getNome(),
					aluno.getDataIngresso(),
					aluno.getPeriodo(),
					aluno.getCoeficiente()
			});
		}
	}
	
	private void buscarCursos() throws SQLException, IOException {
		List<Curso> cursos = this.cursoService.buscarTodos();
		
		for (Curso curso : cursos) {
			
			this.cbCurso.addItem(curso);
		}
	}
	
	public void criarMascaraData() {
		try {
			this.mascaraData = new MaskFormatter("##/####");
		} catch(ParseException e) {
			System.out.println("ERRO: " + e.getMessage());
		}
	}
	public void initComponents() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 868, 580);
		
		menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		JMenu mnArquivo = new JMenu("Arquivo");
		menuBar.add(mnArquivo);
		
		JMenuItem mntmSair = new JMenuItem("Sair");
		mntmSair.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		mnArquivo.add(mntmSair);
		
		JMenu mnAjuda = new JMenu("Ajuda");
		menuBar.add(mnAjuda);
		
		JMenuItem mntmSobre = new JMenuItem("Sobre");
		mntmSobre.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new SobreWindow().setVisible(true);
			}
		});
		mnAjuda.add(mntmSobre);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		lblRegistroAcadmico = new JLabel("Registro Acadêmico");
		lblRegistroAcadmico.setBounds(12, 12, 160, 15);
		contentPane.add(lblRegistroAcadmico);
		
		txtRegistroacademico = new JTextField();
		txtRegistroacademico.setBounds(170, 10, 90, 19);
		contentPane.add(txtRegistroacademico);
		txtRegistroacademico.setColumns(10);
		
		lblNome = new JLabel("Nome");
		lblNome.setBounds(12, 53, 70, 15);
		contentPane.add(lblNome);
		
		txtNome = new JTextField();
		txtNome.setBounds(72, 51, 538, 19);
		contentPane.add(txtNome);
		txtNome.setColumns(10);
		
		painelSexo = new JPanel();
		painelSexo.setBorder(new TitledBorder(null, "Sexo", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		painelSexo.setBounds(12, 80, 160, 128);
		contentPane.add(painelSexo);
		painelSexo.setLayout(null);
		
		rbMasculino = new JRadioButton("Masculino");
		rbMasculino.setBounds(8, 23, 149, 23);
		painelSexo.add(rbMasculino);
		
		rbFeminino = new JRadioButton("Feminino");
		rbFeminino.setBounds(8, 50, 149, 23);
		painelSexo.add(rbFeminino);
		
		rbNaoInformar = new JRadioButton("Não Informar");
		rbNaoInformar.setBounds(8, 77, 149, 23);
		painelSexo.add(rbNaoInformar);
		
		btnGroupSexo = new ButtonGroup();
		btnGroupSexo.add(rbMasculino);
		btnGroupSexo.add(rbFeminino);
		btnGroupSexo.add(rbNaoInformar);
		
		lblCurso = new JLabel("Curso");
		lblCurso.setBounds(209, 95, 70, 15);
		contentPane.add(lblCurso);
		
		cbCurso = new JComboBox();
		cbCurso.setBounds(273, 90, 365, 24);
		contentPane.add(cbCurso);
		
		lblDataDeIngresso = new JLabel("Data de Ingresso");
		lblDataDeIngresso.setBounds(354, 14, 122, 15);
		contentPane.add(lblDataDeIngresso);
		
		txtDataingresso = new JFormattedTextField(mascaraData);
		txtDataingresso.setBounds(494, 12, 114, 19);
		contentPane.add(txtDataingresso);
		txtDataingresso.setColumns(10);
		
		lblPeriodo = new JLabel("Período");
		lblPeriodo.setBounds(699, 9, 70, 15);
		contentPane.add(lblPeriodo);
		
		spPeriodo = new JSpinner();
		spPeriodo.setBounds(787, 7, 69, 20);
		contentPane.add(spPeriodo);
		
		lblCoeficiente = new JLabel("Coeficiente");
		lblCoeficiente.setBounds(654, 51, 90, 15);
		contentPane.add(lblCoeficiente);
		
		txtCoeficiente = new JTextField();
		txtCoeficiente.setBounds(742, 49, 114, 19);
		contentPane.add(txtCoeficiente);
		txtCoeficiente.setColumns(10);
		
		separator = new JSeparator();
		separator.setBounds(12, 220, 844, 2);
		contentPane.add(separator);
		
		btnLimparCampos = new JButton("Limpar Campos");
		btnLimparCampos.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				limparComponentes();
			}
		});
		btnLimparCampos.setBounds(714, 183, 142, 25);
		contentPane.add(btnLimparCampos);
		
		btnCadastrar = new JButton("Cadastrar");
		btnCadastrar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
					btnCadastrarActionPerformed();
			}
		});
		btnCadastrar.setBounds(585, 183, 117, 25);
		contentPane.add(btnCadastrar);
		
		painelAlunos = new JPanel();
		painelAlunos.setBorder(new TitledBorder(null, "Alunos", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		painelAlunos.setBounds(22, 234, 823, 287);
		contentPane.add(painelAlunos);
		painelAlunos.setLayout(null);
		
		scrollPane = new JScrollPane();
		scrollPane.setBounds(12, 12, 811, 263);
		painelAlunos.add(scrollPane);
		
		tblAlunos = new JTable();
		scrollPane.setViewportView(tblAlunos);
		tblAlunos.setModel(new DefaultTableModel(
			new Object[][] {
			},
			new String[] {
					"RA", "Nome", "Sexo", "Curso", "Data de Insercao", "Periodo", "Coeficiente"
			}
		));
	}

	protected void btnCadastrarActionPerformed() {
		 try {
		Aluno aluno = new Aluno();
		 aluno.setRegistroAcademico(Integer.parseInt(this.txtRegistroacademico.getText()));
		 aluno.setNome(this.txtNome.getText());
		 aluno.setSexo(verificarSelecaoRadioButtonSexo());
		 aluno.setCurso((Curso) this.cbCurso.getSelectedItem());
		 aluno.setDataIngresso(this.txtDataingresso.getText());
		 aluno.setPeriodo(Integer.parseInt(this.spPeriodo.getValue().toString()));
		 aluno.setCoeficiente(Double.parseDouble(this.txtCoeficiente.getText()));
		 System.out.println(aluno.getCurso().getNome());
		
			this.alunoService.cadastrar(aluno);

			 this.buscarAlunos();
			 
			 JOptionPane.showMessageDialog(null, "Aluno cadastrado com sucesso", "Cadastro Aluno", JOptionPane.INFORMATION_MESSAGE);
		} catch (SQLException | IOException e) {
			JOptionPane.showMessageDialog(null, "Erro ao cadastrar um novo aluno.","Cadastro Aluno", JOptionPane.ERROR_MESSAGE);

		}
	}
	
	private String verificarSelecaoRadioButtonSexo() {
		if(this.rbMasculino.isSelected()) {
			return this.rbMasculino.getText();
		} else if(this.rbFeminino.isSelected()) {
			return this.rbFeminino.getText();
		} else {
			return this.rbNaoInformar.getText();
		}
	}
}
