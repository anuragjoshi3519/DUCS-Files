import java.io.*; 

class Duplicates {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 

    public static void main(String args[]) {
        int table[] = new int[128];
        String input="";
	System.out.println(); // for new line
        do {
            try {
                System.out.print("Enter a string: ");
                input = br.readLine(); 
            } catch (IOException e) { 
                System.out.println(e);
            }
        } while (input.equals(""));

        for (int i = 0; i < input.length(); i++) { 
            char ch = input.charAt(i); 
            try {
                table[ch]++; 
            } catch (ArrayIndexOutOfBoundsException e) { 
                System.out.println("Invalid character present in string");
            }
        }
        System.out.print("Duplicate Characters are: ");
        boolean notFound = true; 
        for (int i = 0; i < 128; i++) { 
            if (table[i] > 1) { 
                System.out.print("'"+(char)(i)+"'"+ "   "); 
                notFound = false;
            }
        }
        if (notFound) {
            System.out.println("Not Found\n");
        }else System.out.println("\n");
    }
}
