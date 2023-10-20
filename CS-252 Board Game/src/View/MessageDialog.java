package View;


import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class MessageDialog {
	String choice;
	int count=0;
	
	public MessageDialog() {
		JFrame parent = new JFrame();
		
		Object[] choices={"Arch 1","Arch 2","Arch 3","Thiseas"};
		
		
		choice=(String)JOptionPane.showInputDialog(parent,"Select pawn:","Pawn Selection",JOptionPane.PLAIN_MESSAGE,null, choices,"2");
		
		
	}
	
	public String Pawn() {
		return choice;
	}
}
