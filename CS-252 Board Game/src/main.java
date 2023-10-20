import javax.swing.JApplet;

import Controller.Controller;
/**
 * 
 * @author Giwrgos Mitsos 3660
 *
 */

@SuppressWarnings({ "deprecation", "serial" })
public class main extends JApplet {

	public static void main(String args[]){
		
		Controller game = new Controller();
		game=null;
		
		
		System.out.println(game);
		
	}
}
