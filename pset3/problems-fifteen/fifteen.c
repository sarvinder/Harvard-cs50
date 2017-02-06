/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;
int blankTileRowLocation;
int blankTileColLocation;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
bool validmove(int TR,int TC,int BR,int BC);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
   int number=(d*d)-1;
    // TODO
    if(d%2==0)
    {
      //its even
         for(int i=0;i<d;i++)
        {
                for(int j=0;j<d;j++)
                {
                    if(i==d-1&&j==d-3)
                    {
                        board[i][j]=number-1;
                        number--;
                    }
                    else if(i==d-1&&j==d-2)
                    {
                        board[i][j]=number+1;
                        number--;
                    }
                    else
                    {
                    board[i][j]=number;
                    number--;
                
                    }    
                }
        }
        
    }
    else
    {
          //its odd
        for(int i=0;i<d;i++)
        {
                for(int j=0;j<d;j++)
                {
                    board[i][j]=number;
                    number--;
                }
        }
    }
    blankTileRowLocation=d-1;
    blankTileColLocation=d-1;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(board[i][j]==0)
            {
                printf(" -");
            }
            else
            {
            printf("%2i",board[i][j]);
            }
        }printf("\n");
    }
    
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    
    
    int tileRowLocation=0;
    int tileColLocation=0;
    
    
    
    if(tile>(d*d)-1)
    {
        printf("Invalid move number is grater\n");
        return false;
    }
    else
    {
    
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(board[i][j]==tile)
            {
                tileRowLocation=i;
                tileColLocation=j;
            }
        }
    }
    
    //valid move
    bool result=validmove(tileRowLocation,tileColLocation,blankTileRowLocation,blankTileColLocation);
    //2nd step is to check whether the move is valid 
     if(result==true)
    {
        //get the tile user selected
        int Utile=board[tileRowLocation][tileColLocation];
        printf("user tile is : %i\n",Utile);
        
        int Btile=board[blankTileRowLocation][blankTileColLocation];
        printf("blank tile is : %i\n",Btile);
        
        
        
        board[blankTileRowLocation][blankTileColLocation]=Utile;
        board[tileRowLocation][tileColLocation]=Btile;
        
        blankTileRowLocation=tileRowLocation;
        blankTileColLocation=tileColLocation;
        
        draw();
    }
    
    
    
    return result;
    }
}


bool validmove(int TR,int TC,int BR,int BC)
{
 
    if(TR==BR)
    {
        printf("Row are same\n");
        if(TC==BC-1)
        {
            printf("Tile is to the left of the black \n");
            return true;
        }
        else if(TC==BC+1)
        {
             printf("The tile is to the right of the blank\n");
             return true;
        }
        else
        {
             printf("The tile is same as the blank that means invalid move \n");
             return false;
        }
    }
    if(TR==BR-1)
    {
        printf("The tile Row is above than the blank row \n");
        if(TC==BC){
            printf("Valid move and tile is above the blank tile\n");
            return true;
        }
        else
        {
            printf("invalid move");
            return false;
        }
    }
    
    if(TR==BR+1)
    {
        printf("The tile is below the blank row\n");
        if(TC==BC)
        {
            printf("The tile is below the blank tile\n");
            printf("valid move\n");
            return true;
        }
        else
        {
            printf("Invalid move\n");
            return false;
        }
    }
    
    return false;
}



/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    
    int number=0;
    // TODO
    bool value=false;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
           // printf("the board at i and j is %i\n ",board[i][j]);
            //printf("the number is %i",number);
            if(board[i][j]==number){
                value=true;
            }
            else
            {
                value=false;
                break;
            }
            number++;
        }
        if(value==false)
        {
         break;   
        }
    }
    
    return value;
    
}
