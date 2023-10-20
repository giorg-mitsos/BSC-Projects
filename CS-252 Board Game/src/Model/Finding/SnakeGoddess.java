package Model.Finding;
/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

public class SnakeGoddess extends Finding {
	
	private boolean Exists;  // Its value determines this item availability
	private String info;	// Contains description of this item
	
	public SnakeGoddess(){
		super("Θεά των Φιδιών");
		this.Exists=true;
		this.info="";
		/**
		 * CONSTRUCTOR
		 * Gives a name to this item and sets exists to true
		 * because in the beginning of the game all findings
		 * are available,also adds info message
		 */
		
	}
	
	public boolean isAvailable() {
		/**
		 * OBSERVER
		 * post - condition : returns whether this item exist to collect it
		 * Returns whether this item is available
		 */
		return Exists;
	}
	
	public void TakeIt() {
		/**
		 * 
		 * TRANSFORMER
		 * post condition : sets Exists to false
		 * Defines that this item is no longer available
		 */
		Exists=false;
	}
	
	public String getInfo() {
		/**
		 * ACCESSOR
		 * post condition : returns all info about an item in a string
		 * Gives description of this item
		 */
		return info;
	}
	
	
	
	

}
