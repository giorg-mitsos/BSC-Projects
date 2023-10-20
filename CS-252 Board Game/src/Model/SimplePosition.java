package Model;

import Model.Card.Place;
import Model.Finding.Finding;

/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

public class SimplePosition implements Position {

	private Place path;
	
	public SimplePosition(Place path) {
		this.path=path;
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
		 * postcondition : erases all players come here 
		 * 		 
		 */
		
	}

	@Override
	public Finding getFinding() {
		/**
		 * Accessor
		 * post condition : return the Finding in tthis position
		 */
		return null;
	}

	@Override
	public void setScore() {
		/**
		 * Transformer
		 * post condition : set the score of this position
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

	@Override
	public boolean gotWinner() {
		/**
		 * Observer
		 * post condition : Determines a winner
		 */
		return false;
	}

	@Override
	public void setFinding(Finding f) {
		/**
		 * do nothing (simple position)
		 */
		
	}
	
	public Place getPlace() {
		/**
		 * Accessor
		 * post condition : Return the path of this position
		 */
		return this.path;
	}
	

}
