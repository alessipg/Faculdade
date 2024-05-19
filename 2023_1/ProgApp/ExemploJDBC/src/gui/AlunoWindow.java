package gui;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.FlowLayout;
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
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JSpinner;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableModel;
import javax.swing.text.MaskFormatter;

import entities.Aluno;
import entities.Curso;
import service.AlunoService;
import service.CursoService;

public class AlunoWindow extends JFrame {

	private JPanel contentPane;
	private JTextField txtRegistroAcademico;
	private JTextField txtNome;
	private JFormattedTextField txtDataingresso;
	private JTextField txtCoeficiente;
	private JMenuBar menuBar;
	private JMenu mnArquivo;
	private JMenuItem mntmSair;
	private JMenu mnAjuda;
	private JMenuItem mntmSobre;
	private JLabel lblregistroacademico;
	private JLabel lblNome;
	private JPanel painelSexo;
	private FlowLayout flowLayout;
	private JRadioButton rbMasculino;
	private JRadioButton rbFeminino;
	private JRadioButton rbNaoInformar;
	private JLabel lblCurso;
	private JComboBox cbCurso;
	private JLabel lblDataDeIngresso;
	private JLabel lblPerodo;
	private JSpinner spPeriodo;
	private JLabel lblCoeficiente;
	private JSeparator separator;
	private JButton btnCadastrar;
	private JButton btnLimparCampos;
	private MaskFormatter mascaraData;
	private ButtonGroup btnGroupSexo;
	private CursoService cursoService;
	private JPanel painelAlunos;
	private JTable tblAlunos;
	private JScrollPane scrollPane;
	private AlunoService alunoService;
	
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
		this.txtRegistroAcademico.setText("");
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
		for(Aluno aluno : alunos) {
			modelo.addRow(new Object[] {
					aluno.getRegistroAcademico(), aluno.getNome(), aluno.getSexo(), aluno.getCurso().getNome(), aluno.getDataIngresso(), aluno.getPeriodo(), aluno.getCoeficiente()});
			}
		}

	private void buscarCursos() {
		List<Curso> cursos = this.cursoService.buscarTodos();
		for(Curso curso : cursos) {
			this.cbCurso.addItem(curso);
		}
	}
	private void criarMascaraData() {
		try {
			this.mascaraData = new MaskFormatter("##/##/####");
			
		} catch (ParseException e) {
			System.out.println("ERRO: " + e.getMessage());
		}
	}
	
	public void initComponents() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 779, 567);
		
		menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		mnArquivo = new JMenu("Arquivo");
		menuBar.add(mnArquivo);
		
		mntmSair = new JMenuItem("Sair");
		mntmSair.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		mnArquivo.add(mntmSair);
		
		mnAjuda = new JMenu("Ajuda");
		menuBar.add(mnAjuda);
		
		mntmSobre = new JMenuItem("Sobre");
		mntmSobre.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			
				new SobreWindow().setVisible(true);
			}
		});
		mnAjuda.add(mntmSobre);
		contentPane = new JPanel();
		contentPane.setBackground(new Color(153, 193, 241));
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		lblregistroacademico = new JLabel("Registro Acadêmico");
		lblregistroacademico.setBounds(12, 14, 198, 15);
		contentPane.add(lblregistroacademico);
		
		txtRegistroAcademico = new JTextField();
		txtRegistroAcademico.setBounds(163, 12, 114, 19);
		contentPane.add(txtRegistroAcademico);
		txtRegistroAcademico.setColumns(10);
		
		lblNome = new JLabel("Nome");
		lblNome.setBounds(12, 41, 70, 15);
		contentPane.add(lblNome);
		
		txtNome = new JTextField();
		txtNome.setBounds(66, 39, 688, 19);
		contentPane.add(txtNome);
		txtNome.setColumns(10);
		
		painelSexo = new JPanel();
		painelSexo.setBorder(new TitledBorder(null, "Sexo", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		flowLayout = (FlowLayout) painelSexo.getLayout();
		flowLayout.setAlignment(FlowLayout.LEFT);
		painelSexo.setToolTipText("");
		painelSexo.setBounds(22, 90, 184, 124);
		contentPane.add(painelSexo);
		
		rbMasculino = new JRadioButton("Masculino");
		painelSexo.add(rbMasculino);
		
		rbFeminino = new JRadioButton("Feminino");
		rbFeminino.setHorizontalAlignment(SwingConstants.LEFT);
		painelSexo.add(rbFeminino);
		
		rbNaoInformar = new JRadioButton("Não Informar");
		painelSexo.add(rbNaoInformar);
		
		btnGroupSexo = new ButtonGroup();
		btnGroupSexo.add(rbMasculino);
		btnGroupSexo.add(rbFeminino);
		btnGroupSexo.add(rbNaoInformar);
		lblCurso = new JLabel("Curso");
		lblCurso.setBounds(331, 90, 70, 15);
		contentPane.add(lblCurso);
		
		cbCurso = new JComboBox();
		cbCurso.setBounds(396, 85, 358, 24);
		contentPane.add(cbCurso);
		
		lblDataDeIngresso = new JLabel("Data de Ingresso");
		lblDataDeIngresso.setBounds(331, 141, 151, 15);
		contentPane.add(lblDataDeIngresso);
		
		txtDataingresso = new JFormattedTextField(mascaraData);
		txtDataingresso.setBounds(473, 139, 114, 19);
		contentPane.add(txtDataingresso);
		txtDataingresso.setColumns(10);
		
		lblPerodo = new JLabel("Período");
		lblPerodo.setBounds(626, 141, 70, 15);
		contentPane.add(lblPerodo);
		
		spPeriodo = new JSpinner();
		spPeriodo.setBounds(690, 139, 59, 20);
		contentPane.add(spPeriodo);
		
		lblCoeficiente = new JLabel("Coeficiente");
		lblCoeficiente.setBounds(331, 188, 99, 15);
		contentPane.add(lblCoeficiente);
		
		txtCoeficiente = new JTextField();
		txtCoeficiente.setBounds(427, 186, 114, 19);
		contentPane.add(txtCoeficiente);
		txtCoeficiente.setColumns(10);
		
		separator = new JSeparator();
		separator.setBounds(12, 226, 760, 2);
		contentPane.add(separator);
		
		btnCadastrar = new JButton("Cadastrar");
		btnCadastrar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					btnCadastrarActionPerformed();
				} catch(SQLException | IOException er) {
					er.getMessage();
				}
			}
		});
		btnCadastrar.setBounds(470, 240, 117, 25);
		contentPane.add(btnCadastrar);
		
		btnLimparCampos = new JButton("Limpar Campos");
		btnLimparCampos.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				limparComponentes();
			}
		});
		btnLimparCampos.setBounds(602, 240, 147, 25);
		contentPane.add(btnLimparCampos);
		
		painelAlunos = new JPanel();
		painelAlunos.setBounds(12, 270, 755, 238);
		contentPane.add(painelAlunos);
		painelAlunos.setLayout(null);
		
		scrollPane = new JScrollPane();
		scrollPane.setBounds(12, 5, 731, 422);
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

	private void btnCadastrarActionPerformed() throws SQLException, IOException {
		Aluno aluno = new Aluno();
		aluno.setNome(this.txtNome.getText());
		aluno.setSexo(verificarSelecaoRadioButtonSexo());
		aluno.setCurso((Curso) this.cbCurso.getSelectedItem());
		aluno.setDataIngresso(this.txtDataingresso.getText());
		aluno.setPeriodo(Integer.parseInt(this.spPeriodo.getValue().toString()));
		aluno.setCoeficiente(Double.parseDouble(this.txtCoeficiente.getText()));
		aluno.toString();
		this.alunoService.cadastrar(aluno);
		this.buscarAlunos();
		
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
