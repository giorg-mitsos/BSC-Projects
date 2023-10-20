
package Controller;
/**
 * @author Giwrgos mitsos AM:3660
 * @version 0.98
 */

import Model.*;
import Model.Card.Card;
import Model.Card.NumberCard;
import Model.Card.Place;
import Model.Card.SpecialCard;
import Model.Finding.Finding;
import Model.Finding.Fresco;
import Model.Finding.RareFinding;
import Model.Finding.SnakeGoddess;
import View.*;

import java.util.ArrayList;
import java.util.Collections;


public class Controller {
	
	private int decknum; //num of cards in deck
	private ArrayList<Player> players = new ArrayList<Player>(); //list of players (1,2)
	private ArrayList<Card> deck = new ArrayList<Card>();//deck of cards
	private Player p1,p2; //initializes two players
	private Card cardToPlay; //represents the card to be played
	private boolean cardPlayed; 
	public Board table;
	private int turn=-1;
	private int checkpoints;
	private Finding[] items=new Finding[20];
	public GraphicUI gui;
	public String pawnName="";
	
	
	public Controller() {
		table=new Board();
		table.setGame(this);
		p1=new Player();
		p2=new Player();
		table.p1=this.p1;
		table.p2=this.p2;
		players.add(p1);
		players.add(p2);
		p1.setScore(0);
		p2.setScore(0);
		checkpoints=0;
		gui=new GraphicUI();
		init_deck(deck);
		init_starting_hands(deck,p1,p2);
		setTurn();
		initHandCards(p1.cards,p2.cards);
		gui.setInfos(decknum,checkpoints,getTurn());
		setAvailablePawns(p1,p2);
		gui.setScoreLabel(0, p1.getScore());
		gui.setScoreLabel(1, p2.getScore());
		gui.setSnakes(0, p1.getSnakes());
		gui.setSnakes(1, p2.getSnakes());
		init_paths_findings();
		gui.setGame(this);

		
	}
	
	public void replaceCard() {
		int i=0;
		String path="images/cards/";
		if(this.getTurn()==0) {
			for(i=0;i<8;i++) {
				if(p1.cards[i]==null) {
					break;
				}
			}
			p1.cards[i]=deck.get(deck.size()-1);
			deck.remove(deck.size()-1);
			decknum--;
			path+=p1.cards[i].getPlace().toString().toLowerCase();
			if(p1.cards[i].toString().charAt(1)=='0') {
				path+="10.jpg";
			}
			else if(p1.cards[i].toString().startsWith("M")) {
				path+="Min.jpg";
			}
			else if(p1.cards[i].toString().startsWith("A")) {
				path+="Ari.jpg";
			}
			else {
				path+=p1.cards[i].toString().charAt(0)+".jpg";
			}
			
			
		}
		else {
			for(i=0;i<8;i++) {
				if(p2.cards[i]==null) {
					break;
				}
			}
			p2.cards[i]=deck.get(deck.size()-1);
			deck.remove(deck.size()-1);
			decknum--;
			path+=p2.cards[i].getPlace().toString().toLowerCase();
			if(p2.cards[i].toString().charAt(1)=='0') {
				path+="10.jpg";
			}
			else if(p2.cards[i].toString().startsWith("M")) {
				path+="Min.jpg";
			}
			else if(p2.cards[i].toString().startsWith("A")) {
				path+="Ari.jpg";
			}
			else {
				path+=p2.cards[i].toString().charAt(0)+".jpg";
			}
		}
		
		gui.setHandCard(this.getTurn(), path, i);
		this.setTurn();
	}
	
	public void setAvailablePawns(Player p1,Player p2) {
		int i=0,j=0;
		if(p1.p1.getPlace()==null)i++;
		if(p1.p2.getPlace()==null)i++;
		if(p1.p3.getPlace()==null)i++;
		if(p1.thiseas.getPlace()==null)j++;
		gui.setAvailable(0, i, j);
		i=0;
		j=0;
		if(p2.p1.getPlace()==null)i++;
		if(p2.p2.getPlace()==null)i++;
		if(p2.p3.getPlace()==null)i++;
		if(p2.thiseas.getPlace()==null)j++;
		gui.setAvailable(1, i, j);
		
	}
	public void initHandCards(Card[] deck1,Card[] deck2) {
		int i=0;
		String clas,name,path="images/cards/";
		for(i=0;i<8;i++) {
			clas=deck1[i].getClass().getSimpleName();
			if(clas.startsWith("S")) {
				String path2;
				if(deck1[i].toString().startsWith("A")) {
					name="Ari";
				}
				else {
					name="Min";
				}
				path2=deck1[i].getPlace().toString().toLowerCase()+name+".jpg";
				gui.setHandCard(0, path+path2, i);
			}
			else {
				String path2="";
				path2=deck1[i].getPlace().toString().toLowerCase();
				
				if(deck1[i].toString().charAt(1)=='0') {
					path2+="10.jpg";
				}
				else {
				
					path2+=deck1[i].toString().charAt(0)+".jpg";
				}
				gui.setHandCard(0, path+path2, i);
			}
		}
		
		for(i=0;i<8;i++) {
			clas=deck2[i].getClass().getSimpleName();
			if(clas.startsWith("S")) {
				String path2="";
				if(deck2[i].toString().startsWith("A")) {
					name="Ari";
				}
				else {
					name="Min";
				}
				path2=deck2[i].getPlace().toString().toLowerCase()+name+".jpg";
				gui.setHandCard(1, path+path2, i);
			}
			else {
				String path2="";
				path2=deck2[i].getPlace().toString().toLowerCase();
				
				if(deck2[i].toString().charAt(1)=='0') {
					path2+="10.jpg";
				}
				else {
				
					path2+=deck2[i].toString().charAt(0)+".jpg";
				}
				gui.setHandCard(1, path+path2, i);
			}
		}
	}
	//initializes the starting hands of each player
	public void init_starting_hands(ArrayList<Card> deck, Player p1,Player p2) {
		/**
		 * Transformer
		 * post condition : initializes the starting hand
		 */
		int i,j=0;
		for(i=0;i<8;i++) {
			p1.cards[j]=deck.get(i);
			deck.remove(i);
			j++;
		}
		j=0;
		for(i=40;i<48;i++) {
			p2.cards[j]=deck.get(i);
			deck.remove(i);
			j++;
		}
		decknum=deck.size();
		
		
	}

	/*
	 * method to define that a card got played
	 */
	public void setCardPlayed(boolean cardPlayed) {
		/**
		 * Transformer 
		 * post condition : sets whether the card got played or not
		 * 
		 */
	}
	//method that returns cardPlayed
	public boolean getCardPlayed() {
		
		/**
		 * Observer
		 * Post condition : Returns whether a card got played
		 */
		return cardPlayed;
	}
	/*
	 * method to initialize the deck
	 */
	public void init_deck(ArrayList<Card> deck2) {
		/**
		 * Transformer
		 * post condition : initialize the deck
		 */
		int i,value=1;
		for (i=0;i<20;i++) {
			if(i%10==0) {
				value = 1;
			}
			deck2.add(new NumberCard(value,Place.KNOSSOS));
			value++;
		}
		value=1;
		for (i=0;i<20;i++) {
			if(i%10==0) {
				value = 1;
			}
			deck2.add(new NumberCard(value,Place.PHAISTOS));
			value++;
		}
		value=1;
		for (i=0;i<20;i++) {
			if(i%10==0) {
				value = 1;
			}
			deck2.add(new NumberCard(value,Place.ZAKROS));
			value++;
		}
		value=1;
		for (i=0;i<20;i++) {
			if(i%10==0) {
				value = 1;
			}
			deck2.add(new NumberCard(value,Place.MALIA));
			value++;
		}
		for(i=0;i<3;i++) {
			deck2.add(new SpecialCard("Ari", Place.PHAISTOS));
		}
		for(i=0;i<3;i++) {
			deck2.add(new SpecialCard("Ari", Place.ZAKROS));
		}
		for(i=0;i<3;i++) {
			deck2.add(new SpecialCard("Ari", Place.MALIA));
		}
		for(i=0;i<3;i++) {
			deck2.add(new SpecialCard("Ari", Place.KNOSSOS));
		}
		
		for(i=0;i<2;i++) {
			deck2.add(new SpecialCard("Min",Place.PHAISTOS));
		}
		for(i=0;i<2;i++) {
			deck2.add(new SpecialCard("Min",Place.KNOSSOS));
		}
		for(i=0;i<2;i++) {
			deck2.add(new SpecialCard("Min",Place.MALIA));
		}
		for(i=0;i<2;i++) {
			deck2.add(new SpecialCard("Min",Place.ZAKROS));
		}
		
		
		decknum=deck.size();
		Collections.shuffle(deck2);
		
	}

	public void init_paths_findings() {
		items[0]=new RareFinding("ring", 25);
		items[1]=new RareFinding("kosmima", 25);
		items[2]=new RareFinding("diskos", 35);
		items[3]=new RareFinding("ruto", 25);
		int i;
		for (i=4;i<14;i++) {
			items[i]=new SnakeGoddess();
		}
		items[14]=new Fresco("fresco1_20", 20);
		items[15]=new Fresco("fresco2_20", 20);
		items[16]=new Fresco("fresco3_15", 15);
		items[17]=new Fresco("fresco4_20", 20);
		items[18]=new Fresco("fresco5_15", 15);
		items[19]=new Fresco("fresco6_15", 15);
												
				
				
				
	}


	public int getTurn() {
		/**
		 * Accessor
		 * post condition : return the turn 0 for p1 and 1 for p2
		 */
		return turn;
	}
	public void setTurn() {
		/**
		 * Observer 
		 * Post condition : Defines whose turn is to play
		 */
		if(turn==-1)turn=(int)(Math.random()*2);
		else if(turn==1)turn=0;
		else if(turn==0)turn=1;
		gui.setInfos(decknum,checkpoints,getTurn());
	}
	
	public void setPlayerScore(int value) {
		/**
		 * transformer
		 * post-condition : sets the score of each player
		 */
	}

	
	public Player DefineWinner(Player p1,Player p2) {
		/**
		 * Observer 
		 * Post Condition : return the winner
		 */
		
		return null;
	}

	
	public Card getCardtoPlay() {
		/**
		 * Observer
		 * post condition : returns the card to be played
		 */
		return cardToPlay;
	}
	
	
	public boolean setPawn(Player p,Place place) {
		MessageDialog menu = new MessageDialog();
		String name=menu.Pawn();
		this.pawnName=name;
		int i=0;
		if(place==Place.KNOSSOS)i=0;
		if(place==Place.MALIA)i=1;
		if(place==Place.PHAISTOS)i=2;
		if(place==Place.ZAKROS)i=3;
		if(name=="Arch 1") {
			if(p.p1.getPlace()==null) {
				p.p1=table.paths[i][0];
				gui.drawPawn(getTurn(),this.pawnName ,1,place.toString());
				return true;
			}
		}
		if(name=="Arch 2") {
			if(p.p2.getPlace()==null) {
				p.p2=table.paths[i][0];
				gui.drawPawn(getTurn(),this.pawnName ,1,place.toString());
				return true;
			}
		}
		if(name=="Arch 3") {
			if(p.p3.getPlace()==null) {
				p.p3=table.paths[i][0];
				gui.drawPawn(getTurn(),this.pawnName ,1,place.toString());
				return true;
			}
		}
		if(name=="Thiseas") {
			if(p.thiseas.getPlace()==null) {
				p.thiseas=table.paths[i][0];
				gui.drawPawn(getTurn(),this.pawnName ,1,place.toString());
				return true;
			}
		}
		
		return false;
	}
	
	
	
	public void setCardToPlay(int player,int card) {
		/**
		 * transformer
		 * post Condition : sets the card to be played
		 */
		if(player==0) {
			cardToPlay=p1.cards[card];
		}
		else {
			cardToPlay=p2.cards[card];
		}
		Place place;
		place=cardToPlay.getPlace();
		if(turn==0) {
			if(place!=p1.p1.getPlace() && place!=p1.p2.getPlace() && place!=p1.p3.getPlace() && place!=p1.thiseas.getPlace()) {
				while(!setPawn(p1,place)) {
					System.out.println("Can't use that Pawn");
				}
			}
			else {
				if(p1.p1.getPlace()==place) {
					
					gui.drawPawn(getTurn(),"Arch 1" ,1,place.toString());
				}
				else if(p1.p2.getPlace()==place) {
					gui.drawPawn(getTurn(),"Arch 2",1,place.toString());
				}
				else if(p1.p3.getPlace()==place) {
					gui.drawPawn(getTurn(),"Arch 3" ,1,place.toString());
				}
				else {
					gui.drawPawn(getTurn(),"Thiseas",1,place.toString());
				}
			}
		}
		else {
			if(place!=p2.p1.getPlace() && place!=p2.p2.getPlace() && place!=p2.p3.getPlace() && place!=p2.thiseas.getPlace()) {
				while(!setPawn(p2,place)) {
					System.out.println("Can't use that Pawn");
				}
			}
			else {
				if(p2.p1.getPlace()==place) {
					
					gui.drawPawn(getTurn(),"Arch 1" ,1,place.toString());
				}
				else if(p2.p2.getPlace()==place) {
					gui.drawPawn(getTurn(),"Arch 2",1,place.toString());
				}
				else if(p2.p3.getPlace()==place) {
					gui.drawPawn(getTurn(),"Arch 3" ,1,place.toString());
				}
				else {
					gui.drawPawn(getTurn(),"Thiseas",1,place.toString());
				}
			}
		}	
		setAvailablePawns(p1,p2);
		int value=-1;
		String name=cardToPlay.toString();
		if(name.startsWith("A"))value=100;
		else if(name.startsWith("M"))value=100;
		else if(name.charAt(1)=='0')value=10;
		else if(name.charAt(0)=='1')value=1;
		else if(name.charAt(0)=='2')value=2;
		else if(name.charAt(0)=='3')value=3;
		else if(name.charAt(0)=='4')value=4;
		else if(name.charAt(0)=='5')value=5;
		else if(name.charAt(0)=='6')value=6;
		else if(name.charAt(0)=='7')value=7;
		else if(name.charAt(0)=='8')value=8;
		else if(name.charAt(0)=='9')value=9;
		
		
		boolean isValid= table.validPlay(this.cardToPlay,this.getTurn(),value);
		if(isValid) {
			int posx=0;
			int posy=0;
			if(player==0)posx=card;
			else {
				posx=8+card;
			}
			if(this.getTurn()==1)posy=4;
			if(cardToPlay.getPlace()==Place.MALIA)posy+=1;
			if(cardToPlay.getPlace()==Place.PHAISTOS)posy+=2;
			if(cardToPlay.getPlace()==Place.ZAKROS)posy+=3;
			
			gui.DrawImageToPlayed(posx, posy);
			if(this.getTurn()==0) {
				p1.cards[card]=null;
				gui.deleteHandCard(card);
			}
			else {
				p2.cards[card]=null;
				gui.deleteHandCard(card+8);
			}
			//replaceCard();
			//gui.drawPawn(getTurn(),this.pawnName ,1,place.toString());
			//this.setTurn();
		}
		else {
			System.out.println("Can't play that card");
		}
		
	}
	//method to define the finish of the game
	public boolean gameFinished() {
		/**
		 * Observer
		 * post condition : returns whether the game is finished
		 * 
		 */
		return false;
	}
	
	public void Update() {
		/**
		 * Transformer
		 * post condition : Makes several minor updates
		 */
	}

}
