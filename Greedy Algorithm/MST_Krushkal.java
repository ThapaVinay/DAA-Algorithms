import java.util.Scanner;
public class MST_Krushkal{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int arr[][] = new int[9][9];
        for(int i=0; i<9 ;i++)
        {
            for(int j=0; j<9 ;j++)
            {
                if(i == j || i > j)
                {
                    continue;
                }
                System.out.println("Enter :" + i + j);
                int x = sc.nextInt();
                arr[i][j] = x;
                arr[j][i] = x;

            }
        }
        for(int i =0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        //krushkal()
    }
}