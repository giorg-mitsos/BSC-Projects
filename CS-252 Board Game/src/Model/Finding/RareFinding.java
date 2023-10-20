package Model.Finding;
/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

public class RareFinding extends Finding {
	final private int points;
	private String info;
	private boolean Exists;
	
	public RareFinding(String name,int value) {
		super(name);
		this.points=value;
		this.info="";
		this.Exists=true;
		/**
		 * CONSTRUCTOR
		 * Sets name,points,existance and info of this Rare Item
		 */
	}
	
	public int getValue() {
		/**
		 * Accessor
		 * post-condition : Returns number of points 
		 * Returns the value of the RareFinding
		 */
		return points;
	}
	
	public boolean isAvailable() {
		/**
		 * OBSERVER
		 * post condition : Return the existance of this item
		 * Returns whether the RareFinding is available or not
		 */
		return Exists;
	}
	
	public void TakeIt() {
		/**
		 * TRANSFORMER
		 * Post condition :
		 * Defines that this item is no longer available
		 */
		Exists = false;
	}
	
	public String getInfo() {
		/**
		 * Accessor
		 * Post condition: returns all information about this item
		 */
		return info;
	}

}
