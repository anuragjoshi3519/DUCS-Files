import java.util.Scanner;

class StarPattern{
    public static void main(String args[]){
        int n;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number: ");
        n = scan.nextInt();
        scan.close();
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<2*n-1;j++){
                if(i==j || i+j==(2*n-2) ) System.out.print('*');
                else System.out.print(' ');
            }
            System.out.print('\n');
        }
    }
}