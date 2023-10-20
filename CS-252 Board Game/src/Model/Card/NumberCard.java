package Model.Card;
/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

public class NumberCard extends Card {
	private int num;	//its value is the number written on the card
	
	public NumberCard(int num, Place place) {
		super(place,"NumberCard");
		setValue(num);
		/**
		 * Constructor
		 * Post condition : sets place (path) and value into num variable
		 */
		
	}
	
	public void setValue(int num) {
		this.num=num;
		/**
		 * Transformer 
		 * Post condition : sets this.num into the value given
		 */
	}
	
	public int getValue() {
		return this.num;
		/**
		 * Accessor
		 * Post condition : returns the value of the card
		 */
	}
	
	public String toString() {
		return this.num+" "+this.place;
		/**
		 * Accessor
		 * Post condition : Returns String with the num and path of card ex. 8 KNOSSOS
		 */
		
	}
	
	public void ActionOnPlay(NumberCard this) {
		/**
		 * Pre condition : be able to play this card
		 * 
		 * Post condition : Does any work possibly need when play NumberCard this
		 */
		
	}

	@Override
	public boolean ValidPlay(Card c,int turn) {
		/**
		 * Observer
		 * Pre condition : Give a valid card
		 * Post contition :  Determines whether you can play a specific card
		 */
		Place place=c.getPlace();
		int value;
		
		
		
		
		return false;
	}

}
