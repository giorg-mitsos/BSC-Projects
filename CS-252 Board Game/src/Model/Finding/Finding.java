package Model.Finding;
/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

public class Finding {
	
	private String name;
	
	public Finding(String name){
		setName(name);
		/**
		 * constructor
		 */
	}
	
	public void setName(String name) {
		this.name=name;
		/**
		 * Transformer
		 * post condition : sets the name of this item
		 */
	}
	
	public String getName() {
		return this.name;
		/**
		 * Accessor 
		 * post condition : return the name of the finding
		 * 
		 */
	}

}
