package Model.Finding;
/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

public class Fresco extends Finding{
	final private int points;	//Contains points of this painting
	private String info;	//Contains informations about this painting
	
	public Fresco(String name,int value){
		super(name);
		this.points=value;
		this.info="";
		/**
		 * Constructor
		 * sets name,points,and info of this item
		 */
	}
	
	public int getValue() {
		/**
		 * Accessor
		 * Post condition : Returns number of points aquired by photoshooting this painting
		 */
		return this.points;
	}
	
	public boolean isAvailable() {
		/** 
		 * Observer
		 * Post condition : Paintings are always available so this method returns true
		 */
		return true;
	}
	
	public String getInfo() {
		/**
		 * Accessor
		 * post condition : returns string with all information about this painting
		 */
		return info;
	}
	

}
