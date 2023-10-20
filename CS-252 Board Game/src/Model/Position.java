package Model;

import Model.Card.Place;
import Model.Finding.Finding;

/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

public abstract interface Position {
	
	public Player whoIsHere();
	public void setVisit();
	public void clear();
	public boolean gotWinner();
	public void setFinding(Finding f);
	public Finding getFinding();
	public void setScore();
	public int getScore();
	public Place getPlace();
	
	
	
	

}
