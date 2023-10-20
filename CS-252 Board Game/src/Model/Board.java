package Model;

import java.util.ArrayList;

import Controller.Controller;
import Model.Card.Card;
import Model.Card.Place;

/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

public class Board {
	Controller game;
	public Player p1,p2;
	public Position[][] paths = new Position[4][9];
	Card[][] PlayedCard = new Card[2][4];
	int[][] PlayedCardValue=new int[2][4];
	
	public Board() {
		int i,j;
		for(i=0;i<2;i++) {
			for(j=0;j<4;j++) {
				PlayedCard[i][j]=null;
				PlayedCardValue[i][j]=0;
			}
		}
		initPath(paths);
	}
	
	public boolean validPlay(Card c,int turn,int value) {
		Place place=c.getPlace();
		int j = 5;
		if(place==Place.KNOSSOS)j=0;
		if(place==Place.MALIA)j=1;
		if(place==Place.PHAISTOS)j=2;
		if(place==Place.ZAKROS)j=3;
			if(value!=100) {
				if(PlayedCardValue[turn][j]<=value) {
					PlayedCardValue[turn][j]=value;
					PlayedCard[turn][j]=c;
					return true;
				}
			}
			else {
				
				
				PlayedCard[turn][j]=c;
				return true;
			}
		
		return false;
	}
	public void setGame(Controller game1) {
		this.game=game1;
	}
	
	public void initPath(Position[][] a) {
		/**
		 * Transformer
		 * post Condition : Sets the 4 paths
		 */
		int i,j;
		Place place = null;
		for(i=0;i<4;i++) {
			if(i==0)place=Place.KNOSSOS;
			if(i==1)place=Place.MALIA;
			if(i==2)place=Place.PHAISTOS;
			if(i==3)place=Place.ZAKROS;
			for (j=0;j<9;j++){
				paths[i][j]=new SimplePosition(place);
			}
		}
		
	}
	
	public void setPlayed(Card[][] a) {
		/**
		 * Transformer 
		 * Post Condition : Sets the cards that have been played
		 */
	}
	

	

}
