package Model.Card;
/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

    public abstract class Card {
    String type;
	protected Place place;  // Enum variable indicates the path of the item
	
	public Card(Place place,String type){
		this.place=place;
		this.type=type;
		/**
		 * Constructor
		 * 
		 * post condition : sets place into the right path
		 */
	}
	
	abstract public boolean ValidPlay(Card c,int turn);
	
	public Place getPlace() {
		/**
		 * Accessor
		 * post condition : returns the place value
		 */
		return place;
	}
	
}


