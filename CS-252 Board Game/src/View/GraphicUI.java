package View;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.URL;

import javax.swing.*;

import Controller.Controller;




@SuppressWarnings("serial")
public class GraphicUI extends JFrame {
	
	public JFrame frame;
	public JLayeredPane board;
	public JLayeredPane player1_panel=new JLayeredPane();	//card panel player 1
	public JLayeredPane player2_panel=new JLayeredPane(); //card panel player 2
	public JButton player1_Fresco; //Frescos button player 1
	public JButton player2_Fresco; //Frescos button player 2
	public JButton[] hand = new JButton[16]; // Card button 0-7 player 1, 8-15 player 2
	public JLabel[] last = new JLabel[8]; // last cards 0-3 player 1, 4-7 player 2
	private JLabel[] score = new JLabel[2]; //Score player 1,player 2
	public JLabel[] snakes = new JLabel[2]; //SnakeGoddess player1,2
	public JLabel[] available = new JLabel[2]; //available Pawns
	public JLabel[] path = new JLabel[36]; //path labels
	public JLabel[] pawn = new JLabel[8]; //pawns 0-3 player 1 4-7 player 2
	public JLabel[] special = new JLabel[8]; //Special Findings 0-3 player 1 and 4-7 player 2
	public JLabel[] scores = new JLabel[10];
	public JButton deck;
	public JLabel info;
	public ClassLoader cldr;
	public URL ImageURL;
	public ImageIcon pic;
	public Image image;
	private Controller game;
	public int p1x=405,p2x=437,step=100,y1=216,y2=297,y3=382,y4=468; //(x,y) for placeing pawns
	
	
	@SuppressWarnings("deprecation")
	public GraphicUI() {
		/*
		 * Constructor
		 */
		int x=1320,y=821;
		cldr=this.getClass().getClassLoader();
		ImageURL= cldr.getResource("images/background.jpg");
		frame = new JFrame("Αναζητώντας τα χαμένα Μινωικά Ανάκτορα");
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		frame.setResizable(false);
		//frame.setLayout(new BorderLayout());
		
		frame.setSize(x, y);
		ImageIcon pic = new ImageIcon(ImageURL);
		Image image = pic.getImage();
		pic=resizeImage(pic.getIconWidth(),pic.getIconHeight()-100,image);
		JLabel background = new JLabel(pic);
		background.setBounds(0,170,pic.getIconWidth(),pic.getIconHeight());
		board = new JLayeredPane();
		board.add(background);
		
		ImageURL = cldr.getResource("images/cards/backCard.jpg");
		pic =new ImageIcon(ImageURL.getFile());
		image = pic.getImage();
		pic = resizeImage(100,140,image);
		deck = new JButton(pic);
		deck.setBounds(100, 350, 100,140);
		board.add(deck,new Integer(2),0);
		scores[0]=new JLabel("-20 Points");
		scores[0].setBounds(400, 175, 56, 10);
		board.add(scores[0],new Integer(2),0);
		scores[1]=new JLabel("-15 Points");
		scores[1].setBounds(500, 175, 56, 10);
		board.add(scores[1],new Integer(2),0);
		scores[2]=new JLabel("-10 Points");
		scores[2].setBounds(600, 175, 56, 10);
		board.add(scores[2],new Integer(2),0);
		scores[3]=new JLabel("5 Points");
		scores[3].setBounds(700, 175, 56, 10);
		board.add(scores[3],new Integer(2),0);
		scores[4]=new JLabel("10 Points");
		scores[4].setBounds(800, 175, 56, 10);
		board.add(scores[4],new Integer(2),0);
		scores[5]=new JLabel("15 Points");
		scores[5].setBounds(900, 175, 56, 10);
		board.add(scores[5],new Integer(2),0);
		scores[6]=new JLabel("30 Points");
		scores[6].setBounds(1000, 175, 100, 10);
		board.add(scores[6],new Integer(2),0);
		scores[9]=new JLabel("Check Point!");
		scores[9].setBounds(1000, 184, 100, 20);
		board.add(scores[9],new Integer(2),0);
		scores[7]=new JLabel("35 Points");
		scores[7].setBounds(1100, 175, 56, 10);
		board.add(scores[7],new Integer(2),0);
		scores[8]=new JLabel("50 Points");
		scores[8].setBounds(1200, 175, 56, 10);
		board.add(scores[8],new Integer(2),0);
		
		int i=0,twist=0,offsetx=100,posx=400;
		for (i=0;i<8;i++) {
			path[i]=new JLabel();
			path[i].setBorder(BorderFactory.createLineBorder(Color.RED));
			path[i].setOpaque(true);
			path[i].setBounds(posx, 210, 75, 65);
			board.add(path[i],new Integer(2),0);
			posx+=offsetx;
			if(twist==0) {
				twist=1;
				ImageURL = cldr.getResource("images/paths/knossos.jpg");
				pic =new ImageIcon(ImageURL.getFile());
				image = pic.getImage();
				pic = resizeImage(75,66,image);
				path[i].setIcon(pic);
			}
			else {
				twist=0;
				ImageURL = cldr.getResource("images/paths/knossos2.jpg");
				pic =new ImageIcon(ImageURL.getFile());
				image = pic.getImage();
				pic = resizeImage(75,66,image);
				path[i].setIcon(pic);
			}
			
		}
		path[i]=new JLabel();
		path[i].setBorder(BorderFactory.createLineBorder(Color.RED));
		path[i].setOpaque(true);
		path[i].setBounds(posx-10, 205, 100, 75);
		board.add(path[i],new Integer(2),0);
		ImageURL = cldr.getResource("images/paths/knossosPalace.jpg");
		pic =new ImageIcon(ImageURL.getFile());
		image = pic.getImage();
		pic = resizeImage(105,80,image);
		path[i].setIcon(pic);
		twist=0;
		offsetx=100;
		posx=400;
		for (i=9;i<17;i++) {
			path[i]=new JLabel();
			path[i].setBorder(BorderFactory.createLineBorder(Color.YELLOW));
			path[i].setOpaque(true);
			path[i].setBounds(posx, 290, 76, 66);
			board.add(path[i],new Integer(2),0);
			posx+=offsetx;
			if(twist==0) {
				twist=1;
				ImageURL = cldr.getResource("images/paths/malia.jpg");
				pic =new ImageIcon(ImageURL.getFile());
				image = pic.getImage();
				pic = resizeImage(76,66,image);
				path[i].setIcon(pic);
			}
			else {
				twist=0;
				ImageURL = cldr.getResource("images/paths/malia2.jpg");
				pic =new ImageIcon(ImageURL.getFile());
				image = pic.getImage();
				pic = resizeImage(76,66,image);
				path[i].setIcon(pic);
			}
			
		}
		path[i]=new JLabel();
		path[i].setBorder(BorderFactory.createLineBorder(Color.YELLOW));
		path[i].setOpaque(true);
		path[i].setBounds(posx-10, 285, 100, 75);
		board.add(path[i],new Integer(2),0);
		ImageURL = cldr.getResource("images/paths/maliaPalace.jpg");
		pic =new ImageIcon(ImageURL.getFile());
		image = pic.getImage();
		pic = resizeImage(105,80,image);
		path[i].setIcon(pic);
		twist=0;
		offsetx=100;
		posx=400;
		for (i=18;i<26;i++) {
			path[i]=new JLabel();
			path[i].setBorder(BorderFactory.createLineBorder(Color.white));
			path[i].setOpaque(true);
			path[i].setBounds(posx, 375, 76, 66);
			board.add(path[i],new Integer(2),0);
			posx+=offsetx;
			if(twist==0) {
				twist=1;
				ImageURL = cldr.getResource("images/paths/phaistos.jpg");
				pic =new ImageIcon(ImageURL.getFile());
				image = pic.getImage();
				pic = resizeImage(76,66,image);
				path[i].setIcon(pic);
			}
			else {
				twist=0;
				ImageURL = cldr.getResource("images/paths/phaistos2.jpg");
				pic =new ImageIcon(ImageURL.getFile());
				image = pic.getImage();
				pic = resizeImage(76,66,image);
				path[i].setIcon(pic);
			}
			
		}
		path[i]=new JLabel();
		path[i].setBorder(BorderFactory.createLineBorder(Color.white));
		path[i].setOpaque(true);
		path[i].setBounds(posx-10, 370, 100, 75);
		board.add(path[i],new Integer(2),0);
		ImageURL = cldr.getResource("images/paths/phaistosPalace.jpg");
		pic =new ImageIcon(ImageURL.getFile());
		image = pic.getImage();
		pic = resizeImage(105,80,image);
		path[i].setIcon(pic);
		twist=0;
		offsetx=100;
		posx=400;
		for (i=27;i<35;i++) {
			path[i]=new JLabel();
			path[i].setBorder(BorderFactory.createLineBorder(Color.BLUE));
			path[i].setOpaque(true);
			path[i].setBounds(posx, 460, 76, 66);
			board.add(path[i],new Integer(2),0);
			posx+=offsetx;
			if(twist==0) {
				twist=1;
				ImageURL = cldr.getResource("images/paths/zakros.jpg");
				pic =new ImageIcon(ImageURL.getFile());
				image = pic.getImage();
				pic = resizeImage(76,66,image);
				path[i].setIcon(pic);
			}
			else {
				twist=0;
				ImageURL = cldr.getResource("images/paths/zakros2.jpg");
				pic =new ImageIcon(ImageURL.getFile());
				image = pic.getImage();
				pic = resizeImage(76,66,image);
				path[i].setIcon(pic);
			}
			
		}
		path[i]=new JLabel();
		path[i].setBorder(BorderFactory.createLineBorder(Color.BLUE));
		path[i].setOpaque(true);
		path[i].setBounds(posx-10, 455, 100, 75);
		board.add(path[i],new Integer(2),0);
		ImageURL = cldr.getResource("images/paths/zakrosPalace.jpg");
		pic =new ImageIcon(ImageURL.getFile());
		image = pic.getImage();
		pic = resizeImage(105,80,image);
		path[i].setIcon(pic);
		
		/*
		 * Design paths done
		 * 
		 */
		player1_panel.setOpaque(true);
		player1_panel.setBounds(0, 0, 1304, 172);
		player1_panel.setBorder(BorderFactory.createLineBorder(Color.RED,2));
		board.add(player1_panel,new Integer(2),0);
		player2_panel.setOpaque(true);
		player2_panel.setBounds(0, 610, 1304, 172);
		player2_panel.setBorder(BorderFactory.createLineBorder(Color.GREEN,2));
		board.add(player2_panel,new Integer(2),0);
		posx=20;
		offsetx=80;
		for (i=0;i<8;i++) {
			hand[i]=new JButton();
			hand[i].setBounds(posx, 5, 70, 100);
			player1_panel.add(hand[i]);
			posx+=offsetx;
		}
		posx=20;
		for(i=8;i<16;i++) {
			hand[i]=new JButton();
			hand[i].setBounds(posx, 5, 70, 100);
			player2_panel.add(hand[i]);
			posx+=offsetx;
		}
		
		last[0]=new JLabel("Κνωσός");
		last[0].setBorder(BorderFactory.createLineBorder(Color.red, 4));
		last[1]=new JLabel("Μάλια");
		last[1].setBorder(BorderFactory.createLineBorder(Color.yellow, 4));
		last[2]=new JLabel("Φαιστός");
		last[2].setBorder(BorderFactory.createLineBorder(Color.DARK_GRAY, 4));
		last[3]=new JLabel("Ζάκρος");
		last[3].setBorder(BorderFactory.createLineBorder(Color.blue, 4));
		posx=700;
		offsetx=80;
		for (i=0;i<4;i++) {
			last[i].setOpaque(true);
			last[i].setBounds(posx, 5, 70, 100);
			player1_panel.add(last[i]);
			posx+=offsetx;
		}
		last[4]=new JLabel("Κνωσός");
		last[4].setBorder(BorderFactory.createLineBorder(Color.red, 4));
		last[5]=new JLabel("Μάλια");
		last[5].setBorder(BorderFactory.createLineBorder(Color.yellow, 4));
		last[6]=new JLabel("Φαιστός");
		last[6].setBorder(BorderFactory.createLineBorder(Color.DARK_GRAY, 4));
		last[7]=new JLabel("Ζάκρος");
		last[7].setBorder(BorderFactory.createLineBorder(Color.blue, 4));
		posx=700;
		offsetx=80;
		for (i=4;i<8;i++) {
			last[i].setOpaque(true);
			last[i].setBounds(posx, 5, 70, 100);
			player2_panel.add(last[i]);
			posx+=offsetx;
		}
		
		player1_Fresco= new JButton("Οι τοιχογραφίες μου");
		player1_Fresco.setBounds(1050, 50, 170, 35);
		player1_panel.add(player1_Fresco);
		player2_Fresco= new JButton("Οι τοιχογραφίες μου");
		player2_Fresco.setBounds(1050, 50, 170, 35);
		player2_panel.add(player2_Fresco);
		
		score[0]=new JLabel("Sample Text");
		score[1]=new JLabel("Sample Text");
		score[0].setBounds(1050, 15, 170, 35);
		score[1].setBounds(1050, 15, 170, 35);
		player1_panel.add(score[0]);
		player2_panel.add(score[1]);
		snakes[0]=new JLabel("Sample Text");
		snakes[1]=new JLabel("Sample Text");
		snakes[0].setBounds(1050, 120, 170, 35);
		snakes[1].setBounds(1050, 120, 170, 35);
		player1_panel.add(snakes[0]);
		player2_panel.add(snakes[1]);
		
		
		ImageURL = cldr.getResource("images/findings/snakes.jpg");
		pic =new ImageIcon(ImageURL.getFile());
		image = pic.getImage();
		pic=resizeImage(50,50,image);
		JLabel snakeicon = new JLabel(pic);
		snakeicon.setBounds(1200, 115, 50, 50);
		snakeicon.setOpaque(true);
		JLabel snakeicon2 = new JLabel(pic);
		snakeicon2.setBounds(1200, 115, 50, 50);
		snakeicon2.setOpaque(true);
		player1_panel.add(snakeicon);
		player2_panel.add(snakeicon2);
		
		available[0]=new JLabel("Sample Text");
		available[0].setBounds(20,140,600,30);
		player1_panel.add(available[0]);
		available[1]=new JLabel("Sample Text");
		available[1].setBounds(20,140,600,30);
		player2_panel.add(available[1]);
		
		
		
		info = new JLabel("Sample Text");
		info.setBackground(Color.white);
		info.setBorder(BorderFactory.createLineBorder(Color.BLACK, 3));
		info.setOpaque(true);
		info.setBounds(75, 500, 150, 65);
		board.add(info,new Integer(2),0);
		
		posx=710;
		offsetx=80;
		for(i=0;i<4;i++) {
			special[i]=new JLabel();
			special[i].setOpaque(true);
			special[i].setBackground(Color.LIGHT_GRAY);
			special[i].setBounds(posx, 105, 50, 50);
			posx+=offsetx;
			player1_panel.add(special[i]);
		}
		posx=710;
		offsetx=80;
		for(i=4;i<8;i++) {
			special[i]=new JLabel();
			special[i].setOpaque(true);
			special[i].setBackground(Color.LIGHT_GRAY);
			special[i].setBounds(posx, 105, 50, 50);
			posx+=offsetx;
			player2_panel.add(special[i]);
		}
		
		//to be deleted
		
		for(i=0;i<3;i++) {
			if(i==3) {
				i++;
			}
			pawn[i]=new JLabel();
			pawn[i].setBounds(0,0,33,50);
			pawn[i].setBorder(BorderFactory.createLineBorder(Color.red,2));
			ImageURL = cldr.getResource("images/pionia/arch.jpg");
			pic =new ImageIcon(ImageURL.getFile());
			image = pic.getImage();
			pic=resizeImage(33,50,image);
			pawn[i].setIcon(pic);
			posx+=offsetx;
			
		}
		pawn[3]=new JLabel();
		pawn[3].setBounds(0,0,35,53);
		pawn[3].setBorder(BorderFactory.createLineBorder(Color.red,2));
		ImageURL = cldr.getResource("images/pionia/theseus.jpg");
		pic =new ImageIcon(ImageURL.getFile());
		image = pic.getImage();
		pic=resizeImage(35,53,image);
		pawn[3].setIcon(pic);
		
		for(i=4;i<8;i++) {
			pawn[i]=new JLabel();
			pawn[i].setBounds(0,0,33,50);
			pawn[i].setBorder(BorderFactory.createLineBorder(Color.green,2));
			ImageURL = cldr.getResource("images/pionia/arch.jpg");
			pic =new ImageIcon(ImageURL.getFile());
			image = pic.getImage();
			pic=resizeImage(33,50,image);
			pawn[i].setIcon(pic);
			posx+=offsetx;
			
		}
		pawn[7]=new JLabel();
		pawn[7].setBounds(0,0,35,53);
		pawn[7].setBorder(BorderFactory.createLineBorder(Color.green,2));
		ImageURL = cldr.getResource("images/pionia/theseus.jpg");
		pic =new ImageIcon(ImageURL.getFile());
		image = pic.getImage();
		pic=resizeImage(35,53,image);
		pawn[7].setIcon(pic);
		
		for(i=0;i<16;i++) {
			hand[i].addActionListener(new CardListener());
		}
		deck.addActionListener(new DeckButton());
		
		frame.add(board);
		frame.setVisible(true);
	}
	
	
	public void setGame(Controller game) {
		this.game=game;
	}
	public void deleteHandCard(int pos) {
		hand[pos].setIcon(null);
	}
	public void DrawImageToPlayed(int handcard,int played) {
		
		last[played].setIcon(hand[handcard].getIcon());
	}
	
	public ImageIcon resizeImage(int x,int y, Image image) {
		
		image = image.getScaledInstance(x, y,Image.SCALE_DEFAULT);
		
		ImageIcon pic = new ImageIcon(image);
		return pic;
	}

	public void setScoreLabel(int i,int num) {
		
		score[i].setText("Το Σκορ μου : "+num);
	}
	public void setSnakes(int i,int num) {
		snakes[i].setText("Αγαλματάκια : "+num);
	}
	public void setAvailable(int i, int num1,int num2) {
		if (num1!=0 && num2!=0) {
			available[i].setText("Παίκτης "+(i+1)+" - Διαθέσιμα Πιόνια "+num1+" Αρχαιολόγοι και "+num2+" Θησέας");
		}
		else if(num1!=0 && num2==0) {
			available[i].setText("Παίκτης "+(i+1)+" - Διαθέσιμα Πιόνια "+num1+" Αρχαιολόγοι");
		}
		else if(num1==0 && num2!=0) {
			available[i].setText("Παίκτης "+(i+1)+" - Διαθέσιμα Πιόνια "+num2+" Θησέας");
		}
		else {
			available[i].setText("Παίκτης "+(i+1)+ " - Δεν υπάρχουν διαθεσιμα πιόνια");
		}
		
	}
	public void setInfos(int numcards,int checkpoints,int turn) {
		String infos;
		infos="<html>Available Cards: "+numcards+"<br/>CheckPoints : "+checkpoints+"<br/>Turn : Player "+(turn+1); 
		info.setText(infos);
	}
	public void setHandCard(int player,String path,int pos) {
		ImageURL=null;
		cldr=this.getClass().getClassLoader();
		ImageURL=cldr.getResource(path);
		pic=new ImageIcon(ImageURL.getFile());
		pic=resizeImage(70,100,pic.getImage());
		if(player==0) {
			hand[pos].setIcon(pic);
		}
		else {
			hand[pos+8].setIcon(pic);
		}
	}
	
	@SuppressWarnings("deprecation")
	public void drawPawn(int turn,String name,int steps,String place) {
		int i=0;
		int x=p1x;
		int y=y1;
		if(place=="MALIA") {
			y=y2;
		}
		else if(place=="PHAISTOS"){
			y=y3;
		}
		else if(place=="ZAKROS") {
			y=y4;
		}
		if (turn==1) {
			i=4;
			x = p2x;
		}
		JLabel pawn=null;
		if(name=="Arch 1") { 
			pawn=this.pawn[i];
			
			}
		
		else if(name=="Arch 2") {
			pawn=this.pawn[i+1];
		}
		else if(name=="Arch 3") {
			pawn=this.pawn[i+2];
		}
		else if(name=="Thiseas") {
			pawn=this.pawn[i+3];
		}
		
		board.add(pawn,new Integer(2),0);
		if(pawn.getX()==0) {
			pawn.setLocation(x,y);
		}
		else {
			x=pawn.getX()+steps*step;
			pawn.setLocation(x,y);
		}
		
	}
	
	/*
	 * Class to make action after a card button is pushed
	 */
	
	private class CardListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			
			Object button = arg0.getSource();
			if(game.getTurn()==0) {
				int i;
				for(i=0;i<8;i++) {
					if(button==hand[i]) {		
						game.setCardToPlay(0, i);
						break;
					}
				}
			}
			else {
				int i;
				for(i=8;i<16;i++) {
					if(button==hand[i]) {
						game.setCardToPlay(1, i-8);
						break;
					}
				}

			}
			
		}
		
	}
	/*
	 * class to make actions when Frescos button is pushed
	 */
	private class FrescoListener implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent arg0) {
		
			
		}
		
	}
	/*
	 * Class makes action when the deck button is pushed
	 */
	private class DeckButton implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent arg0) {
			// TODO Auto-generated method stub
			Object button = arg0.getSource();
			if(button==deck)game.replaceCard();
			
			
		}
		
	}
	
	
	
	
	
	
	

}
