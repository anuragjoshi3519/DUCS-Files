import java.io.*;

class PerfectSquare {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                                                                                     

    public static void main(String args[]) {
       
        int number=-1; 

        while(true) {
            try {
                System.out.print("Please enter a number: ");
                number = Integer.parseInt(br.readLine()); 
                if (number < 0) throw new ArithmeticException();
		else break;
            } catch (IOException e1) {
                System.out.println(e1);
                break; 
            } catch (NumberFormatException e2) { 
                System.out.println("Please enter a valid number.\n");
		continue;
            } catch (ArithmeticException e3) {
                System.out.println("Negative numbers are not allowed.\n");
                continue;
            }
	}
	
	double root = Math.sqrt(number);
 	if (root == (int) (root)) System.out.println(number + " is a perfect square");
        else System.out.println(number + " is not a perfect square"); 
    
    }

}
