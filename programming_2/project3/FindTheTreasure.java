import java.awt.*;
import java.util.*;
import java.util.List;
import java.lang.Math; 
import java.util.Random;
/*
 * This program is a non complete functional version of the find the treasure game.
 * In this version, the game has only one row. 
 */
public class FindTheTreasure {
  /* The main method draws out the 5x5 grid implements the color arrays, creates and fills the square grid,
   * and determines what to do when the colors do and don't match
   * */
  static int attempts = 6;  // Intial attempts is equal to 6 tries.
  
  public static void main(String[] args) {
    // Declares variables
    DrawingPanel2 panel = new DrawingPanel2(600,600);
    Graphics g = panel.getGraphics();
    
    int row = -1;
    int col = -1;
    
    int pRow = -2;
    int pCol = -2;
    
    int r = 0;
    int c = 0;
    
    int treasureCounter = 0; // Is used to count the total treasures and is implemented in ending the game
    boolean ret = false;
    
    System.out.println("Project 3 written by Jose David Pague");
    
    int size = getSize(); // this asks the method for the "size" amount of treasures
    
    /*******************************************************************************************************/    
    boolean[] found = new boolean[size];
    int []treasureX = new int[size];
    int []treasureY = new int[size];
    int []selectedX = new int[7];
    int []selectedY = new int[7];
    int [][] selectedXY = new int [5][5];
    
    /* This creates the randomized locations within the 5x5 grid */ 
    int xRand;
    int yRand;
    int [][] totalTreasure = new int [5][5];
      
    for (int a = 0; a < 7; a++) { 
      selectedX[a]=0;
      selectedY[a]=0;
    }
    List<Object> treasureLists = randomizedLocation(size, treasureX, treasureY);
    treasureX = (int[])treasureLists.get(0);
    treasureY = (int[])treasureLists.get(1);
    
    /*******************************************************************************************************/
    //To help locate the treasures
     for (int a = 0; a < size; a++) { 
     System.out.println("[" + treasureX[a] + "," + treasureY[a] + "]"); 
     }
    /*******************************************************************************************************/        
    // Draws the contour of the squares
    for (c = 0; c < 5; c++) { 
      for (r = 0; r < 5; r++) {
        g.drawRect(c * 100 + 50, r * 100 + 50, 100, 100);
      }
    }
    // Fills the squares
    g.setColor(Color.LIGHT_GRAY);
       
     // Adds color to the squares
    for (c = 0; c < 5; c++) {
      for (r = 0; r < 5; r++) {
        g.fillRect(c * 100 + 51, r * 100 + 51, 99, 99);
      }
    }
    /*******************************************************************************************************/  
    // Verifies if the position selected is correct
    while (attempts > 0) {  
      row = getClickRow(panel);
      col = getClickColumn(panel);
      while ((row < 0 || col < 0) && !(pRow == row && pCol == col)) {
        row = getClickRow(panel);        
        col = getClickColumn(panel);       
      }
      System.out.println("Clicking: before ret" + row + ", " + col );
      if (selectedXY[row][col] == 0) { 
        selectedXY[row][col] = 1;
      
        if (pRow != row || pCol != col) { 
          pRow = row;
          pCol = col;
         
          g.setColor(Color.WHITE);               
          g.drawString("                ", 25, 25);
          g.fillRect(0, 0, 600, 50);
        
          g.setColor(Color.BLACK);         
          g.drawString("Attempts available: " + (attempts-1), 25, 25);//creates an attempt icon on the top far left corner
          
          ret = verifyPos(treasureX, treasureY, row, col); // Is used in verifying all treasures using a method
          System.out.println("Clicking: after ret" + row + ", " + col );
          if (row > -1 && col > -1) { // changes color from Grey to Green/Red
            if (ret) {
              g.setColor(Color.GREEN);
              g.fillRect(col * 100 + 51, row * 100 + 51, 99, 99);
              treasureCounter++; // counts the squares that contain the "treasure" and turn green              
            }
            else {
              g.setColor(Color.RED);
              g.fillRect(col * 100 + 51, row * 100 + 51, 99, 99);        
            }          
          }
          //creates the box which congratulated the user when the game is over
          if (size == treasureCounter) { // if the player wins the game, this if statement is used
            
            g.setColor(Color.WHITE);
            g.fillRect(75, 75, 450, 50);
            g.setColor(Color.BLACK);
            g.drawRect(75, 75, 450, 50);
            g.drawString("CONGRATULATIONS! You have won the game", 100, 100); // congratulates the player
            
            g.setFont(new Font ("SansSerif", Font.BOLD, 65));
            g.setColor(Color.BLACK);
            g.drawString("The game is over!", 0 , 300); // Writes a quick message saying game is over
            break;
          }   
          attempts--;
        }     
      }
  }    
    // If the player loses the game, this if statement is used 
    if (size != treasureCounter) { 
    
      g.setColor(Color.WHITE);                    
      g.drawString("                ", 25, 25);
      g.fillRect(0, 0, 600, 50);
      g.setColor(Color.BLACK);         
      g.drawString("Attempts available: " + (attempts), 25, 25); //makes an attempted icon on the top far left corner
      
      g.setColor(Color.WHITE);
      g.fillRect(75, 75, 450, 50);
      g.setColor(Color.BLACK);
      g.drawRect(75, 75, 450, 50);
      g.drawString("You have lost the game", 100, 100); // Provides a message saying that the player has lost
      
      g.setFont(new Font ("SansSerif", Font.BOLD, 65));
      g.setColor(Color.BLACK);
      g.drawString("The game is over!", 0 , 300);
    }
  }

  /*******************************************************************************************************/  
// This method determines where your clicker is in respects to the row you are on and passes it on to the main method
  public static int getClickRow(DrawingPanel2 panel) {
    int x = panel.getClickX();
    int y = panel.getClickY();
    if (x > 50 && x < 550 && y > 50 && y < 150) {
      return 0; // tells the program your clicker is on the first row
    } 
    else if (x > 50 && x < 550 && y > 150 && y < 250) {
      return 1; // dimensions of the second column
    }
    else if (x > 50 && x < 550 && y > 250 && y < 350) {
      return 2; // dimensions of the third column
    }
    else if (x > 50 && x < 550 && y > 350 && y < 450) {
      return 3; // dimensions of the fourth column
    }
    else if (x > 50 && x < 550 && y > 450 && y < 550) {
      return 4; // dimensions of the fifth column
    }  
    else {
      return -1; // tells the program you aren't in the grey box area
    }
  }
  
  /*******************************************************************************************************/
// this method determines where your clicker is in respects to the row you are on and passes it on to the main method
  public static int getClickColumn(DrawingPanel2 panel) {
    int x = panel.getClickX();
    int y = panel.getClickY();
    if (x > 50 && x < 150 && y > 50 && y < 550) {
      return 0; // dimensions of the first column
    }
    else if (x > 150 && x < 250 && y > 50 && y < 550) {
      return 1; // dimensions of the second column
    }
    else if (x > 250 && x < 350 && y > 50 && y < 550) {
      return 2; // dimensions of the third column
    }
    else if (x > 350 && x < 450 && y > 50 && y < 550) {
      return 3; // dimensions of the fourth column
    }
    else if (x > 450 && x < 550 && y > 50 && y < 550) {
      return 4; // dimensions of the fifth column
    }
    else {
      return -1;
    }
  }
  
  /*******************************************************************************************************/
  /*This Method is used to help verify the position of the xPos and yPos*/
  public static boolean verifyPos(int[] xL, int[] yL, int row, int col){ 
    int iCount = xL.length;
    for(int i = 0; i < iCount; i++){
      if( xL[i] == row && yL[i] == col ){
        return true;
      }
    }   
    return false;
  }
  
  /*******************************************************************************************************/
  /* This Method is used to verify is the treasures are found and if so to subtract 1 once it has been found*/
  public static boolean isFinished(boolean[] found){
    attempts = attempts - 1;
    for(int i = 0; i < found.length; i++){
      if (found[i] == false) {
        return false;
      }
    }
    return true;
  }
  
  /*****************************************************************************************************/
  /* This Method asks the user to input a certain number of treasures to later be randomized */
  public static int getSize() {
    Scanner scnr = new Scanner (System.in);
    int size = 0;
    
    while (size <= 0 || size >= 6) { // asks for a number between 1-5
      System.out.println("Please input a number between 1-5 on how many treasures wanted: ");
      size = scnr.nextInt();  
    }
    return size;
  }
  
  /*****************************************************************************************************/
  /* This Method randomizes the location of the given amount of treasures*/
  private static List<Object> randomizedLocation(int size, int[] treasureX, int[] treasureY){
    int treasureCount = 0;
    Random rand = new Random();
    boolean not_existed = false;
    int xRand;
    int yRand;
  
    for (int a = 0; a < size; a++) { // is used to create the treasure
      not_existed = false;
      while( !not_existed ){
        xRand = rand.nextInt(5);
        yRand = rand.nextInt(5);
        
        int j = 0;
        for( ; j < treasureCount; j++){
          if( treasureX[j] == xRand && treasureY[j] == yRand )  { // checks if randomized "treasures" are duplicates
            break;
          }
        }
        
        if(j == treasureCount){
          treasureCount++;
          not_existed = true;
          treasureX[j] = xRand;
          treasureY[j] = yRand;
        }
      }
    }
    return Arrays.asList(treasureX, treasureY);
  }
}








  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
