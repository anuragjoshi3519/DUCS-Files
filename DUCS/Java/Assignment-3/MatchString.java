import java.util.Scanner;

class NoMatchException extends Exception {
    NoMatchException() {
        super("NoMatchError : strings did not match");
    }
}

class StringCheck {

    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.print("Enter the string: ");

        try{
	    String str = scanner.next();             
            if ( !str.contentEquals("India") ) {
                throw new NoMatchException();
            }else{
		System.out.println("Long Live India !");
            }
        } catch (NoMatchException e) {
            System.out.println(e.getMessage());
        } finally {
            scanner.close();
        }

    }
}
