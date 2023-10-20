package covid19;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.sql.*;
import java.sql.Date;
import java.util.*;

import javax.swing.*;

import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;



public class main implements ActionListener {
	

	static String url = new String("jdbc:mysql://localhost");
	static String databaseName = new String("cs360_3660");
	static final int port = 3306;
	static String username = new String("root");
	static String password = new String ("");
	static Connection conn;
	static int __Access=-123;
	static ResultSet __currentUser;
	static JFrame loginPanel;
	static int i=0;
	static Date __Date;
	static int flag=0;
	static int datePlus=1;
	
	
	
	
	@SuppressWarnings("resource")
	public static boolean initialize() {
		Calendar calendar = Calendar.getInstance();
		java.util.Date currentDate = calendar.getTime();
		__Date = new java.sql.Date(currentDate.getTime());
		System.out.println("TRY: Executing initDB...");
		InputStream inputstream;
		try {
			System.out.println("\t TRY: Open File initDB.sql.");
			inputstream = new FileInputStream("C:\\Users\\giwrg\\Desktop\\tools\\HY360\\project\\covid19\\initDB.sql");
			System.out.println("\t PASS: File initDB.sql is open.");
			
		} catch (FileNotFoundException e) {
			System.out.println("\t FAIL: File initDB.sql did not found.");
			return false;
			//e.printStackTrace();
		}
		
		
		
		try {
			System.out.println("\t TRY: Establishing connection to "+databaseName+" database.");
			conn = DriverManager.getConnection(url+":"+port+"/"+databaseName+"?characterEncoding=UTF-8",username,password);
			System.out.println("\t PASS: Connection to DataBase "+databaseName+" established");
		} catch (SQLException e) {
			System.out.println("\t FAIL: Connection to DataBase "+databaseName+" did not established");
			//e.printStackTrace();
			return false;
		}
		
		
		
		try {
			System.out.println("\t TRY: Import data from initDB.sql");
			importSQL(conn, inputstream);
			System.out.println("\t PASS: Data imported from initDB.sql");
		} catch (SQLException e) {
			System.out.println("\t FAIL: Data did not imported from initDB.sql");
			e.printStackTrace();
			return false;
		}
		
		return true;
		
	}
	
	public static void clearText() {
		for(Component c : loginPanel.getContentPane().getComponents()) {
			if(c.getX()>300 && c.getX()<751 && (c instanceof JTextField)) {
				((JTextField)c).setText("");
			}
		}
	}
	
	public static  void importSQL(Connection conn, InputStream in) throws SQLException
	{
	    Scanner s = new Scanner(in);
	    s.useDelimiter("(;(\r)?\n)|(--\n)");
	    Statement st = null;
	    try
	    {
	        st = conn.createStatement();
	        while (s.hasNext())
	        {
	            String line = s.next();
	            if (line.startsWith("/*!") && line.endsWith("*/"))
	            {
	                int i = line.indexOf(' ');
	                line = line.substring(i + 1, line.length() - " */".length());
	            }

	            if (line.trim().length() > 0)
	            {
	                st.execute(line);
	            }
	        }
	    }
	    finally
	    {
	        if (st != null) st.close();
	    }
	    s.close();
	}	
	
	public static void BasicGUI(String givenID) {
		loginPanel.setTitle("Τμήμα Επειγόντων Περιστατικών CS360 - csd3660");
		loginPanel.getContentPane().removeAll();
		loginPanel.repaint();
		
		JLabel Access = new JLabel("Access: ");
		Access.setBounds(320, 200, 200, 20);
		JLabel SID = new JLabel("SID: ");
		SID.setBounds(320, 225, 200, 20);
		JLabel MID = new JLabel("MID: ");
		MID.setBounds(320, 250, 200, 20);
		JLabel AMKA = new JLabel("AMKA: ");
		AMKA.setBounds(320, 275, 200, 20);
		JLabel Name = new JLabel("Name: ");
		Name.setBounds(320, 300, 200, 20);
		JLabel Surname = new JLabel("Surname: ");
		Surname.setBounds(320, 325, 200, 20);
		JLabel Phone = new JLabel("Phone: ");
		Phone.setBounds(320, 350, 200, 20);
		JLabel Email = new JLabel("E-mail: ");
		Email.setBounds(320, 375, 200, 20);
		JLabel Birthday = new JLabel("Birthday: ");
		Birthday.setBounds(320, 400, 200, 20);
		JLabel Address = new JLabel("Address: ");
		Address.setBounds(320, 425, 200, 20);
		JLabel Years = new JLabel("Years: ");
		Years.setBounds(320, 450, 200, 20);
		JLabel Specialty = new JLabel("Specialty: ");
		Specialty.setBounds(320, 475, 200, 20);
		JLabel Notes = new JLabel("Notes: ");
		Notes.setBounds(320, 500, 200, 20);
		JLabel Chronic_Co = new JLabel("Chronic Co: ");
		Chronic_Co.setBounds(320, 525, 200, 20);
		JLabel Date = new JLabel("Date: ");
		Date.setBounds(320, 550, 200, 20);
		JLabel Type = new JLabel("Type: ");
		Type.setBounds(320, 575, 200, 20);
		JLabel Result = new JLabel("Result: ");
		Result.setBounds(320, 600, 200, 20);
		JLabel Insurance = new JLabel("Insurance: ");
		Insurance.setBounds(320, 625, 200, 20);
		JLabel MG = new JLabel("MG: ");
		MG.setBounds(320, 650, 200, 20);
		JLabel Usage = new JLabel("Usage: ");
		Usage.setBounds(320, 675, 200, 20);
		JLabel PID = new JLabel("PID: ");
		PID.setBounds(320, 700, 200, 20);
		JLabel _Date = new JLabel("Date: "+__Date);
		_Date.setBounds(10, 720, 100, 20);
		
		JTextField AccessT = new JTextField();
		AccessT.setBounds(400, 200, 300, 20);
		JTextField SIDT = new JTextField();
		SIDT.setBounds(400, 225, 300, 20);
		JTextField MIDT = new JTextField();
		MIDT.setBounds(400, 250, 300, 20);
		JTextField AMKAT = new JTextField();
		AMKAT.setBounds(400, 275, 300, 20);
		JTextField NameT = new JTextField();
		NameT.setBounds(400, 300, 300, 20);
		JTextField SurnameT = new JTextField();
		SurnameT.setBounds(400, 325, 300, 20);
		JTextField PhoneT = new JTextField();
		PhoneT.setBounds(400, 350, 300, 20);
		JTextField EmailT = new JTextField();
		EmailT.setBounds(400, 375, 300, 20);
		JTextField BirthdayT = new JTextField();
		BirthdayT.setBounds(400, 400, 300, 20);
		JTextField AddressT = new JTextField();
		AddressT.setBounds(400, 425, 300, 20);
		JTextField YearsT = new JTextField();
		YearsT.setBounds(400, 450, 300, 20);
		JTextField SpecialtyT = new JTextField();
		SpecialtyT.setBounds(400, 475, 300, 20);
		JTextField NotesT = new JTextField();
		NotesT.setBounds(400, 500, 300, 20);
		JTextField Chronic_CoT = new JTextField();
		Chronic_CoT.setBounds(400, 525, 300, 20);
		JTextField DateT = new JTextField();
		DateT.setBounds(400, 550, 300, 20);
		JTextField TypeT = new JTextField();
		TypeT.setBounds(400, 575, 300, 20);
		JTextField ResultT = new JTextField();
		ResultT.setBounds(400, 600, 300, 20);
		JTextField InsuranceT = new JTextField();
		InsuranceT.setBounds(400, 625, 300, 20);
		JTextField MGT = new JTextField();
		MGT.setBounds(400, 650, 300, 20);
		JTextField UsageT = new JTextField();
		UsageT.setBounds(400, 675, 300, 20);
		JTextField PIDT = new JTextField();
		PIDT.setBounds(400, 700, 300, 20);
		
		JLabel queryLabel = new JLabel("To DB: ");
		queryLabel.setBounds(10,5,50,15);
		
		loginPanel.add(queryLabel);
		JTextField queryText = new JTextField();
		queryText.setBounds(60,3,800,20);
		loginPanel.add(queryText);
		
		JButton queryButton = new JButton("Query DB");
		queryButton.setBounds(865, 3, 110, 20);
		loginPanel.add(queryButton);
		queryButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQuery(queryText.getText());
			}	
		});
		
		JButton InsertButton = new JButton("Update DB");
		InsertButton.setBounds(865, 25, 110, 20);
		loginPanel.add(InsertButton);
		InsertButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				InsertToDB(queryText.getText());
			}	
		});
		
		JButton viewMedicines = new JButton("View Medicines");
		viewMedicines.setBounds(825, 60, 150, 20);
		loginPanel.add(viewMedicines);
		viewMedicines.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `medicine`");
			}	
		});
		
		JButton viewDoctors = new JButton("View Doctors");
		viewDoctors.setBounds(825, 85, 150, 20);
		loginPanel.add(viewDoctors);
		viewDoctors.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `doctor`");
			}	
		});
		
		JButton viewNurse = new JButton("View Nurses");
		viewNurse.setBounds(825, 110, 150, 20);
		loginPanel.add(viewNurse);
		viewNurse.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `nurse`");
			}	
		});
		
		JButton viewPatients = new JButton("View Patients");
		viewPatients.setBounds(825, 135, 150, 20);
		loginPanel.add(viewPatients);
		viewPatients.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `patient`");
			}	
		});
		
		JButton viewStaff = new JButton("View Staff");
		viewStaff.setBounds(825, 160, 150, 20);
		loginPanel.add(viewStaff);
		viewStaff.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `staff`");
			}	
		});
		
		JButton viewPrescriptions = new JButton("View Prescriptions");
		viewPrescriptions.setBounds(825, 185, 150, 20);
		loginPanel.add(viewPrescriptions);
		viewPrescriptions.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `prescribe`");
			}	
		});
		
		JButton viewDuties = new JButton("View Duties");
		viewDuties.setBounds(825, 210, 150, 20);
		loginPanel.add(viewDuties);
		viewDuties.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `duty`");
			}	
		});
		
		JButton viewExams = new JButton("View Exams");
		viewExams.setBounds(825, 235, 150, 20);
		loginPanel.add(viewExams);
		viewExams.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `examines`");
			}	
		});
		
		
		JButton myMedicines = new JButton("View My Medicines");
		myMedicines.setBounds(800, 300, 180, 20);
		loginPanel.add(myMedicines);
		myMedicines.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `takes` WHERE amka='"+givenID+"'");
			}	
		});
		
		JButton myExaminations= new JButton("View My Examinations");
		myExaminations.setBounds(800, 325, 180, 20);
		loginPanel.add(myExaminations);
		myExaminations.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				askQueryToPop("SELECT * FROM `examines` WHERE amka='"+givenID+"'");
			}	
		});
		
		JButton myDuties= new JButton("View My Duties");
		myDuties.setBounds(800, 350, 180, 20);
		loginPanel.add(myDuties);
		myDuties.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					viewMyDuties(__currentUser.getString("SID"));
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
			}	
		});
		
		JButton myAttend= new JButton("View My Attend");
		myAttend.setBounds(800, 375, 180, 20);
		loginPanel.add(myAttend);
		myAttend.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					askQueryToPop("SELECT * FROM attend WHERE SID = '"+__currentUser.getInt("SID")+"'");
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
			}	
		});
		
		JButton userDuties= new JButton("View User Duties (SID)");
		userDuties.setBounds(800, 400, 180, 20);
		loginPanel.add(userDuties);
		userDuties.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
					viewMyDuties(SIDT.getText());
			}	
		});
		
		loginPanel.add(_Date);
		loginPanel.add(Access);
		loginPanel.add(SID);
		loginPanel.add(MID);
		loginPanel.add(AMKA);
		loginPanel.add(Name);
		loginPanel.add(Surname);
		loginPanel.add(Phone);
		loginPanel.add(Email);
		loginPanel.add(Birthday);
		loginPanel.add(Address);
		loginPanel.add(Years);
		loginPanel.add(Specialty);
		loginPanel.add(Notes);
		loginPanel.add(Chronic_Co);
		loginPanel.add(Date);
		loginPanel.add(Type);
		loginPanel.add(Result);
		loginPanel.add(Insurance);
		loginPanel.add(MG);
		loginPanel.add(Usage);
		loginPanel.add(PID);
		loginPanel.add(PIDT);
		loginPanel.add(AccessT);
		loginPanel.add(SIDT);
		loginPanel.add(MIDT);
		loginPanel.add(AMKAT);
		loginPanel.add(NameT);
		loginPanel.add(SurnameT);
		loginPanel.add(PhoneT);
		loginPanel.add(EmailT);
		loginPanel.add(BirthdayT);
		loginPanel.add(AddressT);
		loginPanel.add(YearsT);
		loginPanel.add(SpecialtyT);
		loginPanel.add(NotesT);
		loginPanel.add(Chronic_CoT);
		loginPanel.add(DateT);
		loginPanel.add(TypeT);
		loginPanel.add(ResultT);
		loginPanel.add(InsuranceT);
		loginPanel.add(MGT);
		loginPanel.add(UsageT);
		
		JButton genDuty = new JButton("Generate Duty");
		genDuty.setBounds(800, 450, 180, 20);
		loginPanel.add(genDuty);
		genDuty.addActionListener(new ActionListener() {
			@SuppressWarnings("deprecation")
			public void actionPerformed(ActionEvent e) {
				insidents();
				medicines();
				__Date.setDate(__Date.getDate()+1);
				_Date.setText("Date: "+__Date);
				newDuty();
			}
		});
		
		JButton monInsi = new JButton("Monthly Insidents");
		monInsi.setBounds(800, 500, 180, 20);
		loginPanel.add(monInsi);
		monInsi.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				viewMonInsidents();
			}
		});
		
		JButton monMed = new JButton("Monthly Prescriptions");
		monMed.setBounds(800, 525, 180, 20);
		loginPanel.add(monMed);
		monMed.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				viewMonMedicines();
			}
		});
		
		JButton covid = new JButton("COVID-19 Report");
		covid.setBounds(800, 600, 180, 20);
		loginPanel.add(covid);
		covid.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				viewCovid();
			}
		});
		
		
		
		JButton loadStaff = new JButton("Load Staff (SID)");
		loadStaff.setBounds(10, 500, 300, 25);
		loginPanel.add(loadStaff);
		loadStaff.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					Statement stmt = conn.createStatement();
					ResultSet rs = stmt.executeQuery("SELECT * FROM staff WHERE SID="+SIDT.getText());
					if(rs.next()) {
						clearText();
						SIDT.setText(rs.getString("SID"));
						AccessT.setText(rs.getString("Access"));
						NameT.setText(rs.getString("Name"));
						SurnameT.setText(rs.getString("SURNAME"));
						PhoneT.setText(rs.getString("PHONE"));
						EmailT.setText(rs.getString("EMAIL"));
						BirthdayT.setText(rs.getString("BIRTHDAY"));
						AddressT.setText(rs.getString("ADDRESS"));
						NotesT.setText(rs.getString("NOTES"));
					}
					else JOptionPane.showMessageDialog(null,"No Staff member with given SID","Info",JOptionPane.INFORMATION_MESSAGE);
					rs = stmt.executeQuery("SELECT * FROM doctor WHERE SID="+SIDT.getText());
					if(rs.next()) {
						SpecialtyT.setText(rs.getString("Specialty"));
						YearsT.setText(rs.getString("Years"));
					}
				}
				catch(Exception ex){
					
				}
				
			}
			
		});
		
		JButton loadExam = new JButton("Load Exam (Day,AMKA,Type)");
		loadExam.setBounds(10, 530, 300, 25);
		loginPanel.add(loadExam);
		loadExam.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					Statement stmt = conn.createStatement();
					ResultSet rs = stmt.executeQuery("SELECT * FROM examines WHERE day=\""+DateT.getText() +"\" AND AMKA ="+AMKAT.getText()+" AND TYPE=\""+TypeT.getText()+"\"");
					if(rs.next()) {
						clearText();
						AMKAT.setText(rs.getString("AMKA"));
						DateT.setText(rs.getString("DAY"));
						SIDT.setText(rs.getString("SID"));
						ResultT.setText(rs.getString("RESULT"));
						TypeT.setText(rs.getString("TYPE"));
					}
					else JOptionPane.showMessageDialog(null,"No Exam with Given Day,AMKA,Type","Info",JOptionPane.INFORMATION_MESSAGE);
				}
				catch(Exception ex){
					
				}
				
			}
			
		});
		
		JButton loadMedicine = new JButton("Load Medicine (MID)");
		loadMedicine.setBounds(10, 560, 300, 25);
		loginPanel.add(loadMedicine);
		loadMedicine.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					Statement stmt = conn.createStatement();
					ResultSet rs = stmt.executeQuery("SELECT * FROM medicine WHERE MID="+MIDT.getText());
					if(rs.next()) {
						clearText();
						MIDT.setText(rs.getString("MID"));
						NameT.setText(rs.getString("NAME"));
						UsageT.setText(rs.getString("USAGES"));
						MGT.setText(rs.getString("MG"));
						TypeT.setText(rs.getString("TYPE"));
					}
					else JOptionPane.showMessageDialog(null,"No Medicine with given MID","Info",JOptionPane.INFORMATION_MESSAGE);
				}
				catch(Exception ex){
					
				}
				
			}
			
		});
		
		JButton loadPatient = new JButton("Load Patient (AMKA)");
		loadPatient.setBounds(10, 590, 300, 25);
		loginPanel.add(loadPatient);
		loadPatient.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					Statement stmt = conn.createStatement();
					ResultSet rs = stmt.executeQuery("SELECT * FROM patient WHERE AMKA="+AMKAT.getText());
					if(rs.next()) {
						clearText();
						AMKAT.setText(rs.getString("AMKA"));
						AccessT.setText(rs.getString("Access"));
						NameT.setText(rs.getString("Name"));
						SurnameT.setText(rs.getString("SURNAME"));
						PhoneT.setText(rs.getString("PHONE"));
						EmailT.setText(rs.getString("EMAIL"));
						BirthdayT.setText(rs.getString("BIRTHDAY"));
						AddressT.setText(rs.getString("ADDRESS"));
						Chronic_CoT.setText(rs.getString("CHRONICCO"));
						InsuranceT.setText(rs.getString("INSURANCE"));
					}
					else JOptionPane.showMessageDialog(null,"No Patient with given AMKA","Info",JOptionPane.INFORMATION_MESSAGE);
				}
				catch(Exception ex){
					
				}
				
			}
			
		});
		
		JButton loadPrescribe = new JButton("Load Prescribe (PID)");
		loadPrescribe.setBounds(10, 620, 300, 25);
		loginPanel.add(loadPrescribe);
		loadPrescribe.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					Statement stmt = conn.createStatement();
					ResultSet rs = stmt.executeQuery("SELECT * FROM Prescribe WHERE PID="+PIDT.getText());
					if(rs.next()) {
						clearText();
						AMKAT.setText(rs.getString("AMKA"));
						PIDT.setText(rs.getString("PID"));
						DateT.setText(rs.getString("DAY"));
						MIDT.setText(rs.getString("MID"));
						SIDT.setText(rs.getString("SID"));
						
					}
					else JOptionPane.showMessageDialog(null,"No Prescription with given PID","Info",JOptionPane.INFORMATION_MESSAGE);
				}
				catch(Exception ex){
					
				}
				
			}
			
		});
		
		
		
		
		
		JButton NDUINFO = new JButton("INFO");
		NDUINFO.setBounds(740, 80, 65, 45);
		loginPanel.add(NDUINFO);
		NDUINFO.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String info = "Complete all fields required for each action:\n"+
							  "Patient New Complete : ACCESS,NAME,SURNAME,PHONE,EMAIL,INSURANCE,AMKA,BIRTHDAY,ADDRESS,CHRONICCO\n"+
							  "Patient Delete Complete : AMKA\n"+
							  "Patient Update Complete : ACCESS,NAME,SURNAME,PHONE,EMAIL,INSURANCE,AMKA,BIRTHDAY,ADDRESS,CHRONICCO\n"+
							  "Staff New Complete : ACCESS,ADDRESS,BIRTHDAY,EMAIL,NAME,NOTES,PHONE,SID,SURNAME,(SPECIALTY,YEARS)\n"+
							  "Staff Delete Complete : SID\n"+
							  "Staff Update Complete : ACCESS,ADDRESS,BIRTHDAY,EMAIL,NAME,NOTES,PHONE,SID,SURNAME,(SPECIALTY,YEARS)\n"+
							  "Medicine New Complete : MG,MID,NAME,TYPE,USAGES\n"+
							  "Medicine Delete Complete : MID\n"+
							  "Medicine Update Complete : MG,MID,NAME,TYPE,USAGES\n"+
							  "Exam New Complete : AMKA,DAY,SID,TYPE\n"+
							  "Exam Delete Complete : AMKA,DAY,TYPE\n"+
							  "Exam Update Complete : AMKA,DAY,RESULT,TYPE\n"+
							  "Duty New Complete : SID,DATE"+
							  "Duty Delete Complete : SID,DATE\n"+
							  "Duty Update Complete : -\n"+
							  "Prescribe New Complete : AMKA,DAY,SID,MID\n"+
							  "Prescribe Delete Complete : PID\n"+
							  "Prescribe Update Complete : AMKA,DAY,SID,MID,PID\n";
							  
				
				JOptionPane.showMessageDialog(null,info,"Info",JOptionPane.INFORMATION_MESSAGE);
				
			}
			
		});
		
		
		
		JLabel Patient = new JLabel("Patient (P)");
		Patient.setBounds(320,30,100,20);
		loginPanel.add(Patient);
		
		JButton newPatient = new JButton("New");
		newPatient.setBounds(425, 30, 100, 20);
		loginPanel.add(newPatient);
		newPatient.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(FindUIDinDataBase(AMKAT.getText())) {
					JOptionPane.showMessageDialog(null,"Key Value Already Exists","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				InsertToDB("INSERT INTO PATIENT(ACCESS,NAME,SURNAME,PHONE,EMAIL,INSURANCE,AMKA,BIRTHDAY,ADDRESS,CHRONICCO) VALUES('"+
							AccessT.getText()+
							"','"+NameT.getText()+
							"','"+SurnameT.getText()+
							"','"+PhoneT.getText()+
							"','"+EmailT.getText()+
							"','"+InsuranceT.getText()+
							"','"+AMKAT.getText()+
							"','"+BirthdayT.getText()+
							"','"+AddressT.getText()+
							"','"+Chronic_CoT.getText()+"')");
			}
		});
		
		JButton deletePatient = new JButton("Delete");
		deletePatient.setBounds(530, 30, 100, 20);
		loginPanel.add(deletePatient);
		deletePatient.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				InsertToDB("delete from patient where amka="+AMKAT.getText());
				
			}		
		});
		
		JButton updatePatient = new JButton("Update");
		updatePatient.setBounds(635, 30, 100, 20);
		loginPanel.add(updatePatient);
		updatePatient.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent e) {
				InsertToDB("UPDATE patient SET  name='"+NameT.getText()+
						"',surname='"+SurnameT.getText()+
						"',phone='"+PhoneT.getText()+
						"',email='"+EmailT.getText()+
						"',insurance='"+InsuranceT.getText()+
						"',amka='"+AMKAT.getText()+
						"',birthday='"+BirthdayT.getText()+
						"',address='"+AddressT.getText()+
						"',chronicco='"+Chronic_CoT.getText()+
						"' WHERE AMKA='"+AMKAT.getText()+"'");
			}	
		});
		
		JLabel Staff = new JLabel("Staff (S)");
		Staff.setBounds(320,55,100,20);
		loginPanel.add(Staff);
		
		JButton newStaff = new JButton("New");
		newStaff.setBounds(425, 55, 100, 20);
		loginPanel.add(newStaff);
		newStaff.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(FindUIDinDataBase(AMKAT.getText())) {
					JOptionPane.showMessageDialog(null,"Key Value Already Exists","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				InsertToDB("INSERT INTO STAFF(ACCESS,ADDRESS,BIRTHDAY,EMAIL,NAME,NOTES,PHONE,SID,SURNAME) VALUES('"+
						AccessT.getText()+
						"','"+AddressT.getText()+
						"','"+BirthdayT.getText()+
						"','"+EmailT.getText()+
						"','"+NameT.getText()+
						"','"+NotesT.getText()+
						"','"+PhoneT.getText()+
						"','"+SIDT.getText()+
						"','"+SurnameT.getText()+"')");
				if(AccessT.getText().equals("2")) InsertToDB("INSERT INTO NURSE(SID) VALUES('"+SIDT.getText()+"')");
				else if(AccessT.getText().equals("3"))InsertToDB("INSERT INTO DOCTOR(SID,YEARS,SPECIALTY) VALUES('"+SIDT.getText()+"','"+YearsT.getText()+"','"+SpecialtyT.getText()+"')");
				else if(AccessT.getText().equals("4"))InsertToDB("INSERT INTO Administrator(SID) VALUES('"+SIDT.getText()+"')");
			}
			
		});
		
		JButton deleteStaff = new JButton("Delete");
		deleteStaff.setBounds(530, 55, 100, 20);
		loginPanel.add(deleteStaff);
		deleteStaff.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				InsertToDB("delete from staff where SID="+SIDT.getText());
				InsertToDB("delete from administrator where SID="+SIDT.getText());
				InsertToDB("delete from doctor where SID="+SIDT.getText());
				InsertToDB("delete from nurse where SID="+SIDT.getText());
			}
		});
		
		JButton updateStaff = new JButton("Update");
		updateStaff.setBounds(635, 55, 100, 20);
		loginPanel.add(updateStaff);
		updateStaff.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(!FindUIDinDataBase(SIDT.getText())) {
					JOptionPane.showMessageDialog(null,"SID does not exist","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				InsertToDB("UPDATE staff SET  name='"+NameT.getText()+
						"',surname='"+SurnameT.getText()+
						"',phone='"+PhoneT.getText()+
						"',email='"+EmailT.getText()+
						"',birthday='"+BirthdayT.getText()+
						"',address='"+AddressT.getText()+
						"',notes='"+NotesT.getText()+
						"' WHERE sid='"+SIDT.getText()+"'");
				try {
					InsertToDB("UPDATE doctor SET  specialty='"+SpecialtyT.getText()+
							"',years='"+YearsT.getText()+
							"' WHERE sid='"+SIDT.getText()+"'");
				}
				catch(Exception ex) {}
				
				
				
			}
			
		});
		
		JLabel Medicine = new JLabel("Medicine (M)");
		Medicine.setBounds(320,80,100,20);
		loginPanel.add(Medicine);
		
		JButton newMedicine = new JButton("New");
		newMedicine.setBounds(425, 80, 100, 20);
		loginPanel.add(newMedicine);
		newMedicine.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(FindUIDinDataBase(MIDT.getText())) {
					JOptionPane.showMessageDialog(null,"Key Value Already Exists","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				InsertToDB("INSERT INTO MEDICINE(MG,MID,NAME,TYPE,USAGES) VALUES('"+
						MGT.getText()+
						"','"+MIDT.getText()+
						"','"+NameT.getText()+
						"','"+TypeT.getText()+
						"','"+UsageT.getText()+"')");
			}
		});
		
		JButton deleteMedicine = new JButton("Delete");
		deleteMedicine.setBounds(530, 80, 100, 20);
		loginPanel.add(deleteMedicine);
		deleteMedicine.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				InsertToDB("delete from medicine where MID="+MIDT.getText());
			}	
		});
		
		JButton updateMedicine = new JButton("Update");
		updateMedicine.setBounds(635, 80, 100, 20);
		loginPanel.add(updateMedicine);
		updateMedicine.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(!FindUIDinDataBase(MIDT.getText())) {
					JOptionPane.showMessageDialog(null,"SID or AMKA or MID does not exist","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				InsertToDB("UPDATE MEDICINE SET  type='"+TypeT.getText()+
						"',usages='"+UsageT.getText()+
						"',name='"+NameT.getText()+
						"',MG='"+MGT.getText()+
						"' WHERE mid='"+MIDT.getText()+"'");
			}
			
		});
		
		JLabel Exam = new JLabel("Exam (E)");
		Exam.setBounds(320,105,100,20);
		loginPanel.add(Exam);
		
		JButton newExam = new JButton("New");
		newExam.setBounds(425, 105, 100, 20);
		loginPanel.add(newExam);
		newExam.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(!FindUIDinDataBase(AMKAT.getText()) || !FindUIDinDataBase(SIDT.getText())) {
					JOptionPane.showMessageDialog(null,"SID or AMKA does not exist","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				InsertToDB("INSERT INTO EXAMINES(AMKA,DAY,SID,RESULT,TYPE) VALUES('"+
						AMKAT.getText()+
						"','"+DateT.getText()+
						"','"+SIDT.getText()+
						"','TBD','"+TypeT.getText()+"')");	
			}	
		});
		
		JButton deleteExam = new JButton("Delete");
		deleteExam.setBounds(530, 105, 100, 20);
		loginPanel.add(deleteExam);
		deleteExam.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				InsertToDB("delete from examines where amka='"+AMKAT.getText()+"' AND date='"+DateT.getText()+"'"+"' AND date='"+TypeT.getText()+"'");
			}
		});
		
		JButton updateExam = new JButton("Update");
		updateExam.setBounds(635, 105, 100, 20);
		loginPanel.add(updateExam);
		updateExam.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(!FindUIDinDataBase(AMKAT.getText())) {
					JOptionPane.showMessageDialog(null,"SID or AMKA does not exist","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				InsertToDB("UPDATE EXAMINES SET  result='"+ResultT.getText()+
						"' WHERE amka='"+AMKAT.getText()+
						"' AND day='"+DateT.getText()+
						"' AND type='"+TypeT.getText()+"'");
				
			}
			
		});
		
		JLabel Duty = new JLabel("Duty (D)");
		Duty.setBounds(320,130,100,20);
		loginPanel.add(Duty);
		
		JButton newDuty = new JButton("New");
		newDuty.setBounds(425, 130, 100, 20);
		loginPanel.add(newDuty);
		newDuty.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				InsertToDB("INSERT INTO DUTY(SID,DAY) VALUES('"+
						SIDT.getText()+
						"','"+DateT.getText()+"')");
				InsertToDB("INSERT INTO ATTEND(SID,DAY) VALUES('"+
						SIDT.getText()+
						"','"+DateT.getText()+"')");
			}
		});
		
		JButton deleteDuty = new JButton("Delete");
		deleteDuty.setBounds(530, 130, 100, 20);
		loginPanel.add(deleteDuty);
		deleteDuty.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				InsertToDB("delete from duty where SID='"+SIDT.getText()+"' AND day ='"+DateT.getText()+"'");
				InsertToDB("delete from attend where SID='"+SIDT.getText()+"' AND day ='"+DateT.getText()+"'");
			}
		});
		
		
		JButton updateDuty = new JButton("Update");
		updateDuty.setBounds(635, 130, 100, 20);
		loginPanel.add(updateDuty);
		updateDuty.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println("Nothing to update.");
			}
		});
		
		JLabel Prescribe = new JLabel("Prescribe (PR)");
		Prescribe.setBounds(320,155,100,20);
		loginPanel.add(Prescribe);
		
		JButton newPrescribe = new JButton("New");
		newPrescribe.setBounds(425, 155, 100, 20);
		loginPanel.add(newPrescribe);
		newPrescribe.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(!FindUIDinDataBase(AMKAT.getText()) || !FindUIDinDataBase(SIDT.getText()) || !FindUIDinDataBase(MIDT.getText())) {
					System.out.println(AMKAT.getText()+","+SIDT.getText()+","+MIDT.getText());
					JOptionPane.showMessageDialog(null,"SID or AMKA or MID does not exist","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				InsertToDB("INSERT INTO PRESCRIBE(AMKA,DAY,SID,MID,PID) VALUES('"+
						AMKAT.getText()+
						"','"+DateT.getText()+
						"','"+SIDT.getText()+
						"','"+MIDT.getText()+
						"','"+MIDT.getText()+SIDT.getText()+DateT.getText().replaceAll("-", "")+"')");
				InsertToDB("INSERT INTO TAKES(AMKA,MID) VALUES('"+
						AMKAT.getText()+
						"','"+MIDT.getText()+"')");
			}
			
		});
		
		JButton deletePrescribe = new JButton("Delete");
		deletePrescribe.setBounds(530, 155, 100, 20);
		loginPanel.add(deletePrescribe);
		deletePrescribe.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				InsertToDB("delete from prescribe where pid='"+PIDT.getText()+"'");	
			}
		});
		
		JButton updatePrescribe = new JButton("Update");
		updatePrescribe.setBounds(635, 155, 100, 20);
		loginPanel.add(updatePrescribe);
		updatePrescribe.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent e) {
				if(FindUIDinDataBase(PIDT.getText())) {
					JOptionPane.showMessageDialog(null,"Prescription has already been given","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				if(!FindUIDinDataBase(AMKAT.getText()) || !FindUIDinDataBase(SIDT.getText()) || !FindUIDinDataBase(MIDT.getText())) {
					JOptionPane.showMessageDialog(null,"SID or AMKA or MID does not exist","Info",JOptionPane.INFORMATION_MESSAGE);
					return;
				}
				InsertToDB("UPDATE PRESCRIBE SET  amka='"+AMKAT.getText()+
						"',day='"+DateT.getText()+
						"',mid='"+MIDT.getText()+
						"',SID='"+SIDT.getText()+
						"' WHERE pid='"+PIDT.getText()+"'");
				
			}
			
		});
		
		
		
		
		
		
		
		JLabel mySID = new JLabel("SID: " + givenID);
		JLabel myAccess = new JLabel("Access: " + __Access);
		JLabel myName = new JLabel("Name:");
		JLabel mySurname = new JLabel("Surname:");
		JLabel myPhone = new JLabel("Phone:");
		JLabel myEmail = new JLabel("E-mail:");
		JLabel myBirthday = new JLabel("Birthday:");
		JLabel myAddress = new JLabel("Address:");
		JLabel myYears = new JLabel("Years: ");
		JLabel mySpecialty = new JLabel("Specialty: ");
		JLabel myNotes = new JLabel("Notes:");
		mySID.setBounds(10,30,150,15);
		myAccess.setBounds(10,50,150,15);
		myName.setBounds(10,70,45,15);
		mySurname.setBounds(10,90,70,15);
		myPhone.setBounds(10,110,40,15);
		myEmail.setBounds(10,130,40,15);
		myBirthday.setBounds(10,150,60,15);
		myAddress.setBounds(10,170,60,15);
		myYears.setBounds(10,190,70,15);
		mySpecialty.setBounds(10,210,70,15);
		myNotes.setBounds(10,230,110,15);
		loginPanel.add(mySID);
		loginPanel.add(myAccess);
		loginPanel.add(myName);
		loginPanel.add(mySurname);
		loginPanel.add(myPhone);
		loginPanel.add(myEmail);
		loginPanel.add(myBirthday);
		loginPanel.add(myAddress);
		loginPanel.add(myYears);
		loginPanel.add(mySpecialty);
		loginPanel.add(myNotes);
		JTextField myNameT = new JTextField();
		JTextField mySurnameT = new JTextField();
		JTextField myPhoneT = new JTextField();
		JTextField myEmailT = new JTextField();
		JTextField myBirthdayT = new JTextField();
		JTextField myAddressT = new JTextField();
		JTextField myNotesT = new JTextField();
		JTextField myYearsT = new JTextField();
		JTextField mySpecialtyT = new JTextField();
		myNameT.setBounds(110,70,200,17);
		mySurnameT.setBounds(110,90,200,17);
		myPhoneT.setBounds(110,110,200,17);
		myEmailT.setBounds(110,130,200,17);
		myBirthdayT.setBounds(110,150,200,17);
		myAddressT.setBounds(110,170,200,17);
		myYearsT.setBounds(110,190,200,15);
		mySpecialtyT.setBounds(110,210,200,15);
		myNotesT.setBounds(110,230,200,200);
		loginPanel.add(myNameT);
		loginPanel.add(mySurnameT);
		loginPanel.add(myPhoneT);
		loginPanel.add(myEmailT);
		loginPanel.add(myBirthdayT);
		loginPanel.add(myAddressT);
		loginPanel.add(myNotesT);
		loginPanel.add(myYearsT);
		loginPanel.add(mySpecialtyT);
		//Fetch Data
		try {
			myNameT.setText(__currentUser.getString("name"));
			mySurnameT.setText(__currentUser.getString("Surname"));
			myEmailT.setText(__currentUser.getString("email"));
			myAddressT.setText(__currentUser.getString("address"));
			myNotesT.setText(__currentUser.getString("notes"));
			myPhoneT.setText(__currentUser.getString("Phone"));
			myBirthdayT.setText(__currentUser.getString("Birthday"));
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery("SELECT * FROM doctor WHERE SID="+givenID);
			if(rs.next()) {
				myYearsT.setText(rs.getString("years"));
				mySpecialtyT.setText(rs.getString("specialty"));
			}
			
			
	
		}
		catch(Exception e){
			
		}
		
		
		//Visibility per Access Level
		if (__Access > 4) {
			//Administrator of Administrators
			mySpecialtyT.setText("ADMINISTRATOR");
			myYearsT.setText("ADMINISTRATOR");
		}
		else if(__Access == 4) {
			//Administrator
			mySpecialtyT.setVisible(false);
			mySpecialty.setVisible(false);
			myYearsT.setVisible(false);
			myYears.setVisible(false);
			queryLabel.setVisible(false);
			queryText.setVisible(false);
			queryButton.setVisible(false);
			InsertButton.setVisible(false);
		}
		else if(__Access == 3) {
			//Doctor
			myAccess.setText("Access:3");
			queryLabel.setVisible(false);
			queryText.setVisible(false);
			queryButton.setVisible(false);
			InsertButton.setVisible(false);
			Duty.setVisible(false);
			newDuty.setVisible(false);
			deleteDuty.setVisible(false);
			updateDuty.setVisible(false);
			deletePatient.setVisible(false);
			updatePatient.setVisible(false);
			Staff.setVisible(false);
			newStaff.setVisible(false);
			deleteStaff.setVisible(false);
			updateStaff.setVisible(false);
			updateExam.setVisible(false);
			deletePrescribe.setVisible(false);
			updatePrescribe.setVisible(false);
			myMedicines.setVisible(false);
			myExaminations.setVisible(false);
			genDuty.setVisible(false);
			
			
		}
		else if(__Access==2) {
			//Nurse
			queryLabel.setVisible(false);
			queryText.setVisible(false);
			queryButton.setVisible(false);
			InsertButton.setVisible(false);
			mySpecialtyT.setVisible(false);
			mySpecialty.setVisible(false);
			myYearsT.setVisible(false);
			myYears.setVisible(false);
			deletePatient.setVisible(false);
			updatePatient.setVisible(false);
			Staff.setVisible(false);
			newStaff.setVisible(false);
			deleteStaff.setVisible(false);
			updateStaff.setVisible(false);
			Medicine.setVisible(false);
			newMedicine.setVisible(false);
			updateMedicine.setVisible(false);
			deleteMedicine.setVisible(false);
			newExam.setVisible(false);
			deleteExam.setVisible(false);
			Duty.setVisible(false);
			newDuty.setVisible(false);
			deleteDuty.setVisible(false);
			updateDuty.setVisible(false);
			Prescribe.setVisible(false);
			newPrescribe.setVisible(false);
			deletePrescribe.setVisible(false);
			updatePrescribe.setVisible(false);
			userDuties.setVisible(false);
			myMedicines.setVisible(false);
			myExaminations.setVisible(false);
			genDuty.setVisible(false);
			
			
		}
		else {
			
			
			//Patient
			queryLabel.setVisible(false);
			queryText.setVisible(false);
			queryButton.setVisible(false);
			mySID.setText("AMKA: "+givenID);
			myNotes.setText("Chronic Condition:");
			myNotesT.setBounds(120, 230, 190, 200);
			for(Component c : loginPanel.getContentPane().getComponents()) {
				if(c.getX()>300) {
					c.setVisible(false);
				}
			}
			for(Component c : loginPanel.getContentPane().getComponents()) {
				if(c.getY()>349) {
					c.setVisible(false);
				}
			}
			myExaminations.setVisible(true);
			myMedicines.setVisible(true);
			_Date.setVisible(true);
		}
		
		JButton updateMyInfo = new JButton("Update Personal Info");
		updateMyInfo.setBounds(10, 450, 300, 25);
		loginPanel.add(updateMyInfo);
		updateMyInfo.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (__Access > 4) {
					//Administrator of Administrators
					InsertToDB("UPDATE staff SET name ='"+myNameT.getText()+
							"',surname='"+mySurnameT.getText()+
							"',phone='"+myPhoneT.getText()+
							"',email='"+myEmail.getText()+
							"',address='"+myAddress.getText()+
							"',notes='"+myNotesT.getText()+
							"',birthday='"+myBirthdayT.getText()+
							"' WHERE sid='"+givenID+"'");
				}
				else if(__Access == 4) {
					//Administrator
					InsertToDB("UPDATE staff SET name ='"+myNameT.getText()+
							"',surname='"+mySurnameT.getText()+
							"',phone='"+myPhoneT.getText()+
							"',email='"+myEmail.getText()+
							"',address='"+myAddress.getText()+
							"',notes='"+myNotesT.getText()+
							"',birthday='"+myBirthdayT.getText()+
							"' WHERE sid='"+givenID+"'");
		
				}
				else if(__Access == 3) {
					//Doctor
					InsertToDB("UPDATE staff SET name ='"+myNameT.getText()+
							"',surname='"+mySurnameT.getText()+
							"',phone='"+myPhoneT.getText()+
							"',email='"+myEmail.getText()+
							"',address='"+myAddress.getText()+
							"',notes='"+myNotesT.getText()+
							"',birthday='"+myBirthdayT.getText()+
							"' WHERE sid='"+givenID+"'");
					InsertToDB("UPDATE doctor SET specialty ='"+mySpecialtyT.getText()+
							"',years='"+myYearsT.getText()+
							"' WHERE sid='"+givenID+"'");
				}
				else if(__Access==2) {
					//Nurse
					InsertToDB("UPDATE staff SET name ='"+myNameT.getText()+
							"',surname='"+mySurnameT.getText()+
							"',phone='"+myPhoneT.getText()+
							"',email='"+myEmail.getText()+
							"',address='"+myAddress.getText()+
							"',notes='"+myNotesT.getText()+
							"',birthday='"+myBirthdayT.getText()+
							"' WHERE sid='"+givenID+"'");
				}
				else {
					//Patient
					InsertToDB("UPDATE patient SET name ='"+myNameT.getText()+
							"',surname='"+mySurnameT.getText()+
							"',phone='"+myPhoneT.getText()+
							"',email='"+myEmail.getText()+
							"',address='"+myAddress.getText()+
							"',chronicco='"+myNotesT.getText()+
							"',birthday='"+myBirthdayT.getText()+
							"' WHERE amka='"+givenID+"'");
				}
			}	
		});
		
	}
	
	
	public static void insidents() {
		try {
			flag = 1;
			askQueryToPop("SELECT * FROM EXAMINES WHERE day=\""+__Date+"\"");
			flag = 0;
		}
		catch(Exception ex) {
			
		}
	}
	
	public static void medicines() {
		try {
			flag = 1;
			askQueryToPop("SELECT * FROM prescribe WHERE day=\""+__Date+"\"");
			flag = 0;
		}
		catch(Exception ex) {
			
		}
	}
	
	@SuppressWarnings("deprecation")
	public static void viewMonMedicines(){
		String outPut="";
		int medicines=0;
		Calendar calendar = Calendar.getInstance();
		java.util.Date currentDate = calendar.getTime();
		Date oldDate = new java.sql.Date(currentDate.getTime());
		oldDate.setDate(__Date.getDate()-30);
		oldDate.setMonth(__Date.getMonth());
		oldDate.setYear(__Date.getYear());
		try {
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery("SELECT * FROM prescribe WHERE DAY > '"+oldDate.toString()+"'");
			ResultSetMetaData rsmd = rs.getMetaData();
			int columnsNumber = rsmd.getColumnCount();
			while (rs.next()) {
			    for (int i = 1; i <= columnsNumber; i++) {
			        if (i > 1) outPut+=",  ";
			        String columnValue = rs.getString(i);
			        outPut+=rsmd.getColumnName(i) + ": " +columnValue;
			    }
			    outPut+="\n";
			    medicines++;
			}
			outPut+="Last 30 days given "+medicines+" medicines";
			if(countLines(outPut)>40) {
				JOptionPane.showMessageDialog(null,"Output too big. Redirect to console output","Exams performed from "+oldDate.toString()+" until "+__Date.toString(),JOptionPane.INFORMATION_MESSAGE);
				System.out.println(outPut);
				return;
			}
			JOptionPane.showMessageDialog(null,outPut,"Medicines given from "+oldDate.toString()+" until "+__Date.toString(),JOptionPane.INFORMATION_MESSAGE);
		} catch (SQLException e) {
			
			e.printStackTrace();
		}
		
	}
	
	@SuppressWarnings("deprecation")
	public static void viewMonInsidents() {
		String outPut="";
		int exams=0;
		Calendar calendar = Calendar.getInstance();
		java.util.Date currentDate = calendar.getTime();
		Date oldDate = new java.sql.Date(currentDate.getTime());
		oldDate.setDate(__Date.getDate()-30);
		oldDate.setMonth(__Date.getMonth());
		oldDate.setYear(__Date.getYear());
		try {
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery("SELECT * FROM examines WHERE DAY > '"+oldDate.toString()+"'");
			ResultSetMetaData rsmd = rs.getMetaData();
			int columnsNumber = rsmd.getColumnCount();
			while (rs.next()) {
			    for (int i = 1; i <= columnsNumber; i++) {
			        if (i > 1) outPut+=",  ";
			        String columnValue = rs.getString(i);
			        outPut+=rsmd.getColumnName(i) + ": " +columnValue;
			    }
			    outPut+="\n";
			    exams++;
			}
			outPut+="Last 30 days performed "+exams+" exams";
			if(countLines(outPut)>40) {
				JOptionPane.showMessageDialog(null,"Output too big. Redirect to console output","Exams performed from "+oldDate.toString()+" until "+__Date.toString(),JOptionPane.INFORMATION_MESSAGE);
				System.out.println(outPut);
				return;
			}
			JOptionPane.showMessageDialog(null,outPut,"Exams performed from "+oldDate.toString()+" until "+__Date.toString(),JOptionPane.INFORMATION_MESSAGE);
			
		} catch (SQLException e) {
			
			e.printStackTrace();
		}
	}
	
	public static void viewCovid() {
		String query = "SELECT * FROM patient WHERE AMKA IN (SELECT AMKA FROM examines WHERE `TYPE` LIKE '%COVID%' AND (`RESULT` LIKE '%POSITIVE%' OR `RESULT` LIKE '%YES%'))";
		int patient =0;
		String outPut="";
		try {
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery(query);
			ResultSetMetaData rsmd = rs.getMetaData();
			int columnsNumber = rsmd.getColumnCount();
			while (rs.next()) {
			    for (int i = 1; i <= columnsNumber; i++) {
			        if (i > 1) outPut+=",  ";
			        String columnValue = rs.getString(i);
			        outPut+=rsmd.getColumnName(i) + ": " +columnValue;
			    }
			    outPut+="\n";
			    patient++;
			}
			outPut+="COVID-19 POSITIVES : "+patient;
			if(countLines(outPut)>40) {
				JOptionPane.showMessageDialog(null,"Output too big. Redirect to console output","SARS-CoViD-2 / COVID-19 Report",JOptionPane.INFORMATION_MESSAGE);
				System.out.println(outPut);
				return;
			}
			JOptionPane.showMessageDialog(null,outPut,"SARS-CoViD-2 / COVID-19 Report",JOptionPane.INFORMATION_MESSAGE);
		}
		catch(Exception ex) {
			ex.printStackTrace();
		}
	}
	
	
	
	public static void newDuty() {
		Statement stmt;
		String outPut="SIDs :\n";
		try {
			stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery("SELECT SID FROM doctor WHERE SPECIALTY =\"PATHOLOGIST\" AND SID NOT IN (SELECT SID FROM attend WHERE DAY <= \""+__Date+"\") ORDER BY RAND() LIMIT 3");
			while(rs.next()) {
				InsertToDB("INSERT INTO DUTY(SID,DAY) VALUES("+rs.getInt("SID")+",\""+__Date+"\")");
				outPut+=rs.getString("SID")+", Pathologist\n";
			}
			rs = stmt.executeQuery("SELECT SID FROM doctor WHERE SPECIALTY =\"CARDIOLOGIST\" AND SID NOT IN (SELECT SID FROM attend WHERE DAY <= \""+__Date+"\") ORDER BY RAND() LIMIT 3");
			while(rs.next()) {
				InsertToDB("INSERT INTO DUTY(SID,DAY) VALUES("+rs.getInt("SID")+",\""+__Date+"\")");
				outPut+=rs.getString("SID")+", Cardiologist\n";
			}
			rs = stmt.executeQuery("SELECT SID FROM doctor WHERE SPECIALTY =\"ANESTHISIOLOGIST\" AND SID NOT IN (SELECT SID FROM attend WHERE DAY <= \""+__Date+"\") ORDER BY RAND() LIMIT 3");
			while(rs.next()) {
				InsertToDB("INSERT INTO DUTY(SID,DAY) VALUES("+rs.getInt("SID")+",\""+__Date+"\")");
				outPut+=rs.getString("SID")+", Anesthisiologist\n";
			}
			rs = stmt.executeQuery("SELECT SID FROM doctor WHERE SPECIALTY =\"UROLOGIST\" AND SID NOT IN (SELECT SID FROM attend WHERE DAY <= \""+__Date+"\") ORDER BY RAND() LIMIT 3");
			while(rs.next()) {
				InsertToDB("INSERT INTO DUTY(SID,DAY) VALUES("+rs.getInt("SID")+",\""+__Date+"\")");
				outPut+=rs.getString("SID")+", Urologist\n";
			}
			rs = stmt.executeQuery("SELECT SID FROM doctor WHERE SPECIALTY =\"INFECTIOUS DISEASE EXPERT\" AND SID NOT IN (SELECT SID FROM attend WHERE DAY <= \""+__Date+"\") ORDER BY RAND() LIMIT 3");
			while(rs.next()) {
				InsertToDB("INSERT INTO DUTY(SID,DAY) VALUES("+rs.getInt("SID")+",\""+__Date+"\")");
				outPut+=rs.getString("SID")+", Infectious Disease Expert\n";
			}
			rs = stmt.executeQuery("SELECT SID FROM nurse WHERE SID NOT IN (SELECT SID FROM attend WHERE DAY <= \""+__Date+"\") ORDER BY RAND() LIMIT 5");
			while(rs.next()) {
				InsertToDB("INSERT INTO DUTY(SID,DAY) VALUES("+rs.getInt("SID")+",\""+__Date+"\")");
				outPut+=rs.getString("SID")+", Nurse\n";
			}
			rs = stmt.executeQuery("SELECT SID FROM administrator WHERE SID NOT IN (SELECT SID FROM attend WHERE DAY <= \""+__Date+"\") ORDER BY RAND() LIMIT 1");
			while(rs.next()) {
				InsertToDB("INSERT INTO DUTY(SID,DAY) VALUES("+rs.getInt("SID")+",\""+__Date+"\")");
				outPut+=rs.getString("SID")+", Administrator\n";
			}
			stmt.executeUpdate("DELETE FROM ATTEND");
			rs = stmt.executeQuery("SELECT SID FROM duty WHERE day =\""+__Date+"\"");
			while(rs.next()) {
				InsertToDB("INSERT INTO ATTEND(SID,DAY) VALUES("+rs.getInt("SID")+",\""+__Date+"\")");
			}
			JOptionPane.showMessageDialog(null,outPut,"SIDs for duty in "+__Date,JOptionPane.INFORMATION_MESSAGE);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
	}
	
	
	@SuppressWarnings("deprecation")
	public static void viewMyDuties(String string) {
		String outPut="";
		int duties=0;
		Calendar calendar = Calendar.getInstance();
		java.util.Date currentDate = calendar.getTime();
		Date oldDate = new java.sql.Date(currentDate.getTime());
		oldDate.setDate(__Date.getDate()-30);
		oldDate.setMonth(__Date.getMonth());
		oldDate.setYear(__Date.getYear());
		try {
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery("SELECT * FROM duty WHERE SID='"+string+"'");
			while(rs.next()) {
				outPut+="Date: "+rs.getString("DAY")+"\n";
			}
			rs= stmt.executeQuery("SELECT * FROM duty WHERE DAY > '"+oldDate.toString()+"' AND SID = '"+string+"'");
			while(rs.next()) {
				duties++;
			}
			outPut+="Last 30 days attended "+duties+" duties";
			JOptionPane.showMessageDialog(null,outPut,"My Duties - "+string,JOptionPane.INFORMATION_MESSAGE);
		} catch (SQLException e) {
			
			e.printStackTrace();
		}
		
	}
	
	public static void askQueryToPop(String query) {
		String outPut="";
		try {
			System.out.println("TRY: Execute handwritten query.");
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery(query);
			ResultSetMetaData rsmd = rs.getMetaData();
			int columnsNumber = rsmd.getColumnCount();
			while (rs.next()) {
			    for (int i = 1; i <= columnsNumber; i++) {
			        if (i > 1) outPut+=",  ";
			        String columnValue = rs.getString(i);
			        outPut+=rsmd.getColumnName(i) + ": " +columnValue;
			    }
			    outPut+="\n";
			}
			System.out.println("PASS: Handwritten query executed successfully.");
		} catch (SQLException e) {
			System.out.println("FAIL: Handwritten query did not execute or it was wrong written.");
			e.printStackTrace();
		}
		
		int lines = countLines(outPut);
		if(lines > 40) {
			JOptionPane.showMessageDialog(null,"Output too big. Redirect to console output","Info",JOptionPane.INFORMATION_MESSAGE);
			System.out.println(outPut);
			if (flag == 1) {
				System.out.println("Insidents today : "+(lines));
			}
			else if (flag == 1) {
				System.out.println("Medicines today : "+(lines));
			}
		}
		else {
			if (flag == 1) {
				outPut+="\nInsidents today : "+(lines) ;
			}
			else if (flag == 2) {
				System.out.println("Medicines today : "+(lines));
			}
			JOptionPane.showMessageDialog(null,outPut,"Info",JOptionPane.INFORMATION_MESSAGE);
		}
		
		
	}
	
	public static int countLines(String str){
		   String[] lines = str.split("\r\n|\r|\n");
		   return  lines.length;
		}
	
	public static void askQuery(String query) {
		try {
			System.out.println("TRY: Execute handwritten query.");
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery(query);
			ResultSetMetaData rsmd = rs.getMetaData();
			int columnsNumber = rsmd.getColumnCount();
			while (rs.next()) {
			    for (int i = 1; i <= columnsNumber; i++) {
			        if (i > 1) System.out.print(",  ");
			        String columnValue = rs.getString(i);
			        System.out.print(rsmd.getColumnName(i) + ": " +columnValue);
			    }
			    System.out.println("");
			}
			System.out.println("PASS: Handwritten query executed successfully.");
		} catch (SQLException e) {
			System.out.println("FAIL: Handwritten query did not execute or it was wrong written.");
			e.printStackTrace();
		}
		
	}
	
	public static void InsertToDB(String ins) {
		try {
			System.out.println("TRY: Execute handwritten insertion.");
			Statement stmt = conn.createStatement();
			stmt.executeUpdate(ins);
			System.out.println("PASS: Handwritten insertion executed successfully.");
			
		}
		catch(SQLException e) {
			System.out.println("FAIL: Handwritten insertion did not execute or it was wrong written.");
			System.out.println(">>>>>>   "+ins);
			e.printStackTrace();
		}
	}
	
	public static void StartUI() {
		loginPanel = new JFrame("Log in ΤΕΠ");
		JLabel idLabel = new JLabel("ID or AMKA:");
		JTextField idField = new JTextField(4);
		JButton infoButton = new JButton("INFO");
		JButton SignInButton = new JButton("SIGN IN");
		loginPanel.setLayout(null);
		idField.setBounds(450, 360, 100, 30);
		idLabel.setBounds(350, 350, 90, 50);
		
		infoButton.setBounds(450, 445, 100, 40);
		infoButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				PopInfoPanel();
			}});
		
		SignInButton.setBounds(450, 400, 100, 40);
		SignInButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String givenID = idField.getText();
				if (FindUIDinDataBase(givenID)) {
					
					BasicGUI(givenID);
				}
				else {
					JOptionPane.showMessageDialog(null,"The given user ID or AMKA does not exists.\n Read INFO for existing IDs and AMKAs","Fail To Retrieve Data",JOptionPane.INFORMATION_MESSAGE);
				}
			}});
		
		
		
		loginPanel.add(idField);
		loginPanel.add(idLabel);
		loginPanel.add(infoButton);
		loginPanel.add(SignInButton);
		
		loginPanel.setSize(1000, 800);
		loginPanel.setVisible(true);
		loginPanel.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	protected static boolean FindUIDinDataBase(String givenID) {
		Statement stmt;
		try {
			stmt = conn.createStatement();
			String ps = "SELECT * FROM staff WHERE `SID` ="+ givenID;
			ResultSet rs = stmt.executeQuery(ps);
			if(rs.next()) {
				if(__Access == -123) {
					__Access = rs.getInt("ACCESS");
					System.out.println("Logged in as " +rs.getString("name") + ", " +givenID);
					__currentUser = rs;
				
				}
				return true;
			}
		} catch (SQLException e) {
			
			//e.printStackTrace();
		}
		try {
			stmt = conn.createStatement();
			String ps = "SELECT * FROM patient WHERE `AMKA` ="+ givenID;
			ResultSet rs = stmt.executeQuery(ps);
			if(rs.next()) {
				if(__Access == -123) {
					__Access = rs.getInt("ACCESS");
					System.out.println("Logged in as " +rs.getString("name") + ", " +givenID);
					__currentUser = rs;
					
				}
				return true;
			}
		} catch (SQLException e) {
			
			//e.printStackTrace();
		}
		try {
			stmt = conn.createStatement();
			String ps = "SELECT * FROM medicine WHERE `MID` ="+ givenID;
			ResultSet rs = stmt.executeQuery(ps);
			if(rs.next()) return true;
		} catch (SQLException e) {
			
			//e.printStackTrace();
		}
		try {
			stmt = conn.createStatement();
			String ps = "SELECT * FROM prescribe WHERE `PID` ="+ givenID;
			ResultSet rs = stmt.executeQuery(ps);
			if(rs.next()) return true;
		} catch (SQLException e) {
			
			//e.printStackTrace();
		}
		return false;
	}

	protected static void PopInfoPanel() {
		JOptionPane.showMessageDialog(null,"Use IDs:\n [SID] 1001-1002 : Admins\n [SID] 2001-2030 : Doctors\n [SID] 3001-3011 : Nurse\n [AMKA] 9001-9009 : Patient","Log In Info",JOptionPane.INFORMATION_MESSAGE);
		
	}

	public static void main(final String[] args){
		
		
		if(initialize()) {
			System.out.println("PASS: DataBase Initialized.\nTRY: Starting UI...");
			StartUI();
			
		}
		else {
			System.out.println("FAIL: Failed to Initialize DataBase. Exiting...");
			System.exit(1);
			
		}
		
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		
	}
	
	
	
}	


	
