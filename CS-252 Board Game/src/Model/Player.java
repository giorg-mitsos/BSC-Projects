package Model;
/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */
import java.util.ArrayList;
import Model.Card.*;
import Model.Finding.*;


public class Player {
	private int score; //total points
	public Card[] cards = new Card[8]; //hand cards
	ArrayList<Finding> collectables=new ArrayList<Finding>(); //all found items (RareFindings - Frescos)
	int Snakes; //all SnakeGoddess collected
	public Position p1,p2,p3,thiseas; // characters position in path??
	
	public Player(){
		this.score = 0;
		this.Snakes = 0;
		p1=new SimplePosition(null);
		p2=new SimplePosition(null);
		p3=new SimplePosition(null);
		thiseas=new SimplePosition(null);
		/**
		 * Constructor
		 */
	}
	
	public int getSnakes() {
		return this.Snakes;
	}
	
	public int scoreCalculator() {
		int total=0;
		/**
		 * Accessor 
		 * post condition : Return the Total score of a player
		 */
		total = this.getSnakePoints();
		this.setScore(total);
		return total;
	}
	
	public int getScore() {
		/**
		 * Accessor
		 * post condition : return the score
		 * returns Score of player
		 */
		setScore(scoreCalculator());
		return score;
	}
	
	public void setScore(int score) {
		/**
		 * Transformer
		 * post condition : refresh the score
		 * sets score of player
		 */
		this.score=score;
	}
	

	
	public ArrayList<Finding> getFindings() {
		/**
		 * Accessor
		 * postconditon  : return the collectables list
		 * returns ArrayList<Finding> collectables 
		 */
		return collectables;
		
	}
	
	public void addSnakeGoddess() {
		/**
		 * Transformer
		 * post condition : increase the snake counter
		 * adds a SnakeGoddess
		 */
		Snakes+=1;
	}
	
	public int getSnakePoints() {
		int total = 0;
		/**
		 * Accessor
		 *  post condition : calculate and return all points acquired 
		 * returns all snake points collected
		 */
		if(Snakes==0)total=0;
		else if(Snakes==1)total=-20;
		else if(Snakes==2)total=-15;
		else if(Snakes==3)total=5;
		else if(Snakes==4)total=15;
		else if(Snakes==5)total=30;
		else if(Snakes==6)total=45;
		else if(Snakes==7)total=55;
		else if(Snakes==8)total=70;
		else if(Snakes==9)total=90;
		else if(Snakes==10)total=100;
		return total;
	}
	
	
	public Place getPath(Position p) {
		
		/**
		 * Accessor 
		 * Post condition : return the path of this pawn
		 */
		return p.getPlace();
	}
	
	
	
	

}
