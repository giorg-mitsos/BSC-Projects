package Model.Card;
/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

public class SpecialCard extends Card {
	
	private String name; //Contains the name of this card
	
	public SpecialCard(String name, Place place) {
		super(place,"SpecialCard");
		setName(name);
		/**
		 * Constructor
		 * Post condition :  Sets place value and name value into the given ones
		 */
	}
	
	public void setName(String name) {
		this.name=name;
		/**
		 * Transformer
		 * Post condition :  sets the name of this item into given one
		 */
	}
	
	public String getName() {
		return this.name;
		/**
		 * Accessor
		 * Post condition : returns the value of the name variable of this item
		 */
	}
	
	public String toString() {
		return this.name+" "+this.place;
		/**
		 * Accessor
		 * Post condition : returns String with name and place (ex. Minotaur KNOSSOS)
		 */
	}
	
	public void ActionOnPlay(SpecialCard this) {
		/**
		 * Pre condition : Can play this card
		 * Post condition : Takes care of all processes need to be done 
		 * when playing a card
		 */
		
	}

	@Override
	public boolean ValidPlay(Card c,int turn) {
		/**
		 * Observer
		 * Pre condition : Give a valid Card 
		 * Post condition : Determines whether you can play a specific card
		 */
		return false;
	}

}
