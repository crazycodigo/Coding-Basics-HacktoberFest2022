import java.util.*;

public class Queen
{
    private static int N; //number of queens
    private static int[][] board = new int[100][100];

    private static boolean isAttack(int i,int j)
    {
        int k,l;
        //checking if there is a queen in row or column
        for(k=0;k<N;k++)
        {
            if((board[i][k] == 1) || (board[k][j] == 1))
                return true;
        }

        for(k=0;k<N;k++)
        {
            for(l=0;l<N;l++)
            {
                if(((k+l) == (i+j)) || ((k-l) == (i-j))) //Checks for diagonal attack
                {
                    if(board[k][l] == 1)
                        return true;
                }
            }
        }
        return false;
    }

    private static boolean nQueen(int n)
    {
        int i,j;
        //if n is 0, solution found
        if(n==0)
            return true;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {

                if((!isAttack(i,j)) && (board[i][j]!=1))
                {
                    board[i][j] = 1;
                    // Checking if we can place the next queen if the current queen is placed at a position
                    if(nQueen(n-1)==true)
                    {
                        return true;
                    }
                    board[i][j] = 0;
                }
            }
        }
        return false;
    }

    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter the size of the NxN chessboard: ");
        N = s.nextInt();
        nQueen(N);

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                System.out.print(board[i][j]+"\t");
            System.out.print("\n");
        }
    }
}