package Model;

import Model.Card.Place;
import Model.Finding.Finding;

public class FindingPosition implements Position {

	Place path;
	private Finding item;
	public FindingPosition(Finding c,Place path) {
		this.item = c;
		this.path = path;
	}
	@Override
	public Player whoIsHere() {
		/**
		 * post condition : return the player who is here
		 * returns player 
		 */
		return null;
	}

	@Override
	public void setVisit() {
		/**
		 * Transformer
		 * postcondition : sets the players that just got here
		 * 
		 */
		
	}

	@Override
	public void clear() {
		/**
		 * Transformer
		 * postcondition : erases all players come here and findings 
		 * 		 
		 */
		
	}

	@Override
	public boolean gotWinner() {
		/**
		 * Observer
		 * post condition determines a winner if someone hits 7 block
		 */
		return true;
	}
	@Override
	public void setFinding(Finding f) {
		/**
		 * Transformer 
		 * post condition : sets the finding in this position
		 */
		this.item=f;
	}
	@Override
	public Finding getFinding() {
		/**
		 * Accessor 
		 * post condition : return the finding
		 */
		return item;
	}
	@Override
	public void setScore() {
		/**
		 * Transformer
		 * Post condition : set the score of this position
		 */
		
	}
	@Override
	public int getScore() {
		/**
		 * Accessor 
		 * post condition : return the score of this position
		 */
		return 0;
	}
	
	public Place getPlace() {
		return this.path;
	}

}
